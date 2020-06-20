#ifndef REGIME_V1_REQUESTS_HPP
#define REGIME_V1_REQUESTS_HPP

#include "Poco/JSON/Object.h"
#include "common/requests.hpp"
#include "types.hpp"

DECLARE_REQUEST_DATA(AccountIds, std::vector<std::string> account_ids;)

DECLARE_REQUEST_TYPE_NO_META(RequestAccountIds, AccountIds)

#endif //REGIME_V1_REQUESTS_HPP