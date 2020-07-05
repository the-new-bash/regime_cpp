
#include <v1/requests.hpp>

#include "../../include/v1/requests.hpp"

namespace regime::v1
{
    std::tuple<obj, obj> parse_request(const Poco::JSON::Object::Ptr &payload)
    {
        const auto data = payload->getObject("data");
        Poco::JSON::Object::Ptr meta;
        if (payload->has("meta"))
            meta = payload->getObject("meta");
        return std::make_tuple(data, meta);
    }

    void AccountIds::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        get(account_ids, payload, "accountIds");
    }

    Poco::JSON::Object::Ptr AccountIds::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "accountIds", account_ids);
        return json;
    }
}
