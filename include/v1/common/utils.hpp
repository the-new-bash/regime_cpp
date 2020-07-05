#ifndef REGIME_UTILS_HPP
#define REGIME_UTILS_HPP

#include <charconv>
#include <type_traits>
#include "types.hpp"

namespace regime::util
{
    template<typename Test, template<typename...> class Ref>
    struct is_specialization : std::false_type
    {
    };

    template<template<typename...> class Ref, typename... Args>
    struct is_specialization<Ref<Args...>, Ref> : std::true_type
    {
    };

    template<class Mapping, class E>
    std::string get_string(Mapping m, E e)
    {
        auto p = std::find_if(
                std::begin(m), std::end(m), [&e](typename Mapping::value_type t)
                { return t._enum == e; });
        if (p != std::end(m))
            return p->_string;
        else
            throw; // TODO
    }

    template<class Mapping>
    typename Mapping::value_type::value_type get_enum(Mapping m, std::string s)
    {
        auto p = std::find_if(
                std::begin(m), std::end(m), [&s](typename Mapping::value_type t)
                { return t._string == s; });
        if (p != std::end(m))
            return p->_enum;
        else
            throw;  // TODO
    }

    template<class T, std::enable_if_t<std::is_base_of<IObject, T>::value ||
                                       std::is_arithmetic<T>::value ||
                                       std::is_same<T, std::string>::value> * = nullptr>
    void add(Poco::JSON::Object::Ptr &obj, const std::string &key, const T &t)
    {
        if constexpr (std::is_base_of<IObject, T>::value)
            obj->set(key, t.to_json());
        else
            obj->set(key, t);
    }

    template<class T, std::enable_if_t<is_specialization<T, std::optional>::value, T> * = nullptr>
    void add(Poco::JSON::Object::Ptr &obj, const std::string &key, const T &t)
    {
        if (t.has_value())
            add(obj, key, t.value());
    }

    template<class T>
    void add(Poco::JSON::Object::Ptr &obj, const std::string &key, const std::vector<T> &t)
    {
        Poco::JSON::Array arr;
        for (const auto &e : t)
        {
            if constexpr (std::is_base_of<IObject, T>::value)
                arr.add(e.to_json());
            else
                arr.add(e);
        }
        obj->set(key, arr);
    }

    template<class T>
    void add(Poco::JSON::Object::Ptr &obj, const std::string &key, const std::optional<std::vector<T>> &t)
    {
        if (t.has_value())
            add(obj, key, static_cast<const std::vector<T> &>(t.value()));
    }


    template<class T, class M, std::enable_if_t<is_specialization<T, std::optional>::value, T> * = nullptr>
    void add(Poco::JSON::Object::Ptr &obj, const std::string &key, M m, const T &t)
    {
        if (t.has_value())
            obj->set(key, get_string(m, t.value()));
    }

    template<class T, class M, std::enable_if_t<std::is_enum<T>::value, T> * = nullptr>
    void add(Poco::JSON::Object::Ptr &obj, const std::string &key, M m, const T &t)
    {
        obj->set(key, get_string(m, t));
    }

    template<class T, std::enable_if_t<std::is_base_of<IObject, T>::value ||
                                       std::is_arithmetic<T>::value ||
                                       std::is_same<T, std::string>::value> * = nullptr>
    void get(T &t, const Poco::JSON::Object::Ptr &data, const std::string &key)
    {
        if constexpr (std::is_base_of<IObject, T>::value)
        {
            T tmp;
            tmp.deserialize(data->getObject(key));
            t = tmp;
        }
        else
            t = data->getValue<T>(key);
    }

    template<class T, std::enable_if_t<is_specialization<T, std::optional>::value, T> * = nullptr>
    void get(T &t, const Poco::JSON::Object::Ptr &data, const std::string &key)
    {
        if (data->has(key))
        {
            typename T::value_type tmp;
            get(tmp, data, key);
            t = tmp;
        }
        else
            t = std::nullopt;
    }

    template<class T>
    void get(std::vector<T> &t, const Poco::JSON::Object::Ptr &data, const std::string &key)
    {
        for (const auto &it: *data->getArray(key))
        {
            if constexpr (std::is_base_of<IObject, T>::value)
            {
                T tmp;
                tmp.deserialize(it.extract<Poco::JSON::Object::Ptr>());
                t.emplace_back(tmp);
            }
            else
                t.emplace_back(it.extract<T>());
        }
    }

    template<class T>
    void get(std::optional<std::vector<T>> &t, const Poco::JSON::Object::Ptr &data, const std::string &key)
    {
        if (data->has(key))
        {
            std::vector<T> tmp;
            get(tmp, data, key);
            t = tmp;
        }
        else
            t = std::nullopt;
    }

    template<class T, class M, std::enable_if_t<is_specialization<T, std::optional>::value, T> * = nullptr>
    void get(T &t, const Poco::JSON::Object::Ptr &data, M m, const std::string &key)
    {
        std::optional<std::string> tmp;
        get(tmp, data, key);
        if (tmp.has_value())
            t = get_enum(m, tmp.value());
        else
            t = std::nullopt;
    }

    template<class T, class M, std::enable_if_t<std::is_enum<T>::value, T> * = nullptr>
    void get(T &t, const Poco::JSON::Object::Ptr &data, M m, const std::string &key)
    {
        std::string tmp;
        get(tmp, data, key);
        t = get_enum(m, tmp);
    }
}

#endif //REGIME_UTILS_HPP
