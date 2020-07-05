#ifndef REGIME_V1_COMMON_RESPONSES_HPP
#define REGIME_V1_COMMON_RESPONSES_HPP

#include "utils.hpp"
#include "errors.hpp"


template<class Data, class Links, class Meta>
struct Response : public IObject
{
    Data data;
    Links links;
    std::optional<Meta> meta;

    void deserialize(const Poco::JSON::Object::Ptr &payload) override;

    Poco::JSON::Object::Ptr to_json() const override;
};


using obj = Poco::JSON::Object::Ptr;

std::tuple<obj, obj, obj> parse_response(const Poco::JSON::Object::Ptr &payload);

#define DECLARE_RESPONSE_TYPE(name, data, links, meta) \
        struct name final : public Response<data, links, meta> \
        { \
            ~name() = default; \
        };

#endif //REGIME_V1_COMMON_RESPONSES_HPP
