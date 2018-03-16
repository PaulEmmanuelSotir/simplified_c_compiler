#pragma once
#include <iostream>
#include <list>
#include <map>

#include "Declaration.h"
#include "Fonction.h"

namespace SyntaxModel {

    class Programme {
    public:
        Programme();
        virtual ~Programme() = default;

    private:
        std::list<Fonction> _fonctions;
        std::list<Declaration> _declarations;
    };
}
