
#include <v1/common/requests.hpp>

#include "../../include/v1/requests.hpp"

void RequestAccountIds::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Request::parse(payload);
    auto *_data = static_cast<AccountIds *>(data.get());
    _data->deserialize(std::get<0>(resp));
}

Poco::JSON::Object::Ptr RequestAccountIds::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "accountIds", static_cast<AccountIds *>(data.get())->account_ids);
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
