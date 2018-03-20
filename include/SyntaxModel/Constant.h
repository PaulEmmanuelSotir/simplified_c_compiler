#pragma once
#include <vector>

#include "SyntaxModel/Expression.h"

namespace SyntaxModel {

    template <Type::PrimitiveType T>
    class Constant final : public Expression {
    public:
        Constant(const Type::UnderlyingType<T>& value)
            : _value(value)
        {
        }
        virtual ~Constant() = default;

    private:
        const Type::PrimitiveType _type = T;
        const Type::UnderlyingType<T> _value;
    };

    template <Type::PrimitiveType T>
    class ArrayConstant final : public Expression {
    public:
        ArrayConstant(const std::vector<const Type::UnderlyingType<T>>& values)
            : _values(values)
        {
        }
        virtual ~ArrayConstant() = default;

    private:
        const Type::PrimitiveType _type = T;
        const std::vector<const Type::UnderlyingType<T>> _values;
    };
}
