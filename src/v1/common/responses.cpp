#include "../../../include/v1/common/responses.hpp"

typedef Poco::JSON::Object::Ptr obj;

std::tuple<obj, obj, obj> parse_response(const Poco::JSON::Object::Ptr &payload)
{
    if (payload->has("errors"))
        throw ResponseError(payload->getArray("errors"));

    const auto data = payload->getObject("data");
    const auto links = payload->getObject("links");
    Poco::JSON::Object::Ptr meta;
    if (payload->has("meta"))
        meta = payload->getObject("meta");
    return std::make_tuple(data, links, meta);
}

template<class Data, class Links, class Meta>
void Response<Data, Links, Meta>::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto[_data, _links, _meta] = parse_response(payload);
    data.deserialize(_data);
    links.deserialize(_links);
    meta.value().deserialize(_meta);
}

template<class Data, class Links, class Meta>
Poco::JSON::Object::Ptr Response<Data, Links, Meta>::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "data", data.products);
    regime::util::add(json, "links", links);
    regime::util::add(json, "meta", meta.value());
    return json;
}
