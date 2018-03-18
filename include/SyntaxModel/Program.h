#pragma once
#include <iostream>
#include <map>
#include <vector>

#include "SyntaxModel/Declaration.h"
#include "SyntaxModel/Function.h"

namespace SyntaxModel {

    class Program {
    public:
        Program(const std::vector<Function>& functions, const std::vector<Declaration>& declarations);
        virtual ~Program() = default;

    private:
        const std::vector<Function> _functions;
        const std::vector<Declaration> _declarations;
    };
}
