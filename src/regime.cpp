#include "Poco/Net/HTTPSClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/JSON/Parser.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "../include/regime.hpp"

#include <utility>

namespace regime {
    using namespace Poco;

/**
 * @brief Obtain a list of accounts.
 *
 * @param bank              Bank endpoint to use.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @param product_category  Filter results on product category.
 * @param open_status       Filter results according to open/closed status.
 * @return                  List of accounts.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto accounts = regime.get_accounts(Bank::ANZ);
 * @endcode
 */
    std::vector<BankingAccount>
    Client::get_accounts(Bank bank, const std::string &version, std::optional<std::string> min_version,
                         std::optional<ProductCategory> product_category, std::optional<OpenStatus> open_status,
                         std::optional<bool> is_owned) const {
        URI uri(get_uri(bank, "accounts"));
        std::vector<BankingAccount> result;
        if (product_category.has_value())
            uri.addQueryParameter("product-category", get_string(ProductCategories, product_category.value()));
        if (open_status.has_value())
            uri.addQueryParameter("open-status", get_string(OpenStatuses, open_status.value()));
        if (is_owned.has_value())
            uri.addQueryParameter("is-owned", is_owned.value() ? "true" : "false");
        request_paginated<ResponseBankingAccountList>(uri, version, std::move(min_version),
                                                      [&result](const ResponseBankingAccountList &resp) {
                                                          result.insert(result.end(), resp.data.accounts.begin(),
                                                                        resp.data.accounts.end());
                                                      });
        return result;
    }

/**
 * @brief Obtain balances for multiple, filtered accounts.
 *
 * @param bank              Bank endpoint to use.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @param product_category  Filter results on product category.
 * @param open_status       Filter results according to open/closed status.
 * @param is_owned          Filter results based on whether they are owned by the authorised customer.
 * @return                  Filtered list of account balances.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto bulk_balances = regime.get_bulk_balances(Bank::ANZ);
 * @endcode
 */
    std::vector<BankingBalance>
    Client::get_bulk_balances(Bank bank, const std::string &version, std::optional<std::string> min_version,
                              std::optional<ProductCategory> product_category, std::optional<OpenStatus> open_status,
                              std::optional<bool> is_owned) const {
        URI uri(get_uri(bank, "accounts/balances"));
        std::vector<BankingBalance> result;
        if (product_category.has_value())
            uri.addQueryParameter("product-category", get_string(ProductCategories, product_category.value()));
        if (open_status.has_value())
            uri.addQueryParameter("open-status", get_string(OpenStatuses, open_status.value()));
        if (is_owned.has_value())
            uri.addQueryParameter("is-owned", is_owned.value() ? "true" : "false");
        request_paginated<ResponseBankingAccountsBalanceList>(uri, version, std::move(min_version), [&result](
                const ResponseBankingAccountsBalanceList &resp) {
            result.insert(result.end(), resp.data.balances.begin(), resp.data.balances.end());
        });
        return result;
    }

/**
 * @brief Obtain balances for a specified list of accounts.
 *
 * @param bank              Bank endpoint to use.
 * @param account_ids       List of account ids.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @return                  List of account balances.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto balances = regime.get_balances_for_specific_accounts(Bank::ANZ, std::vector<std::string>("1234"));
 * @endcode
 */
    std::vector<BankingBalance>
    Client::get_balances_for_specific_accounts(Bank bank, const std::vector<std::string> &account_ids,
                                               const std::string &version,
                                               std::optional<std::string> min_version) const {
        URI uri(get_uri(bank, "accounts/balances"));
        RequestAccountIds accounts;
        accounts.data.account_ids = account_ids;
        auto body = static_cast<Poco::DynamicStruct>(*accounts.to_json()).toString();
        std::vector<BankingBalance> result;
        request_paginated<ResponseBankingAccountsBalanceList>(uri, version, std::move(min_version),
                                                              [&result](
                                                                      const ResponseBankingAccountsBalanceList &resp) {
                                                                  result.insert(result.end(),
                                                                                resp.data.balances.begin(),
                                                                                resp.data.balances.end());
                                                              }, body);
        return result;
    }

/**
 * @brief Obtain the balance for a single specified account.
 *
 * @param bank              Bank endpoint to use.
 * @param account_id        ID of the specified account.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @return                  Account balance.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto account_balance = regime.get_account_balance(Bank::ANZ, "1234");
 * @endcode
 */
    BankingBalance Client::get_account_balance(Bank bank, const std::string &account_id, const std::string &version,
                                               std::optional<std::string> min_version) const {
        URI uri(get_uri(bank, "accounts/" + account_id + "/balance"));
        auto ret = request(uri, version, std::move(min_version));
        ResponseBankingAccountsBalanceById resp;
        resp.deserialize(ret);
        return resp.data;
    }

/**
 * @brief Obtain detailed information on a single account.
 *
 * @param bank              Bank endpoint to use.
 * @param account_id        ID of the specified account.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @return                  Account detail.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto account_detail = regime.get_account_detail(Bank::ANZ, "1234");
 * @endcode
 */
    BankingAccountDetail
    Client::get_account_detail(Bank bank, const std::string &account_id, const std::string &version,
                               std::optional<std::string> min_version) const {
        URI uri(get_uri(bank, "accounts/" + account_id));
        auto ret = request(uri, version, std::move(min_version));
        ResponseBankingAccountById resp;
        resp.deserialize(ret);
        return resp.data;
    }

/**
 * @brief Obtain transactions for a specific account.
 *
 * @param bank              Bank endpoint to use.
 * @param account_id        ID of the specified account.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @param oldest_time       Constrain transaction history to those with effective time at or after this date/time.
 * @param newest_time       Constrain transaction history to those with effective time at or before this date/time.
 * @param min_amount        Filter transactions by amounts higher or equal to this amount.
 * @param max_amount        Filter transactions to amounts less than or equal to to this amount.
 * @param text              Filter transactions based on substrings found in reference of description fields.
 * @return                  List of transactions.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto account_transactions = regime.get_transactions_for_account(Bank::ANZ, "1234");
 * @endcode
 */
    std::vector<BankingTransaction>
    Client::get_transactions_for_account(Bank bank, const std::string &account_id, const std::string &version,
                                         std::optional<std::string> min_version,
                                         std::optional<std::string> oldest_time,
                                         std::optional<std::string> newest_time,
                                         std::optional<std::string> min_amount,
                                         std::optional<std::string> max_amount, std::optional<std::string> text) const {

        URI uri(get_uri(bank, "accounts/" + account_id + "/transactions"));
        if (oldest_time.has_value())
            uri.addQueryParameter("oldest-time", oldest_time.value());
        if (newest_time.has_value())
            uri.addQueryParameter("newest-time", newest_time.value());
        if (min_amount.has_value())
            uri.addQueryParameter("min-amount", min_amount.value());
        if (max_amount.has_value())
            uri.addQueryParameter("max-amount", max_amount.value());
        if (text.has_value())
            uri.addQueryParameter("text", text.value());
        std::vector<BankingTransaction> result;
        request_paginated<ResponseBankingTransactionList>(uri, version, std::move(min_version),
                                                          [&result](const ResponseBankingTransactionList &resp) {
                                                              result.insert(result.end(),
                                                                            resp.data.transactions.begin(),
                                                                            resp.data.transactions.end());
                                                          });
        return result;
    }

/**
 * @brief Obtain detailed information on a transaction for a specific account.
 *
 * @param bank              Bank endpoint to use.
 * @param account_id        ID of the specified account.
 * @param transaction_id    ID of the specified transaction.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @return                  Transaction detail.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto transaction_detail = regime.get_transaction_detail(Bank::ANZ, "1234", "5678");
 * @endcode
 */
    BankingTransactionDetail
    Client::get_transaction_detail(Bank bank, const std::string &account_id, const std::string &transaction_id,
                                   const std::string &version, std::optional<std::string> min_version) const {
        URI uri(get_uri(bank, "accounts/" + account_id + "/transactions/" + transaction_id));
        auto ret = request(uri, version, std::move(min_version));
        ResponseBankingTransactionById resp;
        resp.deserialize(ret);
        return resp.data;
    }

/**
 * @brief Obtain direct debit authorisations for a specific account.
 *
 * @param bank              bank endpoint to use.
 * @param account_id        id of the specified account.
 * @param version           version of the api end point.
 * @param min_version       minimum version of the api end point.
 * @return                  list of account direct debits.
 *
 * example:
 * @code
 *      regime regime(1);
 *      auto direct_debits = regime.get_direct_debits_for_account(bank::anz, "1234");
 * @endcode
 */
    std::vector<BankingDirectDebit>
    Client::get_direct_debits_for_account(Bank bank, const std::string &account_id, const std::string &version,
                                          std::optional<std::string> min_version) const {

        URI uri(get_uri(bank, "accounts/" + account_id + "/direct-debits"));
        std::vector<BankingDirectDebit> result;
        request_paginated<ResponseBankingDirectDebitAuthorisationList>(uri, version, std::move(min_version), [&result](
                const ResponseBankingDirectDebitAuthorisationList &resp) {
            result.insert(
                    result.end(), resp.data.direct_debit_authorisations.begin(),
                    resp.data.direct_debit_authorisations.end());
        });
        return result;
    }

/**
 * @brief Obtain direct debit authorisations for multiple, filtered accounts.
 *
 * @param bank              Bank endpoint to use.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @param product_category  Filter results on product category.
 * @param open_status       Filter results according to open/closed status.
 * @param is_owned          Filter results based on whether they are owned by the authorised customer.
 * @return                  Filtered list of direct debits.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto bulk_direct_debits = regime.get_bulk_direct_debits(Bank::ANZ, "1234");
 * @endcode
 */
    std::vector<BankingDirectDebit>
    Client::get_bulk_direct_debits(Bank bank, const std::string &version, std::optional<std::string> min_version,
                                   std::optional<ProductCategory> product_category,
                                   std::optional<OpenStatus> open_status,
                                   std::optional<bool> is_owned) const {
        URI uri(get_uri(bank, "accounts/direct-debits"));
        if (product_category.has_value())
            uri.addQueryParameter("product-category", get_string(ProductCategories, product_category.value()));
        if (open_status.has_value())
            uri.addQueryParameter("open-status", get_string(OpenStatuses, open_status.value()));
        if (is_owned.has_value())
            uri.addQueryParameter("is-owned", is_owned.value() ? "true" : "false");
        std::vector<BankingDirectDebit> result;
        request_paginated<ResponseBankingDirectDebitAuthorisationList>(uri, version, std::move(min_version), [&result](
                const ResponseBankingDirectDebitAuthorisationList &resp) {
            result.insert(
                    result.end(), resp.data.direct_debit_authorisations.begin(),
                    resp.data.direct_debit_authorisations.end());
        });
        return result;
    }

/**
 * @brief Obtain direct debit authorisations for a specified list of accounts.
 *
 * @param bank              Bank endpoint to use.
 * @param account_ids       List of account ids.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @return                  List of direct debits for specified accounts.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto accounts_direct_debits = regime.get_direct_debits_for_specific_accounts(Bank::ANZ, std::vector<std::string>("1234"));
 * @endcode
 */
    std::vector<BankingDirectDebit>
    Client::get_direct_debits_for_specific_accounts(Bank bank, const std::vector<std::string> &account_ids,
                                                    const std::string &version,
                                                    std::optional<std::string> min_version) const {
        URI uri(get_uri(bank, "accounts/direct-debits"));
        RequestAccountIds accounts;
        accounts.data.account_ids = account_ids;
        auto body = static_cast<Poco::DynamicStruct>(*accounts.to_json()).toString();
        std::vector<BankingDirectDebit> result;
        request_paginated<ResponseBankingDirectDebitAuthorisationList>(uri, version, std::move(min_version), [&result](
                const ResponseBankingDirectDebitAuthorisationList &resp) {
            result.insert(
                    result.end(), resp.data.direct_debit_authorisations.begin(),
                    resp.data.direct_debit_authorisations.end());
        }, body);
        return result;
    }

/**
 * @brief Obtain scheduled, outgoing payments for a specific account.
 *
 * @param bank              Bank endpoint to use.
 * @param account_id        ID of the specified account.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @return                  List of scheduled outgoing payments for account.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto outgoing_payments = regime.get_scheduled_payments_for_account(Bank::ANZ, "1234");
 * @endcode
 */
    std::vector<BankingScheduledPayment>
    Client::get_scheduled_payments_for_account(Bank bank, const std::string &account_id, const std::string &version,
                                               std::optional<std::string> min_version) const {
        URI uri(get_uri(bank, "accounts/" + account_id + "/payments/scheduled"));
        std::vector<BankingScheduledPayment> result;
        request_paginated<ResponseBankingScheduledPaymentsList>(uri, version, std::move(min_version), [&result](
                const ResponseBankingScheduledPaymentsList &resp) {
            result.insert(result.end(), resp.data.scheduled_payments.begin(), resp.data.scheduled_payments.end());
        });
        return result;
    }

/**
 * @brief Obtain scheduled payments for multiple, filtered accounts that are the source of funds for the payments.
 *
 * @param bank              Bank endpoint to use.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @param product_category  Filter results on product category.
 * @param open_status       Filter results according to open/closed status.
 * @param is_owned          Filter results based on whether they are owned by the authorised customer.
 * @return                  Filtered list of scheduled outgoing payments.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto bulk_outgoing_payments = regime.get_scheduled_payments_bulk(Bank::ANZ);
 * @endcode
 */
    std::vector<BankingScheduledPayment>
    Client::get_scheduled_payments_bulk(Bank bank, const std::string &version, std::optional<std::string> min_version,
                                        std::optional<ProductCategory> product_category,
                                        std::optional<OpenStatus> open_status, std::optional<bool> is_owned) const {
        URI uri(get_uri(bank, "payments/scheduled"));
        if (product_category.has_value())
            uri.addQueryParameter("product-category", get_string(ProductCategories, product_category.value()));
        if (open_status.has_value())
            uri.addQueryParameter("open-status", get_string(OpenStatuses, open_status.value()));
        if (is_owned.has_value())
            uri.addQueryParameter("is-owned", is_owned.value() ? "true" : "false");
        std::vector<BankingScheduledPayment> result;
        request_paginated<ResponseBankingScheduledPaymentsList>(uri, version, std::move(min_version),
                                                                [&result](
                                                                        const ResponseBankingScheduledPaymentsList &resp) {
                                                                    result.insert(result.end(),
                                                                                  resp.data.scheduled_payments.begin(),
                                                                                  resp.data.scheduled_payments.end());
                                                                });

        return result;
    }

/**
 * @brief Obtain scheduled payments for a specified list of accounts.
 *
 * @param bank              Bank endpoint to use.
 * @param account_ids       List of account ids.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @return                  List of scheduled payments for specific accounts.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto account_outgoing_payments = regime.get_scheduled_payments_for_specific_accounts(Bank::ANZ, std::vector<std::string>("1234"));
 * @endcode
 */
    std::vector<BankingScheduledPayment>
    Client::get_scheduled_payments_for_specific_accounts(Bank bank, const std::vector<std::string> &account_ids,
                                                         const std::string &version,
                                                         std::optional<std::string> min_version) const {
        URI uri(get_uri(bank, "payments/scheduled"));
        RequestAccountIds accounts;
        accounts.data.account_ids = account_ids;
        auto body = static_cast<Poco::DynamicStruct>(*accounts.to_json()).toString();
        std::vector<BankingScheduledPayment> result;
        request_paginated<ResponseBankingScheduledPaymentsList>(uri, version, std::move(min_version), [&result](
                const ResponseBankingScheduledPaymentsList &resp) {
            result.insert(result.end(), resp.data.scheduled_payments.begin(), resp.data.scheduled_payments.end());
        }, body);
        return result;
    }

/**
 * @brief Obtain a list of pre-registered payees.
 *
 * @param bank              Bank endpoint to use.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @param type              Filter results on payee type.
 * @return                  List of pre-registered payees.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto payees = regime.get_payees(Bank::ANZ);
 * @endcode
 */
    std::vector<BankingPayee>
    Client::get_payees(Bank bank, const std::string &version, std::optional<std::string> min_version,
                       std::optional<PayeeType> type) const {
        URI uri(get_uri(bank, "payees"));
        if (type.has_value())
            uri.addQueryParameter("type", get_string(PayeeTypes, type.value()));
        std::vector<BankingPayee> result;
        request_paginated<ResponseBankingPayeeList>(uri, version, std::move(min_version),
                                                    [&result](const ResponseBankingPayeeList &resp) {
                                                        result.insert(result.end(), resp.data.payees.begin(),
                                                                      resp.data.payees.end());
                                                    });
        return result;
    }

/**
 * @brief Obtain detailed information on a single payee.
 *
 * @param bank              Bank endpoint to use.
 * @param payee_id          ID of the specified payee.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @return                  Payee detail.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto payee_detail = regime.get_payee_detail(Bank::ANZ, "1234");
 * @endcode
 */
    BankingPayeeDetail Client::get_payee_detail(Bank bank, const std::string &payee_id, const std::string &version,
                                                std::optional<std::string> min_version) const {
        URI uri(get_uri(bank, "payees/" + payee_id));
        auto ret = request(uri, version, std::move(min_version));
        ResponseBankingPayeeById resp;
        resp.deserialize(ret);
        return resp.data;
    }

/**
 * @brief Obtain a list of products that are currently openly offered to the market.
 *
 * @param bank              Bank endpoint to use.
 * @param version           Version of the API end point.
 * @param min_version       Minimum version of the API end point.
 * @param effective         Filters results based on whether the current time is within the period of time defined as effective.
 * @param updated_since     Only include products that have been updated after the specified date and time.
 * @param brand             Filter results based on a specific brand.
 * @param product_category  Filter results on product category.
 * @return                  Vector of banking products.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto products = regime.get_products(Bank::ANZ);
 * @endcode
 */
    std::vector<BankingProductV2> Client::get_products(Bank bank,
                                                       const std::string &version,
                                                       std::optional<std::string> min_version,
                                                       std::optional<Effective> effective,
                                                       std::optional<DateTime> updated_since,
                                                       std::optional<std::string> brand,
                                                       std::optional<ProductCategory> product_category) const {
        URI uri(get_uri(bank, "products"));
        if (effective.has_value())
            uri.addQueryParameter("effective", get_string(EffectiveFields, effective.value()));
        if (updated_since.has_value())
            uri.addQueryParameter(
                    "updated-since",
                    DateTimeFormatter::format(updated_since.value(), DateTimeFormat::ISO8601_FORMAT));
        if (brand.has_value())
            uri.addQueryParameter("brand", brand.value());
        if (product_category.has_value())
            uri.addQueryParameter("product-category", get_string(ProductCategories, product_category.value()));
        std::vector<BankingProductV2> result;
        request_paginated<ResponseBankingProductList>(uri, version, std::move(min_version),
                                                      [&result](const ResponseBankingProductList &resp) {
                                                          result.insert(result.end(), resp.data.products.begin(),
                                                                        resp.data.products.end());
                                                      });
        return result;
    }

/**
 * @brief Obtain detailed information on a single product offered openly to the market.
 *
 * @param bank          Bank endpoint to use.
 * @param product_id    ID of the specified product.
 * @param version       Version of the API end point.
 * @param min_version   Minimum version of the API end point.
 * @return              Banking product details.
 *
 * Example:
 * @code
 *      Regime regime(1);
 *      auto product_details = regime.get_product_details(Bank::ANZ, "8123haf-1237fa-123jaj");
 * @endcode
 */
    BankingProductDetail Client::get_product_details(Bank bank,
                                                     const std::string &product_id,
                                                     const std::string &version,
                                                     std::optional<std::string> min_version) const {
        URI uri(get_uri(bank, "products/" + product_id));
        auto ret = request(uri, version, std::move(min_version));
        ResponseBankingProductById resp;
        resp.deserialize(ret);
        return resp.data;
    }

    std::string Client::get_uri(Bank bank, const std::string &resource) const {
        std::ostringstream stream;
        stream << "https://"
               << get_string(Banks, bank)
               << "/cds-au/v"
               << std::to_string(_version)
               << "/banking/"
               << resource;
        return stream.str();
    }

    Poco::JSON::Object::Ptr
    Client::request(const URI &uri, const std::string &version, std::optional<std::string> min_version,
                    const std::string &body) const {
        Poco::JSON::Parser parser;
        Net::HTTPResponse res;
        Net::HTTPSClientSession session(uri.getHost(), uri.getPort(), _context);
        Net::HTTPRequest req(Net::HTTPRequest::HTTP_GET, uri.getPathAndQuery(), Net::HTTPMessage::HTTP_1_1);
        req.setContentType("application/json");
        if (!body.empty())
            req.setContentLength(body.length());
        req.add("x-v", version);
        if (min_version.has_value())
            req.add("x-min-v", min_version.value());
        std::ostream &o = session.sendRequest(req);
        if (!body.empty())
            o << body;
        std::istream &s = session.receiveResponse(res);
        return parser.parse(s).extract<JSON::Object::Ptr>();
    }

    template<class R>
    void
    Client::request_paginated(const URI &uri, const std::string &version, std::optional<std::string> min_version,
                              std::function<void(const R &)> handler, const std::string &body) const {
        R resp;
        unsigned int page = 1, total_pages;
        do {
            URI temp{uri};
            temp.addQueryParameter("page", std::to_string(page));
            temp.addQueryParameter("page-size", std::to_string(MAXIMUM_PAGE_SIZE));
            auto ret = request(temp, version, min_version, body);
            resp.deserialize(ret);
            handler(resp);
            total_pages = resp.meta.value().total_pages;
        } while (++page <= total_pages);
    }
}

