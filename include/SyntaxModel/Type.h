#pragma once
#include <cstdint>
#include <type_traits>

#include "SyntaxModel/PrimitiveType.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {

    struct Type final : public SyntaxNodeBase {

        Type(const antlr4::misc::Interval& source_interval, const PrimitiveType type, const bool isArray);
        virtual ~Type() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Type>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;

    private:
        template <PrimitiveType T, class Enable = void>
        struct _UnderlyingType;

        template <PrimitiveType T>
        struct _UnderlyingType<T, std::enable_if_t<T == PrimitiveType::CHAR>> {
            using type = char32_t;
        };

        template <PrimitiveType T>
        struct _UnderlyingType<T, std::enable_if_t<T == PrimitiveType::INT32_T>> {
            using type = int32_t;
        };

        template <PrimitiveType T>
        struct _UnderlyingType<T, std::enable_if_t<T == PrimitiveType::INT64_T>> {
            using type = int64_t;
        };

    public:
        const PrimitiveType type;
        const bool isArray;

        template <PrimitiveType T>
        using UnderlyingType = typename _UnderlyingType<T>::type;
    };
}
