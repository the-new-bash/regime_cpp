#ifndef REGIME_V1_COMMON_REQUESTS_HPP
#define REGIME_V1_COMMON_REQUESTS_HPP

#include "utils.hpp"
#include "objects.hpp"

#define DECLARE_REQUEST_DATA(type_name, ...) \
        struct type_name : public Data \
        { \
            type_name() = default; \
            ~type_name() = default; \
            void deserialize(const Poco::JSON::Object::Ptr &payload) override; \
            Poco::JSON::Object::Ptr to_json() const override; \
            __VA_ARGS__ \
        };

#define DECLARE_REQUEST_TYPE_NO_META(type_name, data_name) \
        struct type_name: public Request \
        { \
            type_name() { \
                data.reset(new data_name()); \
            } \
            ~type_name() = default; \
            void deserialize(const Poco::JSON::Object::Ptr &payload) override; \
            Poco::JSON::Object::Ptr to_json() const override; \
        };

typedef Poco::JSON::Object::Ptr obj;

struct Request : public Object
{
public:
    std::unique_ptr<Data> data;
    std::optional<std::unique_ptr<Meta>> meta;

protected:
    static std::tuple<obj, obj> parse(const Poco::JSON::Object::Ptr &payload);
};

#endif //REGIME_V1_COMMON_REQUESTS_HPP
