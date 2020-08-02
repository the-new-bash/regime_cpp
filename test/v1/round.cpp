#include "helpers.hpp"

static Poco::JSON::Parser parser;
static Poco::JSON::Object::Ptr object;

using namespace regime::v1::test;
using namespace regime::v1;

#define EXTRACT_OBJECT(obj, str) obj = parser.parse(str).extract<Poco::JSON::Object::Ptr>()

TEST(TypeRoundTest, BankingProductV2)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_V2);
    BankingProductV2 product;
    product.deserialize(object);
    test_product_v2_fields(product);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductDetail)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_DETAIL);
    BankingProductDetail product_detail;
    product_detail.deserialize(object);
    test_product_detail_fields(product_detail);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_detail.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductBundle)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_BUNDLE);
    BankingProductBundle product_bundle;
    product_bundle.deserialize(object);
    test_product_bundle_fields(product_bundle);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_bundle.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductFeature)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_FEATURE);
    BankingProductFeature product_feature;
    product_feature.deserialize(object);
    test_product_feature_fields(product_feature);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_feature.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductConstraint)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_CONSTRAINT);
    BankingProductConstraint product_constraint;
    product_constraint.deserialize(object);
    test_product_constraint_fields(product_constraint);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_constraint.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductEligibility)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_ELIGIBILITY);
    BankingProductEligibility product_eligibility;
    product_eligibility.deserialize(object);
    test_product_eligibility_fields(product_eligibility);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_eligibility.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductFee)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_FEE);
    BankingProductFee product_fee;
    product_fee.deserialize(object);
    test_product_fee_fields(product_fee);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_fee.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductDiscount)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_DISCOUNT);
    BankingProductDiscount product_discount;
    product_discount.deserialize(object);
    test_product_discount_fields(product_discount);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_discount.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductDiscountEligibility)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_DISCOUNT_ELIGIBILITY);
    BankingProductDiscountEligibility product_discount_eligibility;
    product_discount_eligibility.deserialize(object);
    test_product_discount_eligibility_fields(product_discount_eligibility);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_discount_eligibility.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductDepositRate)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_DEPOSIT_RATE);
    BankingProductDepositRate product_deposit_rate;
    product_deposit_rate.deserialize(object);
    test_product_deposit_rate_fields(product_deposit_rate);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_deposit_rate.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductLendingRate)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_LENDING_RATE);
    BankingProductLendingRate product_lending_rate;
    product_lending_rate.deserialize(object);
    test_product_lending_rate_fields(product_lending_rate);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_lending_rate.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingProductRateTier)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_RATE_TIER);
    BankingProductRateTier product_rate_tier;
    product_rate_tier.deserialize(object);
    test_product_rate_tier_fields(product_rate_tier);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_rate_tier.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, ProductRateCondition)
{
    EXTRACT_OBJECT(object, BANKING_PRODUCT_RATE_CONDITION);
    BankingProductRateCondition product_rate_condition;
    product_rate_condition.deserialize(object);
    test_product_rate_condition_fields(product_rate_condition);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(product_rate_condition.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingAccount)
{
    EXTRACT_OBJECT(object, BANKING_ACCOUNT);
    BankingAccount account;
    account.deserialize(object);
    test_account_fields(account);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(account.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingAccountDetail)
{
    EXTRACT_OBJECT(object, BANKING_ACCOUNT_DETAIL);
    BankingAccountDetail account_detail;
    account_detail.deserialize(object);
    test_account_detail_fields(account_detail);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(account_detail.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingTermDepositAccount)
{
    EXTRACT_OBJECT(object, BANKING_TERM_DEPOSIT_ACCOUNT);
    BankingTermDepositAccount term_deposit_account;
    term_deposit_account.deserialize(object);
    test_term_deposit_account_fields(term_deposit_account);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(term_deposit_account.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, CreditCardAccount)
{
    EXTRACT_OBJECT(object, BANKING_CREDIT_CARD_ACCOUNT);
    BankingCreditCardAccount credit_card_account;
    credit_card_account.deserialize(object);
    test_credit_card_account_fields(credit_card_account);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(credit_card_account.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingLoanAccount)
{
    EXTRACT_OBJECT(object, BANKING_LOAN_ACCOUNT);
    BankingLoanAccount loan_account;
    loan_account.deserialize(object);
    test_loan_account_fields(loan_account);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(loan_account.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingTransaction)
{
    EXTRACT_OBJECT(object, BANKING_TRANSACTION);
    BankingTransaction transaction;
    transaction.deserialize(object);
    test_transaction_fields(transaction);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(transaction.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingTransactionDetail)
{
    EXTRACT_OBJECT(object, BANKING_TRANSACTION_DETAIL);
    BankingTransactionDetail transaction_detail;
    transaction_detail.deserialize(object);
    test_transaction_detail_fields(transaction_detail);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(transaction_detail.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingBalance)
{
    EXTRACT_OBJECT(object, BANKING_BALANCE);
    BankingBalance balance;
    balance.deserialize(object);
    test_balance_fields(balance);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(balance.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingBalancePurse)
{
    EXTRACT_OBJECT(object, BANKING_BALANCE_PURSE);
    BankingBalancePurse purse;
    purse.deserialize(object);
    test_balance_purse_fields(purse);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(purse.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingPayee)
{
    EXTRACT_OBJECT(object, BANKING_PAYEE);
    BankingPayee payee;
    payee.deserialize(object);
    test_payee_fields(payee);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(payee.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingPayeeDetail)
{
    EXTRACT_OBJECT(object, BANKING_PAYEE_DETAIL);
    BankingPayeeDetail payee_detail;
    payee_detail.deserialize(object);
    test_payee_detail_fields(payee_detail);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(payee_detail.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingDomesticPayee)
{
    EXTRACT_OBJECT(object, BANKING_DOMESTIC_PAYEE);
    BankingDomesticPayee domestic_payee;
    domestic_payee.deserialize(object);
    test_domestic_payee_fields(domestic_payee);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(domestic_payee.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingDomesticPayeeAccount)
{
    EXTRACT_OBJECT(object, BANKING_DOMESTIC_PAYEE_ACCOUNT);
    BankingDomesticPayeeAccount domestic_payee_account;
    domestic_payee_account.deserialize(object);
    test_domestic_payee_account_fields(domestic_payee_account);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(domestic_payee_account.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingDomesticPayeeCard)
{
    EXTRACT_OBJECT(object, BANKING_DOMESTIC_PAYEE_CARD);
    BankingDomesticPayeeCard domestic_payee_card;
    domestic_payee_card.deserialize(object);
    test_domestic_payee_card_fields(domestic_payee_card);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(domestic_payee_card.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, DomesticPayeePayId)
{
    EXTRACT_OBJECT(object, BANKING_DOMESTIC_PAYEE_PAY_ID);
    BankingDomesticPayeePayId domestic_payee_pay_id;
    domestic_payee_pay_id.deserialize(object);
    test_domestic_payee_pay_id_fields(domestic_payee_pay_id);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(domestic_payee_pay_id.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingBillerPayee)
{
    EXTRACT_OBJECT(object, BANKING_BILLER_PAYEE);
    BankingBillerPayee biller_payee;
    biller_payee.deserialize(object);
    test_biller_payee_fields(biller_payee);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(biller_payee.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingInternationalPayee)
{
    EXTRACT_OBJECT(object, BANKING_INTERNATIONAL_PAYEE);
    BankingInternationalPayee international_payee;
    international_payee.deserialize(object);
    test_international_payee_fields(international_payee);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(international_payee.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingDirectDebit)
{
    EXTRACT_OBJECT(object, BANKING_DIRECT_DEBIT);
    BankingDirectDebit direct_debit;
    direct_debit.deserialize(object);
    test_direct_debit_fields(direct_debit);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(direct_debit.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingAuthorisedEntity)
{
    EXTRACT_OBJECT(object, BANKING_AUTHORISED_ENTITY);
    BankingAuthorisedEntity authorised_entity;
    authorised_entity.deserialize(object);
    test_authorised_entity_fields(authorised_entity);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(authorised_entity.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingScheduledPayment)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT);
    BankingScheduledPayment payment;
    payment.deserialize(object);
    test_scheduled_payment_fields(payment);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(payment.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingScheduledPaymentSet)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_SET);
    BankingScheduledPaymentSet scheduled_payment_set;
    scheduled_payment_set.deserialize(object);
    test_scheduled_payment_set_fields(scheduled_payment_set);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(scheduled_payment_set.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingScheduledPaymentTo)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_TO);
    BankingScheduledPaymentTo scheduled_payment_to;
    scheduled_payment_to.deserialize(object);
    test_scheduled_payment_to_fields(scheduled_payment_to);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(scheduled_payment_to.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingScheduledPaymentFrom)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_FROM);
    BankingScheduledPaymentFrom scheduled_payment_from;
    scheduled_payment_from.deserialize(object);
    test_scheduled_payment_from_fields(scheduled_payment_from);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(scheduled_payment_from.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingScheduledPaymentRecurrence)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_RECURRENCE);
    BankingScheduledPaymentRecurrence scheduled_payment_recurrence;
    scheduled_payment_recurrence.deserialize(object);
    test_scheduled_payment_recurrence_fields(scheduled_payment_recurrence);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(scheduled_payment_recurrence.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingScheduledPaymentRecurrenceOnceOff)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_RECURRENCE_ONCE_OFF);
    BankingScheduledPaymentRecurrenceOnceOff scheduled_payment_recurrence_once_off;
    scheduled_payment_recurrence_once_off.deserialize(object);
    test_scheduled_payment_recurrence_once_off_fields(scheduled_payment_recurrence_once_off);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(scheduled_payment_recurrence_once_off.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingScheduledPaymentRecurrenceIntervalSchedule)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_RECURRENCE_INTERVAL_SCHEDULE);
    BankingScheduledPaymentRecurrenceIntervalSchedule scheduled_payment_recurrence_interval_schedule;
    scheduled_payment_recurrence_interval_schedule.deserialize(object);
    test_scheduled_payment_recurrence_interval_schedule_fields(scheduled_payment_recurrence_interval_schedule);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(scheduled_payment_recurrence_interval_schedule.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingScheduledPaymentInterval)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_INTERVAL);
    BankingScheduledPaymentInterval scheduled_payment_interval;
    scheduled_payment_interval.deserialize(object);
    test_scheduled_payment_interval_fields(scheduled_payment_interval);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(scheduled_payment_interval.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingScheduledPaymentRecurrenceLastWeekday)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_RECURRENCE_LAST_WEEKDAY);
    BankingScheduledPaymentRecurrenceLastWeekday scheduled_payment_recurrence_last_weekday;
    scheduled_payment_recurrence_last_weekday.deserialize(object);
    test_scheduled_payment_recurrence_last_weekday_fields(scheduled_payment_recurrence_last_weekday);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(scheduled_payment_recurrence_last_weekday.serialize().c_str(), expected.str().c_str());
}

TEST(TypeRoundTest, BankingScheduledPaymentRecurrenceEventBased)
{
    EXTRACT_OBJECT(object, BANKING_SCHEDULED_PAYMENT_RECURRENCE_EVENT_BASED);
    BankingScheduledPaymentRecurrenceEventBased scheduled_payment_recurrence_event_based;
    scheduled_payment_recurrence_event_based.deserialize(object);
    test_scheduled_payment_recurrence_event_based_fields(scheduled_payment_recurrence_event_based);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(scheduled_payment_recurrence_event_based.serialize().c_str(), expected.str().c_str());
}

TEST(RequestRoundTest, AccountIds)
{
    EXTRACT_OBJECT(object, REQUEST_BANKING_ACCOUNT_IDS);
    RequestAccountIds request;
    request.deserialize(object);
    EXPECT_STREQ(request.data.account_ids[0].c_str(), "string");
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(request.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingProductList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_PRODUCT_LIST);
    ResponseBankingProductList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.products.size(), 1);
    test_product_v2_fields(response.data.products[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingProductById)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_PRODUCT_BY_ID);
    ResponseBankingProductById response;
    response.deserialize(object);
    test_product_detail_fields(response.data);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingAccountList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_ACCOUNT_LIST);
    ResponseBankingAccountList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.accounts.size(), 1);
    test_account_fields(response.data.accounts[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingAccountById)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_ACCOUNT_BY_ID);
    ResponseBankingAccountById response;
    response.deserialize(object);
    test_account_detail_fields(response.data);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingTransactionList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_TRANSACTION_LIST);
    ResponseBankingTransactionList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.transactions.size(), 1);
    test_transaction_fields(response.data.transactions[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingTransactionById)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_TRANSACTION_BY_ID);
    ResponseBankingTransactionById response;
    response.deserialize(object);
    test_transaction_detail_fields(response.data);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingAccountsBalanceList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_ACCOUNTS_BALANCE_LIST);
    ResponseBankingAccountsBalanceList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.balances.size(), 1);
    test_balance_fields(response.data.balances[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingAccountsBalanceById)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_ACCOUNTS_BALANCE_BY_ID);
    ResponseBankingAccountsBalanceById response;
    response.deserialize(object);
    test_balance_fields(response.data);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingPayeeList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_PAYEE_LIST);
    ResponseBankingPayeeList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.payees.size(), 1);
    test_payee_fields(response.data.payees[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingPayeeById)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_PAYEE_BY_ID);
    ResponseBankingPayeeById response;
    response.deserialize(object);
    test_payee_detail_fields(response.data);
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingDirectDebitAuthorisationList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_DIRECT_DEBIT_AUTHORISATION_LIST);
    ResponseBankingDirectDebitAuthorisationList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.direct_debit_authorisations.size(), 1);
    test_direct_debit_fields(response.data.direct_debit_authorisations[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}

TEST(ResponseRoundTest, BankingScheduledPaymentsList)
{
    EXTRACT_OBJECT(object, RESPONSE_BANKING_SCHEDULED_PAYMENTS_LIST);
    ResponseBankingScheduledPaymentsList response;
    response.deserialize(object);
    EXPECT_EQ(response.data.scheduled_payments.size(), 1);
    test_scheduled_payment_fields(response.data.scheduled_payments[0]);
    test_paginated_links_fields(response.links);
    test_paginated_meta_fields(response.meta.value());
    std::ostringstream expected;
    object->stringify(expected);
    EXPECT_STREQ(response.serialize().c_str(), expected.str().c_str());
}
