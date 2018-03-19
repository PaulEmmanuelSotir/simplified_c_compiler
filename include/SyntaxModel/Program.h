#pragma once
#include <vector>

#include "SyntaxModel/Declaration.h"
#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Function.h"
#include "utils.h"

using namespace std;

namespace SyntaxModel {

    class Program final {
    public:
        Program(const vector<utils::TerminalInfo>& includes, const vector<const Function*>& functions, const vector<const Declaration*>& declarations, const vector<const Definition*>& definitions);
        ~Program();

    private:
        const vector<utils::TerminalInfo> _includes;
        const vector<const Function*> _functions;
        const vector<const Declaration*> _declarations;
        const vector<const Definition*> _definitions;
    };
}
