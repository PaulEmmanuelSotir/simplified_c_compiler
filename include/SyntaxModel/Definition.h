#pragma once
#include <iostream>
#include "SyntaxModel/Constant.h"
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"
#include "SyntaxModel/Type.h"

using namespace std;

namespace SyntaxModel {

    //TODO: store array size for array declarations/defintions
    struct Definition final : public Instruction {
        using empty_expr_vector = std::vector<const Expression*>;
        using size_constant = Constant<Type::PrimitiveType::INT32_T>;

        Definition(const Type* type, const std::vector<Identifier>& names, const std::vector<const Expression*>& init_values = empty_expr_vector());
        Definition(const Type* type, const std::vector<Identifier>& names, const std::vector<const size_constant*>& sizes, const std::vector<const Expression*>& init_arrays = empty_expr_vector());
        virtual ~Definition();
        virtual ostream& toString(ostream& os) const override;

        const Type* type;
        const std::vector<Identifier> names;
        const std::vector<const Expression*> init_values;
        const std::vector<const size_constant*>& sizes = std::vector<const size_constant*>();
    };
}
