#pragma once
#include <cstdint>
#include <type_traits>

#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {

    struct Type final : public SyntaxNodeBase {
        enum class PrimitiveType { INT32_T,
            INT64_T,
            CHAR };

        Type(const antlr4::misc::Interval& source_interval, const PrimitiveType type, const bool isArray);
        virtual ~Type() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Type>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;

    private:
        template <Type::PrimitiveType T, class Enable = void>
        struct _UnderlyingType;

        template <Type::PrimitiveType T>
        struct _UnderlyingType<T, std::enable_if_t<T == Type::PrimitiveType::CHAR>> {
            using type = char32_t;
        };

        template <Type::PrimitiveType T>
        struct _UnderlyingType<T, std::enable_if_t<T == Type::PrimitiveType::INT32_T>> {
            using type = int32_t;
        };

        template <Type::PrimitiveType T>
        struct _UnderlyingType<T, std::enable_if_t<T == Type::PrimitiveType::INT64_T>> {
            using type = int64_t;
        };

    public:
        const PrimitiveType type;
        const bool isArray;

        template <Type::PrimitiveType T>
        using UnderlyingType = typename _UnderlyingType<T>::type;
    };
}
