#include "SyntaxModel/Function.h"
#include "utils.h"

namespace SyntaxModel {

    Args::Args(const vector<const Type*>& types, const vector<Identifier>& names)
        : types(types)
        , names(names)
    {
    }

    Args::~Args()
    {
        utils::delete_all(types);
    }

    Function::Function(const std::vector<const Definition*>& definitions, const std::vector<const Instruction*>& instructions, const Args* arguments, const Identifier& id, const Type* returnType)
        : definitions(definitions)
        , instructions(instructions)
        , arguments(arguments)
        , id(id)
        , returnType(returnType)
    {
    }

    Function::~Function()
    {
        delete arguments;
        delete returnType;
        utils::delete_all(instructions);
        utils::delete_all(definitions);
    }
}
