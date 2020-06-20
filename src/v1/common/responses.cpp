#include "../../../include/v1/common/responses.hpp"

typedef Poco::JSON::Object::Ptr obj;

std::tuple<obj, obj, obj> Response::parse(const Poco::JSON::Object::Ptr &payload)
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
