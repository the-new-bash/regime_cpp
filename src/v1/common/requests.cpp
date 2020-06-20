#include <v1/requests.hpp>

std::tuple<obj, obj> Request::parse(const Poco::JSON::Object::Ptr &payload)
{
    const auto data = payload->getObject("data");
    Poco::JSON::Object::Ptr meta;
    if (payload->has("meta"))
        meta = payload->getObject("meta");
    return std::make_tuple(data, meta);
}
