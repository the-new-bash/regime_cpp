#include "../../../include/v1/common/errors.hpp"

ResponseError::ResponseError(const Poco::JSON::Array::Ptr &errs)
{
    for (const auto &it : *errs)
    {
        Error error;
        const auto &err_obj = it.extract<Poco::JSON::Object::Ptr>();
        regime::util::get(error.code, err_obj, "code");
        regime::util::get(error.title, err_obj, "title");
        regime::util::get(error.detail, err_obj, "detail");
        if (err_obj->has("meta"))
            error.meta = err_obj->getObject("meta");
        else
            error.meta = std::nullopt;
        errors.push_back(error);
    }
}