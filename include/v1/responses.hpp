#ifndef REGIME_V1_COMMON_RESPONSES_HPP
#define REGIME_V1_COMMON_RESPONSES_HPP

#include "utils.hpp"
#include "errors.hpp"

namespace regime::v1
{
    template<class Data, class Links, class Meta>
    struct Response : public IObject
    {
        Data data;
        Links links;
        std::optional<Meta> meta;

        void deserialize(const Poco::JSON::Object::Ptr &payload) override;

        [[nodiscard]] Poco::JSON::Object::Ptr to_json() const override;
    };

    using obj = Poco::JSON::Object::Ptr;

    std::tuple<obj, obj, obj> parse_response(const Poco::JSON::Object::Ptr &payload);

    template<class Data, class Links, class Meta>
    void Response<Data, Links, Meta>::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        const auto[_data, _links, _meta] = parse_response(payload);
        data.deserialize(_data);
        links.deserialize(_links);
        if (!_meta.isNull())
        {
            Meta tmp;
            tmp.deserialize(_meta);
            meta = tmp;
        }
    }

    template<class Data, class Links, class Meta>
    Poco::JSON::Object::Ptr Response<Data, Links, Meta>::to_json() const
    {
        Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
        add(json, "data", data);
        add(json, "links", links);
        add(json, "meta", meta.value());
        return json;
    }

#define DECLARE_RESPONSE_TYPE(name, data, links, meta) struct name final : public Response<data, links, meta> {};

    DECLARE_COMMON_TYPE(BankingProductList, std::vector<BankingProductV2> products;)

    DECLARE_COMMON_TYPE(BankingAccountList, std::vector<BankingAccount> accounts;)

    DECLARE_COMMON_TYPE(BankingTransactionList, std::vector<BankingTransaction> transactions;)

    DECLARE_COMMON_TYPE(BankingAccountsBalanceList, std::vector<BankingBalance> balances;)

    DECLARE_COMMON_TYPE(BankingPayeeList, std::vector<BankingPayee> payees;)

    DECLARE_COMMON_TYPE(BankingDirectDebitAuthorisationList,
                        std::vector<BankingDirectDebit> direct_debit_authorisations;)

    DECLARE_COMMON_TYPE(BankingScheduledPaymentsList, std::vector<BankingScheduledPayment> scheduled_payments;)

    DECLARE_RESPONSE_TYPE(ResponseBankingProductList, BankingProductList, LinksPaginated, MetaPaginated)

    DECLARE_RESPONSE_TYPE(ResponseBankingProductById, BankingProductDetail, Links, Meta)

    DECLARE_RESPONSE_TYPE(ResponseBankingAccountList, BankingAccountList, LinksPaginated, MetaPaginated)

    DECLARE_RESPONSE_TYPE(ResponseBankingAccountById, BankingAccountDetail, Links, Meta)

    DECLARE_RESPONSE_TYPE(ResponseBankingTransactionList, BankingTransactionList, LinksPaginated, MetaPaginated)

    DECLARE_RESPONSE_TYPE(ResponseBankingTransactionById, BankingTransactionDetail, Links, Meta)

    DECLARE_RESPONSE_TYPE(ResponseBankingAccountsBalanceList, BankingAccountsBalanceList, LinksPaginated, MetaPaginated)

    DECLARE_RESPONSE_TYPE(ResponseBankingAccountsBalanceById, BankingBalance, Links, Meta)

    DECLARE_RESPONSE_TYPE(ResponseBankingPayeeList, BankingPayeeList, LinksPaginated, MetaPaginated)

    DECLARE_RESPONSE_TYPE(ResponseBankingPayeeById, BankingPayeeDetail, Links, Meta)

    DECLARE_RESPONSE_TYPE(ResponseBankingDirectDebitAuthorisationList, BankingDirectDebitAuthorisationList,
                          LinksPaginated,
                          MetaPaginated)

    DECLARE_RESPONSE_TYPE(ResponseBankingScheduledPaymentsList, BankingScheduledPaymentsList, LinksPaginated,
                          MetaPaginated)
}

#endif //REGIME_V1_COMMON_RESPONSES_HPP
