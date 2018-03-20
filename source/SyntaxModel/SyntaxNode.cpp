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

    //bool SyntaxNodeBase::sameTypeAs(const SyntaxNodeBase& other) const { return getTypename() == other.getTypename(); }
    bool SyntaxNodeBase::operator==(const SyntaxNodeBase& obj) const { return _unique_id == obj._unique_id; }
    bool SyntaxNodeBase::operator<(const SyntaxNodeBase& obj) const { return _unique_id < obj._unique_id; }

    std::list<const SyntaxNodeBase*> SyntaxNodeBase::getAllChildren() const
    {
        std::list<const SyntaxNodeBase*> all_childrens;

        for (const auto* child : _children)
            if (child != nullptr) {
                all_childrens.push_back(child);
                _push_all(all_childrens, child->getAllChildren());
            }
        return all_childrens;
    }

    void _push_all(std::list<const SyntaxNodeBase*>& list, const std::list<const SyntaxNodeBase*>& list_to_merge_with)
    {
        list.resize(list.size() + list_to_merge_with.size());
        for (auto val : list_to_merge_with)
            list.push_back(val);
    }
}
