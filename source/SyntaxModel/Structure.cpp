#include "SyntaxModel/Structure.h"

namespace SyntaxModel {

    Structure::Structure(const Expression* condition, const std::vector<const Instruction*>& instructions)
        : _condition(condition)
        , _instructions(instructions)
    {
    }

    Structure::~Structure()
    {
        delete _condition;
        for (auto* instr : _instructions)
            delete instr;
    }
}
