#pragma once
#include <vector>

#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Function.h"
#include "SyntaxModel/Terminals.h"

using namespace std;

namespace SyntaxModel {

    class Program final {
    public:
        Program(const vector<Include>& includes, const vector<const Function*>& functions, const vector<const Definition*>& declarations, const vector<const Definition*>& definitions);
        ~Program();

    private:
        const vector<Include> _includes;
        const vector<const Function*> _functions;
        const vector<const Definition*> _declarations;
        const vector<const Definition*> _definitions;
    };
}
