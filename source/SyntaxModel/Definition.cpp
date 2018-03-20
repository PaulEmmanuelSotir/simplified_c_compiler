#include "SyntaxModel/Definition.h"
#include "utils.h"

namespace SyntaxModel {
    Definition::Definition(const Type* type, const std::vector<Identifier>& names, const std::vector<const Expression*>& init_values)
        : type(type)
        , names(names)
        , init_values(init_values)
    {
    }

    Definition::Definition(const Type* type, const std::vector<Identifier>& names, const std::vector<const size_constant*>& sizes, const std::vector<const Expression*>& init_arrays)
        : type(type)
        , names(names)
        , init_values(init_arrays)
        , sizes(sizes)
    {
    }

    Definition::~Definition()
    {
        delete type;
        utils::delete_all(sizes);
        utils::delete_all(init_values);
    }
}
