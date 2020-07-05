#ifndef REGIME_V1_RESPONSES_HPP
#define REGIME_V1_RESPONSES_HPP

#include "Poco/JSON/Object.h"
#include "common/responses.hpp"
#include "types.hpp"

DECLARE_COMMON_TYPE(BankingProductList, std::vector<BankingProductV2> products;)

DECLARE_COMMON_TYPE(BankingAccountList, std::vector<BankingAccount> accounts;)

DECLARE_COMMON_TYPE(BankingTransactionList, std::vector<BankingTransaction> transactions;)

DECLARE_COMMON_TYPE(BankingAccountsBalanceList, std::vector<BankingBalance> balances;)

DECLARE_COMMON_TYPE(BankingPayeeList, std::vector<BankingPayee> payees;)

DECLARE_COMMON_TYPE(BankingDirectDebitAuthorisationList, std::vector<BankingDirectDebit> direct_debit_authorisations;)

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

DECLARE_RESPONSE_TYPE(ResponseBankingDirectDebitAuthorisationList, BankingDirectDebitAuthorisationList, LinksPaginated,
                      MetaPaginated)

DECLARE_RESPONSE_TYPE(ResponseBankingScheduledPaymentsList, BankingScheduledPaymentsList, LinksPaginated,
                      MetaPaginated)

#endif //REGIME_V1_RESPONSES_HPP
