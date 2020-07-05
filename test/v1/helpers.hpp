#ifndef REGIME_V1_TEST_HELPERS_HPP
#define REGIME_V1_TEST_HELPERS_HPP

#include "v1/types.hpp"
#include "v1/requests.hpp"
#include "v1/responses.hpp"
#include "types.hpp"
#include "Poco/JSON/Parser.h"
#include "gtest/gtest.h"
#include "requests.hpp"
#include "responses.hpp"

namespace regime::v1::test
{
    void test_product_v2_fields(const BankingProductV2 &product);

    void test_product_bundle_fields(const BankingProductBundle &bundle);

    void test_product_feature_fields(const BankingProductFeature &feature);

    void test_product_feature_toggled_fields(const BankingProductFeatureToggled &feature);

    void test_product_constraint_fields(const BankingProductConstraint &constraint);

    void test_product_eligibility_fields(const BankingProductEligibility &eligibility);

    void test_product_discount_eligibility_fields(const BankingProductDiscountEligibility &eligibility);

    void test_product_discount_fields(const BankingProductDiscount &discount);

    void test_product_fee_fields(const BankingProductFee &fee);

    void test_product_rate_sub_tier_fields(const BankingProductRateSubTier &tier);

    void test_product_rate_tier_fields(const BankingProductRateTier &tier);

    void test_product_deposit_rate_fields(const BankingProductDepositRate &rate);

    void test_product_lending_rate_fields(const BankingProductLendingRate &rate);

    void test_product_rate_condition_fields(const BankingProductRateCondition &condition);

    void test_product_detail_fields(const BankingProductDetail &detail);

    void test_account_fields(const BankingAccount &account);

    void test_term_deposit_account_fields(const BankingTermDepositAccount &account);

    void test_credit_card_account_fields(const BankingCreditCardAccount &account);

    void test_loan_account_fields(const BankingLoanAccount &account);

    void test_transaction_fields(const BankingTransaction &transaction);

    void test_transaction_detail_fields(const BankingTransactionDetail &detail);

    void test_account_detail_fields(const BankingAccountDetail &detail);

    void test_balance_purse_fields(const BankingBalancePurse &purse);

    void test_balance_fields(const BankingBalance &balance);

    void test_payee_fields(const BankingPayee &payee);

    void test_domestic_payee_account_fields(const BankingDomesticPayeeAccount &account);

    void test_domestic_payee_card_fields(const BankingDomesticPayeeCard &card);

    void test_domestic_payee_pay_id_fields(const BankingDomesticPayeePayId &pay_id);

    void test_domestic_payee_fields(const BankingDomesticPayee &payee);

    void test_biller_payee_fields(const BankingBillerPayee &payee);

    void test_international_payee_fields(const BankingInternationalPayee &payee);

    void test_payee_detail_fields(const BankingPayeeDetail &detail);

    void test_authorised_entity_fields(const BankingAuthorisedEntity &entity);

    void test_direct_debit_fields(const BankingDirectDebit &direct_debit);

    void test_scheduled_payment_from_fields(const BankingScheduledPaymentFrom &from);

    void test_scheduled_payment_to_fields(const BankingScheduledPaymentTo &to);

    void test_scheduled_payment_set_fields(const BankingScheduledPaymentSet &set);

    void test_scheduled_payment_interval_fields(const BankingScheduledPaymentInterval &interval);

    void test_scheduled_payment_recurrence_once_off_fields(const BankingScheduledPaymentRecurrenceOnceOff &once_off);

    void
    test_scheduled_payment_recurrence_last_weekday_fields(const BankingScheduledPaymentRecurrenceLastWeekday &interval);

    void test_scheduled_payment_recurrence_interval_schedule_fields(
            const BankingScheduledPaymentRecurrenceIntervalSchedule &interval);

    void test_scheduled_payment_recurrence_event_based_fields(const BankingScheduledPaymentRecurrenceEventBased &event);

    void test_scheduled_payment_recurrence_fields(const BankingScheduledPaymentRecurrence &recurrence);

    void test_scheduled_payment_fields(const BankingScheduledPayment &payment);

    void test_paginated_links_fields(const LinksPaginated &links);

    void test_paginated_meta_fields(const MetaPaginated &meta);
}


#endif //REGIME_V1_TEST_HELPERS_HPP
