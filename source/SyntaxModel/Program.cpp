#include "SyntaxModel/Program.h"
#include "utils.h"

namespace SyntaxModel {

    Program::Program(const antlr4::misc::Interval& source_interval, const std::vector<Include>& includes, const std::list<const Function*>& functions, const std::list<const Definition*>& definitions)
        : SyntaxNodeBase(source_interval, utils::children_list(functions, definitions))
        , includes(includes)
        , functions(functions)
        , definitions(definitions)
    {
    }
}
