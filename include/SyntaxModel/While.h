#pragma once

#include "SyntaxModel/Structure.h"

namespace SyntaxModel {

    class While final : public Structure {
    public:
        While();
        virtual ~While() = default;
    };
}
