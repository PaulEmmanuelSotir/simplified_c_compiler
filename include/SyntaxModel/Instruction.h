#pragma once
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {

    struct Instruction {
        virtual ~Instruction() = default;
        virtual ostream& toString(ostream& os) const = 0;
        friend ostream& operator<<(ostream& os, const Instruction& i){
            return i.toString(os);
        }
    };

    struct Break final : public Instruction {
        virtual ~Break() = default;
        ostream& toString(ostream& os) const {
            os << "break" << endl;
            return os;
        }
    };

    struct Continue final : public Instruction {
        virtual ~Continue() = default;
        ostream& toString(ostream& os) const {
            os << "continue" << endl;
            return os;
        }
    };
}
