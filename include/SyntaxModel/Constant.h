#pragma once
#include <string>
#include <vector>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Terminals.h"
#include "SyntaxModel/Type.h"

namespace SyntaxModel {

    template <Type::PrimitiveType T>
    struct Constant final : public Expression {
        Constant(const Type::UnderlyingType<T>& value)
            : value(value)
        {
        }

        virtual ~Constant() = default;

        const Type::PrimitiveType type = T;
        const Type::UnderlyingType<T> value;
    };

    template <Type::PrimitiveType type>
    Constant<type>* make_constant_from_terminal(antlr4::tree::TerminalNode* value_token)
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
        return new Constant<type>(value);
    }

    template <Type::PrimitiveType T>
    struct ArrayConstant final : public Expression {
        ArrayConstant(const std::vector<const Constant<T>*>& values)
            : values(values)
        {
        }

        virtual ~ArrayConstant()
        {
            utils::delete_all(values);
        };

        const Type::PrimitiveType type = T;
        const std::vector<const Constant<T>*> values;
    };

    template <Type::PrimitiveType T>
    ArrayConstant<T> make_array_const(const std::vector<antlr4::tree::TerminalNode*>& terminals)
    {
        std::vector<const Constant<T>*> values(terminals.size());
        for (auto* c : terminals) {
            values.push_back(SyntaxModel::make_constant_from_terminal<T>(c));
        }
        return SyntaxModel::ArrayConstant<T>(values);
    }

    ArrayConstant<Type::PrimitiveType::CHAR>* make_array_const_from_string(antlr4::tree::TerminalNode* str_token);
}
