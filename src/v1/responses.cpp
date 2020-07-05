#include "../../include/v1/responses.hpp"

void BankingProductList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    regime::util::get(products, payload, "products");
}

Poco::JSON::Object::Ptr BankingProductList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "products", products);
    return json;
}

void BankingAccountList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    regime::util::get(accounts, payload, "accounts");
}

Poco::JSON::Object::Ptr BankingAccountList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "accounts", accounts);
    return json;
}

void BankingTransactionList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    regime::util::get(transactions, payload, "transactions");
}

Poco::JSON::Object::Ptr BankingTransactionList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "transactions", transactions);
    return json;
}

void BankingAccountsBalanceList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    regime::util::get(balances, payload, "balances");
}

Poco::JSON::Object::Ptr BankingAccountsBalanceList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "balances", balances);
    return json;
}

void BankingPayeeList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    regime::util::get(payees, payload, "payees");
}

Poco::JSON::Object::Ptr BankingPayeeList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "payees", payees);
    return json;
}

void BankingDirectDebitAuthorisationList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    regime::util::get(direct_debit_authorisations, payload, "directDebitAuthorisations");
}

Poco::JSON::Object::Ptr BankingDirectDebitAuthorisationList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "directDebitAuthorisations", direct_debit_authorisations);
    return json;
}

void BankingScheduledPaymentsList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    regime::util::get(scheduled_payments, payload, "scheduledPayments");
}

Poco::JSON::Object::Ptr BankingScheduledPaymentsList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "scheduledPayments", scheduled_payments);
    return json;
}
