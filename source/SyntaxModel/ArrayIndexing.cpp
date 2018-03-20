#include "SyntaxModel/ArrayIndexing.h"

namespace SyntaxModel {
    ArrayIndexing::ArrayIndexing(const Identifier& name, const Expression* indice)
        : _name(name)
        , _indice(indice)
    {
    }

    ArrayIndexing::~ArrayIndexing()
    {
        delete _indice;
    }
}
