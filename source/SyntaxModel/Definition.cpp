#include "SyntaxModel/Definition.h"
#include "utils.h"

namespace SyntaxModel {
    Definition::Definition(const antlr4::misc::Interval& source_interval, const Type* type, const std::vector<Identifier>& names, const std::list<const Expression*>& init_values)
        : Instruction(source_interval, utils::children_list(type, init_values))
        , type(type)
        , names(names)
        , init_values(init_values)
    {
    }

    Definition::Definition(const antlr4::misc::Interval& source_interval, const Type* type, const std::vector<Identifier>& names, const std::list<const size_constant*>& sizes, const std::list<const Expression*>& init_arrays)
        : Instruction(source_interval, utils::children_list(type, init_values, sizes))
        , type(type)
        , names(names)
        , init_values(init_arrays)
        , sizes(sizes)
    {
    }

    std::ostream& Definition::toString(std::ostream& os) const
    {
        os << *(type) << " ";
        int i = 0;
        for (auto name : names) {
            os << name;
            auto it = utils::get_at(init_values, i);
            if (init_values.size() && it != init_values.cend())
                os << "=" << *it;
            i++;
        }
        os << std::endl;
        return os;
    }
}
