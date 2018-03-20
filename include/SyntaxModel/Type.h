#pragma once
#include <cstdint>
#include <type_traits>

namespace SyntaxModel {

    class Type final {
    public:
        enum class PrimitiveType { INT32_T,
            INT64_T,
            CHAR };

        Type(const PrimitiveType type, const bool isArray);
        virtual ~Type() = default;

    public:
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

        const PrimitiveType _type;
        const bool _isArray;

    public:
        template <Type::PrimitiveType T>
        using UnderlyingType = typename _UnderlyingType<T>::type;
    };
}
