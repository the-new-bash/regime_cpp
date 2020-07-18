#include "v1/objects.hpp"
#include "v1/utils.hpp"

namespace regime::v1
{
    void Links::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        get(self, payload, "self");
    }

    Poco::JSON::Object::Ptr Links::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "self", self);
        return json;
    }

    void LinksPaginated::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        Links::deserialize(payload);
        get(first, payload, "first");
        get(previous, payload, "prev");
        get(next, payload, "next");
        get(last, payload, "last");
    }

    Poco::JSON::Object::Ptr LinksPaginated::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "self", self);
        add(json, "first", first);
        add(json, "prev", previous);
        add(json, "next", next);
        add(json, "last", last);
        return json;
    }

    void MetaPaginated::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        get(total_records, payload, "totalRecords");
        get(total_pages, payload, "totalPages");
    }

    Poco::JSON::Object::Ptr MetaPaginated::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "totalRecords", total_records);
        add(json, "totalPages", total_pages);
        return json;
    }
}
