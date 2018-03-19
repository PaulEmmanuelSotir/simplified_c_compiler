#include "SyntaxModel/FunctionCall.h"

using namespace std;

namespace SyntaxModel {
    FunctionCall::FunctionCall(const vector<const Expression*>& args, const Identifier& func_name)
        : _args(args)
        , _func_name(func_name)
    {
    }

    FunctionCall::~FunctionCall()
    {
        for (auto* expr : _args)
            delete expr;
    }
}
