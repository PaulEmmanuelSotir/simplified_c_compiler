#pragma once
#include "antlr4-runtime.h"
#include <string>

namespace utils {
    struct TerminalInfo {
        TerminalInfo(antlr4::tree::TerminalNode* terminal);
        size_t line;
        size_t column;
        std::string text;
    };
}
