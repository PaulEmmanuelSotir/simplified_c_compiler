#include "SyntaxModel/FunctionCall.h"
#include "utils.h"

using namespace std;

namespace SyntaxModel {
    FunctionCall::FunctionCall(const antlr4::misc::Interval& source_interval, const list<const Expression*>& args, const Identifier& func_name)
        : Expression(source_interval, utils::container_cast(args))
        , args(args)
        , func_name(func_name)
    {
    }

    std::ostream& FunctionCall::toString(std::ostream& os) const
    {
        os << func_name << "(";
        for (auto arg : args)
            os << *arg;
        os << ")" << std::endl;
        return os;
    }
}
