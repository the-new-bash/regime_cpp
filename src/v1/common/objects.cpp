#include "../../../include/v1/common/objects.hpp"
#include "../../../include/v1/common/utils.hpp"

void Links::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    regime::util::get(self, payload, "self");
}

Poco::JSON::Object::Ptr Links::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "self", self);
    return json;
}

void LinksPaginated::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    Links::deserialize(payload);
    regime::util::get(first, payload, "first");
    regime::util::get(previous, payload, "prev");
    regime::util::get(next, payload, "next");
    regime::util::get(last, payload, "last");
}

Poco::JSON::Object::Ptr LinksPaginated::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "self", self);
    regime::util::add(json, "first", first);
    regime::util::add(json, "prev", previous);
    regime::util::add(json, "next", next);
    regime::util::add(json, "last", last);
    return json;
}

void MetaPaginated::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    regime::util::get(total_records, payload, "totalRecords");
    regime::util::get(total_pages, payload, "totalPages");
}

Poco::JSON::Object::Ptr MetaPaginated::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "totalRecords", total_records);
    regime::util::add(json, "totalPages", total_pages);
    return json;
}
