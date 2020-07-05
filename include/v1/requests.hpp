#ifndef REGIME_V1_REQUESTS_HPP
#define REGIME_V1_REQUESTS_HPP

#include "Poco/JSON/Object.h"
#include "common/requests.hpp"
#include "types.hpp"

DECLARE_COMMON_TYPE(AccountIds, std::vector<std::string> account_ids;)

DECLARE_REQUEST_TYPE(RequestAccountIds, AccountIds, Meta)

#endif //REGIME_V1_REQUESTS_HPP