#include "SyntaxModel/Structure.h"
#include "utils.h"

namespace SyntaxModel {

    Structure::Structure(const Expression* condition, const std::vector<const Instruction*>& instructions)
        : condition(condition)
        , instructions(instructions)
    {
    }

    Structure::~Structure()
    {
        delete condition;
        utils::delete_all(instructions);
    }
}
