#include "helpers.hpp"

static Poco::JSON::Parser parser;
static Poco::JSON::Object::Ptr object;

using namespace regime::v1::test;
using namespace regime::v1;

#define EXTRACT_OBJECT(obj, str) obj = parser.parse(str).extract<Poco::JSON::Object::Ptr>()

TEST(TypeDeserialization, BankingProductV2)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_V2);
    BankingProductV2 product;
    product.deserialize(object);
    test_product_v2_fields(product);
}

TEST(TypeDeserialization, BankingProductDetail)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_DETAIL);
    BankingProductDetail product_detail;
    product_detail.deserialize(object);
    test_product_detail_fields(product_detail);
}

TEST(TypeDeserialization, BankingProductBundle)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_BUNDLE);
    BankingProductBundle product_bundle;
    product_bundle.deserialize(object);
    test_product_bundle_fields(product_bundle);
}

TEST(TypeDeserialization, BankingProductFeature)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_FEATURE);
    BankingProductFeature product_feature;
    product_feature.deserialize(object);
    test_product_feature_fields(product_feature);
}

TEST(TypeDeserialization, BankingProductConstraint)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_CONSTRAINT);
    BankingProductConstraint product_constraint;
    product_constraint.deserialize(object);
    test_product_constraint_fields(product_constraint);
}

TEST(TypeDeserialization, BankingProductEligibility)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_ELIGIBILITY);
    BankingProductEligibility product_eligibility;
    product_eligibility.deserialize(object);
    test_product_eligibility_fields(product_eligibility);
}

TEST(TypeDeserialization, BankingProductFee)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_FEE);
    BankingProductFee product_fee;
    product_fee.deserialize(object);
    test_product_fee_fields(product_fee);
}

TEST(TypeDeserialization, BankingProductDiscount)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_DISCOUNT);
    BankingProductDiscount product_discount;
    product_discount.deserialize(object);
    test_product_discount_fields(product_discount);
}

TEST(TypeDeserialization, BankingProductDiscountEligibility)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_DISCOUNT_ELIGIBILITY);
    BankingProductDiscountEligibility product_discount_eligibility;
    product_discount_eligibility.deserialize(object);
    test_product_discount_eligibility_fields(product_discount_eligibility);
}

TEST(TypeDeserialization, BankingProductDepositRate)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_DEPOSIT_RATE);
    BankingProductDepositRate product_deposit_rate;
    product_deposit_rate.deserialize(object);
    test_product_deposit_rate_fields(product_deposit_rate);
}

TEST(TypeDeserialization, BankingProductLendingRate)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_LENDING_RATE);
    BankingProductLendingRate product_lending_rate;
    product_lending_rate.deserialize(object);
    test_product_lending_rate_fields(product_lending_rate);
}

TEST(TypeDeserialization, BankingProductRateTier)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_RATE_TIER);
    BankingProductRateTier product_rate_tier;
    product_rate_tier.deserialize(object);
    test_product_rate_tier_fields(product_rate_tier);
}

TEST(TypeDeserialization, ProductRateCondition)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_RATE_CONDITION);
    BankingProductRateCondition product_rate_condition;
    product_rate_condition.deserialize(object);
    test_product_rate_condition_fields(product_rate_condition);
}

TEST(TypeDeserialization, BankingAccount)
{
    EXTRACT_OBJECT(object, BANKING_ACCOUNT);
    BankingAccount account;
    account.deserialize(object);
    test_account_fields(account);
}

TEST(TypeDeserialization, BankingAccountDetail)
{
    EXTRACT_OBJECT(object, BANKING_ACCOUNT_DETAIL);
    BankingAccountDetail account_detail;
    account_detail.deserialize(object);
    test_account_detail_fields(account_detail);
}

TEST(TypeDeserialization, BankingTermDepositAccount)
{
    EXTRACT_OBJECT(object, BANKING_TERM_DEPOSIT_ACCOUNT);
    BankingTermDepositAccount term_deposit_account;
    term_deposit_account.deserialize(object);
    test_term_deposit_account_fields(term_deposit_account);
}

TEST(TypeDeserialization, CreditCardAccount)
{
    EXTRACT_OBJECT(object, BANKING_CREDIT_CARD_ACCOUNT);
    BankingCreditCardAccount credit_card_account;
    credit_card_account.deserialize(object);
    test_credit_card_account_fields(credit_card_account);
}

TEST(TypeDeserialization, BankingLoanAccount)
{
    EXTRACT_OBJECT(object, BANKING_LOAN_ACCOUNT);
    BankingLoanAccount loan_account;
    loan_account.deserialize(object);
    test_loan_account_fields(loan_account);
}

TEST(TypeDeserialization, BankingTransaction)
{
    EXTRACT_OBJECT(object, BANKING_TRANSACTION);
    BankingTransaction transaction;
    transaction.deserialize(object);
    test_transaction_fields(transaction);
}

TEST(TypeDeserialization, BankingTransactionDetail)
{
    EXTRACT_OBJECT(object, BANKING_TRANSACTION_DETAIL);
    BankingTransactionDetail transaction_detail;
    transaction_detail.deserialize(object);
    test_transaction_detail_fields(transaction_detail);
}

TEST(TypeDeserialization, BankingBalance)
{
    EXTRACT_OBJECT(object, BANKING_BALANCE);
    BankingBalance balance;
    balance.deserialize(object);
    test_balance_fields(balance);
}

TEST(TypeDeserialization, BankingBalancePurse)
{
    EXTRACT_OBJECT(object, BANKING_BALANCE_PURSE);
    BankingBalancePurse purse;
    purse.deserialize(object);
    test_balance_purse_fields(purse);
}

TEST(TypeDeserialization, BankingPayee)
{
    EXTRACT_OBJECT(object, BANKING_PAYEE);
    BankingPayee payee;
    payee.deserialize(object);
    test_payee_fields(payee);
}

TEST(TypeDeserialization, BankingPayeeDetail)
{
    EXTRACT_OBJECT(object, BANKING_PAYEE_DETAIL);
    BankingPayeeDetail payee_detail;
    payee_detail.deserialize(object);
    test_payee_detail_fields(payee_detail);
}

TEST(TypeDeserialization, BankingDomesticPayee)
{
    EXTRACT_OBJECT(object, BANKING_DOMESTIC_PAYEE);
    BankingDomesticPayee domestic_payee;
    domestic_payee.deserialize(object);
    test_domestic_payee_fields(domestic_payee);
}

TEST(TypeDeserialization, BankingDomesticPayeeAccount)
{
    EXTRACT_OBJECT(object, BANKING_DOMESTIC_PAYEE_ACCOUNT);
    BankingDomesticPayeeAccount domestic_payee_account;
    domestic_payee_account.deserialize(object);
    test_domestic_payee_account_fields(domestic_payee_account);
}

TEST(TypeDeserialization, BankingDomesticPayeeCard)
{
    EXTRACT_OBJECT(object, BANKING_DOMESTIC_PAYEE_CARD);
    BankingDomesticPayeeCard domestic_payee_card;
    domestic_payee_card.deserialize(object);
    test_domestic_payee_card_fields(domestic_payee_card);
}

TEST(TypeDeserialization, DomesticPayeePayId)
{
    EXTRACT_OBJECT(object, BANKING_DOMESTIC_PAYEE_PAY_ID);
    BankingDomesticPayeePayId domestic_payee_pay_id;
    domestic_payee_pay_id.deserialize(object);
    test_domestic_payee_pay_id_fields(domestic_payee_pay_id);
}

TEST(TypeDeserialization, BankingBillerPayee)
{
    EXTRACT_OBJECT(object, BANKING_BILLER_PAYEE);
    BankingBillerPayee biller_payee;
    biller_payee.deserialize(object);
    test_biller_payee_fields(biller_payee);
}

TEST(TypeDeserialization, BankingInternationalPayee)
{
    EXTRACT_OBJECT(object, BANKING_INTERNATIONAL_PAYEE);
    BankingInternationalPayee international_payee;
    international_payee.deserialize(object);
    test_international_payee_fields(international_payee);
}

TEST(TypeDeserialization, BankingDirectDebit)
{
    EXTRACT_OBJECT(object, BANKING_DIRECT_DEBIT);
    BankingDirectDebit direct_debit;
    direct_debit.deserialize(object);
    test_direct_debit_fields(direct_debit);
}

TEST(TypeDeserialization, BankingAuthorisedEntity)
{
    EXTRACT_OBJECT(object, BANKING_AUTHORISED_ENTITY);
    BankingAuthorisedEntity authorised_entity;
    authorised_entity.deserialize(object);
    test_authorised_entity_fields(authorised_entity);
}

TEST(TypeDeserialization, BankingScheduledPayment)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT);
    BankingScheduledPayment payment;
    payment.deserialize(object);
    test_scheduled_payment_fields(payment);
}

TEST(TypeDeserialization, BankingScheduledPaymentSet)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_SET);
    BankingScheduledPaymentSet scheduled_payment_set;
    scheduled_payment_set.deserialize(object);
    test_scheduled_payment_set_fields(scheduled_payment_set);
}

TEST(TypeDeserialization, BankingScheduledPaymentTo)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_TO);
    BankingScheduledPaymentTo scheduled_payment_to;
    scheduled_payment_to.deserialize(object);
    test_scheduled_payment_to_fields(scheduled_payment_to);
}

TEST(TypeDeserialization, BankingScheduledPaymentFrom)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_FROM);
    BankingScheduledPaymentFrom scheduled_payment_from;
    scheduled_payment_from.deserialize(object);
    test_scheduled_payment_from_fields(scheduled_payment_from);
}

TEST(TypeDeserialization, BankingScheduledPaymentRecurrence)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_RECURRENCE);
    BankingScheduledPaymentRecurrence scheduled_payment_recurrence;
    scheduled_payment_recurrence.deserialize(object);
    test_scheduled_payment_recurrence_fields(scheduled_payment_recurrence);
}

TEST(TypeDeserialization, BankingScheduledPaymentRecurrenceOnceOff)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_RECURRENCE_ONCE_OFF);
    BankingScheduledPaymentRecurrenceOnceOff scheduled_payment_recurrence_once_off;
    scheduled_payment_recurrence_once_off.deserialize(object);
    test_scheduled_payment_recurrence_once_off_fields(scheduled_payment_recurrence_once_off);
}

TEST(TypeDeserialization, BankingScheduledPaymentRecurrenceIntervalSchedule)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_RECURRENCE_INTERVAL_SCHEDULE);
    BankingScheduledPaymentRecurrenceIntervalSchedule scheduled_payment_recurrence_interval_schedule;
    scheduled_payment_recurrence_interval_schedule.deserialize(object);
    test_scheduled_payment_recurrence_interval_schedule_fields(scheduled_payment_recurrence_interval_schedule);
}

TEST(TypeDeserialization, BankingScheduledPaymentInterval)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_INTERVAL);
    BankingScheduledPaymentInterval scheduled_payment_interval;
    scheduled_payment_interval.deserialize(object);
    test_scheduled_payment_interval_fields(scheduled_payment_interval);
}

TEST(TypeDeserialization, BankingScheduledPaymentRecurrenceLastWeekday)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_RECURRENCE_LAST_WEEKDAY);
    BankingScheduledPaymentRecurrenceLastWeekday scheduled_payment_recurrence_last_weekday;
    scheduled_payment_recurrence_last_weekday.deserialize(object);
    test_scheduled_payment_recurrence_last_weekday_fields(scheduled_payment_recurrence_last_weekday);
}

TEST(TypeDeserialization, BankingScheduledPaymentRecurrenceEventBased)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_RECURRENCE_EVENT_BASED);
    BankingScheduledPaymentRecurrenceEventBased scheduled_payment_recurrence_event_based;
    scheduled_payment_recurrence_event_based.deserialize(object);
    test_scheduled_payment_recurrence_event_based_fields(scheduled_payment_recurrence_event_based);
}

TEST(RequestDeserialization, AccountIds)
{
    EXTRACT_OBJECT(object, REQUEST_BANKING_ACCOUNT_IDS);
    RequestAccountIds request;
    request.deserialize(object);
    EXPECT_STREQ(request.data.account_ids[0].c_str(), "string");
}

TEST(ResponseDeserialization, BankingProductList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_PRODUCT_LIST);
    ResponseBankingProductList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.products.size(), 1);
    test_product_v2_fields(response.data.products[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
}

TEST(ResponseDeserialization, BankingProductById)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_PRODUCT_BY_ID);
    ResponseBankingProductById response;
    response.deserialize(object);
    test_product_detail_fields(response.data);
}

TEST(ResponseDeserialization, BankingAccountList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_ACCOUNT_LIST);
    ResponseBankingAccountList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.accounts.size(), 1);
    test_account_fields(response.data.accounts[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
}

TEST(ResponseDeserialization, BankingAccountById)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_ACCOUNT_BY_ID);
    ResponseBankingAccountById response;
    response.deserialize(object);
    test_account_detail_fields(response.data);
}

TEST(ResponseDeserialization, BankingTransactionList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_TRANSACTION_LIST);
    ResponseBankingTransactionList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.transactions.size(), 1);
    test_transaction_fields(response.data.transactions[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
}

TEST(ResponseDeserialization, BankingTransactionById)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_TRANSACTION_BY_ID);
    ResponseBankingTransactionById response;
    response.deserialize(object);
    test_transaction_detail_fields(response.data);
}

TEST(ResponseDeserialization, BankingAccountsBalanceList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_ACCOUNTS_BALANCE_LIST);
    ResponseBankingAccountsBalanceList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.balances.size(), 1);
    test_balance_fields(response.data.balances[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
}

TEST(ResponseDeserialization, BankingAccountsBalanceById)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_ACCOUNTS_BALANCE_BY_ID);
    ResponseBankingAccountsBalanceById response;
    response.deserialize(object);
    test_balance_fields(response.data);
}

TEST(ResponseDeserialization, BankingPayeeList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_PAYEE_LIST);
    ResponseBankingPayeeList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.payees.size(), 1);
    test_payee_fields(response.data.payees[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
}

TEST(ResponseDeserialization, BankingPayeeById)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_PAYEE_BY_ID);
    ResponseBankingPayeeById response;
    response.deserialize(object);
    test_payee_detail_fields(response.data);
}

TEST(ResponseDeserialization, BankingDirectDebitAuthorisationList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_DIRECT_DEBIT_AUTHORISATION_LIST);
    ResponseBankingDirectDebitAuthorisationList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.direct_debit_authorisations.size(), 1);
    test_direct_debit_fields(response.data.direct_debit_authorisations[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
}

TEST(ResponseDeserialization, BankingScheduledPaymentsList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_SCHEDULED_PAYMENTS_LIST);
    ResponseBankingScheduledPaymentsList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.scheduled_payments.size(), 1);
    test_scheduled_payment_fields(response.data.scheduled_payments[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
}
