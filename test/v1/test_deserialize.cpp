#include <v1/types.hpp>
#include "types.hpp"
#include "Poco/JSON/Parser.h"
#include "gtest/gtest.h"

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
    EXPECT_STREQ(product.additional_information->overview_uri->c_str(), "string");
    EXPECT_STREQ(product.additional_information->terms_uri->c_str(), "string");
    EXPECT_STREQ(product.additional_information->eligibility_uri->c_str(), "string");
    EXPECT_STREQ(product.additional_information->fees_and_pricing_uri->c_str(), "string");
    EXPECT_STREQ(product.additional_information->bundle_uri->c_str(), "string");
    EXPECT_STREQ(product.card_art.value()[0].title->c_str(), "string");
    EXPECT_STREQ(product.card_art.value()[0].image_uri.c_str(), "string");
}

TEST(TypeDeserialization, BankingProductDetail)
{
    object = parser.parse(BANKING_PRODUCT_DETAIL).extract<Poco::JSON::Object::Ptr>();
    BankingProductDetail product_detail;
    product_detail.deserialize(object);
    EXPECT_STREQ(product_detail.product->product_id.c_str(), "string");
    EXPECT_STREQ(product_detail.product->effective_from->c_str(), "string");
    EXPECT_STREQ(product_detail.product->effective_to->c_str(), "string");
    EXPECT_STREQ(product_detail.product->last_updated.c_str(), "string");
    EXPECT_EQ(product_detail.product->product_category, ProductCategory::TRANS_AND_SAVINGS_ACCOUNTS);
    EXPECT_STREQ(product_detail.product->name.c_str(), "string");
    EXPECT_STREQ(product_detail.product->description.c_str(), "string");
    EXPECT_STREQ(product_detail.product->brand.c_str(), "string");
    EXPECT_STREQ(product_detail.product->brand_name->c_str(), "string");
    EXPECT_STREQ(product_detail.product->application_uri->c_str(), "string");
    EXPECT_EQ(product_detail.product->is_tailored, true);
    EXPECT_STREQ(product_detail.product->additional_information->overview_uri->c_str(), "string");
    EXPECT_STREQ(product_detail.product->additional_information->terms_uri->c_str(), "string");
    EXPECT_STREQ(product_detail.product->additional_information->eligibility_uri->c_str(), "string");
    EXPECT_STREQ(product_detail.product->additional_information->fees_and_pricing_uri->c_str(), "string");
    EXPECT_STREQ(product_detail.product->additional_information->bundle_uri->c_str(), "string");
    EXPECT_STREQ(product_detail.product->card_art.value()[0].title->c_str(), "string");
    EXPECT_STREQ(product_detail.product->card_art.value()[0].image_uri.c_str(), "string");
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
    EXPECT_STREQ(product_fee.discounts.value()[0].description.c_str(), "string");
    EXPECT_STREQ(product_fee.discounts.value()[0].description.c_str(), "string");
    EXPECT_EQ(product_fee.discounts.value()[0].discount_type, DiscountType::BALANCE);
    EXPECT_STREQ(product_fee.discounts.value()[0].amount->c_str(), "string");
    EXPECT_STREQ(product_fee.discounts.value()[0].balance_rate->c_str(), "string");
    EXPECT_STREQ(product_fee.discounts.value()[0].transaction_rate->c_str(), "string");
    EXPECT_STREQ(product_fee.discounts.value()[0].accrued_rate->c_str(), "string");
    EXPECT_STREQ(product_fee.discounts.value()[0].fee_rate->c_str(), "string");
    EXPECT_STREQ(product_fee.discounts.value()[0].additional_value->c_str(), "string");
    EXPECT_STREQ(product_fee.discounts.value()[0].additional_info->c_str(), "string");
    EXPECT_STREQ(product_fee.discounts.value()[0].additional_info_uri->c_str(), "string");
    EXPECT_EQ(product_fee.discounts.value()[0].eligibility.value()[0].discount_eligibility_type,
              DiscountEligibilityType::BUSINESS);
    EXPECT_STREQ(product_fee.discounts.value()[0].eligibility.value()[0].additional_value->c_str(), "string");
    EXPECT_STREQ(product_fee.discounts.value()[0].eligibility.value()[0].additional_info->c_str(), "string");
    EXPECT_STREQ(product_fee.discounts.value()[0].eligibility.value()[0].additional_info_uri->c_str(), "string");
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
    EXPECT_EQ(product_discount.eligibility.value()[0].discount_eligibility_type, DiscountEligibilityType::BUSINESS);
    EXPECT_STREQ(product_discount.eligibility.value()[0].additional_value->c_str(), "string");
    EXPECT_STREQ(product_discount.eligibility.value()[0].additional_info->c_str(), "string");
    EXPECT_STREQ(product_discount.eligibility.value()[0].additional_info_uri->c_str(), "string");
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
    EXPECT_STREQ(product_deposit_rate.tiers.value()[0].name.c_str(), "string");
    EXPECT_EQ(product_deposit_rate.tiers.value()[0].unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(product_deposit_rate.tiers.value()[0].minimum_value, 0);
    EXPECT_EQ(product_deposit_rate.tiers.value()[0].maximum_value, 0);
    EXPECT_EQ(product_deposit_rate.tiers.value()[0].rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(product_deposit_rate.tiers.value()[0].applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(product_deposit_rate.tiers.value()[0].applicability_conditions->additional_info_uri->c_str(),
                 "string");
    EXPECT_STREQ(product_deposit_rate.tiers.value()[0].sub_tier->name.c_str(), "string");
    EXPECT_STREQ(product_deposit_rate.tiers.value()[0].sub_tier->name.c_str(), "string");
    EXPECT_EQ(product_deposit_rate.tiers.value()[0].sub_tier->unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(product_deposit_rate.tiers.value()[0].sub_tier->minimum_value, 0);
    EXPECT_EQ(product_deposit_rate.tiers.value()[0].sub_tier->maximum_value, 0);
    EXPECT_EQ(product_deposit_rate.tiers.value()[0].sub_tier->rate_application_method,
              RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(product_deposit_rate.tiers.value()[0].sub_tier->applicability_conditions->additional_info->c_str(),
                 "string");
    EXPECT_STREQ(product_deposit_rate.tiers.value()[0].sub_tier->applicability_conditions->additional_info_uri->c_str(),
                 "string");
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
    EXPECT_STREQ(product_lending_rate.tiers.value()[0].name.c_str(), "string");
    EXPECT_EQ(product_lending_rate.tiers.value()[0].unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(product_lending_rate.tiers.value()[0].minimum_value, 0);
    EXPECT_EQ(product_lending_rate.tiers.value()[0].maximum_value, 0);
    EXPECT_EQ(product_lending_rate.tiers.value()[0].rate_application_method, RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(product_lending_rate.tiers.value()[0].applicability_conditions->additional_info->c_str(), "string");
    EXPECT_STREQ(product_lending_rate.tiers.value()[0].applicability_conditions->additional_info_uri->c_str(),
                 "string");
    EXPECT_STREQ(product_lending_rate.tiers.value()[0].sub_tier->name.c_str(), "string");
    EXPECT_EQ(product_lending_rate.tiers.value()[0].sub_tier->unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(product_lending_rate.tiers.value()[0].sub_tier->minimum_value, 0);
    EXPECT_EQ(product_lending_rate.tiers.value()[0].sub_tier->maximum_value, 0);
    EXPECT_EQ(product_lending_rate.tiers.value()[0].sub_tier->rate_application_method,
              RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(product_lending_rate.tiers.value()[0].sub_tier->applicability_conditions->additional_info->c_str(),
                 "string");
    EXPECT_STREQ(product_lending_rate.tiers.value()[0].sub_tier->applicability_conditions->additional_info_uri->c_str(),
                 "string");
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
    EXPECT_EQ(account_detail.deposit_rates.value()[0].deposit_rate_type, DepositRateType::FIXED);
    EXPECT_STREQ(account_detail.deposit_rates.value()[0].rate.c_str(), "string");
    EXPECT_STREQ(account_detail.deposit_rates.value()[0].calculation_frequency->c_str(), "string");
    EXPECT_STREQ(account_detail.deposit_rates.value()[0].application_frequency->c_str(), "string");
    EXPECT_STREQ(account_detail.deposit_rates.value()[0].tiers.value()[0].name.c_str(), "string");
    EXPECT_EQ(account_detail.deposit_rates.value()[0].tiers.value()[0].unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(account_detail.deposit_rates.value()[0].tiers.value()[0].minimum_value, 0);
    EXPECT_EQ(account_detail.deposit_rates.value()[0].tiers.value()[0].minimum_value, 0);
    EXPECT_STREQ(
            account_detail.deposit_rates.value()[0].tiers.value()[0].applicability_conditions->additional_info->c_str(),
            "string");
    EXPECT_STREQ(
            account_detail.deposit_rates.value()[0].tiers.value()[0].applicability_conditions->additional_info_uri->c_str(),
            "string");
    EXPECT_STREQ(account_detail.deposit_rates.value()[0].tiers.value()[0].sub_tier->name.c_str(), "string");
    EXPECT_EQ(account_detail.deposit_rates.value()[0].tiers.value()[0].sub_tier->unit_of_measure,
              UnitOfMeasure::DOLLAR);
    EXPECT_EQ(account_detail.deposit_rates.value()[0].tiers.value()[0].sub_tier->minimum_value, 0);
    EXPECT_EQ(account_detail.deposit_rates.value()[0].tiers.value()[0].sub_tier->maximum_value, 0);
    EXPECT_EQ(account_detail.deposit_rates.value()[0].tiers.value()[0].sub_tier->rate_application_method,
              RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(
            account_detail.deposit_rates.value()[0].tiers.value()[0].sub_tier->applicability_conditions->additional_info->c_str(),
            "string");
    EXPECT_STREQ(
            account_detail.deposit_rates.value()[0].tiers.value()[0].sub_tier->applicability_conditions->additional_info_uri->c_str(),
            "string");
    EXPECT_STREQ(account_detail.deposit_rates.value()[0].additional_value->c_str(), "string");
    EXPECT_STREQ(account_detail.deposit_rates.value()[0].additional_info->c_str(), "string");
    EXPECT_STREQ(account_detail.deposit_rates.value()[0].additional_info_uri->c_str(), "string");
    EXPECT_EQ(account_detail.lending_rates.value()[0].lending_rate_type, LendingRateType::FIXED);
    EXPECT_STREQ(account_detail.lending_rates.value()[0].rate.c_str(), "string");
    EXPECT_STREQ(account_detail.lending_rates.value()[0].comparison_rate->c_str(), "string");
    EXPECT_STREQ(account_detail.lending_rates.value()[0].calculation_frequency->c_str(), "string");
    EXPECT_STREQ(account_detail.lending_rates.value()[0].application_frequency->c_str(), "string");
    EXPECT_EQ(account_detail.lending_rates.value()[0].interest_payment_due, InterestPaymentDue::IN_ARREARS);
    EXPECT_EQ(account_detail.lending_rates.value()[0].tiers.value()[0].unit_of_measure, UnitOfMeasure::DOLLAR);
    EXPECT_EQ(account_detail.lending_rates.value()[0].tiers.value()[0].minimum_value, 0);
    EXPECT_EQ(account_detail.lending_rates.value()[0].tiers.value()[0].minimum_value, 0);
    EXPECT_STREQ(
            account_detail.lending_rates.value()[0].tiers.value()[0].applicability_conditions->additional_info->c_str(),
            "string");
    EXPECT_STREQ(
            account_detail.lending_rates.value()[0].tiers.value()[0].applicability_conditions->additional_info_uri->c_str(),
            "string");
    EXPECT_STREQ(account_detail.lending_rates.value()[0].tiers.value()[0].sub_tier->name.c_str(), "string");
    EXPECT_EQ(account_detail.lending_rates.value()[0].tiers.value()[0].sub_tier->unit_of_measure,
              UnitOfMeasure::DOLLAR);
    EXPECT_EQ(account_detail.lending_rates.value()[0].tiers.value()[0].sub_tier->minimum_value, 0);
    EXPECT_EQ(account_detail.lending_rates.value()[0].tiers.value()[0].sub_tier->maximum_value, 0);
    EXPECT_EQ(account_detail.lending_rates.value()[0].tiers.value()[0].sub_tier->rate_application_method,
              RateApplicationMethod::WHOLE_BALANCE);
    EXPECT_STREQ(
            account_detail.lending_rates.value()[0].tiers.value()[0].sub_tier->applicability_conditions->additional_info->c_str(),
            "string");
    EXPECT_STREQ(
            account_detail.lending_rates.value()[0].tiers.value()[0].sub_tier->applicability_conditions->additional_info_uri->c_str(),
            "string");
    EXPECT_STREQ(account_detail.lending_rates.value()[0].additional_value->c_str(), "string");
    EXPECT_STREQ(account_detail.lending_rates.value()[0].additional_info->c_str(), "string");
    EXPECT_STREQ(account_detail.deposit_rates.value()[0].additional_info_uri->c_str(), "string");
    EXPECT_EQ(account_detail.features.value()[0].feature_type, FeatureType::CARD_ACCESS);
    EXPECT_STREQ(account_detail.features.value()[0].additional_value->c_str(), "string");
    EXPECT_STREQ(account_detail.features.value()[0].additional_info->c_str(), "string");
    EXPECT_STREQ(account_detail.features.value()[0].additional_info_uri->c_str(), "string");
    EXPECT_EQ(account_detail.features.value()[0].is_activated, true);
    EXPECT_STREQ(account_detail.fees.value()[0].name.c_str(), "string");
    EXPECT_EQ(account_detail.fees.value()[0].fee_type, FeeType::PERIODIC);
    EXPECT_STREQ(account_detail.fees.value()[0].amount->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].balance_rate->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].transaction_rate->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].accrued_rate->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].accrual_frequency->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].currency->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].additional_value->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].additional_info->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].additional_info_uri->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].description.c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].description.c_str(), "string");
    EXPECT_EQ(account_detail.fees.value()[0].discounts.value()[0].discount_type, DiscountType::BALANCE);
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].amount->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].balance_rate->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].transaction_rate->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].accrued_rate->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].fee_rate->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].additional_value->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].additional_info->c_str(), "string");
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].additional_info_uri->c_str(), "string");
    EXPECT_EQ(account_detail.fees.value()[0].discounts.value()[0].eligibility.value()[0].discount_eligibility_type,
              DiscountEligibilityType::BUSINESS);
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].eligibility.value()[0].additional_value->c_str(),
                 "string");
    EXPECT_STREQ(account_detail.fees.value()[0].discounts.value()[0].eligibility.value()[0].additional_info->c_str(),
                 "string");
    EXPECT_STREQ(
            account_detail.fees.value()[0].discounts.value()[0].eligibility.value()[0].additional_info_uri->c_str(),
            "string");
    EXPECT_EQ(account_detail.addresses.value()[0].address_u_type, AddressUType::SIMPLE);
    EXPECT_STREQ(account_detail.addresses.value()[0].simple->mailing_name->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].simple->address_line1.c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].simple->address_line2->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].simple->address_line3->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].simple->postcode->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].simple->city.c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].simple->state.c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].simple->country->c_str(), "AUS");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->dpid->c_str(), "string");
    EXPECT_EQ(account_detail.addresses.value()[0].paf->thoroughfare_number1, 0);
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->thoroughfare_number1_suffix->c_str(), "string");
    EXPECT_EQ(account_detail.addresses.value()[0].paf->thoroughfare_number2, 0);
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->thoroughfare_number2_suffix->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->flat_unit_type->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->flat_unit_number->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->floor_level_type->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->floor_level_number->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->lot_number->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->building_name1->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->building_name2->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->street_name->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->street_type->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->street_suffix->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->postal_delivery_type->c_str(), "string");
    EXPECT_EQ(account_detail.addresses.value()[0].paf->postal_delivery_number, 0);
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->postal_delivery_number_prefix->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->postal_delivery_number_suffix->c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->locality_name.c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->postcode.c_str(), "string");
    EXPECT_STREQ(account_detail.addresses.value()[0].paf->state.c_str(), "string");
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
    EXPECT_STREQ(transaction_detail.transaction->account_id.c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->transaction_id->c_str(), "string");
    EXPECT_EQ(transaction_detail.transaction->is_detail_available, true);
    EXPECT_EQ(transaction_detail.transaction->type, TransactionType::FEE);
    EXPECT_EQ(transaction_detail.transaction->status, TransactionStatus::PENDING);
    EXPECT_STREQ(transaction_detail.transaction->description.c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->posting_date_time->c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->value_date_time->c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->execution_date_time->c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->amount.c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->currency->c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->reference.c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->merchant_name->c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->merchant_category_code->c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->biller_code->c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->biller_name->c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->crn->c_str(), "string");
    EXPECT_STREQ(transaction_detail.transaction->apca_number->c_str(), "string");
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
    EXPECT_STREQ(payee_detail.domestic->account->account_name->c_str(), "string");
    EXPECT_STREQ(payee_detail.domestic->account->bsb.c_str(), "string");
    EXPECT_STREQ(payee_detail.domestic->account->account_number.c_str(), "string");
    EXPECT_STREQ(payee_detail.domestic->card->card_number.c_str(), "string");
    EXPECT_STREQ(payee_detail.domestic->pay_id->name->c_str(), "string");
    EXPECT_STREQ(payee_detail.domestic->pay_id->identifier.c_str(), "string");
    EXPECT_EQ(payee_detail.domestic->pay_id->type, PayIdType::EMAIL);
    EXPECT_STREQ(payee_detail.biller->biller_code.c_str(), "string");
    EXPECT_STREQ(payee_detail.biller->crn->c_str(), "string");
    EXPECT_STREQ(payee_detail.biller->biller_name.c_str(), "string");
    EXPECT_STREQ(payee_detail.international->beneficiary_details.name->c_str(), "string");
    EXPECT_STREQ(payee_detail.international->beneficiary_details.country.c_str(), "string");
    EXPECT_STREQ(payee_detail.international->beneficiary_details.message->c_str(), "string");
    EXPECT_STREQ(payee_detail.international->bank_details.country.c_str(), "string");
    EXPECT_STREQ(payee_detail.international->bank_details.bank_address.name.c_str(), "string");
    EXPECT_STREQ(payee_detail.international->bank_details.bank_address.address.c_str(), "string");
    EXPECT_STREQ(payee_detail.international->bank_details.beneficiary_bank_bic->c_str(), "string");
    EXPECT_STREQ(payee_detail.international->bank_details.fed_wire_number->c_str(), "string");
    EXPECT_STREQ(payee_detail.international->bank_details.sort_code->c_str(), "string");
    EXPECT_STREQ(payee_detail.international->bank_details.chip_number->c_str(), "string");
    EXPECT_STREQ(payee_detail.international->bank_details.routing_number->c_str(), "string");
    EXPECT_STREQ(payee_detail.international->bank_details.legal_entity_identifier->c_str(), "string");
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
    EXPECT_EQ(scheduled_payment.payment_set[0].to.to_u_type, ToUType::ACCOUNT_ID);
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.account_id->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.payee_id->c_str(), "string");
    EXPECT_EQ(scheduled_payment.payment_set[0].to.domestic->payee_account_u_type, PayeeAccountUType::ACCOUNT);
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.domestic->account->account_name->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.domestic->account->bsb.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.domestic->account->account_number.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.domestic->card->card_number.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.domestic->pay_id->name->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.domestic->pay_id->identifier.c_str(), "string");
    EXPECT_EQ(scheduled_payment.payment_set[0].to.domestic->pay_id->type, PayIdType::EMAIL);
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.biller->biller_code.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.biller->crn->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.biller->biller_name.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->beneficiary_details.name->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->beneficiary_details.country.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->beneficiary_details.message->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->bank_details.country.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->bank_details.account_number.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->bank_details.bank_address.name.c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->bank_details.bank_address.address.c_str(),
                 "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->bank_details.beneficiary_bank_bic->c_str(),
                 "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->bank_details.fed_wire_number->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->bank_details.sort_code->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->bank_details.chip_number->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->bank_details.routing_number->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].to.international->bank_details.legal_entity_identifier->c_str(),
                 "string");
    EXPECT_EQ(scheduled_payment.payment_set[0].is_amount_calculated, true);
    EXPECT_STREQ(scheduled_payment.payment_set[0].amount->c_str(), "string");
    EXPECT_STREQ(scheduled_payment.payment_set[0].currency->c_str(), "string");
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

TEST(ResponseDeserialization, BankingProductList)
{

}

TEST(ResponseDeserialization, BankingProductById)
{
}

TEST(ResponseDeserialization, BankingAccountList)
{
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
