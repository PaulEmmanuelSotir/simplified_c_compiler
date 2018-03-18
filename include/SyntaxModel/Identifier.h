#pragma once
#include <string>

namespace SyntaxModel {

    class Identifier final {
    public:
        Identifier(const std::string& name);

    private:
        const std::string _name;
    };
}
