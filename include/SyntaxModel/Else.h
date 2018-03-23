#pragma once
#include <vector>
#include <iostream>

#include "SyntaxModel/Instruction.h"

using namespace std;
namespace SyntaxModel {

    struct Else final {
        Else(const vector<const Instruction*>& instructions);
        ~Else();
        friend ostream& operator<<(ostream& os, const Else& e);

        const vector<const Instruction*> instructions;
    };
}
