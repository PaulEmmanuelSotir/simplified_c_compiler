#pragma once
#include <vector>

#include "SyntaxModel/Declaration.h"
#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Function.h"
#include "utils.h"

namespace SyntaxModel {

    class Program final {
    public:
        Program(const std::vector<utils::TerminalInfo>& includes, const std::vector<const Function*>& functions, const std::vector<const Declaration*>& declarations, const std::vector<const Definition*>& definitions);
        ~Program();

    private:
        const std::vector<utils::TerminalInfo> _includes;
        const std::vector<const Function*> _functions;
        const std::vector<const Declaration*> _declarations;
        const std::vector<const Definition*> _definitions;
    };
}
