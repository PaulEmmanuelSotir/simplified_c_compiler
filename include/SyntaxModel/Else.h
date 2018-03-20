#pragma once
#include <vector>

#include "SyntaxModel/Instruction.h"

using namespace std;
namespace SyntaxModel {

    struct Else final {
        Else(const vector<const Instruction*>& instructions);
        ~Else();

        const vector<const Instruction*> instructions;
    };
}
