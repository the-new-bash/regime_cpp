#ifndef REGIME_V1_RESPONSES_HPP
#define REGIME_V1_RESPONSES_HPP

#include "Poco/JSON/Object.h"
#include "common/responses.hpp"
#include "types.hpp"

DECLARE_RESPONSE_DATA(BankingProductList, std::vector<BankingProductV2> products;)

DECLARE_RESPONSE_TYPE(ResponseBankingProductList, BankingProductList, LinksPaginated, MetaPaginated)

DECLARE_RESPONSE_DATA(BankingProductById, BankingProductDetail product_detail;)

DECLARE_RESPONSE_TYPE_NO_META(ResponseBankingProductById, BankingProductById, Links)

DECLARE_RESPONSE_DATA(BankingAccountList, std::vector<BankingAccount> accounts;)

DECLARE_RESPONSE_TYPE(ResponseBankingAccountList, BankingAccountList, LinksPaginated, MetaPaginated)

DECLARE_RESPONSE_DATA(BankingAccountById, BankingAccountDetail account_detail;)

DECLARE_RESPONSE_TYPE_NO_META(ResponseBankingAccountById, BankingAccountById, Links)

DECLARE_RESPONSE_DATA(BankingTransactionList, std::vector<BankingTransaction> transactions;)

DECLARE_RESPONSE_TYPE(ResponseBankingTransactionList, BankingTransactionList, LinksPaginated, MetaPaginated)

DECLARE_RESPONSE_DATA(BankingTransactionById, BankingTransactionDetail transaction_detail;)

DECLARE_RESPONSE_TYPE_NO_META(ResponseBankingTransactionById, BankingTransactionById, Links)

DECLARE_RESPONSE_DATA(BankingAccountsBalanceList, std::vector<BankingBalance> balances;)

DECLARE_RESPONSE_TYPE(ResponseBankingAccountsBalanceList, BankingAccountsBalanceList, LinksPaginated, MetaPaginated)

DECLARE_RESPONSE_DATA(BankingAccountsBalanceById, BankingBalance balance;)

DECLARE_RESPONSE_TYPE_NO_META(ResponseBankingAccountsBalanceById, BankingAccountsBalanceById, Links)

DECLARE_RESPONSE_DATA(BankingPayeeList, std::vector<BankingPayee> payees;)

DECLARE_RESPONSE_TYPE(ResponseBankingPayeeList, BankingPayeeList, LinksPaginated, MetaPaginated)

DECLARE_RESPONSE_DATA(BankingPayeeById, BankingPayeeDetail payee_detail;)

DECLARE_RESPONSE_TYPE_NO_META(ResponseBankingPayeeById, BankingPayeeById, Links)

DECLARE_RESPONSE_DATA(BankingDirectDebitAuthorisationList, std::vector<BankingDirectDebit> direct_debit_authorisations;)

DECLARE_RESPONSE_TYPE(ResponseBankingDirectDebitAuthorisationList, BankingDirectDebitAuthorisationList, LinksPaginated,
                      MetaPaginated)

DECLARE_RESPONSE_DATA(BankingScheduledPaymentsList, std::vector<BankingScheduledPayment> scheduled_payments;)

DECLARE_RESPONSE_TYPE(ResponseBankingScheduledPaymentsList, BankingScheduledPaymentsList, LinksPaginated, MetaPaginated)

#endif //REGIME_V1_RESPONSES_HPP
