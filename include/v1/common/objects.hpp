#ifndef REGIME_V1_COMMON_OBJECTS_HPP
#define REGIME_V1_COMMON_OBJECTS_HPP

#include "Poco/JSON/Object.h"

struct IObject
{
    [[nodiscard]] std::string serialize() const;

    virtual void deserialize(const Poco::JSON::Object::Ptr &payload) = 0;

    [[nodiscard]] virtual Poco::JSON::Object::Ptr to_json() const = 0;
};

struct Meta : IObject
{
    Meta() = default;

    void deserialize(const Poco::JSON::Object::Ptr &payload) override
    {};

    [[nodiscard]] Poco::JSON::Object::Ptr to_json() const override
    { return Poco::JSON::Object::Ptr(); };
};

struct Links : public IObject
{
    Links() = default;

    void deserialize(const Poco::JSON::Object::Ptr &payload) override;

    [[nodiscard]] Poco::JSON::Object::Ptr to_json() const override;

    std::string self;
};


struct LinksPaginated : public Links
{
    LinksPaginated() = default;

    void deserialize(const Poco::JSON::Object::Ptr &payload) override;

    [[nodiscard]] Poco::JSON::Object::Ptr to_json() const override;

    std::optional<std::string> first;
    std::optional<std::string> previous;
    std::optional<std::string> next;
    std::optional<std::string> last;
};

struct MetaPaginated : public Meta
{
    MetaPaginated() = default;

    void deserialize(const Poco::JSON::Object::Ptr &payload) override;

    [[nodiscard]] Poco::JSON::Object::Ptr to_json() const override;

    unsigned int total_records;
    unsigned int total_pages;
};

#endif //REGIME_V1_COMMON_OBJECTS_HPP
