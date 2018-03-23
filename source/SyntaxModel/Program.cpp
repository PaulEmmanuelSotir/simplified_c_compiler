#include "SyntaxModel/Program.h"
#include "utils.h"

namespace SyntaxModel {

    Program::Program(const std::vector<Include>& includes, const std::vector<const Function*>& functions, const std::vector<const Definition*>& declarations, const std::vector<const Definition*>& definitions)
        : includes(includes)
        , functions(functions)
        , declarations(declarations)
        , definitions(definitions)
    {
    }

    Program::~Program()
    {
        utils::delete_all(functions);
        utils::delete_all(declarations);
        utils::delete_all(definitions);
    }

    ostream& operator<<(ostream& os, const Program& prog)
    {
        os << "( program :" << endl;
        for(auto def : prog.definitions) {
            os << *def << endl;
        }
        for(auto function : prog.functions){
            os << *function;
        }
        os << ")" << endl;
        return os;
    }
}
