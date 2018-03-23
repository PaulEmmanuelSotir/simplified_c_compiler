#pragma once
#include "SyntaxModel/Structure.h"

using namespace std;

namespace SyntaxModel {

    struct While final : public Structure {
        While(const Expression* condition, const vector<const Instruction*>& instructions);
        virtual ~While() = default;
        virtual ostream& toString(ostream& os) const override {
            os << "while" << endl;
            return os;
        }
    };
}
