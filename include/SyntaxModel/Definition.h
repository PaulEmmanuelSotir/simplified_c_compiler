#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"
#include "SyntaxModel/Type.h"

namespace SyntaxModel {

    //TODO: store array size for array declarations/defintions
    class Definition final : public Instruction {
    public:
        using empty_expr_vector = std::vector<const Expression*>;

        Definition(const Type* type, const std::vector<Identifier>& names, const std::vector<const Expression*>& init_values = empty_expr_vector());
        virtual ~Definition();

    private:
        const Type* _type;
        const std::vector<Identifier> _names;
        const std::vector<const Expression*> _init_values;
    };
}
