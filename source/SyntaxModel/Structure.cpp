#include "SyntaxModel/Structure.h"
#include "utils.h"

namespace SyntaxModel {

    Structure::Structure(const Expression* condition, const std::vector<const Instruction*>& instructions)
        : _condition(condition)
        , _instructions(instructions)
    {
    }

    Structure::~Structure()
    {
        delete _condition;
        utils::delete_all(_instructions);
    }
}
