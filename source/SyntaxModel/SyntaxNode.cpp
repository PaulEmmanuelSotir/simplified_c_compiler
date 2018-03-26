#include "SyntaxModel/SyntaxNode.h"

namespace std {
    size_t hash<SyntaxModel::SyntaxNodeBase>::operator()(const SyntaxModel::SyntaxNodeBase& obj) const
    {
        return hash<size_t>()(obj._unique_id);
    }
}

namespace SyntaxModel {
    size_t SyntaxNodeBase::_instance_count = 0;

    SyntaxNodeBase::SyntaxNodeBase(const antlr4::misc::Interval& source_interval, const std::list<const SyntaxNodeBase*>& children)
        : source_interval(source_interval)
        , _children(children)
    {
    }

    SyntaxNodeBase::~SyntaxNodeBase()
    {
        for (const auto* child : _children)
            delete child;
    }

    bool SyntaxNodeBase::operator==(const SyntaxNodeBase& obj) const { return _unique_id == obj._unique_id; }
    bool SyntaxNodeBase::operator<(const SyntaxNodeBase& obj) const { return _unique_id < obj._unique_id; }

    std::ostream& operator<<(std::ostream& os, const SyntaxNodeBase& node) { return node.toString(os); }

    std::list<const SyntaxNodeBase*> SyntaxNodeBase::getAllChildren() const
    {
        std::list<const SyntaxNodeBase*> all_childrens;

        for (const auto* child : _children)
            if (child != nullptr) {
                all_childrens.push_back(child);
                for (auto val : child->getAllChildren())
                    all_childrens.push_back(val);
            }
        return all_childrens;
    }
}
