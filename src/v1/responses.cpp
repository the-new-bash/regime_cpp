#include "../../include/v1/responses.hpp"

namespace regime::v1
{
    typedef Poco::JSON::Object::Ptr obj;

    std::tuple<obj, obj, obj> parse_response(const Poco::JSON::Object::Ptr &payload)
    {
        if (payload->has("errors"))
            throw ResponseError(payload->getArray("errors"));

        const auto data = payload->getObject("data");
        const auto links = payload->getObject("links");
        Poco::JSON::Object::Ptr meta;
        if (payload->has("meta"))
            meta = payload->getObject("meta");
        return std::make_tuple(data, links, meta);
    }

    void BankingProductList::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        get(products, payload, "products");
    }

    Poco::JSON::Object::Ptr BankingProductList::to_json() const
    {
        Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
        add(json, "products", products);
        return json;
    }

    void BankingAccountList::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        get(accounts, payload, "accounts");
    }

    Poco::JSON::Object::Ptr BankingAccountList::to_json() const
    {
        Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
        add(json, "accounts", accounts);
        return json;
    }

    void BankingTransactionList::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        get(transactions, payload, "transactions");
    }

    Poco::JSON::Object::Ptr BankingTransactionList::to_json() const
    {
        Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
        add(json, "transactions", transactions);
        return json;
    }

    void BankingAccountsBalanceList::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        get(balances, payload, "balances");
    }

    Poco::JSON::Object::Ptr BankingAccountsBalanceList::to_json() const
    {
        Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
        add(json, "balances", balances);
        return json;
    }

    void BankingPayeeList::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        get(payees, payload, "payees");
    }

    Poco::JSON::Object::Ptr BankingPayeeList::to_json() const
    {
        Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
        add(json, "payees", payees);
        return json;
    }

    void BankingDirectDebitAuthorisationList::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        get(direct_debit_authorisations, payload, "directDebitAuthorisations");
    }

    Poco::JSON::Object::Ptr BankingDirectDebitAuthorisationList::to_json() const
    {
        Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
        add(json, "directDebitAuthorisations", direct_debit_authorisations);
        return json;
    }

    void BankingScheduledPaymentsList::deserialize(const Poco::JSON::Object::Ptr &payload)
    {
        get(scheduled_payments, payload, "scheduledPayments");
    }

    Poco::JSON::Object::Ptr BankingScheduledPaymentsList::to_json() const
    {
        Poco::JSON::Object::Ptr json = new Poco::JSON::Object;
        add(json, "scheduledPayments", scheduled_payments);
        return json;
    }
}
