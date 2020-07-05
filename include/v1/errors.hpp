#ifndef REGIME_V1_COMMON_ERRORS_HPP
#define REGIME_V1_COMMON_ERRORS_HPP

#include "utils.hpp"

namespace regime::v1
{
    class ResponseError : public std::exception
    {
    public:
        struct Error
        {
            std::string code;
            std::string title;
            std::string detail;
            std::optional<Poco::JSON::Object::Ptr> meta;
        };

        explicit ResponseError(const Poco::JSON::Array::Ptr &errs);

        std::vector<Error> errors;
    };
}

#endif //REGIME_V1_COMMON_ERRORS_HPP
