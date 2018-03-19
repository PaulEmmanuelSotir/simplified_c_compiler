#pragma once
#include <vector>

#include "SyntaxModel/Instruction.h"

using namespace std;
namespace SyntaxModel {

    class Else final {
    public:
        Else(const vector<const Instruction*>& instructions);
        ~Else();

    private:
        const vector<const Instruction*> _instructions;
    };
}
