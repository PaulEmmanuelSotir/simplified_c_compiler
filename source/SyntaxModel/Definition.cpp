#include "SyntaxModel/Definition.h"
#include "utils.h"

namespace SyntaxModel {
    Definition::Definition(const Type* type, const std::vector<Identifier>& names, const std::vector<const Expression*>& init_values)
        : _type(type)
        , _names(names)
        , _init_values(init_values)
    {
    }

    Definition::~Definition()
    {
        delete _type;
        utils::delete_all(_init_values);
    }
}
