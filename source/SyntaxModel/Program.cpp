#include "SyntaxModel/Program.h"
#include "utils.h"

namespace SyntaxModel {

    Program::Program(const std::vector<Include>& includes, const std::vector<const Function*>& functions, const std::vector<const Definition*>& declarations, const std::vector<const Definition*>& definitions)
        : _includes(includes)
        , _functions(functions)
        , _declarations(declarations)
        , _definitions(definitions)
    {
    }

    Program::~Program()
    {
        utils::delete_all(_functions);
        utils::delete_all(_declarations);
        utils::delete_all(_definitions);
    }
}
