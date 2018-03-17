#pragma once

#include "SyntaxModel/Else.h"
#include "SyntaxModel/Structure.h"

namespace SyntaxModel {
    class If final : public Structure {
    public:
        If();
        virtual ~If() = default;

    private:
        Else _clauseElse;
    };
}
