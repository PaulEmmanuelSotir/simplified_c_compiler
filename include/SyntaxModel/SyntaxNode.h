#pragma once
#include <functional>
#include <iostream>
#include <list>
#include <type_traits>
#include <vector>

#include "IR/IR.h"
#include "antlr4-runtime.h"
#include "utils.h"

namespace SyntaxModel {
    // forward declare SyntaxNodeBase for std::hash specialization
    class SyntaxNodeBase;
}

namespace IR {
    class ControlFlowGraph;
}

namespace std {
    template <>
    struct hash<SyntaxModel::SyntaxNodeBase> {
        size_t operator()(const SyntaxModel::SyntaxNodeBase& obj) const;
    };
}

namespace SyntaxModel {
    using Identifier = utils::TerminalInfo;
    using Include = utils::TerminalInfo;

    class SyntaxNodeBase {
    public:
        static size_t _instance_count;
        SyntaxNodeBase(const antlr4::misc::Interval& source_interval, const std::list<const SyntaxNodeBase*>& children = std::list<const SyntaxNodeBase*>());
        virtual ~SyntaxNodeBase();

        bool operator==(const SyntaxNodeBase& obj) const;
        bool operator<(const SyntaxNodeBase& obj) const;
        friend std::ostream& operator<<(std::ostream& os, const SyntaxNodeBase& node);

        template <typename T>
        bool is() const
        {
            static const std::string type_name = utils::type_name<T>();
            auto types = getTypenames();
            return types.find(type_name) != types.end();
        }

        // Returns all children syntaxic elements recursively
        std::list<const SyntaxNodeBase*>
        getAllChildren() const;

        // Returns an list of all children syntaxic elements recursively for which T is their final type (doesn't handle base classes)
        template <typename T>
        std::list<const T*> getAllChildrenOfType() const
        {
            std::list<const T*> all_childrens;

            for (const auto* child : _children)
                if (child != nullptr) {
                    if (child->is<T>())
                        all_childrens.push_back(dynamic_cast<const T*>(child));

                    for (const T* val : child->getAllChildrenOfType<T>())
                        all_childrens.push_back(val);
                }
            return all_childrens;
        }

        const antlr4::misc::Interval source_interval;
        const std::list<const SyntaxNodeBase*> _children;
        const size_t unique_id;

    protected:
        virtual std::unordered_set<std::string> getTypenames() const = 0;
        virtual std::ostream& toString(std::ostream& os) const = 0;

    private:
        friend size_t std::hash<SyntaxNodeBase>::operator()(const SyntaxNodeBase&) const;
    };

    template <typename... Types>
    struct TN;

    template <typename FirstT, typename... OtherTs>
    struct TN<FirstT, OtherTs...> {
        static inline std::unordered_set<std::string> typenames()
        {
            static const std::string type_name = utils::type_name<FirstT>();
            std::unordered_set<std::string> types(TN<OtherTs...>::typenames());
            types.insert(type_name);
            return types;
        }
    };

    template <typename LastT>
    struct TN<LastT> {
        static inline std::unordered_set<std::string> typenames()
        {
            //static_assert(std::is_base_of<SyntaxNodeBase, LastT>::value, "TN::typenames is meant to be used on classes derived from 'SyntaxNodeBase'.");
            static const std::string type_name = utils::type_name<LastT>();
            static const std::string base_type_name = utils::type_name<SyntaxNodeBase>();
            return { type_name, base_type_name };
        }
    };
}
