#include "helpers.hpp"

namespace regime::v1::test
{
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

    void test_product_feature_toggled_fields(const BankingProductFeatureToggled &feature)
    {
        EXPECT_EQ(feature.feature_type, static_cast<FeatureType>(0));
        EXPECT_STREQ(feature.additional_value->c_str(), "string");
        EXPECT_STREQ(feature.additional_info->c_str(), "string");
        EXPECT_STREQ(feature.additional_info_uri->c_str(), "string");
        EXPECT_TRUE(feature.is_activated.value());
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
        EXPECT_EQ(account.repayment_type, static_cast<RepaymentType>(1));
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
        test_product_feature_toggled_fields(detail.features.value()[0]);
        EXPECT_EQ(detail.fees.value().size(), 1);
        test_product_fee_fields(detail.fees.value()[0]);
        EXPECT_EQ(detail.addresses.value().size(), 1);
        auto address = detail.addresses.value()[0];
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

    void
    test_scheduled_payment_recurrence_last_weekday_fields(const BankingScheduledPaymentRecurrenceLastWeekday &interval)
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

    void test_paginated_links_fields(const LinksPaginated &links)
    {
        EXPECT_STREQ(links.self.c_str(), "string");
        EXPECT_STREQ(links.first.value().c_str(), "string");
        EXPECT_STREQ(links.previous.value().c_str(), "string");
        EXPECT_STREQ(links.next.value().c_str(), "string");
        EXPECT_STREQ(links.last.value().c_str(), "string");
    }

    void test_paginated_meta_fields(const MetaPaginated &meta)
    {
        EXPECT_EQ(meta.total_records, 0);
        EXPECT_EQ(meta.total_pages, 0);
    }
}
