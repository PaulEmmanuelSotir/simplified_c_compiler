
#pragma once
#include <vector>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"

using namespace std;

namespace SyntaxModel {

    struct Structure : public Instruction {
        Structure(const Expression* condition, const vector<const Instruction*>& instructions);
        virtual ~Structure();
        virtual ostream& toString(ostream& os) const override {
            os << "structure" << endl;
            return os;
        }

        const Expression* condition;
        const vector<const Instruction*> instructions;
    };
}
