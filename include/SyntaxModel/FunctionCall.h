#pragma once
#include <vector>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Terminals.h"

using namespace std;

namespace SyntaxModel {
    class FunctionCall final : public Expression {
    public:
        FunctionCall(const vector<const Expression*>& args, const Identifier& func_name);
        virtual ~FunctionCall();

    private:
        const vector<const Expression*> _args;
        const Identifier _func_name;
    };
}
