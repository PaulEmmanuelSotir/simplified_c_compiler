#include "utils.h"

namespace utils {
    TerminalInfo::TerminalInfo(antlr4::tree::TerminalNode* terminal)
    {
        auto* token = terminal->getSymbol();
        line = token->getLine();
        column = token->getCharPositionInLine();
        text = token->getText();
    }

    std::ostream& operator<<(std::ostream& os, const TerminalInfo& ti)
    {
        os << ti.text;
        return os;
    }
}
