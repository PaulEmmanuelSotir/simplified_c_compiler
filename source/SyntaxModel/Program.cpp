#include "SyntaxModel/Program.h"
#include "utils.h"

namespace SyntaxModel {

    Program::Program(const antlr4::misc::Interval& source_interval, const std::vector<Include>& includes, const std::list<const Function*>& functions, const std::list<const Definition*>& definitions)
        : SyntaxNodeBase(source_interval, utils::children_list(functions, definitions))
        , includes(includes)
        , functions(functions)
        , definitions(definitions)
    {
    }

    std::ostream& Program::toString(std::ostream& os) const
    {
        os << "( program :" << std::endl;
        for (auto def : definitions)
            os << *def << std::endl;
        for (auto function : functions)
            os << *function;
        os << ")" << std::endl;
        return os;
    }

    void Program::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* const eb) const
    {
        // Generate IR for global defintions
        //for (const auto* decl : definitions)
        //    decl->generateIR(cfg, eb);

        // Generate IR for main function (entry point)
        for (const auto& func : functions)
            if (func->id.text == "main")
                func->generateIR(cfg, nullptr);
    }
}
