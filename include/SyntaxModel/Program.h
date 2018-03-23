#pragma once
#include <vector>
#include <iostream>

#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Function.h"
#include "SyntaxModel/Terminals.h"

using namespace std;

namespace SyntaxModel {

    struct Program final {
        Program(const vector<Include>& includes, const vector<const Function*>& functions, const vector<const Definition*>& declarations, const vector<const Definition*>& definitions);
        ~Program();
        friend ostream& operator<<(ostream& os, const Program& prog);

        const vector<Include> includes;
        const vector<const Function*> functions;
        const vector<const Definition*> declarations;
        const vector<const Definition*> definitions;
    };
}
