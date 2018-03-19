#pragma once

#include "SyntaxModel/Structure.h"

using namespace std;

namespace SyntaxModel {

    class While final : public Structure {
    public:
        While(const Expression* condition, const vector<const Instruction*>& instructions);
        virtual ~While() = default;
    };
}
