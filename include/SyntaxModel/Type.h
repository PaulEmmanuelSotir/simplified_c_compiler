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

    private:
        template <Type::PrimitiveType T, typename = std::enable_if_t<T == Type::PrimitiveType::CHAR>>
        static char32_t _UnderlyingType()
        {
            return static_cast<char32_t>(0);
        }

        template <Type::PrimitiveType T, typename = std::enable_if_t<T == Type::PrimitiveType::INT32_T>>
        static int32_t _UnderlyingType()
        {
            return static_cast<int32_t>(0);
        }

        template <Type::PrimitiveType T, typename = std::enable_if_t<T == Type::PrimitiveType::INT64_T>>
        static int64_t _UnderlyingType()
        {
            return static_cast<int64_t>(0);
        }

        const PrimitiveType _type;
        const bool _isArray;

    public:
        template <Type::PrimitiveType T>
        using UnderlyingType = decltype(_UnderlyingType<T>);
    };
}
