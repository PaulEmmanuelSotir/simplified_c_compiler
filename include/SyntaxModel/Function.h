#pragma once
#include <vector>

#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"
#include "SyntaxModel/Type.h"

using namespace std;

namespace SyntaxModel {

    class Args final {
    public:
        Args(const vector<const Type*>& types, const vector<Identifier>& names);
        virtual ~Args();

    private:
        const vector<const Type*> _types;
        const vector<Identifier> _names;
    };

    class Function final {
    public:
        Function(const vector<const Definition*>& definitions, const vector<const Instruction*>& instructions, const Args* arguments, const Identifier& id, const Type* returnType);
        virtual ~Function();

    private:
        const vector<const Definition*> _definitions;
        const vector<const Instruction*> _instructions;
        const Args* _arguments;
        const Identifier _id;
        const Type* _returnType;
    };
}
