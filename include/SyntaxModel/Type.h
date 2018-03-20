#pragma once
#include <cstdint>
#include <type_traits>

namespace SyntaxModel {

    struct Type final {
        enum class PrimitiveType { INT32_T,
            INT64_T,
            CHAR };

        Type(const PrimitiveType type, const bool isArray);
        virtual ~Type() = default;

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
