#pragma once
#include <optional>

#include "Else.h"
#include "Structure.h"

namespace SyntaxModel {
    class If final : public Structure {
    public:
        If();
        virtual ~If() = default;

    private:
        Else _clauseElse;
    };
}
