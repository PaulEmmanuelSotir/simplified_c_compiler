#pragma once
#include <string>
using namespace std;

namespace SyntaxModel {

    class Identifier final {
    public:
        Identifier(const string& name);

    private:
        const string _name;
    };
}
