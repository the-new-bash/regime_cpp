#ifndef REGIME_V1_COMMON_RESPONSES_HPP
#define REGIME_V1_COMMON_RESPONSES_HPP

#include "utils.hpp"
#include "errors.hpp"

#define DECLARE_RESPONSE_DATA(type_name, ...) \
        struct type_name final : public Data \
        { \
            void deserialize(const Poco::JSON::Object::Ptr &payload) override; \
            Poco::JSON::Object::Ptr to_json() const override; \
            __VA_ARGS__ \
        };

#define DECLARE_RESPONSE_TYPE(type_name, data_name, links_name, meta_name) \
        struct type_name final : public Response \
        { \
            type_name() \
            { \
                data.reset(new data_name()); \
                links.reset(new links_name()); \
                meta = std::make_unique<meta_name>(); \
            } \
            ~type_name() = default; \
            void deserialize(const Poco::JSON::Object::Ptr &payload) override; \
            Poco::JSON::Object::Ptr to_json() const override; \
        };

#define DECLARE_RESPONSE_TYPE_NO_META(type_name, data_name, links_name) \
        struct type_name final : public Response \
        { \
            type_name() \
            { \
                data.reset(new data_name()); \
                links.reset(new links_name()); \
            } \
            ~type_name() = default; \
            void deserialize(const Poco::JSON::Object::Ptr &payload) override; \
            Poco::JSON::Object::Ptr to_json() const override; \
        };

typedef Poco::JSON::Object::Ptr obj;

class Response : public Object
{
public:
    std::unique_ptr<Data> data;
    std::unique_ptr<Links> links;
    std::optional<std::unique_ptr<Meta>> meta;

protected:
    static std::tuple<obj, obj, obj> parse(const Poco::JSON::Object::Ptr &payload);
};

#endif //REGIME_V1_COMMON_RESPONSES_HPP
