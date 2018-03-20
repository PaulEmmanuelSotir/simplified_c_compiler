#include "SyntaxModel/FunctionCall.h"
#include "utils.h"

using namespace std;

namespace SyntaxModel {
    FunctionCall::FunctionCall(const vector<const Expression*>& args, const Identifier& func_name)
        : _args(args)
        , _func_name(func_name)
    {
    }

    FunctionCall::~FunctionCall()
    {
        utils::delete_all(_args);
    }
}
