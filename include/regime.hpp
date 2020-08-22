#include <utility>

#include "Poco/Net/Context.h"
#include "Poco/Net/HTTPSClientSession.h"
#include "Poco/URI.h"
#include "v1/responses.hpp"
#include "v1/requests.hpp"

namespace regime {
    using namespace v1;

    enum class Bank {
        ANZ,
        CBA,
        NAB,
        WBC,
    };

    const std::array<const EnumStringPair<Bank>, 4> Banks
            {
                    {
                            {Bank::ANZ, "api.anz"},
                            {Bank::CBA, "api.commbank.com.au"},
                            {Bank::NAB, "openbank.api.nab.com.au"},
                            {Bank::WBC, "digital-api.westpac.com.au"}
                    }
            };

    class Client {
    public:
        Client(const unsigned int &version) :
                _version{version},
                _context{
                        new Poco::Net::Context(Poco::Net::Context::CLIENT_USE, "", Poco::Net::Context::VERIFY_NONE)} {};

        virtual ~Client() = default;

        std::vector<BankingAccount> get_accounts(
                Bank bank,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt,
                std::optional<ProductCategory> product_category = std::nullopt,
                std::optional<OpenStatus> open_status = std::nullopt,
                std::optional<bool> is_owned = std::nullopt) const;

        std::vector<BankingBalance> get_bulk_balances(
                Bank bank,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt,
                std::optional<ProductCategory> product_category = std::nullopt,
                std::optional<OpenStatus> open_status = std::nullopt,
                std::optional<bool> is_owned = std::nullopt) const;

        std::vector<BankingBalance> get_balances_for_specific_accounts(
                Bank bank,
                const std::vector<std::string> &account_ids,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt) const;

        BankingBalance get_account_balance(
                Bank bank,
                const std::string &account_id,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt) const;

        BankingAccountDetail get_account_detail(
                Bank bank,
                const std::string &account_id,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt) const;

        std::vector<BankingTransaction> get_transactions_for_account(
                Bank bank,
                const std::string &account_id,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt,
                std::optional<std::string> oldest_time = std::nullopt,
                std::optional<std::string> newest_time = std::nullopt,
                std::optional<std::string> min_amount = std::nullopt,
                std::optional<std::string> max_amount = std::nullopt,
                std::optional<std::string> text = std::nullopt) const;

        BankingTransactionDetail get_transaction_detail(
                Bank bank,
                const std::string &account_id,
                const std::string &transaction_id,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt) const;

        std::vector<BankingDirectDebit> get_direct_debits_for_account(
                Bank bank,
                const std::string &account_id,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt) const;

        std::vector<BankingDirectDebit> get_bulk_direct_debits(
                Bank bank,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt,
                std::optional<ProductCategory> product_category = std::nullopt,
                std::optional<OpenStatus> open_status = std::nullopt,
                std::optional<bool> is_owned = std::nullopt) const;

        std::vector<BankingDirectDebit> get_direct_debits_for_specific_accounts(
                Bank bank,
                const std::vector<std::string> &account_ids,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt) const;

        std::vector<BankingScheduledPayment> get_scheduled_payments_for_account(
                Bank bank,
                const std::string &account_id,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt) const;

        std::vector<BankingScheduledPayment> get_scheduled_payments_bulk(
                Bank bank,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt,
                std::optional<ProductCategory> product_category = std::nullopt,
                std::optional<OpenStatus> open_status = std::nullopt,
                std::optional<bool> is_owned = std::nullopt) const;

        std::vector<BankingScheduledPayment> get_scheduled_payments_for_specific_accounts(
                Bank bank,
                const std::vector<std::string> &account_ids,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt) const;

        std::vector<BankingPayee> get_payees(
                Bank bank,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt,
                std::optional<PayeeType> type = std::nullopt) const;

        BankingPayeeDetail get_payee_detail(
                Bank bank,
                const std::string &payee_id,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt) const;

        std::vector<BankingProductV2> get_products(
                Bank bank,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt,
                std::optional<Effective> effective = std::nullopt,
                std::optional<Poco::DateTime> updated_since = std::nullopt,
                std::optional<std::string> brand = std::nullopt,
                std::optional<ProductCategory> product_category = std::nullopt) const;

        BankingProductDetail get_product_details(
                Bank bank,
                const std::string &product_id,
                const std::string &version = "1",
                std::optional<std::string> min_version = std::nullopt) const;

    protected:
        template<class R>
        void get(const Poco::URI &uri,
                 const std::string &version,
                 std::optional<std::string> min_version,
                 std::function<void(const R &)> handler,
                 bool paginated,
                 const std::string &body = "") const;

        template<typename T, typename = int>
        struct is_paginated : std::false_type {
        };

        template<typename T>
        struct is_paginated<T, decltype((void) T::total_pages, 0)> : std::true_type {
        };

        [[nodiscard]] std::string get_uri(Bank bank, const std::string &resource) const;

        static const unsigned int MAXIMUM_PAGE_SIZE = 1000;

    private:
        const unsigned int _version;
        const Poco::Net::Context::Ptr _context;

    };
}
