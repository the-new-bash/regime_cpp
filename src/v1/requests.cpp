
#include <v1/common/requests.hpp>

#include "../../include/v1/requests.hpp"

void RequestAccountIds::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto[_data, _meta] = parse_request(payload);
    data.deserialize(_data);
    meta.value().deserialize(_meta);
}

Poco::JSON::Object::Ptr RequestAccountIds::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "accountIds", data.account_ids);
    return json;
}

void AccountIds::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    regime::util::get(account_ids, payload, "accountIds");
}

Poco::JSON::Object::Ptr AccountIds::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "accountIds", account_ids);
    return json;
}
