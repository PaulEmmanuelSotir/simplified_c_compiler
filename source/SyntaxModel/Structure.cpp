#include "SyntaxModel/Structure.h"
#include "utils.h"

#include <list>
namespace SyntaxModel {

    Structure::Structure(const antlr4::misc::Interval& source_interval, const Expression* condition, const std::list<const Instruction*>& instructions, const std::list<const SyntaxNodeBase*>& additionnal_children)
        : Instruction(source_interval, utils::children_list(condition, instructions, additionnal_children))
        , condition(condition)
        , instructions(instructions)
    {
    }
}
