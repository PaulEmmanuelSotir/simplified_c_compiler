#pragma once
#include <vector>

#include "SyntaxModel/Declaration.h"
#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Identifier.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Arg.h"

using namespace std;

namespace SyntaxModel {

    class Function final {
    public:
        Function(const vector<const Declaration*>& declarations, const vector<const Definition*>& definitions, const vector<const Instruction*>& instructions, const vector<const Arg*>& arguments, const Identifier& name, const Type& typeRetour);
        virtual ~Function();

    private:
        const vector<const Declaration*> _declarations;
        const vector<const Definition*> _definitions;
        const vector<const Instruction*> _instructions;
        const vector<const Arg*> _arguments;
        const Type _typeRetour;
        const Identifier _name;
    };
}
