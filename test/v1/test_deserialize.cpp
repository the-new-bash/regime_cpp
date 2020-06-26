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

TEST(TypeDeserialization, BankingProductV2)
{
    object = parser.parse(BANKING_PRODUCT_V2).extract<Poco::JSON::Object::Ptr>();
    BankingProductV2 product;
    product.deserialize(object);
    EXPECT_STREQ(product.product_id.c_str(), "string");
    EXPECT_STREQ(product.effective_from->c_str(), "string");
    EXPECT_STREQ(product.effective_to->c_str(), "string");
    EXPECT_STREQ(product.last_updated.c_str(), "string");
    EXPECT_EQ(product.product_category, ProductCategory::TRANS_AND_SAVINGS_ACCOUNTS);
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

TEST(TypeDeserialization, BankingProductDetail)
{
    object = parser.parse(BANKING_PRODUCT_DETAIL).extract<Poco::JSON::Object::Ptr>();
    BankingProductDetail product_detail;
    product_detail.deserialize(object);
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
    EXPECT_EQ(product->is_tailored, true);
    auto additional_information = product->additional_information;
    EXPECT_STREQ(additional_information->overview_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->terms_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->eligibility_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->fees_and_pricing_uri->c_str(), "string");
    EXPECT_STREQ(additional_information->bundle_uri->c_str(), "string");
    EXPECT_STREQ(product->card_art.value()[0].title->c_str(), "string");
    EXPECT_STREQ(product->card_art.value()[0].image_uri.c_str(), "string");
    EXPECT_STREQ(product_detail.bundles.value()[0].name.c_str(), "string");
}

TEST(TypeDeserialization, BankingProductBundle)
{
    object = parser.parse(BANKING_PRODUCT_BUNDLE).extract<Poco::JSON::Object::Ptr>();
    BankingProductBundle product_bundle;
    product_bundle.deserialize(object);
    EXPECT_STREQ(product_bundle.name.c_str(), "string");
    EXPECT_STREQ(product_bundle.description.c_str(), "string");
    EXPECT_STREQ(product_bundle.additional_info->c_str(), "string");
    EXPECT_STREQ(product_bundle.additional_info_uri->c_str(), "string");
    EXPECT_STREQ(product_bundle.product_ids.value()[0].c_str(), "string");
}

TEST(TypeDeserialization, BankingProductFeature)
{
    object = parser.parse(BANKING_PRODUCT_FEATURE).extract<Poco::JSON::Object::Ptr>();
    BankingProductFeature product_feature;
    product_feature.deserialize(object);
    EXPECT_EQ(product_feature.feature_type, FeatureType::CARD_ACCESS);
    EXPECT_STREQ(product_feature.additional_value->c_str(), "string");
    EXPECT_STREQ(product_feature.additional_info->c_str(), "string");
    EXPECT_STREQ(product_feature.additional_info_uri->c_str(), "string");
}

TEST(TypeDeserialization, BankingProductConstraint)
{
    object = parser.parse(BANKING_PRODUCT_CONSTRAINT).extract<Poco::JSON::Object::Ptr>();
    BankingProductConstraint product_constraint;
    product_constraint.deserialize(object);
    EXPECT_EQ(product_constraint.constraint_type, ConstraintType::MIN_BALANCE);
    EXPECT_STREQ(product_constraint.additional_value->c_str(), "string");
    EXPECT_STREQ(product_constraint.additional_info->c_str(), "string");
    EXPECT_STREQ(product_constraint.additional_info_uri->c_str(), "string");
}

TEST(TypeDeserialization, BankingProductEligibility)
{
    object = parser.parse(BANKING_PRODUCT_ELIGIBILITY).extract<Poco::JSON::Object::Ptr>();
    BankingProductEligibility product_eligibility;
    product_eligibility.deserialize(object);
    EXPECT_EQ(product_eligibility.eligibility_type, EligibilityType::BUSINESS);
    EXPECT_STREQ(product_eligibility.additional_value->c_str(), "string");
    EXPECT_STREQ(product_eligibility.additional_info->c_str(), "string");
    EXPECT_STREQ(product_eligibility.additional_info_uri->c_str(), "string");
}

TEST(TypeDeserialization, BankingProductFee)
{
    object = parser.parse(BANKING_PRODUCT_FEE).extract<Poco::JSON::Object::Ptr>();
    BankingProductFee product_fee;
    product_fee.deserialize(object);
    EXPECT_STREQ(product_fee.name.c_str(), "string");
    EXPECT_EQ(product_fee.fee_type, FeeType::PERIODIC);
    EXPECT_STREQ(product_fee.amount->c_str(), "string");
    EXPECT_STREQ(product_fee.balance_rate->c_str(), "string");
    EXPECT_STREQ(product_fee.transaction_rate->c_str(), "string");
    EXPECT_STREQ(product_fee.accrued_rate->c_str(), "string");
    EXPECT_STREQ(product_fee.accrual_frequency->c_str(), "string");
    EXPECT_STREQ(product_fee.currency->c_str(), "string");
    EXPECT_STREQ(product_fee.additional_value->c_str(), "string");
    EXPECT_STREQ(product_fee.additional_info->c_str(), "string");
    EXPECT_STREQ(product_fee.additional_info_uri->c_str(), "string");
    auto discount = product_fee.discounts.value()[0];
    EXPECT_STREQ(discount.description.c_str(), "string");
    EXPECT_STREQ(discount.description.c_str(), "string");
    EXPECT_EQ(discount.discount_type, DiscountType::BALANCE);
    EXPECT_STREQ(discount.amount->c_str(), "string");
    EXPECT_STREQ(discount.balance_rate->c_str(), "string");
    EXPECT_STREQ(discount.transaction_rate->c_str(), "string");
    EXPECT_STREQ(discount.accrued_rate->c_str(), "string");
    EXPECT_STREQ(discount.fee_rate->c_str(), "string");
    EXPECT_STREQ(discount.additional_value->c_str(), "string");
    EXPECT_STREQ(discount.additional_info->c_str(), "string");
    EXPECT_STREQ(discount.additional_info_uri->c_str(), "string");
    EXPECT_EQ(discount.eligibility.value()[0].discount_eligibility_type, DiscountEligibilityType::BUSINESS);
    EXPECT_STREQ(discount.eligibility.value()[0].additional_value->c_str(), "string");
    EXPECT_STREQ(discount.eligibility.value()[0].additional_info->c_str(), "string");
    EXPECT_STREQ(discount.eligibility.value()[0].additional_info_uri->c_str(), "string");
}

TEST(TypeDeserialization, BankingProductDiscount)
{
    object = parser.parse(BANKING_PRODUCT_DISCOUNT).extract<Poco::JSON::Object::Ptr>();
    BankingProductDiscount product_discount;
    product_discount.deserialize(object);
    EXPECT_STREQ(product_discount.description.c_str(), "string");
    EXPECT_EQ(product_discount.discount_type, DiscountType::BALANCE);
    EXPECT_STREQ(product_discount.amount->c_str(), "string");
    EXPECT_STREQ(product_discount.balance_rate->c_str(), "string");
    EXPECT_STREQ(product_discount.transaction_rate->c_str(), "string");
    EXPECT_STREQ(product_discount.accrued_rate->c_str(), "string");
    EXPECT_STREQ(product_discount.fee_rate->c_str(), "string");
    EXPECT_STREQ(product_discount.additional_value->c_str(), "string");
    EXPECT_STREQ(product_discount.additional_info->c_str(), "string");
    EXPECT_STREQ(product_discount.additional_info_uri->c_str(), "string");
    auto eligibility = product_discount.eligibility.value()[0];
    EXPECT_EQ(eligibility.discount_eligibility_type, DiscountEligibilityType::BUSINESS);
    EXPECT_STREQ(eligibility.additional_value->c_str(), "string");
    EXPECT_STREQ(eligibility.additional_info->c_str(), "string");
    EXPECT_STREQ(eligibility.additional_info_uri->c_str(), "string");
}

TEST(TypeDeserialization, BankingProductDiscountEligibility)
{
    object = parser.parse(BANKING_PRODUCT_DISCOUNT_ELIGIBILITY).extract<Poco::JSON::Object::Ptr>();
    BankingProductDiscountEligibility product_discount_eligibility;
    product_discount_eligibility.deserialize(object);
    EXPECT_EQ(product_discount_eligibility.discount_eligibility_type, DiscountEligibilityType::BUSINESS);
    EXPECT_STREQ(product_discount_eligibility.additional_value->c_str(), "string");
    EXPECT_STREQ(product_discount_eligibility.additional_info->c_str(), "string");
    EXPECT_STREQ(product_discount_eligibility.additional_info_uri->c_str(), "string");
}

TEST(TypeDeserialization, BankingProductDepositRate)
{
    object = parser.parse(BANKING_PRODUCT_DEPOSIT_RATE).extract<Poco::JSON::Object::Ptr>();
    BankingProductDepositRate product_deposit_rate;
    product_deposit_rate.deserialize(object);
    EXPECT_EQ(product_deposit_rate.deposit_rate_type, DepositRateType::FIXED);
    EXPECT_STREQ(product_deposit_rate.rate.c_str(), "string");
    EXPECT_STREQ(product_deposit_rate.calculation_frequency->c_str(), "string");
    EXPECT_STREQ(product_deposit_rate.application_frequency->c_str(), "string");
    auto tier = product_deposit_rate.tiers.value()[0];
    EXPECT_STREQ(tier.name.c_str(), "string");
    EXPECT_EQ(tier.unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(tier.minimum_value, 0);
    EXPECT_EQ(tier.maximum_value, 0);
    EXPECT_EQ(tier.rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(tier.applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(tier.applicability_conditions->additional_info_uri->c_str(), "string");
    EXPECT_STREQ(tier.sub_tier->name.c_str(), "string");
    EXPECT_STREQ(tier.sub_tier->name.c_str(), "string");
    EXPECT_EQ(tier.sub_tier->unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(tier.sub_tier->minimum_value, 0);
    EXPECT_EQ(tier.sub_tier->maximum_value, 0);
    EXPECT_EQ(tier.sub_tier->rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(tier.sub_tier->applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(tier.sub_tier->applicability_conditions->additional_info_uri->c_str(), "string");
    EXPECT_STREQ(product_deposit_rate.additional_value->c_str(), "string");
    EXPECT_STREQ(product_deposit_rate.additional_info->c_str(), "string");
    EXPECT_STREQ(product_deposit_rate.additional_info_uri->c_str(), "string");
}

TEST(TypeDeserialization, BankingProductLendingRate)
{
    object = parser.parse(BANKING_PRODUCT_LENDING_RATE).extract<Poco::JSON::Object::Ptr>();
    BankingProductLendingRate product_lending_rate;
    product_lending_rate.deserialize(object);
    EXPECT_EQ(product_lending_rate.lending_rate_type, LendingRateType::FIXED);
    EXPECT_STREQ(product_lending_rate.rate.c_str(), "string");
    EXPECT_STREQ(product_lending_rate.comparison_rate->c_str(), "string");
    EXPECT_STREQ(product_lending_rate.calculation_frequency->c_str(), "string");
    EXPECT_STREQ(product_lending_rate.application_frequency->c_str(), "string");
    EXPECT_EQ(product_lending_rate.interest_payment_due, InterestPaymentDue::IN_ARREARS);
    auto tier = product_lending_rate.tiers.value()[0];
    EXPECT_STREQ(tier.name.c_str(), "string");
    EXPECT_EQ(tier.unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(tier.minimum_value, 0);
    EXPECT_EQ(tier.maximum_value, 0);
    EXPECT_EQ(tier.rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(tier.applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(tier.applicability_conditions->additional_info_uri->c_str(), "string");
    EXPECT_STREQ(tier.sub_tier->name.c_str(), "string");
    EXPECT_EQ(tier.sub_tier->unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(tier.sub_tier->minimum_value, 0);
    EXPECT_EQ(tier.sub_tier->maximum_value, 0);
    EXPECT_EQ(tier.sub_tier->rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(tier.sub_tier->applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(tier.sub_tier->applicability_conditions->additional_info_uri->c_str(), "string");
    EXPECT_STREQ(product_lending_rate.additional_info->c_str(), "string");
    EXPECT_STREQ(product_lending_rate.additional_info_uri->c_str(), "string");
}

TEST(TypeDeserialization, BankingProductRateTier)
{
    object = parser.parse(BANKING_PRODUCT_RATE_TIER).extract<Poco::JSON::Object::Ptr>();
    BankingProductRateTier product_rate_tier;
    product_rate_tier.deserialize(object);
    EXPECT_STREQ(product_rate_tier.name.c_str(), "string");
    EXPECT_EQ(product_rate_tier.unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(product_rate_tier.minimum_value, 0);
    EXPECT_EQ(product_rate_tier.maximum_value, 0);
    EXPECT_EQ(product_rate_tier.rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(product_rate_tier.applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(product_rate_tier.applicability_conditions->additional_info_uri->c_str(), "string");
    EXPECT_STREQ(product_rate_tier.sub_tier->name.c_str(), "string");
    EXPECT_EQ(product_rate_tier.sub_tier->unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(product_rate_tier.sub_tier->minimum_value, 0);
    EXPECT_EQ(product_rate_tier.sub_tier->maximum_value, 0);
    EXPECT_EQ(product_rate_tier.sub_tier->rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(product_rate_tier.sub_tier->applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(product_rate_tier.sub_tier->applicability_conditions->additional_info_uri->c_str(), "string");
}

TEST(TypeDeserialization, ProductRateCondition)
{
    object = parser.parse(BANKING_PRODUCT_RATE_CONDITION).extract<Poco::JSON::Object::Ptr>();
    BankingProductRateCondition product_rate_condition;
    product_rate_condition.deserialize(object);
    EXPECT_STREQ(product_rate_condition.additional_info->c_str(), "string");
    EXPECT_STREQ(product_rate_condition.additional_info_uri->c_str(), "string");
}

TEST(TypeDeserialization, BankingAccount)
{
    object = parser.parse(BANKING_ACCOUNT).extract<Poco::JSON::Object::Ptr>();
    BankingAccount account;
    account.deserialize(object);
    EXPECT_STREQ(account.account_id.c_str(), "string");
    EXPECT_STREQ(account.creation_date->c_str(), "string");
    EXPECT_STREQ(account.display_name.c_str(), "string");
    EXPECT_STREQ(account.nickname->c_str(), "string");
    EXPECT_EQ(account.is_owned, true);
    EXPECT_STREQ(account.masked_number.c_str(), "string");
    EXPECT_EQ(account.product_category, ProductCategory::TRANS_AND_SAVINGS_ACCOUNTS);
    EXPECT_STREQ(account.product_name.c_str(), "string");
}

TEST(TypeDeserialization, BankingAccountDetail)
{
    object = parser.parse(BANKING_ACCOUNT_DETAIL).extract<Poco::JSON::Object::Ptr>();
    BankingAccountDetail account_detail;
    account_detail.deserialize(object);
    EXPECT_STREQ(account_detail.account.account_id.c_str(), "string");
    EXPECT_STREQ(account_detail.account.creation_date->c_str(), "string");
    EXPECT_STREQ(account_detail.account.display_name.c_str(), "string");
    EXPECT_STREQ(account_detail.account.nickname->c_str(), "string");
    EXPECT_EQ(account_detail.account.open_status, OpenStatus::OPEN);
    EXPECT_EQ(account_detail.account.is_owned, true);
    EXPECT_STREQ(account_detail.account.masked_number.c_str(), "string");
    EXPECT_EQ(account_detail.account.product_category, ProductCategory::TRANS_AND_SAVINGS_ACCOUNTS);
    EXPECT_STREQ(account_detail.account.product_name.c_str(), "string");
    EXPECT_STREQ(account_detail.bsb->c_str(), "string");
    EXPECT_STREQ(account_detail.account_number->c_str(), "string");
    EXPECT_STREQ(account_detail.bundle_name->c_str(), "string");
    EXPECT_EQ(account_detail.specific_account_u_type, SpecificAccountUType::TERM_DEPOSIT);
    EXPECT_STREQ(account_detail.term_deposit.value()[0].lodgement_date.c_str(), "string");
    EXPECT_STREQ(account_detail.term_deposit.value()[0].maturity_date.c_str(), "string");
    EXPECT_STREQ(account_detail.term_deposit.value()[0].maturity_amount->c_str(), "string");
    EXPECT_STREQ(account_detail.term_deposit.value()[0].maturity_currency->c_str(), "string");
    EXPECT_EQ(account_detail.term_deposit.value()[0].maturity_instructions, MaturityInstructions::ROLLED_OVER);
    EXPECT_STREQ(account_detail.credit_card->min_payment_amount.c_str(), "string");
    EXPECT_STREQ(account_detail.credit_card->payment_due_amount.c_str(), "string");
    EXPECT_STREQ(account_detail.credit_card->payment_currency->c_str(), "string");
    EXPECT_STREQ(account_detail.credit_card->payment_due_date.c_str(), "string");
    EXPECT_STREQ(account_detail.loan->original_start_date->c_str(), "string");
    EXPECT_STREQ(account_detail.loan->original_loan_amount->c_str(), "string");
    EXPECT_STREQ(account_detail.loan->original_loan_currency->c_str(), "string");
    EXPECT_STREQ(account_detail.loan->loan_end_date.c_str(), "string");
    EXPECT_STREQ(account_detail.loan->next_instalment_date.c_str(), "string");
    EXPECT_STREQ(account_detail.loan->min_instalment_amount->c_str(), "string");
    EXPECT_STREQ(account_detail.loan->min_instalment_currency->c_str(), "string");
    EXPECT_STREQ(account_detail.loan->max_redraw->c_str(), "string");
    EXPECT_STREQ(account_detail.loan->max_redraw_currency->c_str(), "string");
    EXPECT_STREQ(account_detail.loan->min_redraw->c_str(), "string");
    EXPECT_STREQ(account_detail.loan->min_redraw_currency->c_str(), "string");
    EXPECT_EQ(account_detail.loan->offset_account_enabled, true);
    EXPECT_STREQ(account_detail.loan->offset_account_ids.value()[0].c_str(), "string");
    EXPECT_EQ(account_detail.loan->repayment_type, RepaymentType::PRINCIPAL_AND_INTEREST);
    EXPECT_STREQ(account_detail.loan->repayment_frequency.c_str(), "string");
    EXPECT_STREQ(account_detail.deposit_rate->c_str(), "string");
    EXPECT_STREQ(account_detail.lending_rate->c_str(), "string");
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
    object = parser.parse(BANKING_TERM_DEPOSIT_ACCOUNT).extract<Poco::JSON::Object::Ptr>();
    BankingTermDepositAccount term_deposit_account;
    term_deposit_account.deserialize(object);
    EXPECT_STREQ(term_deposit_account.lodgement_date.c_str(), "string");
    EXPECT_STREQ(term_deposit_account.maturity_date.c_str(), "string");
    EXPECT_STREQ(term_deposit_account.maturity_amount->c_str(), "string");
    EXPECT_STREQ(term_deposit_account.maturity_currency->c_str(), "string");
    EXPECT_EQ(term_deposit_account.maturity_instructions, MaturityInstructions::ROLLED_OVER);
}

TEST(TypeDeserialization, CreditCardAccount)
{
    object = parser.parse(BANKING_CREDIT_CARD_ACCOUNT).extract<Poco::JSON::Object::Ptr>();
    BankingCreditCardAccount credit_card_account;
    credit_card_account.deserialize(object);
    EXPECT_STREQ(credit_card_account.min_payment_amount.c_str(), "string");
    EXPECT_STREQ(credit_card_account.payment_due_amount.c_str(), "string");
    EXPECT_STREQ(credit_card_account.payment_currency->c_str(), "string");
    EXPECT_STREQ(credit_card_account.payment_due_date.c_str(), "string");
}

TEST(TypeDeserialization, BankingLoanAccount)
{
    object = parser.parse(BANKING_LOAN_ACCOUNT).extract<Poco::JSON::Object::Ptr>();
    BankingLoanAccount loan_account;
    loan_account.deserialize(object);
    EXPECT_STREQ(loan_account.original_start_date->c_str(), "string");
    EXPECT_STREQ(loan_account.original_loan_amount->c_str(), "string");
    EXPECT_STREQ(loan_account.original_loan_currency->c_str(), "string");
    EXPECT_STREQ(loan_account.loan_end_date.c_str(), "string");
    EXPECT_STREQ(loan_account.next_instalment_date.c_str(), "string");
    EXPECT_STREQ(loan_account.min_instalment_amount->c_str(), "string");
    EXPECT_STREQ(loan_account.min_instalment_currency->c_str(), "string");
    EXPECT_STREQ(loan_account.max_redraw->c_str(), "string");
    EXPECT_STREQ(loan_account.max_redraw_currency->c_str(), "string");
    EXPECT_STREQ(loan_account.min_redraw->c_str(), "string");
    EXPECT_STREQ(loan_account.min_redraw_currency->c_str(), "string");
    EXPECT_EQ(loan_account.offset_account_enabled, true);
    EXPECT_STREQ(loan_account.offset_account_ids.value()[0].c_str(), "string");
    EXPECT_EQ(loan_account.repayment_type, RepaymentType::PRINCIPAL_AND_INTEREST);
    EXPECT_STREQ(loan_account.repayment_frequency.c_str(), "string");
}

TEST(TypeDeserialization, BankingTransaction)
{
    object = parser.parse(BANKING_TRANSACTION).extract<Poco::JSON::Object::Ptr>();
    BankingTransaction transaction;
    transaction.deserialize(object);
    EXPECT_STREQ(transaction.account_id.c_str(), "string");
    EXPECT_STREQ(transaction.transaction_id->c_str(), "string");
    EXPECT_EQ(transaction.is_detail_available, true);
    EXPECT_EQ(transaction.type, TransactionType::FEE);
    EXPECT_EQ(transaction.status, TransactionStatus::PENDING);
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

TEST(TypeDeserialization, BankingTransactionDetail)
{
    object = parser.parse(BANKING_TRANSACTION_DETAIL).extract<Poco::JSON::Object::Ptr>();
    BankingTransactionDetail transaction_detail;
    transaction_detail.deserialize(object);
    auto transaction = transaction_detail.transaction;
    EXPECT_STREQ(transaction->account_id.c_str(), "string");
    EXPECT_STREQ(transaction->transaction_id->c_str(), "string");
    EXPECT_EQ(transaction->is_detail_available, true);
    EXPECT_EQ(transaction->type, TransactionType::FEE);
    EXPECT_EQ(transaction->status, TransactionStatus::PENDING);
    EXPECT_STREQ(transaction->description.c_str(), "string");
    EXPECT_STREQ(transaction->posting_date_time->c_str(), "string");
    EXPECT_STREQ(transaction->value_date_time->c_str(), "string");
    EXPECT_STREQ(transaction->execution_date_time->c_str(), "string");
    EXPECT_STREQ(transaction->amount.c_str(), "string");
    EXPECT_STREQ(transaction->currency->c_str(), "string");
    EXPECT_STREQ(transaction->reference.c_str(), "string");
    EXPECT_STREQ(transaction->merchant_name->c_str(), "string");
    EXPECT_STREQ(transaction->merchant_category_code->c_str(), "string");
    EXPECT_STREQ(transaction->biller_code->c_str(), "string");
    EXPECT_STREQ(transaction->biller_name->c_str(), "string");
    EXPECT_STREQ(transaction->crn->c_str(), "string");
    EXPECT_STREQ(transaction->apca_number->c_str(), "string");
    EXPECT_STREQ(transaction_detail.extended_data.payer->c_str(), "string");
    EXPECT_STREQ(transaction_detail.extended_data.payee->c_str(), "string");
    EXPECT_EQ(transaction_detail.extended_data.extension_u_type, ExtensionUType::X2P101PAYLOAD);
    EXPECT_STREQ(transaction_detail.extended_data.x2p101_payload->extended_description.c_str(), "string");
    EXPECT_STREQ(transaction_detail.extended_data.x2p101_payload->end_to_end_id->c_str(), "string");
    EXPECT_STREQ(transaction_detail.extended_data.x2p101_payload->purpose_code->c_str(), "string");
    EXPECT_EQ(transaction_detail.extended_data.service, TransactionOverlayService::X2P101);
}

TEST(TypeDeserialization, BankingBalance)
{
    object = parser.parse(BANKING_BALANCE).extract<Poco::JSON::Object::Ptr>();
    BankingBalance balance;
    balance.deserialize(object);
    EXPECT_STREQ(balance.account_id.c_str(), "string");
    EXPECT_STREQ(balance.current_balance.c_str(), "string");
    EXPECT_STREQ(balance.available_balance.c_str(), "string");
    EXPECT_STREQ(balance.credit_limit->c_str(), "string");
    EXPECT_STREQ(balance.amortised_limit->c_str(), "string");
    EXPECT_STREQ(balance.currency->c_str(), "string");
    EXPECT_STREQ(balance.purses.value()[0].amount.c_str(), "string");
    EXPECT_STREQ(balance.purses.value()[0].currency->c_str(), "string");
}

TEST(TypeDeserialization, BankingBalancePurse)
{
    object = parser.parse(BANKING_BALANCE_PURSE).extract<Poco::JSON::Object::Ptr>();
    BankingBalancePurse purse;
    purse.deserialize(object);
    EXPECT_STREQ(purse.amount.c_str(), "string");
    EXPECT_STREQ(purse.currency->c_str(), "string");
}

TEST(TypeDeserialization, BankingPayee)
{
    object = parser.parse(BANKING_PAYEE).extract<Poco::JSON::Object::Ptr>();
    BankingPayee payee;
    payee.deserialize(object);
    EXPECT_STREQ(payee.payee_id.c_str(), "string");
    EXPECT_STREQ(payee.nickname.c_str(), "string");
    EXPECT_STREQ(payee.description->c_str(), "string");
    EXPECT_EQ(payee.type, PayeeType::DOMESTIC);
    EXPECT_STREQ(payee.creation_date->c_str(), "string");
}

TEST(TypeDeserialization, BankingPayeeDetail)
{
    object = parser.parse(BANKING_PAYEE_DETAIL).extract<Poco::JSON::Object::Ptr>();
    BankingPayeeDetail payee_detail;
    payee_detail.deserialize(object);
    EXPECT_STREQ(payee_detail.payee->payee_id.c_str(), "string");
    EXPECT_STREQ(payee_detail.payee->nickname.c_str(), "string");
    EXPECT_STREQ(payee_detail.payee->description->c_str(), "string");
    EXPECT_EQ(payee_detail.payee->type, PayeeType::DOMESTIC);
    EXPECT_STREQ(payee_detail.payee->creation_date->c_str(), "string");
    EXPECT_EQ(payee_detail.payee_u_type, PayeeUType::DOMESTIC);
    EXPECT_EQ(payee_detail.domestic->payee_account_u_type, PayeeAccountUType::ACCOUNT);
    auto domestic = payee_detail.domestic;
    EXPECT_STREQ(domestic->account->account_name->c_str(), "string");
    EXPECT_STREQ(domestic->account->bsb.c_str(), "string");
    EXPECT_STREQ(domestic->account->account_number.c_str(), "string");
    EXPECT_STREQ(domestic->card->card_number.c_str(), "string");
    EXPECT_STREQ(domestic->pay_id->name->c_str(), "string");
    EXPECT_STREQ(domestic->pay_id->identifier.c_str(), "string");
    EXPECT_EQ(domestic->pay_id->type, PayIdType::EMAIL);
    auto biller = payee_detail.biller;
    EXPECT_STREQ(biller->biller_code.c_str(), "string");
    EXPECT_STREQ(biller->crn->c_str(), "string");
    EXPECT_STREQ(biller->biller_name.c_str(), "string");
    auto international = payee_detail.international;
    EXPECT_STREQ(international->beneficiary_details.name->c_str(), "string");
    EXPECT_STREQ(international->beneficiary_details.country.c_str(), "string");
    EXPECT_STREQ(international->beneficiary_details.message->c_str(), "string");
    EXPECT_STREQ(international->bank_details.country.c_str(), "string");
    EXPECT_STREQ(international->bank_details.bank_address.name.c_str(), "string");
    EXPECT_STREQ(international->bank_details.bank_address.address.c_str(), "string");
    EXPECT_STREQ(international->bank_details.beneficiary_bank_bic->c_str(), "string");
    EXPECT_STREQ(international->bank_details.fed_wire_number->c_str(), "string");
    EXPECT_STREQ(international->bank_details.sort_code->c_str(), "string");
    EXPECT_STREQ(international->bank_details.chip_number->c_str(), "string");
    EXPECT_STREQ(international->bank_details.routing_number->c_str(), "string");
    EXPECT_STREQ(international->bank_details.legal_entity_identifier->c_str(), "string");
}

TEST(TypeDeserialization, BankingDomesticPayee)
{
    object = parser.parse(BANKING_DOMESTIC_PAYEE).extract<Poco::JSON::Object::Ptr>();
    BankingDomesticPayee domestic_payee;
    domestic_payee.deserialize(object);
    EXPECT_EQ(domestic_payee.payee_account_u_type, PayeeAccountUType::ACCOUNT);
    EXPECT_STREQ(domestic_payee.account->account_name->c_str(), "string");
    EXPECT_STREQ(domestic_payee.account->bsb.c_str(), "string");
    EXPECT_STREQ(domestic_payee.account->account_number.c_str(), "string");
    EXPECT_STREQ(domestic_payee.card->card_number.c_str(), "string");
    EXPECT_STREQ(domestic_payee.pay_id->name->c_str(), "string");
    EXPECT_STREQ(domestic_payee.pay_id->identifier.c_str(), "string");
    EXPECT_EQ(domestic_payee.pay_id->type, PayIdType::EMAIL);
}

TEST(TypeDeserialization, BankingDomesticPayeeAccount)
{
    object = parser.parse(BANKING_DOMESTIC_PAYEE_ACCOUNT).extract<Poco::JSON::Object::Ptr>();
    BankingDomesticPayeeAccount domestic_payee_account;
    domestic_payee_account.deserialize(object);
    EXPECT_STREQ(domestic_payee_account.account_name->c_str(), "string");
    EXPECT_STREQ(domestic_payee_account.bsb.c_str(), "string");
    EXPECT_STREQ(domestic_payee_account.account_number.c_str(), "string");
}

TEST(TypeDeserialization, BankingDomesticPayeeCard)
{
    object = parser.parse(BANKING_DOMESTIC_PAYEE_CARD).extract<Poco::JSON::Object::Ptr>();
    BankingDomesticPayeeCard domestic_payee_card;
    domestic_payee_card.deserialize(object);
    EXPECT_STREQ(domestic_payee_card.card_number.c_str(), "string");
}

TEST(TypeDeserialization, DomesticPayeePayId)
{
    object = parser.parse(BANKING_DOMESTIC_PAYEE_PAY_ID).extract<Poco::JSON::Object::Ptr>();
    BankingDomesticPayeePayId domestic_payee_pay_id;
    domestic_payee_pay_id.deserialize(object);
    EXPECT_STREQ(domestic_payee_pay_id.name->c_str(), "string");
    EXPECT_STREQ(domestic_payee_pay_id.identifier.c_str(), "string");
    EXPECT_EQ(domestic_payee_pay_id.type, PayIdType::EMAIL);
}

TEST(TypeDeserialization, BankingBillerPayee)
{
    object = parser.parse(BANKING_BILLER_PAYEE).extract<Poco::JSON::Object::Ptr>();
    BankingBillerPayee biller_payee;
    biller_payee.deserialize(object);
    EXPECT_STREQ(biller_payee.biller_code.c_str(), "string");
    EXPECT_STREQ(biller_payee.crn->c_str(), "string");
    EXPECT_STREQ(biller_payee.biller_name.c_str(), "string");
}

TEST(TypeDeserialization, BankingInternationalPayee)
{
    object = parser.parse(BANKING_INTERNATIONAL_PAYEE).extract<Poco::JSON::Object::Ptr>();
    BankingInternationalPayee international_payee;
    international_payee.deserialize(object);
    EXPECT_STREQ(international_payee.beneficiary_details.name->c_str(), "string");
    EXPECT_STREQ(international_payee.beneficiary_details.country.c_str(), "string");
    EXPECT_STREQ(international_payee.beneficiary_details.message->c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.country.c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.country.c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.account_number.c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.bank_address.name.c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.bank_address.address.c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.beneficiary_bank_bic->c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.fed_wire_number->c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.sort_code->c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.chip_number->c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.routing_number->c_str(), "string");
    EXPECT_STREQ(international_payee.bank_details.legal_entity_identifier->c_str(), "string");
}

TEST(TypeDeserialization, BankingDirectDebit)
{
    object = parser.parse(BANKING_DIRECT_DEBIT).extract<Poco::JSON::Object::Ptr>();
    BankingDirectDebit direct_debit;
    direct_debit.deserialize(object);
    EXPECT_STREQ(direct_debit.account_id.c_str(), "string");
    EXPECT_STREQ(direct_debit.authorised_entity.description->c_str(), "string");
    EXPECT_STREQ(direct_debit.authorised_entity.financial_institution->c_str(), "string");
    EXPECT_STREQ(direct_debit.authorised_entity.abn->c_str(), "string");
    EXPECT_STREQ(direct_debit.authorised_entity.acn->c_str(), "string");
    EXPECT_STREQ(direct_debit.authorised_entity.arbn->c_str(), "string");
    EXPECT_STREQ(direct_debit.last_debit_date_time->c_str(), "string");
    EXPECT_STREQ(direct_debit.last_debit_amount->c_str(), "string");
}

TEST(TypeDeserialization, BankingAuthorisedEntity)
{
    object = parser.parse(BANKING_AUTHORISED_ENTITY).extract<Poco::JSON::Object::Ptr>();
    BankingAuthorisedEntity authorised_entity;
    authorised_entity.deserialize(object);
    EXPECT_STREQ(authorised_entity.description->c_str(), "string");
    EXPECT_STREQ(authorised_entity.financial_institution->c_str(), "string");
    EXPECT_STREQ(authorised_entity.abn->c_str(), "string");
    EXPECT_STREQ(authorised_entity.acn->c_str(), "string");
    EXPECT_STREQ(authorised_entity.arbn->c_str(), "string");
}

TEST(TypeDeserialization, BankingScheduledPayment)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT).extract<Poco::JSON::Object::Ptr>();
    BankingScheduledPayment scheduled_payment;
    scheduled_payment.deserialize(object);
    EXPECT_STREQ(scheduled_payment.scheduled_payment_id.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.nickname->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payer_reference.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payee_reference.c_str(), "string");
    EXPECT_EQ(scheduled_payment.status, ScheduledPaymentStatus::ACTIVE);
    EXPECT_STREQ(scheduled_payment.from.account_id.c_str(), "string");
    auto payment = scheduled_payment.payment_set[0];
    EXPECT_EQ(payment.to.to_u_type, ToUType::ACCOUNT_ID);
    EXPECT_STREQ(payment.to.account_id->c_str(), "string");
    EXPECT_STREQ(payment.to.payee_id->c_str(), "string");
    EXPECT_EQ(payment.to.domestic->payee_account_u_type, PayeeAccountUType::ACCOUNT);
    EXPECT_STREQ(payment.to.domestic->account->account_name->c_str(), "string");
    EXPECT_STREQ(payment.to.domestic->account->bsb.c_str(), "string");
    EXPECT_STREQ(payment.to.domestic->account->account_number.c_str(), "string");
    EXPECT_STREQ(payment.to.domestic->card->card_number.c_str(), "string");
    EXPECT_STREQ(payment.to.domestic->pay_id->name->c_str(), "string");
    EXPECT_STREQ(payment.to.domestic->pay_id->identifier.c_str(), "string");
    EXPECT_EQ(payment.to.domestic->pay_id->type, PayIdType::EMAIL);
    EXPECT_STREQ(payment.to.biller->biller_code.c_str(), "string");
    EXPECT_STREQ(payment.to.biller->crn->c_str(), "string");
    EXPECT_STREQ(payment.to.biller->biller_name.c_str(), "string");
    EXPECT_STREQ(payment.to.international->beneficiary_details.name->c_str(), "string");
    EXPECT_STREQ(payment.to.international->beneficiary_details.country.c_str(), "string");
    EXPECT_STREQ(payment.to.international->beneficiary_details.message->c_str(), "string");
    EXPECT_STREQ(payment.to.international->bank_details.country.c_str(), "string");
    EXPECT_STREQ(payment.to.international->bank_details.account_number.c_str(), "string");
    EXPECT_STREQ(payment.to.international->bank_details.bank_address.name.c_str(), "string");
    EXPECT_STREQ(payment.to.international->bank_details.bank_address.address.c_str(), "string");
    EXPECT_STREQ(payment.to.international->bank_details.beneficiary_bank_bic->c_str(), "string");
    EXPECT_STREQ(payment.to.international->bank_details.fed_wire_number->c_str(), "string");
    EXPECT_STREQ(payment.to.international->bank_details.sort_code->c_str(), "string");
    EXPECT_STREQ(payment.to.international->bank_details.chip_number->c_str(), "string");
    EXPECT_STREQ(payment.to.international->bank_details.routing_number->c_str(), "string");
    EXPECT_STREQ(payment.to.international->bank_details.legal_entity_identifier->c_str(), "string");
    EXPECT_EQ(payment.is_amount_calculated, true);
    EXPECT_STREQ(payment.amount->c_str(), "string");
    EXPECT_STREQ(payment.currency->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.recurrence.next_payment_date->c_str(), "string");
    EXPECT_EQ(scheduled_payment.recurrence.recurrence_u_type, RecurrenceUType::ONCE_OFF);
    EXPECT_STREQ(scheduled_payment.recurrence.once_off->payment_date.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.recurrence.interval_schedule->final_payment_date->c_str(), "string");
    EXPECT_EQ(scheduled_payment.recurrence.interval_schedule->payments_remaining, 0);
    EXPECT_EQ(scheduled_payment.recurrence.interval_schedule->non_business_day_treatment, NonBusinessDayTreatment::ON);
    EXPECT_STREQ(scheduled_payment.recurrence.interval_schedule->intervals[0].interval.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.recurrence.interval_schedule->intervals[0].day_in_interval->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.recurrence.last_week_day->final_payment_date->c_str(), "string");
    EXPECT_EQ(scheduled_payment.recurrence.last_week_day->payments_remaining, 0);
    EXPECT_STREQ(scheduled_payment.recurrence.last_week_day->interval.c_str(), "string");
    EXPECT_EQ(scheduled_payment.recurrence.last_week_day->last_week_day, LastWeekDay::MON);
    EXPECT_EQ(scheduled_payment.recurrence.last_week_day->non_business_day_treatment, NonBusinessDayTreatment::ON);
    EXPECT_STREQ(scheduled_payment.recurrence.event_based->description.c_str(), "string");
}

TEST(TypeDeserialization, BankingScheduledPaymentSet)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT_SET).extract<Poco::JSON::Object::Ptr>();
    BankingScheduledPaymentSet scheduled_payment_set;
    scheduled_payment_set.deserialize(object);
    EXPECT_EQ(scheduled_payment_set.to.to_u_type, ToUType::ACCOUNT_ID);
    EXPECT_STREQ(scheduled_payment_set.to.account_id->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.payee_id->c_str(), "string");
    EXPECT_EQ(scheduled_payment_set.to.domestic->payee_account_u_type, PayeeAccountUType::ACCOUNT);
    EXPECT_STREQ(scheduled_payment_set.to.domestic->account->account_name->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.domestic->account->bsb.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.domestic->account->account_number.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.domestic->card->card_number.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.domestic->pay_id->name->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.domestic->pay_id->identifier.c_str(), "string");
    EXPECT_EQ(scheduled_payment_set.to.domestic->pay_id->type, PayIdType::EMAIL);
    EXPECT_STREQ(scheduled_payment_set.to.biller->biller_code.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.biller->crn->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.biller->biller_name.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->beneficiary_details.name->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->beneficiary_details.country.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->beneficiary_details.message->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->bank_details.country.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->bank_details.account_number.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->bank_details.bank_address.name.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->bank_details.bank_address.address.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->bank_details.beneficiary_bank_bic->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->bank_details.fed_wire_number->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->bank_details.sort_code->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->bank_details.chip_number->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->bank_details.routing_number->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.to.international->bank_details.legal_entity_identifier->c_str(), "string");
    EXPECT_EQ(scheduled_payment_set.is_amount_calculated, true);
    EXPECT_STREQ(scheduled_payment_set.amount->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_set.currency->c_str(), "string");
}

TEST(TypeDeserialization, BankingScheduledPaymentTo)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT_TO).extract<Poco::JSON::Object::Ptr>();
    BankingScheduledPaymentTo scheduled_payment_to;
    scheduled_payment_to.deserialize(object);
    EXPECT_EQ(scheduled_payment_to.to_u_type, ToUType::ACCOUNT_ID);
    EXPECT_STREQ(scheduled_payment_to.account_id->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.payee_id->c_str(), "string");
    EXPECT_EQ(scheduled_payment_to.domestic->payee_account_u_type, PayeeAccountUType::ACCOUNT);
    EXPECT_STREQ(scheduled_payment_to.domestic->account->account_name->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.domestic->account->bsb.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.domestic->account->account_number.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.domestic->card->card_number.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.domestic->pay_id->name->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.domestic->pay_id->identifier.c_str(), "string");
    EXPECT_EQ(scheduled_payment_to.domestic->pay_id->type, PayIdType::EMAIL);
    EXPECT_STREQ(scheduled_payment_to.biller->biller_code.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.biller->crn->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.biller->biller_name.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->beneficiary_details.name->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->beneficiary_details.country.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->beneficiary_details.message->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->bank_details.country.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->bank_details.account_number.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->bank_details.bank_address.name.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->bank_details.bank_address.address.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->bank_details.beneficiary_bank_bic->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->bank_details.fed_wire_number->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->bank_details.sort_code->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->bank_details.chip_number->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->bank_details.routing_number->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_to.international->bank_details.legal_entity_identifier->c_str(), "string");
}

TEST(TypeDeserialization, BankingScheduledPaymentFrom)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT_FROM).extract<Poco::JSON::Object::Ptr>();
    BankingScheduledPaymentFrom scheduled_payment_from;
    scheduled_payment_from.deserialize(object);
    EXPECT_STREQ(scheduled_payment_from.account_id.c_str(), "string");
}

TEST(TypeDeserialization, BankingScheduledPaymentRecurrence)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT_RECURRENCE).extract<Poco::JSON::Object::Ptr>();
    BankingScheduledPaymentRecurrence scheduled_payment_recurrence;
    scheduled_payment_recurrence.deserialize(object);
    EXPECT_STREQ(scheduled_payment_recurrence.next_payment_date->c_str(), "string");
    EXPECT_EQ(scheduled_payment_recurrence.recurrence_u_type, RecurrenceUType::ONCE_OFF);
    EXPECT_STREQ(scheduled_payment_recurrence.once_off->payment_date.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_recurrence.interval_schedule->final_payment_date->c_str(), "string");
    EXPECT_EQ(scheduled_payment_recurrence.interval_schedule->payments_remaining, 0);
    EXPECT_EQ(scheduled_payment_recurrence.interval_schedule->non_business_day_treatment, NonBusinessDayTreatment::ON);
    EXPECT_STREQ(scheduled_payment_recurrence.interval_schedule->intervals[0].interval.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_recurrence.interval_schedule->intervals[0].day_in_interval->c_str(), "string");
    EXPECT_STREQ(scheduled_payment_recurrence.last_week_day->final_payment_date->c_str(), "string");
    EXPECT_EQ(scheduled_payment_recurrence.last_week_day->payments_remaining, 0);
    EXPECT_STREQ(scheduled_payment_recurrence.last_week_day->interval.c_str(), "string");
    EXPECT_EQ(scheduled_payment_recurrence.last_week_day->last_week_day, LastWeekDay::MON);
    EXPECT_EQ(scheduled_payment_recurrence.last_week_day->non_business_day_treatment, NonBusinessDayTreatment::ON);
    EXPECT_STREQ(scheduled_payment_recurrence.event_based->description.c_str(), "string");
}

TEST(TypeDeserialization, BankingScheduledPaymentRecurrenceOnceOff)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT_RECURRENCE_ONCE_OFF).extract<Poco::JSON::Object::Ptr>();
    BankingScheduledPaymentRecurrenceOnceOff scheduled_payment_recurrence_once_off;
    scheduled_payment_recurrence_once_off.deserialize(object);
    EXPECT_STREQ(scheduled_payment_recurrence_once_off.payment_date.c_str(), "string");
}

TEST(TypeDeserialization, BankingScheduledPaymentRecurrenceIntervalSchedule)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT_RECURRENCE_INTERVAL_SCHEDULE).extract<Poco::JSON::Object::Ptr>();
    BankingScheduledPaymentRecurrenceIntervalSchedule scheduled_payment_recurrence_interval_schedule;
    scheduled_payment_recurrence_interval_schedule.deserialize(object);
    EXPECT_STREQ(scheduled_payment_recurrence_interval_schedule.final_payment_date->c_str(), "string");
    EXPECT_EQ(scheduled_payment_recurrence_interval_schedule.payments_remaining, 0);
    EXPECT_EQ(scheduled_payment_recurrence_interval_schedule.non_business_day_treatment, NonBusinessDayTreatment::ON);
    EXPECT_STREQ(scheduled_payment_recurrence_interval_schedule.intervals[0].interval.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_recurrence_interval_schedule.intervals[0].day_in_interval->c_str(), "string");
}

TEST(TypeDeserialization, BankingScheduledPaymentInterval)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT_INTERVAL).extract<Poco::JSON::Object::Ptr>();
    BankingScheduledPaymentInterval scheduled_payment_interval;
    scheduled_payment_interval.deserialize(object);
    EXPECT_STREQ(scheduled_payment_interval.interval.c_str(), "string");
    EXPECT_STREQ(scheduled_payment_interval.day_in_interval->c_str(), "string");
}

TEST(TypeDeserialization, BankingScheduledPaymentRecurrenceLastWeekday)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT_RECURRENCE_LAST_WEEKDAY).extract<Poco::JSON::Object::Ptr>();
    BankingScheduledPaymentRecurrenceLastWeekday scheduled_payment_recurrence_last_weekday;
    scheduled_payment_recurrence_last_weekday.deserialize(object);
    EXPECT_STREQ(scheduled_payment_recurrence_last_weekday.final_payment_date->c_str(), "string");
    EXPECT_EQ(scheduled_payment_recurrence_last_weekday.payments_remaining, 0);
    EXPECT_STREQ(scheduled_payment_recurrence_last_weekday.interval.c_str(), "string");
    EXPECT_EQ(scheduled_payment_recurrence_last_weekday.last_week_day, LastWeekDay::MON);
    EXPECT_EQ(scheduled_payment_recurrence_last_weekday.non_business_day_treatment, NonBusinessDayTreatment::ON);
}

TEST(TypeDeserialization, BankingScheduledPaymentRecurrenceEventBased)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT_RECURRENCE_EVENT_BASED).extract<Poco::JSON::Object::Ptr>();
    BankingScheduledPaymentRecurrenceEventBased scheduled_payment_recurrence_event_based;
    scheduled_payment_recurrence_event_based.deserialize(object);
    EXPECT_STREQ(scheduled_payment_recurrence_event_based.description.c_str(), "string");
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
}

TEST(ResponseDeserialization, BankingAccountList)
{
    object = parser.parse(BANKING_SCHEDULED_PAYMENT_RECURRENCE_EVENT_BASED).extract<Poco::JSON::Object::Ptr>();
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
