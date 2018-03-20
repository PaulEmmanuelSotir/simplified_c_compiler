#pragma once
#include <vector>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Terminals.h"

using namespace std;

namespace SyntaxModel {
    struct FunctionCall final : public Expression {
        FunctionCall(const vector<const Expression*>& args, const Identifier& func_name);
        virtual ~FunctionCall();

        const vector<const Expression*> args;
        const Identifier func_name;
    };
}
