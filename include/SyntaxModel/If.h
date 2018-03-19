#pragma once

#include "SyntaxModel/Else.h"
#include "SyntaxModel/Structure.h"

using namespace std;

namespace SyntaxModel {
    class If final : public Structure {
    public:
        If(const Expression* condition, const std::vector<const Instruction*>& instructions, const Else* else_clause);
        virtual ~If();

    private:
        const Else* _else_clause;
    };
}
