#include "v1/types.hpp"
#include "v1/requests.hpp"
#include "v1/responses.hpp"
#include "types.hpp"
#include "Poco/JSON/Parser.h"
#include "gtest/gtest.h"
#include "requests.hpp"
#include "responses.hpp"

static Poco::JSON::Parser parser;
static Poco::JSON::Object::Ptr object;

#define EXTRACT_OBJECT(obj, str) obj = parser.parse(str).extract<Poco::JSON::Object::Ptr>()

void test_product_v2_fields(const BankingProductV2 &product)
{
    EXPECT_STREQ(product.product_id.c_str(), "string");
    EXPECT_STREQ(product.effective_from->c_str(), "string");
    EXPECT_STREQ(product.effective_to->c_str(), "string");
    EXPECT_STREQ(product.last_updated.c_str(), "string");
    EXPECT_EQ(product.product_category, static_cast<ProductCategory>(0));
    EXPECT_STREQ(product.name.c_str(), "string");
    EXPECT_STREQ(product.description.c_str(), "string");
    EXPECT_STREQ(product.brand_name->c_str(), "string");
    EXPECT_STREQ(product.application_uri->c_str(), "string");
    EXPECT_EQ(product.is_tailored, true);
    auto additional_information = product.additional_information;
    EXPECT_STREQ(additional_information->overview_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->terms_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->eligibility_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->fees_and_pricing_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->bundle_uri->c_str(), "string");
    EXPECT_STREQ(product.card_art.value()[0].title->c_str(), "string");
    EXPECT_STREQ(product.card_art.value()[0].image_uri.c_str(), "string");
}

void test_product_bundle_fields(const BankingProductBundle &bundle)
{
    EXPECT_STREQ(bundle.name.c_str(), "string");
    EXPECT_STREQ(bundle.description.c_str(), "string");
    EXPECT_STREQ(bundle.additional_info->c_str(), "string");
    EXPECT_STREQ(bundle.additional_info_uri->c_str(), "string");
    EXPECT_STREQ(bundle.product_ids.value()[0].c_str(), "string");
}

void test_product_feature_fields(const BankingProductFeature &feature)
{
    EXPECT_EQ(feature.feature_type, static_cast<FeatureType>(0));
    EXPECT_STREQ(feature.additional_value->c_str(), "string");
    EXPECT_STREQ(feature.additional_info->c_str(), "string");
    EXPECT_STREQ(feature.additional_info_uri->c_str(), "string");
}

void test_product_constraint_fields(const BankingProductConstraint &constraint)
{
    EXPECT_EQ(constraint.constraint_type, static_cast<ConstraintType>(0));
    EXPECT_STREQ(constraint.additional_value->c_str(), "string");
    EXPECT_STREQ(constraint.additional_info->c_str(), "string");
    EXPECT_STREQ(constraint.additional_info_uri->c_str(), "string");
}

void test_product_eligibility_fields(const BankingProductEligibility &eligibility)
{
    EXPECT_EQ(eligibility.eligibility_type, static_cast<EligibilityType>(0));
    EXPECT_STREQ(eligibility.additional_value->c_str(), "string");
    EXPECT_STREQ(eligibility.additional_info->c_str(), "string");
    EXPECT_STREQ(eligibility.additional_info_uri->c_str(), "string");
}

void test_product_discount_eligibility_fields(const BankingProductDiscountEligibility &eligibility)
{
    EXPECT_EQ(eligibility.discount_eligibility_type, static_cast<DiscountEligibilityType>(0));
    EXPECT_STREQ(eligibility.additional_value->c_str(), "string");
    EXPECT_STREQ(eligibility.additional_info->c_str(), "string");
    EXPECT_STREQ(eligibility.additional_info_uri->c_str(), "string");
}

void test_product_discount_fields(const BankingProductDiscount &discount)
{
    EXPECT_STREQ(discount.description.c_str(), "string");
    EXPECT_STREQ(discount.description.c_str(), "string");
    EXPECT_EQ(discount.discount_type, static_cast<DiscountType>(0));
    EXPECT_STREQ(discount.amount->c_str(), "string");
    EXPECT_STREQ(discount.balance_rate->c_str(), "string");
    EXPECT_STREQ(discount.transaction_rate->c_str(), "string");
    EXPECT_STREQ(discount.accrued_rate->c_str(), "string");
    EXPECT_STREQ(discount.fee_rate->c_str(), "string");
    EXPECT_STREQ(discount.additional_value->c_str(), "string");
    EXPECT_STREQ(discount.additional_info->c_str(), "string");
    EXPECT_STREQ(discount.additional_info_uri->c_str(), "string");
    EXPECT_EQ(discount.eligibility.value().size(), 1);
    test_product_discount_eligibility_fields(discount.eligibility.value()[0]);
}

void test_product_fee_fields(const BankingProductFee &fee)
{
    EXPECT_STREQ(fee.name.c_str(), "string");
    EXPECT_EQ(fee.fee_type, static_cast<FeeType>(0));
    EXPECT_STREQ(fee.amount->c_str(), "string");
    EXPECT_STREQ(fee.balance_rate->c_str(), "string");
    EXPECT_STREQ(fee.transaction_rate->c_str(), "string");
    EXPECT_STREQ(fee.accrued_rate->c_str(), "string");
    EXPECT_STREQ(fee.accrual_frequency->c_str(), "string");
    EXPECT_STREQ(fee.currency->c_str(), "string");
    EXPECT_STREQ(fee.additional_value->c_str(), "string");
    EXPECT_STREQ(fee.additional_info->c_str(), "string");
    EXPECT_STREQ(fee.additional_info_uri->c_str(), "string");
    EXPECT_EQ(fee.discounts.value().size(), 1);
    test_product_discount_fields(fee.discounts.value()[0]);
}

void test_product_rate_sub_tier_fields(const BankingProductRateSubTier &tier)
{
    EXPECT_STREQ(tier.name.c_str(), "string");
    EXPECT_STREQ(tier.name.c_str(), "string");
    EXPECT_EQ(tier.unit_of_measure, static_cast<UnitOfMeasure>(0));
    EXPECT_EQ(tier.minimum_value, 0);
    EXPECT_EQ(tier.maximum_value, 0);
    EXPECT_EQ(tier.rate_application_method, static_cast<RateApplicationMethod>(0));
    EXPECT_STREQ(tier.applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(tier.applicability_conditions->additional_info_uri->c_str(), "string");
}

void test_product_rate_tier_fields(const BankingProductRateTier &tier)
{
    EXPECT_STREQ(tier.name.c_str(), "string");
    EXPECT_EQ(tier.unit_of_measure, static_cast<UnitOfMeasure>(0));
    EXPECT_EQ(tier.minimum_value, 0);
    EXPECT_EQ(tier.maximum_value, 0);
    EXPECT_EQ(tier.rate_application_method, static_cast<RateApplicationMethod>(0));
    EXPECT_STREQ(tier.applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(tier.applicability_conditions->additional_info_uri->c_str(), "string");
    test_product_rate_sub_tier_fields(tier.sub_tier.value());
}

void test_product_deposit_rate_fields(const BankingProductDepositRate &rate)
{
    EXPECT_EQ(rate.deposit_rate_type, static_cast<DepositRateType>(0));
    EXPECT_STREQ(rate.rate.c_str(), "string");
    EXPECT_STREQ(rate.calculation_frequency->c_str(), "string");
    EXPECT_STREQ(rate.application_frequency->c_str(), "string");
    EXPECT_EQ(rate.tiers.value().size(), 1);
    test_product_rate_tier_fields(rate.tiers.value()[0]);
    EXPECT_STREQ(rate.additional_value->c_str(), "string");
    EXPECT_STREQ(rate.additional_info->c_str(), "string");
    EXPECT_STREQ(rate.additional_info_uri->c_str(), "string");
}

void test_product_lending_rate_fields(const BankingProductLendingRate &rate)
{
    EXPECT_EQ(rate.lending_rate_type, static_cast<LendingRateType>(0));
    EXPECT_STREQ(rate.rate.c_str(), "string");
    EXPECT_STREQ(rate.comparison_rate->c_str(), "string");
    EXPECT_STREQ(rate.calculation_frequency->c_str(), "string");
    EXPECT_STREQ(rate.application_frequency->c_str(), "string");
    EXPECT_EQ(rate.interest_payment_due, static_cast<InterestPaymentDue>(0));
    EXPECT_EQ(rate.tiers.value().size(), 1);
    test_product_rate_tier_fields(rate.tiers.value()[0]);
    EXPECT_STREQ(rate.additional_value->c_str(), "string");
    EXPECT_STREQ(rate.additional_info->c_str(), "string");
    EXPECT_STREQ(rate.additional_info_uri->c_str(), "string");
}

void test_product_rate_condition_fields(const BankingProductRateCondition &condition)
{
    EXPECT_STREQ(condition.additional_info->c_str(), "string");
    EXPECT_STREQ(condition.additional_info_uri->c_str(), "string");
}

void test_product_detail_fields(const BankingProductDetail &detail)
{
    test_product_v2_fields(detail.product.value());
    EXPECT_EQ(detail.bundles.value().size(), 1);
    test_product_bundle_fields(detail.bundles.value()[0]);
    EXPECT_EQ(detail.features.value().size(), 1);
    test_product_feature_fields(detail.features.value()[0]);
    EXPECT_EQ(detail.constraints.value().size(), 1);
    test_product_constraint_fields(detail.constraints.value()[0]);
    EXPECT_EQ(detail.eligibility.value().size(), 1);
    test_product_eligibility_fields(detail.eligibility.value()[0]);
    EXPECT_EQ(detail.fees.value().size(), 1);
    test_product_fee_fields(detail.fees.value()[0]);
    EXPECT_EQ(detail.deposit_rates.value().size(), 1);
    test_product_deposit_rate_fields(detail.deposit_rates.value()[0]);
    EXPECT_EQ(detail.lending_rates.value().size(), 1);
    test_product_lending_rate_fields(detail.lending_rates.value()[0]);
}

void test_account_fields(const BankingAccount &account)
{
    EXPECT_STREQ(account.account_id.c_str(), "string");
    EXPECT_STREQ(account.creation_date->c_str(), "string");
    EXPECT_STREQ(account.display_name.c_str(), "string");
    EXPECT_STREQ(account.nickname->c_str(), "string");
    EXPECT_EQ(account.is_owned, true);
    EXPECT_STREQ(account.masked_number.c_str(), "string");
    EXPECT_EQ(account.product_category, static_cast<ProductCategory>(0));
    EXPECT_STREQ(account.product_name.c_str(), "string");
}

void test_term_deposit_account_fields(const BankingTermDepositAccount &account)
{
    EXPECT_STREQ(account.lodgement_date.c_str(), "string");
    EXPECT_STREQ(account.maturity_date.c_str(), "string");
    EXPECT_STREQ(account.maturity_amount->c_str(), "string");
    EXPECT_STREQ(account.maturity_currency->c_str(), "string");
    EXPECT_EQ(account.maturity_instructions, static_cast<MaturityInstructions>(0));
}

void test_credit_card_account_fields(const BankingCreditCardAccount &account)
{
    EXPECT_STREQ(account.min_payment_amount.c_str(), "string");
    EXPECT_STREQ(account.payment_due_amount.c_str(), "string");
    EXPECT_STREQ(account.payment_currency->c_str(), "string");
    EXPECT_STREQ(account.payment_due_date.c_str(), "string");
}

void test_loan_account_fields(const BankingLoanAccount &account)
{
    EXPECT_STREQ(account.original_start_date->c_str(), "string");
    EXPECT_STREQ(account.original_loan_amount->c_str(), "string");
    EXPECT_STREQ(account.original_loan_currency->c_str(), "string");
    EXPECT_STREQ(account.loan_end_date.c_str(), "string");
    EXPECT_STREQ(account.next_instalment_date.c_str(), "string");
    EXPECT_STREQ(account.min_instalment_amount->c_str(), "string");
    EXPECT_STREQ(account.min_instalment_currency->c_str(), "string");
    EXPECT_STREQ(account.max_redraw->c_str(), "string");
    EXPECT_STREQ(account.max_redraw_currency->c_str(), "string");
    EXPECT_STREQ(account.min_redraw->c_str(), "string");
    EXPECT_STREQ(account.min_redraw_currency->c_str(), "string");
    EXPECT_EQ(account.offset_account_enabled, true);
    EXPECT_STREQ(account.offset_account_ids.value()[0].c_str(), "string");
    EXPECT_EQ(account.repayment_type, static_cast<RepaymentType>(0));
    EXPECT_STREQ(account.repayment_frequency.c_str(), "string");
}

void test_transaction_fields(const BankingTransaction &transaction)
{
    EXPECT_STREQ(transaction.account_id.c_str(), "string");
    EXPECT_STREQ(transaction.transaction_id->c_str(), "string");
    EXPECT_EQ(transaction.is_detail_available, true);
    EXPECT_EQ(transaction.type, static_cast<TransactionType>(0));
    EXPECT_EQ(transaction.status, static_cast<TransactionStatus>(0));
    EXPECT_STREQ(transaction.description.c_str(), "string");
    EXPECT_STREQ(transaction.posting_date_time->c_str(), "string");
    EXPECT_STREQ(transaction.value_date_time->c_str(), "string");
    EXPECT_STREQ(transaction.execution_date_time->c_str(), "string");
    EXPECT_STREQ(transaction.amount.c_str(), "string");
    EXPECT_STREQ(transaction.currency->c_str(), "string");
    EXPECT_STREQ(transaction.reference.c_str(), "string");
    EXPECT_STREQ(transaction.merchant_name->c_str(), "string");
    EXPECT_STREQ(transaction.merchant_category_code->c_str(), "string");
    EXPECT_STREQ(transaction.biller_code->c_str(), "string");
    EXPECT_STREQ(transaction.biller_name->c_str(), "string");
    EXPECT_STREQ(transaction.crn->c_str(), "string");
    EXPECT_STREQ(transaction.apca_number->c_str(), "string");
}

void test_transaction_detail_fields(const BankingTransactionDetail &detail)
{
    test_transaction_fields(detail.transaction.value());
    EXPECT_STREQ(detail.extended_data.payer->c_str(), "string");
    EXPECT_STREQ(detail.extended_data.payee->c_str(), "string");
    EXPECT_EQ(detail.extended_data.extension_u_type, static_cast<ExtensionUType>(0));
    EXPECT_STREQ(detail.extended_data.x2p101_payload->extended_description.c_str(), "string");
    EXPECT_STREQ(detail.extended_data.x2p101_payload->end_to_end_id->c_str(), "string");
    EXPECT_STREQ(detail.extended_data.x2p101_payload->purpose_code->c_str(), "string");
    EXPECT_EQ(detail.extended_data.service, static_cast<TransactionOverlayService>(0));
}

void test_account_detail_fields(const BankingAccountDetail &detail)
{
    EXPECT_STREQ(detail.bsb->c_str(), "string");
    EXPECT_STREQ(detail.account_number->c_str(), "string");
    EXPECT_STREQ(detail.bundle_name->c_str(), "string");
    EXPECT_EQ(detail.specific_account_u_type, static_cast<SpecificAccountUType>(0));
    EXPECT_EQ(detail.term_deposit.value().size(), 1);
    test_term_deposit_account_fields(detail.term_deposit.value()[0]);
    test_credit_card_account_fields(detail.credit_card.value());
    test_loan_account_fields(detail.loan.value());
    EXPECT_STREQ(detail.deposit_rate->c_str(), "string");
    EXPECT_STREQ(detail.lending_rate->c_str(), "string");
    EXPECT_EQ(detail.deposit_rates.value().size(), 1);
    test_product_deposit_rate_fields(detail.deposit_rates.value()[0]);
    EXPECT_EQ(detail.lending_rates.value().size(), 1);
    test_product_lending_rate_fields(detail.lending_rates.value()[0]);
    EXPECT_EQ(detail.features.value().size(), 1);
//    test_product_feature_fields(detail.features.value()[0]); FIXME
    EXPECT_EQ(detail.fees.value().size(), 1);
    test_product_fee_fields(detail.fees.value()[0]);
}

void test_balance_purse_fields(const BankingBalancePurse &purse)
{
    EXPECT_STREQ(purse.amount.c_str(), "string");
    EXPECT_STREQ(purse.currency->c_str(), "string");
}

void test_balance_fields(const BankingBalance &balance)
{
    EXPECT_STREQ(balance.account_id.c_str(), "string");
    EXPECT_STREQ(balance.current_balance.c_str(), "string");
    EXPECT_STREQ(balance.available_balance.c_str(), "string");
    EXPECT_STREQ(balance.credit_limit->c_str(), "string");
    EXPECT_STREQ(balance.amortised_limit->c_str(), "string");
    EXPECT_STREQ(balance.currency->c_str(), "string");
    EXPECT_EQ(balance.purses.value().size(), 1);
    test_balance_purse_fields(balance.purses.value()[0]);
}

void test_payee_fields(const BankingPayee &payee)
{
    EXPECT_STREQ(payee.payee_id.c_str(), "string");
    EXPECT_STREQ(payee.nickname.c_str(), "string");
    EXPECT_STREQ(payee.description->c_str(), "string");
    EXPECT_EQ(payee.type, static_cast<PayeeType>(0));
    EXPECT_STREQ(payee.creation_date->c_str(), "string");
}

void test_domestic_payee_account_fields(const BankingDomesticPayeeAccount &account)
{
    EXPECT_STREQ(account.account_name->c_str(), "string");
    EXPECT_STREQ(account.bsb.c_str(), "string");
    EXPECT_STREQ(account.account_number.c_str(), "string");
}

void test_domestic_payee_card_fields(const BankingDomesticPayeeCard &card)
{
    EXPECT_STREQ(card.card_number.c_str(), "string");
}

void test_domestic_payee_pay_id_fields(const BankingDomesticPayeePayId &pay_id)
{
    EXPECT_STREQ(pay_id.name->c_str(), "string");
    EXPECT_STREQ(pay_id.identifier.c_str(), "string");
    EXPECT_EQ(pay_id.type, PayIdType::EMAIL);
}

void test_domestic_payee_fields(const BankingDomesticPayee &payee)
{
    EXPECT_EQ(payee.payee_account_u_type, static_cast<PayeeAccountUType>(0));
    test_domestic_payee_account_fields(payee.account.value());
    test_domestic_payee_card_fields(payee.card.value());
    test_domestic_payee_pay_id_fields(payee.pay_id.value());
}

void test_biller_payee_fields(const BankingBillerPayee &payee)
{
    EXPECT_STREQ(payee.biller_code.c_str(), "string");
    EXPECT_STREQ(payee.crn->c_str(), "string");
    EXPECT_STREQ(payee.biller_name.c_str(), "string");
}

void test_international_payee_fields(const BankingInternationalPayee &payee)
{
    EXPECT_STREQ(payee.beneficiary_details.name->c_str(), "string");
    EXPECT_STREQ(payee.beneficiary_details.country.c_str(), "string");
    EXPECT_STREQ(payee.beneficiary_details.message->c_str(), "string");
    EXPECT_STREQ(payee.bank_details.country.c_str(), "string");
    EXPECT_STREQ(payee.bank_details.bank_address.name.c_str(), "string");
    EXPECT_STREQ(payee.bank_details.bank_address.address.c_str(), "string");
    EXPECT_STREQ(payee.bank_details.beneficiary_bank_bic->c_str(), "string");
    EXPECT_STREQ(payee.bank_details.fed_wire_number->c_str(), "string");
    EXPECT_STREQ(payee.bank_details.sort_code->c_str(), "string");
    EXPECT_STREQ(payee.bank_details.chip_number->c_str(), "string");
    EXPECT_STREQ(payee.bank_details.routing_number->c_str(), "string");
    EXPECT_STREQ(payee.bank_details.legal_entity_identifier->c_str(), "string");
}

void test_payee_detail_fields(const BankingPayeeDetail &detail)
{
    test_payee_fields(detail.payee.value());
    EXPECT_EQ(detail.payee_u_type, static_cast<PayeeUType>(0));
    EXPECT_EQ(detail.domestic->payee_account_u_type, static_cast<PayeeAccountUType>(0));
    test_domestic_payee_fields(detail.domestic.value());
    test_biller_payee_fields(detail.biller.value());
    test_international_payee_fields(detail.international.value());
}

void test_authorised_entity_fields(const BankingAuthorisedEntity &entity)
{
    EXPECT_STREQ(entity.description->c_str(), "string");
    EXPECT_STREQ(entity.financial_institution->c_str(), "string");
    EXPECT_STREQ(entity.abn->c_str(), "string");
    EXPECT_STREQ(entity.acn->c_str(), "string");
    EXPECT_STREQ(entity.arbn->c_str(), "string");
}

void test_direct_debit_fields(const BankingDirectDebit &direct_debit)
{
    EXPECT_STREQ(direct_debit.account_id.c_str(), "string");
    test_authorised_entity_fields(direct_debit.authorised_entity);
    EXPECT_STREQ(direct_debit.last_debit_date_time->c_str(), "string");
    EXPECT_STREQ(direct_debit.last_debit_amount->c_str(), "string");
}

void test_scheduled_payment_from_fields(const BankingScheduledPaymentFrom &from)
{
    EXPECT_STREQ(from.account_id.c_str(), "string");
}

void test_scheduled_payment_to_fields(const BankingScheduledPaymentTo &to)
{
    EXPECT_EQ(to.to_u_type, ToUType::ACCOUNT_ID);
    EXPECT_STREQ(to.account_id->c_str(), "string");
    EXPECT_STREQ(to.payee_id->c_str(), "string");
    test_domestic_payee_fields(to.domestic.value());
    test_biller_payee_fields(to.biller.value());
    test_international_payee_fields(to.international.value());
}

void test_scheduled_payment_set_fields(const BankingScheduledPaymentSet &set)
{
    test_scheduled_payment_to_fields(set.to);
    EXPECT_EQ(set.is_amount_calculated, true);
    EXPECT_STREQ(set.amount->c_str(), "string");
    EXPECT_STREQ(set.currency->c_str(), "string");
}

void test_scheduled_payment_interval_fields(const BankingScheduledPaymentInterval &interval)
{
    EXPECT_STREQ(interval.interval.c_str(), "string");
    EXPECT_STREQ(interval.day_in_interval->c_str(), "string");
}

void test_scheduled_payment_recurrence_once_off_fields(const BankingScheduledPaymentRecurrenceOnceOff &once_off)
{
    EXPECT_STREQ(once_off.payment_date.c_str(), "string");
}

void test_scheduled_payment_recurrence_last_weekday_fields(const BankingScheduledPaymentRecurrenceLastWeekday &interval)
{
    EXPECT_STREQ(interval.final_payment_date->c_str(), "string");
    EXPECT_EQ(interval.payments_remaining, 0);
    EXPECT_STREQ(interval.interval.c_str(), "string");
    EXPECT_EQ(interval.last_week_day, LastWeekDay::MON);
    EXPECT_EQ(interval.non_business_day_treatment, NonBusinessDayTreatment::ON);
}

void test_scheduled_payment_recurrence_interval_schedule_fields(
        const BankingScheduledPaymentRecurrenceIntervalSchedule &interval)
{
    EXPECT_STREQ(interval.final_payment_date->c_str(), "string");
    EXPECT_EQ(interval.payments_remaining, 0);
    EXPECT_EQ(interval.non_business_day_treatment, NonBusinessDayTreatment::ON);
    EXPECT_EQ(interval.intervals.size(), 1);
    test_scheduled_payment_interval_fields(interval.intervals[0]);
}

void test_scheduled_payment_recurrence_event_based_fields(const BankingScheduledPaymentRecurrenceEventBased &event)
{
    EXPECT_STREQ(event.description.c_str(), "string");
}

void test_scheduled_payment_recurrence_fields(const BankingScheduledPaymentRecurrence &recurrence)
{
    EXPECT_STREQ(recurrence.next_payment_date->c_str(), "string");
    EXPECT_EQ(recurrence.recurrence_u_type, RecurrenceUType::ONCE_OFF);
    test_scheduled_payment_recurrence_once_off_fields(recurrence.once_off.value());
    test_scheduled_payment_recurrence_interval_schedule_fields(recurrence.interval_schedule.value());
    test_scheduled_payment_recurrence_last_weekday_fields(recurrence.last_week_day.value());
    test_scheduled_payment_recurrence_event_based_fields(recurrence.event_based.value());
}

void test_scheduled_payment_fields(const BankingScheduledPayment &payment)
{
    EXPECT_STREQ(payment.scheduled_payment_id.c_str(), "string");
    EXPECT_STREQ(payment.nickname->c_str(), "string");
    EXPECT_STREQ(payment.payer_reference.c_str(), "string");
    EXPECT_STREQ(payment.payee_reference.c_str(), "string");
    EXPECT_EQ(payment.status, static_cast<ScheduledPaymentStatus>(0));
    EXPECT_EQ(payment.payment_set.size(), 1);
    test_scheduled_payment_from_fields(payment.from);
    test_scheduled_payment_set_fields(payment.payment_set[0]);
    test_scheduled_payment_recurrence_fields(payment.recurrence);
}

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
    object = parser.parse(BANKING_ACCOUNT_DETAIL).extract<Poco::JSON::Object::Ptr>();
    BankingAccountDetail account_detail;
    account_detail.deserialize(object);


    auto deposit_rate = account_detail.deposit_rates.value()[0];
    EXPECT_EQ(deposit_rate.deposit_rate_type, DepositRateType::FIXED);
    EXPECT_STREQ(deposit_rate.rate.c_str(), "string");
    EXPECT_STREQ(deposit_rate.calculation_frequency->c_str(), "string");
    EXPECT_STREQ(deposit_rate.application_frequency->c_str(), "string");
    auto deposit_rate_tier = deposit_rate.tiers.value()[0];
    EXPECT_STREQ(deposit_rate_tier.name.c_str(), "string");
    EXPECT_EQ(deposit_rate_tier.unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(deposit_rate_tier.minimum_value, 0);
    EXPECT_EQ(deposit_rate_tier.minimum_value, 0);
    EXPECT_STREQ(deposit_rate_tier.applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(deposit_rate_tier.applicability_conditions->additional_info_uri->c_str(), "string");
    EXPECT_STREQ(deposit_rate_tier.sub_tier->name.c_str(), "string");
    EXPECT_EQ(deposit_rate_tier.sub_tier->unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(deposit_rate_tier.sub_tier->minimum_value, 0);
    EXPECT_EQ(deposit_rate_tier.sub_tier->maximum_value, 0);
    EXPECT_EQ(deposit_rate_tier.sub_tier->rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(deposit_rate_tier.sub_tier->applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(deposit_rate_tier.sub_tier->applicability_conditions->additional_info_uri->c_str(), "string");
    EXPECT_STREQ(deposit_rate.additional_value->c_str(), "string");
    EXPECT_STREQ(deposit_rate.additional_info->c_str(), "string");
    EXPECT_STREQ(deposit_rate.additional_info_uri->c_str(), "string");
    auto lending_rate = account_detail.lending_rates.value()[0];
    EXPECT_EQ(lending_rate.lending_rate_type, LendingRateType::FIXED);
    EXPECT_STREQ(lending_rate.rate.c_str(), "string");
    EXPECT_STREQ(lending_rate.comparison_rate->c_str(), "string");
    EXPECT_STREQ(lending_rate.calculation_frequency->c_str(), "string");
    EXPECT_STREQ(lending_rate.application_frequency->c_str(), "string");
    EXPECT_EQ(lending_rate.interest_payment_due, InterestPaymentDue::IN_ARREARS);
    auto lending_rate_tier = lending_rate.tiers.value()[0];
    EXPECT_EQ(lending_rate_tier.unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(lending_rate_tier.minimum_value, 0);
    EXPECT_EQ(lending_rate_tier.minimum_value, 0);
    EXPECT_STREQ(lending_rate_tier.applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(lending_rate_tier.applicability_conditions->additional_info_uri->c_str(), "string");
    EXPECT_STREQ(lending_rate_tier.sub_tier->name.c_str(), "string");
    EXPECT_EQ(lending_rate_tier.sub_tier->unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(lending_rate_tier.sub_tier->minimum_value, 0);
    EXPECT_EQ(lending_rate_tier.sub_tier->maximum_value, 0);
    EXPECT_EQ(lending_rate_tier.sub_tier->rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(lending_rate_tier.sub_tier->applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(lending_rate_tier.sub_tier->applicability_conditions->additional_info_uri->c_str(), "string");
    EXPECT_STREQ(lending_rate.additional_value->c_str(), "string");
    EXPECT_STREQ(lending_rate.additional_info->c_str(), "string");
    EXPECT_STREQ(deposit_rate.additional_info_uri->c_str(), "string");
    auto feature = account_detail.features.value()[0];
    EXPECT_EQ(feature.feature_type, FeatureType::CARD_ACCESS);
    EXPECT_STREQ(feature.additional_value->c_str(), "string");
    EXPECT_STREQ(feature.additional_info->c_str(), "string");
    EXPECT_STREQ(feature.additional_info_uri->c_str(), "string");
    EXPECT_EQ(feature.is_activated, true);
    auto fee = account_detail.fees.value()[0];
    EXPECT_STREQ(fee.name.c_str(), "string");
    EXPECT_EQ(fee.fee_type, FeeType::PERIODIC);
    EXPECT_STREQ(fee.amount->c_str(), "string");
    EXPECT_STREQ(fee.balance_rate->c_str(), "string");
    EXPECT_STREQ(fee.transaction_rate->c_str(), "string");
    EXPECT_STREQ(fee.accrued_rate->c_str(), "string");
    EXPECT_STREQ(fee.accrual_frequency->c_str(), "string");
    EXPECT_STREQ(fee.currency->c_str(), "string");
    EXPECT_STREQ(fee.additional_value->c_str(), "string");
    EXPECT_STREQ(fee.additional_info->c_str(), "string");
    EXPECT_STREQ(fee.additional_info_uri->c_str(), "string");
    auto fee_discount = fee.discounts.value()[0];
    EXPECT_STREQ(fee_discount.description.c_str(), "string");
    EXPECT_STREQ(fee_discount.description.c_str(), "string");
    EXPECT_EQ(fee_discount.discount_type, DiscountType::BALANCE);
    EXPECT_STREQ(fee_discount.amount->c_str(), "string");
    EXPECT_STREQ(fee_discount.balance_rate->c_str(), "string");
    EXPECT_STREQ(fee_discount.transaction_rate->c_str(), "string");
    EXPECT_STREQ(fee_discount.accrued_rate->c_str(), "string");
    EXPECT_STREQ(fee_discount.fee_rate->c_str(), "string");
    EXPECT_STREQ(fee_discount.additional_value->c_str(), "string");
    EXPECT_STREQ(fee_discount.additional_info->c_str(), "string");
    EXPECT_STREQ(fee_discount.additional_info_uri->c_str(), "string");
    auto fee_discount_eligibility = fee_discount.eligibility.value()[0];
    EXPECT_EQ(fee_discount_eligibility.discount_eligibility_type, DiscountEligibilityType::BUSINESS);
    EXPECT_STREQ(fee_discount_eligibility.additional_value->c_str(), "string");
    EXPECT_STREQ(fee_discount_eligibility.additional_info->c_str(), "string");
    EXPECT_STREQ(fee_discount_eligibility.additional_info_uri->c_str(), "string");
    auto address = account_detail.addresses.value()[0];
    EXPECT_EQ(address.address_u_type, AddressUType::SIMPLE);
    EXPECT_STREQ(address.simple->mailing_name->c_str(), "string");
    EXPECT_STREQ(address.simple->address_line1.c_str(), "string");
    EXPECT_STREQ(address.simple->address_line2->c_str(), "string");
    EXPECT_STREQ(address.simple->address_line3->c_str(), "string");
    EXPECT_STREQ(address.simple->postcode->c_str(), "string");
    EXPECT_STREQ(address.simple->city.c_str(), "string");
    EXPECT_STREQ(address.simple->state.c_str(), "string");
    EXPECT_STREQ(address.simple->country->c_str(), "AUS");
    EXPECT_STREQ(address.paf->dpid->c_str(), "string");
    EXPECT_EQ(address.paf->thoroughfare_number1, 0);
    EXPECT_STREQ(address.paf->thoroughfare_number1_suffix->c_str(), "string");
    EXPECT_EQ(address.paf->thoroughfare_number2, 0);
    EXPECT_STREQ(address.paf->thoroughfare_number2_suffix->c_str(), "string");
    EXPECT_STREQ(address.paf->flat_unit_type->c_str(), "string");
    EXPECT_STREQ(address.paf->flat_unit_number->c_str(), "string");
    EXPECT_STREQ(address.paf->floor_level_type->c_str(), "string");
    EXPECT_STREQ(address.paf->floor_level_number->c_str(), "string");
    EXPECT_STREQ(address.paf->lot_number->c_str(), "string");
    EXPECT_STREQ(address.paf->building_name1->c_str(), "string");
    EXPECT_STREQ(address.paf->building_name2->c_str(), "string");
    EXPECT_STREQ(address.paf->street_name->c_str(), "string");
    EXPECT_STREQ(address.paf->street_type->c_str(), "string");
    EXPECT_STREQ(address.paf->street_suffix->c_str(), "string");
    EXPECT_STREQ(address.paf->postal_delivery_type->c_str(), "string");
    EXPECT_EQ(address.paf->postal_delivery_number, 0);
    EXPECT_STREQ(address.paf->postal_delivery_number_prefix->c_str(), "string");
    EXPECT_STREQ(address.paf->postal_delivery_number_suffix->c_str(), "string");
    EXPECT_STREQ(address.paf->locality_name.c_str(), "string");
    EXPECT_STREQ(address.paf->postcode.c_str(), "string");
    EXPECT_STREQ(address.paf->state.c_str(), "string");
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
    object = parser.parse(REQUEST_BANKING_ACCOUNT_IDS).extract<Poco::JSON::Object::Ptr>();
    RequestAccountIds request;
    request.deserialize(object);
    auto account_ids = static_cast<AccountIds *>(request.data.get())->ids;
    EXPECT_EQ(account_ids.size(), 1);
    EXPECT_STREQ(account_ids[0].c_str(), "string");
}

TEST(ResponseDeserialization, BankingProductList)
{
    object = parser.parse(RESPONSE_BANKING_PRODUCT_LIST).extract<Poco::JSON::Object::Ptr>();
    ResponseBankingProductList response;
    response.deserialize(object);
    auto products = static_cast<BankingProductList *>(response.data.get())->products;
    auto *links = static_cast<LinksPaginated *>(response.links.get());
    auto *meta = static_cast<MetaPaginated *>(response.meta.value().get());
    auto product = products[0];
    EXPECT_STREQ(product.product_id.c_str(), "string");
    EXPECT_STREQ(product.effective_from.value().c_str(), "string");
    EXPECT_STREQ(product.effective_to.value().c_str(), "string");
    EXPECT_STREQ(product.last_updated.c_str(), "string");
    EXPECT_EQ(product.product_category, ProductCategory::TRANS_AND_SAVINGS_ACCOUNTS);
    EXPECT_STREQ(product.name.c_str(), "string");
    EXPECT_STREQ(product.description.c_str(), "string");
    EXPECT_STREQ(product.brand.c_str(), "string");
    EXPECT_STREQ(product.brand_name.value().c_str(), "string");
    EXPECT_STREQ(product.application_uri.value().c_str(), "string");
    EXPECT_TRUE(product.is_tailored);
    auto additional_information = product.additional_information;
    EXPECT_STREQ(additional_information->overview_uri.value().c_str(), "string");
    EXPECT_STREQ(additional_information->terms_uri.value().c_str(), "string");
    EXPECT_STREQ(additional_information->eligibility_uri.value().c_str(), "string");
    EXPECT_STREQ(additional_information->fees_and_pricing_uri.value().c_str(), "string");
    EXPECT_STREQ(additional_information->bundle_uri.value().c_str(), "string");
    EXPECT_STREQ(product.card_art.value()[0].title->c_str(), "string");
    EXPECT_STREQ(product.card_art.value()[0].image_uri.c_str(), "string");
    EXPECT_STREQ(links->self.c_str(), "string");
    EXPECT_STREQ(links->first.value().c_str(), "string");
    EXPECT_STREQ(links->previous.value().c_str(), "string");
    EXPECT_STREQ(links->next.value().c_str(), "string");
    EXPECT_STREQ(links->last.value().c_str(), "string");
    EXPECT_EQ(meta->total_records, 0);
    EXPECT_EQ(meta->total_pages, 0);
}

TEST(ResponseDeserialization, BankingProductById)
{
    object = parser.parse(RESPONSE_BANKING_PRODUCT_BY_ID).extract<Poco::JSON::Object::Ptr>();
    ResponseBankingProductById response;
    response.deserialize(object);
    auto product_detail = static_cast<BankingProductById *>(response.data.get())->product_detail;
    auto *links = static_cast<Links *>(response.links.get());
    auto product = product_detail.product;
    EXPECT_STREQ(product->product_id.c_str(), "string");
    EXPECT_STREQ(product->effective_from->c_str(), "string");
    EXPECT_STREQ(product->effective_to->c_str(), "string");
    EXPECT_STREQ(product->last_updated.c_str(), "string");
    EXPECT_EQ(product->product_category, ProductCategory::TRANS_AND_SAVINGS_ACCOUNTS);
    EXPECT_STREQ(product->name.c_str(), "string");
    EXPECT_STREQ(product->description.c_str(), "string");
    EXPECT_STREQ(product->brand.c_str(), "string");
    EXPECT_STREQ(product->brand_name->c_str(), "string");
    EXPECT_STREQ(product->application_uri->c_str(), "string");
    EXPECT_TRUE(product->is_tailored);
    auto additional_information = product->additional_information;
    EXPECT_STREQ(additional_information->overview_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->terms_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->eligibility_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->fees_and_pricing_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->bundle_uri->c_str(), "string");
    EXPECT_EQ(product->card_art.value().size(), 1);
    auto card_art = product->card_art.value()[0];
    EXPECT_STREQ(card_art.title->c_str(), "string");
    EXPECT_STREQ(card_art.image_uri.c_str(), "string");
    EXPECT_EQ(product_detail.bundles.value().size(), 1);
    auto bundle = product_detail.bundles.value()[0];
    EXPECT_STREQ(bundle.name.c_str(), "string");
    EXPECT_STREQ(bundle.description.c_str(), "string");
    EXPECT_STREQ(bundle.additional_info->c_str(), "string");
    EXPECT_STREQ(bundle.additional_info_uri->c_str(), "string");
    EXPECT_EQ(bundle.product_ids.value().size(), 1);
    EXPECT_STREQ(bundle.product_ids.value()[0].c_str(), "string");
    EXPECT_EQ(product_detail.features.value().size(), 1);
    auto feature = product_detail.features.value()[0];
    EXPECT_EQ(feature.feature_type, FeatureType::CARD_ACCESS);
    EXPECT_STREQ(feature.additional_value.value().c_str(), "string");
    EXPECT_STREQ(feature.additional_info.value().c_str(), "string");
    EXPECT_STREQ(feature.additional_info_uri.value().c_str(), "string");
    EXPECT_EQ(product_detail.constraints.value().size(), 1);
    auto constraint = product_detail.constraints.value()[0];
    EXPECT_EQ(constraint.constraint_type, ConstraintType::MIN_BALANCE);
    EXPECT_STREQ(constraint.additional_value.value().c_str(), "string");
    EXPECT_STREQ(constraint.additional_info.value().c_str(), "string");
    EXPECT_STREQ(constraint.additional_info_uri.value().c_str(), "string");
    EXPECT_EQ(product_detail.fees.value().size(), 1);
    auto fee = product_detail.fees.value()[0];
    EXPECT_STREQ(fee.name.c_str(), "string");
    EXPECT_EQ(fee.fee_type, FeeType::PERIODIC);
    EXPECT_STREQ(fee.amount.value().c_str(), "string");
    EXPECT_STREQ(fee.balance_rate.value().c_str(), "string");
    EXPECT_STREQ(fee.transaction_rate.value().c_str(), "string");
    EXPECT_STREQ(fee.accrued_rate.value().c_str(), "string");
    EXPECT_STREQ(fee.accrual_frequency.value().c_str(), "string");
    EXPECT_STREQ(fee.currency.value().c_str(), "string");
    EXPECT_STREQ(fee.additional_value.value().c_str(), "string");
    EXPECT_STREQ(fee.additional_info.value().c_str(), "string");
    EXPECT_STREQ(fee.additional_info_uri.value().c_str(), "string");
    EXPECT_EQ(fee.discounts.value().size(), 1);
    auto discount = fee.discounts.value()[0];
    EXPECT_STREQ(discount.description.c_str(), "string");
    EXPECT_EQ(discount.discount_type, DiscountType::BALANCE);
    EXPECT_STREQ(discount.amount.value().c_str(), "string");
    EXPECT_STREQ(discount.balance_rate.value().c_str(), "string");
    EXPECT_STREQ(discount.transaction_rate.value().c_str(), "string");
    EXPECT_STREQ(discount.accrued_rate.value().c_str(), "string");
    EXPECT_STREQ(discount.fee_rate.value().c_str(), "string");
    EXPECT_STREQ(discount.additional_value.value().c_str(), "string");
    EXPECT_STREQ(discount.additional_info.value().c_str(), "string");
    EXPECT_STREQ(discount.additional_info_uri.value().c_str(), "string");
    EXPECT_EQ(discount.eligibility.value().size(), 1);
    auto eligibility = discount.eligibility.value()[0];
    EXPECT_EQ(eligibility.discount_eligibility_type, DiscountEligibilityType::BUSINESS);
    EXPECT_STREQ(eligibility.additional_value.value().c_str(), "string");
    EXPECT_STREQ(eligibility.additional_info.value().c_str(), "string");
    EXPECT_STREQ(eligibility.additional_info_uri.value().c_str(), "string");
    EXPECT_EQ(product_detail.deposit_rates.value().size(), 1);
    auto deposit_rate = product_detail.deposit_rates.value()[0];
    EXPECT_EQ(deposit_rate.deposit_rate_type, DepositRateType::FIXED);
    EXPECT_STREQ(deposit_rate.rate.c_str(), "string");
    EXPECT_STREQ(deposit_rate.calculation_frequency.value().c_str(), "string");
    EXPECT_STREQ(deposit_rate.application_frequency.value().c_str(), "string");
    EXPECT_EQ(deposit_rate.tiers.value().size(), 1);
    auto tier = deposit_rate.tiers.value()[0];
    EXPECT_STREQ(tier.name.c_str(), "string");
    EXPECT_EQ(tier.unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(tier.minimum_value, 0);
    EXPECT_EQ(tier.maximum_value, 0);
    EXPECT_EQ(tier.rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(tier.applicability_conditions.value().additional_info.value().c_str(), "string");
    EXPECT_STREQ(tier.applicability_conditions.value().additional_info_uri.value().c_str(), "string");
    auto sub_tier = tier.sub_tier.value();
    EXPECT_STREQ(sub_tier.name.c_str(), "string");
    EXPECT_EQ(sub_tier.unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(sub_tier.minimum_value, 0);
    EXPECT_EQ(sub_tier.maximum_value, 0);
    EXPECT_EQ(sub_tier.rate_application_method.value(), RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(sub_tier.applicability_conditions.value().additional_info.value().c_str(), "string");
    EXPECT_STREQ(sub_tier.applicability_conditions.value().additional_info_uri.value().c_str(), "string");
    EXPECT_STREQ(deposit_rate.additional_value.value().c_str(), "string");
    EXPECT_STREQ(deposit_rate.additional_info.value().c_str(), "string");
    EXPECT_STREQ(deposit_rate.additional_info_uri.value().c_str(), "string");
    EXPECT_EQ(product_detail.lending_rates.value().size(), 1);
    auto lending_rate = product_detail.lending_rates.value()[0];
    EXPECT_EQ(lending_rate.lending_rate_type, LendingRateType::FIXED);
    EXPECT_STREQ(lending_rate.rate.c_str(), "string");
    EXPECT_STREQ(lending_rate.comparison_rate.value().c_str(), "string");
    EXPECT_STREQ(lending_rate.calculation_frequency.value().c_str(), "string");
    EXPECT_STREQ(lending_rate.application_frequency.value().c_str(), "string");
    EXPECT_EQ(lending_rate.interest_payment_due.value(), InterestPaymentDue::IN_ARREARS);
    EXPECT_EQ(lending_rate.tiers.value().size(), 1);
    auto lr_tier = lending_rate.tiers.value()[0];
    EXPECT_STREQ(lr_tier.name.c_str(), "string");
    EXPECT_EQ(lr_tier.unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(lr_tier.minimum_value, 0);
    EXPECT_EQ(lr_tier.maximum_value, 0);
    EXPECT_EQ(lr_tier.rate_application_method.value(), RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(lr_tier.applicability_conditions.value().additional_info.value().c_str(), "string");
    EXPECT_STREQ(lr_tier.applicability_conditions.value().additional_info_uri.value().c_str(), "string");
    auto lr_sub_tier = lr_tier.sub_tier.value();
    EXPECT_STREQ(lr_sub_tier.name.c_str(), "string");
    EXPECT_EQ(lr_sub_tier.unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(lr_sub_tier.minimum_value, 0);
    EXPECT_EQ(lr_sub_tier.maximum_value, 0);
    EXPECT_EQ(lr_sub_tier.rate_application_method.value(), RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(lr_sub_tier.applicability_conditions.value().additional_info.value().c_str(), "string");
    EXPECT_STREQ(lr_sub_tier.applicability_conditions.value().additional_info_uri.value().c_str(), "string");
    EXPECT_STREQ(lending_rate.additional_value.value().c_str(), "string");
    EXPECT_STREQ(lending_rate.additional_info.value().c_str(), "string");
    EXPECT_STREQ(lending_rate.additional_info_uri.value().c_str(), "string");
    EXPECT_STREQ(links->self.c_str(), "string");
}

TEST(ResponseDeserialization, BankingAccountList)
{
    object = parser.parse(RESPONSE_BANKING_ACCOUNT_LIST).extract<Poco::JSON::Object::Ptr>();
    ResponseBankingAccountList response;
    response.deserialize(object);
    auto accounts = static_cast<BankingAccountList *>(response.data.get())->accounts;
    auto *links = static_cast<LinksPaginated *>(response.links.get());
    auto *meta = static_cast<MetaPaginated *>(response.meta.value().get());
    EXPECT_EQ(accounts.size(), 1);
    auto account = accounts[0];
    EXPECT_STREQ(account.account_id.c_str(), "string");
    EXPECT_STREQ(account.creation_date.value().c_str(), "string");
    EXPECT_STREQ(account.display_name.c_str(), "string");
    EXPECT_STREQ(account.nickname.value().c_str(), "string");
    EXPECT_EQ(account.open_status.value(), OpenStatus::OPEN);
    EXPECT_TRUE(account.is_owned.value());
    EXPECT_STREQ(account.masked_number.c_str(), "string");
    EXPECT_EQ(account.product_category, ProductCategory::TRANS_AND_SAVINGS_ACCOUNTS);
    EXPECT_STREQ(account.product_name.c_str(), "string");
    EXPECT_STREQ(links->self.c_str(), "string");
    EXPECT_STREQ(links->first.value().c_str(), "string");
    EXPECT_STREQ(links->previous.value().c_str(), "string");
    EXPECT_STREQ(links->next.value().c_str(), "string");
    EXPECT_STREQ(links->last.value().c_str(), "string");
    EXPECT_EQ(meta->total_records, 0);
    EXPECT_EQ(meta->total_pages, 0);
}

TEST(ResponseDeserialization, BankingAccountById)
{
}

TEST(ResponseDeserialization, BankingTransactionList)
{
}

TEST(ResponseDeserialization, BankingTransactionById)
{
}

TEST(ResponseDeserialization, BankingAccountsBalanceList)
{
}

TEST(ResponseDeserialization, BankingAccountsBalanceById)
{
}

TEST(ResponseDeserialization, BankingPayeeList)
{
}

TEST(ResponseDeserialization, BankingPayeeById)
{
}

TEST(ResponseDeserialization, BankingDirectDebitAuthorisationList)
{
}

TEST(ResponseDeserialization, BankingScheduledPaymentsList)
{
}
