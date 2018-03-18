#pragma once
#include <vector>

#include "SyntaxModel/Declaration.h"
#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Identifier.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Function final {
    public:
        Function(const std::vector<const Declaration*>& declarations, const std::vector<const Definition*>& definitions, const std::vector<const Instruction*>& instructions, const Identifier& id);
        virtual ~Function();

    private:
        const std::vector<const Declaration*> _declarations;
        const std::vector<const Definition*> _definitions;
        const std::vector<const Instruction*> _instructions;
        const Identifier _id;
    };
}
