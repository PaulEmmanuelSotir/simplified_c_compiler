#pragma once
#include <string>
#include <vector>

#include "antlr4-runtime.h"

namespace utils {
    struct TerminalInfo {
        TerminalInfo(antlr4::tree::TerminalNode* terminal);
        size_t line;
        size_t column;
        std::string text;
    };

    template <class T>
    void delete_all(const std::vector<T*> vect_of_pointers)
    {
        for (auto* ptr : vect_of_pointers)
            delete ptr;
    }
}
