#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {
    struct Return final : public Instruction {
        Return(const Expression* expression);
        virtual ~Return();
        virtual ostream& toString(ostream& os) const override {
            os << "return" << endl;
            return os;
        }

        const Expression* expression;
    };
}
