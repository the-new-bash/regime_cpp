#include "../../include/v1/responses.hpp"

void ResponseBankingProductList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingProductList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
    _meta->deserialize(std::get<2>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingProductList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingProductList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    regime::util::add(json, "data", _data->products);
    regime::util::add(json, "links", *_links);
    regime::util::add(json, "meta", *_meta);
    return json;
}

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

void ResponseBankingProductById::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingProductById *>(data.get());
    auto *_links = static_cast<Links *>(links.get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingProductById::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingProductById *>(data.get());
    auto *_links = static_cast<Links *>(links.get());
    regime::util::add(json, "data", _data->product_detail);
    regime::util::add(json, "links", *_links);
    return json;
}

void BankingProductById::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    product_detail.deserialize(payload);
}

Poco::JSON::Object::Ptr BankingProductById::to_json() const
{
    return product_detail.to_json();
}

void ResponseBankingAccountList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingAccountList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
    _meta->deserialize(std::get<2>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingAccountList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingAccountList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    regime::util::add(json, "data", _data->accounts);
    regime::util::add(json, "links", *_links);
    regime::util::add(json, "meta", *_meta);
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

void ResponseBankingAccountById::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingAccountById *>(data.get());
    auto *_links = static_cast<Links *>(links.get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingAccountById::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingAccountById *>(data.get());
    auto *_links = static_cast<Links *>(links.get());
    regime::util::add(json, "data", _data->account_detail);
    regime::util::add(json, "links", *_links);
    return json;
}

void BankingAccountById::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    account_detail.deserialize(payload);
}

Poco::JSON::Object::Ptr BankingAccountById::to_json() const
{
    return account_detail.to_json();
}

void ResponseBankingTransactionList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingTransactionList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
    _meta->deserialize(std::get<2>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingTransactionList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingTransactionList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    regime::util::add(json, "data", _data->transactions);
    regime::util::add(json, "links", *_links);
    regime::util::add(json, "meta", *_meta);
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

void ResponseBankingTransactionById::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingTransactionById *>(data.get());
    auto *_links = static_cast<Links *>(links.get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingTransactionById::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingTransactionById *>(data.get());
    auto *_links = static_cast<Links *>(links.get());
    regime::util::add(json, "data", _data->transaction_detail);
    regime::util::add(json, "links", *_links);
    return json;
}

void BankingTransactionById::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    transaction_detail.deserialize(payload);
}

Poco::JSON::Object::Ptr BankingTransactionById::to_json() const
{
    return transaction_detail.to_json();
}

void ResponseBankingAccountsBalanceList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingAccountsBalanceList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
    _meta->deserialize(std::get<2>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingAccountsBalanceList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingAccountsBalanceList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    regime::util::add(json, "data", _data->balances);
    regime::util::add(json, "links", *_links);
    regime::util::add(json, "meta", *_meta);
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

void ResponseBankingAccountsBalanceById::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingAccountsBalanceById *>(data.get());
    auto *_links = static_cast<Links *>(links.get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingAccountsBalanceById::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingAccountsBalanceById *>(data.get());
    auto *_links = static_cast<Links *>(links.get());
    regime::util::add(json, "data", _data->balance);
    regime::util::add(json, "links", *_links);
    return json;
}

void BankingAccountsBalanceById::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    balance.deserialize(payload);
}

Poco::JSON::Object::Ptr BankingAccountsBalanceById::to_json() const
{
    return balance.to_json();
}

void ResponseBankingPayeeList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingPayeeList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
    _meta->deserialize(std::get<2>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingPayeeList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingPayeeList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    regime::util::add(json, "data", _data->payees);
    regime::util::add(json, "links", *_links);
    regime::util::add(json, "meta", *_meta);
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

void ResponseBankingPayeeById::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingPayeeById *>(data.get());
    auto *_links = static_cast<Links *>(links.get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingPayeeById::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingPayeeById *>(data.get());
    auto *_links = static_cast<Links *>(links.get());
    regime::util::add(json, "data", _data->payee_detail);
    regime::util::add(json, "links", *_links);
    return json;
}

void BankingPayeeById::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    payee_detail.deserialize(payload);
}

Poco::JSON::Object::Ptr BankingPayeeById::to_json() const
{
    return payee_detail.to_json();
}

void ResponseBankingDirectDebitAuthorisationList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingDirectDebitAuthorisationList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
    _meta->deserialize(std::get<2>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingDirectDebitAuthorisationList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingDirectDebitAuthorisationList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    regime::util::add(json, "data", _data->direct_debit_authorisations);
    regime::util::add(json, "links", *_links);
    regime::util::add(json, "meta", *_meta);
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

void ResponseBankingScheduledPaymentsList::deserialize(const Poco::JSON::Object::Ptr &payload)
{
    const auto resp = Response::parse(payload);
    auto *_data = static_cast<BankingScheduledPaymentsList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    _data->deserialize(std::get<0>(resp));
    _links->deserialize(std::get<1>(resp));
    _meta->deserialize(std::get<2>(resp));
}

Poco::JSON::Object::Ptr ResponseBankingScheduledPaymentsList::to_json() const
{
    Poco::JSON::Object::Ptr json;
    auto *_data = static_cast<BankingScheduledPaymentsList *>(data.get());
    auto *_links = static_cast<LinksPaginated *>(links.get());
    auto *_meta = static_cast<MetaPaginated *>(meta.value().get());
    regime::util::add(json, "data", _data->scheduled_payments);
    regime::util::add(json, "links", *_links);
    regime::util::add(json, "meta", *_meta);
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
