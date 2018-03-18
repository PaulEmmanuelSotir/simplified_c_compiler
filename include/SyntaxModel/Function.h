#pragma once
#include <iostream>
#include <vector>

#include "SyntaxModel/Declaration.h"
#include "SyntaxModel/Identifier.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Function final {
    public:
        Function(const std::vector<Declaration>& declarations, const std::vector<Instruction>& instructions, const Identifier& id);
        virtual ~Function() = default;

    private:
        const std::vector<Declaration> _declarations;
        const std::vector<Instruction> _instructions;
        const Identifier _id;
    };
}
