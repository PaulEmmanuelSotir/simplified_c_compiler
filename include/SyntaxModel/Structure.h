
#pragma once
#include <vector>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"

using namespace std;

namespace SyntaxModel {

    class Structure : public Instruction {
    public:
        Structure(const Expression* condition, const vector<const Instruction*>& instructions);
        virtual ~Structure();

    private:
        const Expression* _condition;
        const vector<const Instruction*> _instructions;
    };
}
