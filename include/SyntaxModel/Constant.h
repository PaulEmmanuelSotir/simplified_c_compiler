#pragma once
#include <string>
#include <vector>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/SyntaxNode.h"
#include "SyntaxModel/Type.h"
#include "antlr4-runtime.h"
#include "utils.h"

namespace SyntaxModel {

    template <Type::PrimitiveType T>
    struct Constant final : public Expression {
        Constant(const antlr4::misc::Interval& source_interval, const Type::UnderlyingType<T>& value)
            : Expression(source_interval)
            , value(value)
        {
        }

        virtual ~Constant() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Instruction, Expression, decltype(*this)>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override
        {
            os << "Constant<" << utils::type_name<Type::UnderlyingType<T>>() << "> (" << value << ")";
            return os;
        }

        const Type::PrimitiveType type = T;
        const Type::UnderlyingType<T> value;
    };

    template <Type::PrimitiveType type>
    Constant<type>* make_constant_from_terminal(const antlr4::misc::Interval& source_interval, antlr4::tree::TerminalNode* value_token)
    {
        auto text = value_token->getSymbol()->getText();
        Type::UnderlyingType<type> value;
        // TODO: use 'if constexpr' here if compiling with C++ 17 standard
        // Parse token string
        if (type == Type::PrimitiveType::CHAR) {
            // Take text from literal token and remove quotes and eventual escaping backslash
            value = (text[1] == '\\') ? text[2] : text[1];
        } else if (type == Type::PrimitiveType::INT32_T) {
            value = std::stoi(text);
        } else if (type == Type::PrimitiveType::INT64_T) {
            value = std::stol(text);
        }
        return new Constant<type>(source_interval, value);
    }

    template <Type::PrimitiveType T>
    struct ArrayConstant final : public Expression {
        ArrayConstant(const antlr4::misc::Interval& source_interval, const std::list<const Constant<T>*>& values)
            : Expression(source_interval, utils::container_cast(values))
            , values(values)
        {
        }

        virtual ~ArrayConstant() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Instruction, Expression, decltype(*this)>::typenames(); }

        const Type::PrimitiveType type = T;
        const std::list<const Constant<T>*> values;
    };

    template <Type::PrimitiveType T>
    ArrayConstant<T>* make_array_const(const antlr4::misc::Interval& source_interval, const std::vector<antlr4::tree::TerminalNode*>& terminals)
    {
        std::list<const Constant<T>*> values;
        for (auto* c : terminals) {
            auto interval = antlr4::misc::Interval(c->getSymbol()->getStartIndex(), c->getSymbol()->getStopIndex()); // TODO: make sure this is the right interval
            values.push_back(make_constant_from_terminal<T>(interval, c));
        }
        return new SyntaxModel::ArrayConstant<T>(source_interval, values);
    }

    ArrayConstant<Type::PrimitiveType::CHAR>* make_array_const_from_string(const antlr4::misc::Interval& source_interval, antlr4::tree::TerminalNode* str_token);
}
