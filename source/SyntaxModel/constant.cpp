#include "SyntaxModel/Constant.h"

namespace SyntaxModel {
    ArrayConstant<Type::PrimitiveType::CHAR>* make_array_const_from_string(antlr4::tree::TerminalNode* str_token)
    {
        std::string str = str_token->getSymbol()->getText();
        // TODO: remove escaping backslashs (e.g. regex "[^\\]?\\(.)|([^\\])" )
        str = str.substr(1, str.length() - 2);
        std::vector<const Constant<Type::PrimitiveType::CHAR>*> values(str.length());
        for (const auto& c : str)
            values.push_back(new Constant<Type::PrimitiveType::CHAR>(c));

        return new ArrayConstant<Type::PrimitiveType::CHAR>(values);
    }
}
