#include "SyntaxModel/Function.h"
#include "utils.h"

namespace SyntaxModel {

    Args::Args(const vector<const Type*>& types, const vector<Identifier>& names)
        : _types(types)
        , _names(names)
    {
    }

    Args::~Args()
    {
        utils::delete_all(_types);
    }

    Function::Function(const std::vector<const Definition*>& definitions, const std::vector<const Instruction*>& instructions, const Args* arguments, const Identifier& id, const Type* returnType)
        : _definitions(definitions)
        , _instructions(instructions)
        , _arguments(arguments)
        , _id(id)
        , _returnType(returnType)
    {
    }

    Function::~Function()
    {
        delete _arguments;
        delete _returnType;
        utils::delete_all(_instructions);
        utils::delete_all(_definitions);
    }
}
