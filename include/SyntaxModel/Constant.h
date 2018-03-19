#pragma once
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
}
