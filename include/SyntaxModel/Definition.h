#pragma once
#include <list>
#include <vector>

#include "SyntaxModel/Constant.h"
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/SyntaxNode.h"
#include "SyntaxModel/Type.h"

using namespace std;

namespace SyntaxModel {

    //TODO: store array size for array declarations/defintions
    struct Definition final : public Instruction {
        using size_constant = Constant<Type::PrimitiveType::INT32_T>;

        Definition(const antlr4::misc::Interval& source_interval, const Type* type, const std::vector<Identifier>& names, const std::list<const Expression*>& init_values = {});
        Definition(const antlr4::misc::Interval& source_interval, const Type* type, const std::vector<Identifier>& names, const std::list<const size_constant*>& sizes, const std::list<const Expression*>& init_arrays = {});
        virtual ~Definition() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Instruction, Definition>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;

        const Type* type;
        const std::vector<Identifier> names;
        const std::list<const Expression*> init_values;
        const std::list<const size_constant*> sizes = {};
    };
}
