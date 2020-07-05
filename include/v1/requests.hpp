#ifndef REGIME_V1_COMMON_REQUESTS_HPP
#define REGIME_V1_COMMON_REQUESTS_HPP

#include "utils.hpp"
#include "objects.hpp"

namespace regime::v1
{
    template<class Data, class Meta>
    struct Request : public IObject
    {
        Data data;
        std::optional<Meta> meta;

        void deserialize(const Poco::JSON::Object::Ptr &payload) override;

        [[nodiscard]] Poco::JSON::Object::Ptr to_json() const override;
    };

    using obj = Poco::JSON::Object::Ptr;

    std::tuple<obj, obj> parse_request(const Poco::JSON::Object::Ptr &payload);

    template<class Data, class Meta>
    void Request<Data, Meta>::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        const auto[_data, _meta] = parse_request(payload);
        data.deserialize(_data);
        if (!_meta.isNull())
        {
            Meta tmp;
            tmp.deserialize(_meta);
            meta = tmp;
        }
    }

    template<class Data, class Meta>
    Poco::JSON::Object::Ptr Request<Data, Meta>::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "data", data);
        add(json, "meta", meta.value());
        return json;
    }

#define DECLARE_REQUEST_TYPE(name, data, meta) struct name final: public Request<data, meta> {};

    DECLARE_COMMON_TYPE(AccountIds, std::vector<std::string> account_ids;)

    DECLARE_REQUEST_TYPE(RequestAccountIds, AccountIds, Meta)

}

#endif //REGIME_V1_COMMON_REQUESTS_HPP
