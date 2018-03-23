#include "SyntaxModel/FunctionCall.h"
#include "utils.h"

using namespace std;

namespace SyntaxModel {
    FunctionCall::FunctionCall(const vector<const Expression*>& args, const Identifier& func_name)
        : args(args)
        , func_name(func_name)
    {
    }

    FunctionCall::~FunctionCall()
    {
        utils::delete_all(args);
    }

    ostream& FunctionCall::toString(ostream& os) const
    {
        os << func_name << "(";
        for(auto arg : args)
        {
            os << *arg;
        }
        os << ")" << endl;
        return os;
    }
}
