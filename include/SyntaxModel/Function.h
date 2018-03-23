#pragma once
#include <vector>

#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"
#include "SyntaxModel/Type.h"

using namespace std;

namespace SyntaxModel {

    struct Args final {
        Args(const vector<const Type*>& types, const vector<Identifier>& names);
        virtual ~Args();

        const vector<const Type*> types;
        const vector<Identifier> names;
        friend ostream& operator<<(ostream& os, const Args& args);
    };

    struct Function final {
        Function(const vector<const Definition*>& definitions, const vector<const Instruction*>& instructions, const Args* arguments, const Identifier& id, const Type* returnType);
        virtual ~Function();
        friend ostream& operator<<(ostream& os, const Function& dt);

        const vector<const Definition*> definitions;
        const vector<const Instruction*> instructions;
        const Args* arguments;
        const Identifier id;
        const Type* returnType;
    };
}
