#pragma once
#include <iostream>
#include <map>
#include <vector>

#include "SyntaxModel/Declaration.h"
#include "SyntaxModel/Fonction.h"

namespace SyntaxModel {

    class Programme {
    public:
        Programme();
        virtual ~Programme() = default;

    private:
        std::vector<Fonction> _fonctions;
        std::vector<Declaration> _declarations;
    };
}
