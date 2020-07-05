#ifndef REGIME_V1_COMMON_REQUESTS_HPP
#define REGIME_V1_COMMON_REQUESTS_HPP

#include "utils.hpp"
#include "objects.hpp"

template<class Data, class Meta>
struct Request : public IObject
{
    Data data;
    std::optional<Meta> meta;
};

using obj = Poco::JSON::Object::Ptr;

std::tuple<obj, obj> parse_request(const Poco::JSON::Object::Ptr &payload);

#define DECLARE_REQUEST_TYPE(name, data, meta) \
        struct name final: public Request<data, meta> \
        { \
            ~name() = default; \
            void deserialize(const Poco::JSON::Object::Ptr &payload) override; \
            Poco::JSON::Object::Ptr to_json() const override; \
        };

#endif //REGIME_V1_COMMON_REQUESTS_HPP
