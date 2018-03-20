#pragma once
#include <vector>

#include "SyntaxModel/Arg.h"
#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"
#include "SyntaxModel/Type.h"

using namespace std;

namespace SyntaxModel {

    class Function final {
    public:
        Function(const vector<const Definition*>& declarations, const vector<const Definition*>& definitions, const vector<const Instruction*>& instructions, const vector<const Arg*>& arguments, const Identifier& id, const Type& returnType);
        virtual ~Function();

    private:
        const vector<const Definition*> _declarations;
        const vector<const Definition*> _definitions;
        const vector<const Instruction*> _instructions;
        const vector<const Arg*> _arguments;
        const Identifier _id;
        const Type _returnType;
    };
}
