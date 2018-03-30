#include "SyntaxModel/Definition.h"
#include "utils.h"

namespace SyntaxModel {
    Definition::Definition(const antlr4::misc::Interval& source_interval, const Type* type, const std::vector<Identifier>& names, const std::list<const Expression*>& init_values)
        : Instruction(source_interval, utils::children_list(type, init_values))
        , type(type)
        , names(names)
        , init_values(init_values)
    {
    }

    Definition::Definition(const antlr4::misc::Interval& source_interval, const Type* type, const std::vector<Identifier>& names, const std::list<const size_constant*>& sizes, const std::list<const Expression*>& init_arrays)
        : Instruction(source_interval, utils::children_list(type, init_values, sizes))
        , type(type)
        , names(names)
        , init_values(init_arrays)
        , sizes(sizes)
    {
    }

    std::ostream& Definition::toString(std::ostream& os) const
    {
        os << *(type) << " ";
        int i = 0;
        for (auto name : names) {
            os << name;
            auto it = utils::get_at(init_values, i);
            if (init_values.size() && it != init_values.cend())
                os << "=" << *it;
            i++;
        }
        os << std::endl;
        return os;
    }

    IR::ExecutionBlock* Definition::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb) const
    {
        /*const auto* analyser = cfg.getAnalyser();

        // TODO: handle arrays
        if (init_values.size() > 0) {
            std::vector<IR::IRVariable> init_tmp_vars;
            init_tmp_vars.reserve(init_values.size());
            for (const auto* expr : init_values) {
                Type type = expr->getExprType(analyser);
                auto init_val_dst = cfg->CreateTempIRVar(type);
                init_tmp_vars.push_back();
                eb = expr->generateIR(cfg, eb, init_val_dst);
            }

            for (const auto* name : names) {
                        }
        }*/
    }
}
