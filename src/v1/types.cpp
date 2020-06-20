#include "../../include/v1/types.hpp"

void BankingProductBundle::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(name, data, "name");
    regime::util::get(description, data, "description");
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
    regime::util::get(product_ids, data, "productIds");
}

Poco::JSON::Object::Ptr BankingProductBundle::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "name", name);
    regime::util::add(json, "description", description);
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    regime::util::add(json, "productIds", product_ids);
    return json;
}

void BankingProductFeature::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(feature_type, data, FeatureTypes, "featureType");
    regime::util::get(additional_value, data, "additionalValue");
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
}

Poco::JSON::Object::Ptr BankingProductFeature::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "featureType", FeatureTypes, feature_type);
    regime::util::add(json, "additionalValue", additional_value);
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    return json;
}

void BankingProductConstraint::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(constraint_type, data, ConstraintTypes, "constraintType");
    regime::util::get(additional_value, data, "additionalValue");
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
}

Poco::JSON::Object::Ptr BankingProductConstraint::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "constraintType", ConstraintTypes, constraint_type);
    regime::util::add(json, "additionalValue", additional_value);
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    return json;
}

void BankingProductEligibility::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(eligibility_type, data, EligibilityTypes, "eligibilityType");
    regime::util::get(additional_value, data, "additionalValue");
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
}

Poco::JSON::Object::Ptr BankingProductEligibility::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "eligibilityType", EligibilityTypes, eligibility_type);
    regime::util::add(json, "additionalValue", additional_value);
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    return json;
}

void BankingProductDiscountEligibility::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(discount_eligibility_type, data, DiscountEligibilityTypes, "discountEligibilityType");
    regime::util::get(additional_value, data, "additionalValue");
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
}

Poco::JSON::Object::Ptr BankingProductDiscountEligibility::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "discountEligibilityType", DiscountEligibilityTypes, discount_eligibility_type);
    regime::util::add(json, "additionalValue", additional_value);
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    return json;
}

void BankingProductDiscount::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(description, data, "description");
    regime::util::get(discount_type, data, DiscountTypes, "discountType");
    regime::util::get(amount, data, "amount");
    regime::util::get(balance_rate, data, "balanceRate");
    regime::util::get(transaction_rate, data, "transactionRate");
    regime::util::get(accrued_rate, data, "accruedRate");
    regime::util::get(fee_rate, data, "feeRate");
    regime::util::get(additional_value, data, "additionalValue");
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
    regime::util::get(eligibility, data, "eligibility");
}

Poco::JSON::Object::Ptr BankingProductDiscount::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "description", description);
    regime::util::add(json, "discountType", DiscountTypes, discount_type);
    regime::util::add(json, "amount", amount);
    regime::util::add(json, "balanceRate", balance_rate);
    regime::util::add(json, "transactionRate", transaction_rate);
    regime::util::add(json, "accruedRate", accrued_rate);
    regime::util::add(json, "feeRate", fee_rate);
    regime::util::add(json, "additionalValue", additional_value);
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    regime::util::add(json, "eligibility", eligibility);
    return json;
}

void BankingProductFee::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(name, data, "name");
    regime::util::get(fee_type, data, FeeTypes, "feeType");
    regime::util::get(amount, data, "amount");
    regime::util::get(balance_rate, data, "balanceRate");
    regime::util::get(transaction_rate, data, "transactionRate");
    regime::util::get(accrued_rate, data, "accruedRate");
    regime::util::get(accrual_frequency, data, "accrualFrequency");
    regime::util::get(currency, data, "currency");  // TODO convert type
    regime::util::get(additional_value, data, "additionalValue");
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
    regime::util::get(discounts, data, "discounts");
}

Poco::JSON::Object::Ptr BankingProductFee::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "name", name);
    regime::util::add(json, "feeType", FeeTypes, fee_type);
    regime::util::add(json, "amount", amount);
    regime::util::add(json, "balanceRate", balance_rate);
    regime::util::add(json, "transactionRate", transaction_rate);
    regime::util::add(json, "accruedRate", accrued_rate);
    regime::util::add(json, "accrualFrequency", accrual_frequency);
    regime::util::add(json, "currency", currency);
    regime::util::add(json, "additionalValue", additional_value);
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    regime::util::add(json, "discounts", discounts);
    return json;
}

void BankingProductRateCondition::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
}

Poco::JSON::Object::Ptr BankingProductRateCondition::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    return json;
}

void BankingProductRateSubTier::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(name, data, "name");
    regime::util::get(unit_of_measure, data, UnitsOfMeasure, "unitOfMeasure");
    regime::util::get(minimum_value, data, "minimumValue");
    regime::util::get(maximum_value, data, "maximumValue");
    regime::util::get(rate_application_method, data, RateApplicationMethods, "rateApplicationMethod");
    regime::util::get(applicability_conditions, data, "applicabilityConditions");
}

Poco::JSON::Object::Ptr BankingProductRateSubTier::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "name", name);
    regime::util::add(json, "unitOfMeasure", UnitsOfMeasure, unit_of_measure);
    regime::util::add(json, "minimumValue", minimum_value);
    regime::util::add(json, "maximumValue", maximum_value);
    regime::util::add(json, "rateApplicationMethod", RateApplicationMethods, rate_application_method);
    regime::util::add(json, "applicabilityConditions", applicability_conditions);
    return json;
}

void BankingProductRateTier::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(name, data, "name");
    regime::util::get(unit_of_measure, data, UnitsOfMeasure, "unitOfMeasure");
    regime::util::get(minimum_value, data, "minimumValue");
    regime::util::get(maximum_value, data, "maximumValue");
    regime::util::get(rate_application_method, data, RateApplicationMethods, "rateApplicationMethod");
    regime::util::get(applicability_conditions, data, "applicabilityConditions");
    regime::util::get(sub_tier, data, "subTier");
}

Poco::JSON::Object::Ptr BankingProductRateTier::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "name", name);
    regime::util::add(json, "unitOfMeasure", UnitsOfMeasure, unit_of_measure);
    regime::util::add(json, "minimumValue", minimum_value);
    regime::util::add(json, "maximumValue", maximum_value);
    regime::util::add(json, "rateApplicationMethod", RateApplicationMethods, rate_application_method);
    regime::util::add(json, "applicabilityConditions", applicability_conditions);
    regime::util::add(json, "subTier", sub_tier);
    return json;
}

void BankingProductDepositRate::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(deposit_rate_type, data, DepositRateTypes, "depositRateType");
    regime::util::get(rate, data, "rate");
    regime::util::get(calculation_frequency, data, "calculationFrequency");
    regime::util::get(application_frequency, data, "applicationFrequency");
    regime::util::get(tiers, data, "tiers");
    regime::util::get(additional_value, data, "additionalValue");
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
}

Poco::JSON::Object::Ptr BankingProductDepositRate::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "depositRateType", DepositRateTypes, deposit_rate_type);
    regime::util::add(json, "rate", rate);
    regime::util::add(json, "calculationFrequency", calculation_frequency);
    regime::util::add(json, "applicationFrequency", application_frequency);
    regime::util::add(json, "tiers", tiers);
    regime::util::add(json, "additionalValue", additional_value);
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    return json;
}

void BankingProductLendingRate::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(lending_rate_type, data, LendingRateTypes, "lendingRateType");
    regime::util::get(rate, data, "rate");
    regime::util::get(comparison_rate, data, "comparisonRate");
    regime::util::get(calculation_frequency, data, "calculationFrequency");
    regime::util::get(application_frequency, data, "applicationFrequency");
    regime::util::get(interest_payment_due, data, InterestPaymentDueFields, "interestPaymentDue");
    regime::util::get(tiers, data, "tiers");
    regime::util::get(additional_value, data, "additionalValue");
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
}

Poco::JSON::Object::Ptr BankingProductLendingRate::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "lendingRateType", LendingRateTypes, lending_rate_type);
    regime::util::add(json, "rate", rate);
    regime::util::add(json, "comparisonRate", comparison_rate);
    regime::util::add(json, "calculationFrequency", calculation_frequency);
    regime::util::add(json, "applicationFrequency", application_frequency);
    regime::util::add(json, "interestPaymentDue", InterestPaymentDueFields, interest_payment_due);
    regime::util::add(json, "tiers", tiers);
    regime::util::add(json, "additionalValue", additional_value);
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    return json;
}

void BankingAccount::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(account_id, data, "accountId");
    regime::util::get(creation_date, data, "creationDate");
    regime::util::get(display_name, data, "displayName");
    regime::util::get(nickname, data, "nickname");
    regime::util::get(open_status, data, OpenStatuses, "openStatus");
    regime::util::get(is_owned, data, "isOwned");
    regime::util::get(masked_number, data, "maskedNumber");
    regime::util::get(product_category, data, ProductCategories, "productCategory");
    regime::util::get(product_name, data, "productName");
}

Poco::JSON::Object::Ptr BankingAccount::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "accountId", account_id);
    regime::util::add(json, "creationDate", creation_date);
    regime::util::add(json, "displayName", display_name);
    regime::util::add(json, "nickname", nickname);
    regime::util::add(json, "openStatus", OpenStatuses, open_status);
    regime::util::add(json, "isOwned", is_owned);
    regime::util::add(json, "maskedNumber", masked_number);
    regime::util::add(json, "productCategory", ProductCategories, product_category);
    regime::util::add(json, "productName", product_name);
    return json;
}

void BankingTermDepositAccount::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(lodgement_date, data, "lodgementDate");
    regime::util::get(maturity_date, data, "maturityDate");
    regime::util::get(maturity_amount, data, "maturityAmount");
    regime::util::get(maturity_currency, data, "maturityCurrency");
    regime::util::get(maturity_instructions, data, MaturityInstructionReflections, "maturityInstructions");
}

Poco::JSON::Object::Ptr BankingTermDepositAccount::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "lodgementDate", lodgement_date);
    regime::util::add(json, "maturityDate", maturity_date);
    regime::util::add(json, "maturityAmount", maturity_amount);
    regime::util::add(json, "maturityCurrency", maturity_currency);
    regime::util::add(json, "maturityInstructions", MaturityInstructionReflections, maturity_instructions);
    return json;
}

void BankingCreditCardAccount::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(min_payment_amount, data, "minPaymentAmount");
    regime::util::get(payment_due_amount, data, "paymentDueAmount");
    regime::util::get(payment_currency, data, "paymentCurrency");
    regime::util::get(payment_due_date, data, "paymentDueDate");
}

Poco::JSON::Object::Ptr BankingCreditCardAccount::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "minPaymentAmount", min_payment_amount);
    regime::util::add(json, "paymentDueAmount", payment_due_date);
    regime::util::add(json, "paymentCurrency", payment_currency);
    regime::util::add(json, "paymentDueDate", payment_due_date);
    return json;
}

void BankingLoanAccount::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(original_start_date, data, "originalStartDate");
    regime::util::get(original_loan_amount, data, "originalLoanAmount");
    regime::util::get(original_loan_currency, data, "originalLoanCurrency");
    regime::util::get(loan_end_date, data, "loanEndDate");
    regime::util::get(next_instalment_date, data, "nextInstalmentDate");
    regime::util::get(min_instalment_amount, data, "minInstalmentAmount");
    regime::util::get(min_instalment_currency, data, "minInstalmentCurrency");
    regime::util::get(max_redraw, data, "maxRedraw");
    regime::util::get(max_redraw_currency, data, "maxRedrawCurrency");
    regime::util::get(min_redraw, data, "minRedraw");
    regime::util::get(min_redraw_currency, data, "minRedrawCurrency");
    regime::util::get(offset_account_enabled, data, "offsetAccountEnabled");
    regime::util::get(offset_account_ids, data, "offsetAccountIds");
    regime::util::get(repayment_type, data, RepaymentTypes, "repaymentType");
    regime::util::get(repayment_frequency, data, "repaymentFrequency");
}

Poco::JSON::Object::Ptr BankingLoanAccount::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "originalStartDate", original_start_date);
    regime::util::add(json, "originalLoanAmount", original_start_date);
    regime::util::add(json, "originalLoanCurrency", original_start_date);
    regime::util::add(json, "loanEndDate", original_start_date);
    regime::util::add(json, "nextInstalmentDate", original_start_date);
    regime::util::add(json, "minInstalmentAmount", original_start_date);
    regime::util::add(json, "minInstalmentCurrency", original_start_date);
    regime::util::add(json, "maxRedraw", original_start_date);
    regime::util::add(json, "maxRedrawCurrency", original_start_date);
    regime::util::add(json, "minRedraw", original_start_date);
    regime::util::add(json, "minRedrawCurrency", original_start_date);
    regime::util::add(json, "offsetAccountEnabled", original_start_date);
    regime::util::add(json, "offsetAccountIds", original_start_date);
    regime::util::add(json, "repaymentType", RepaymentTypes, repayment_type);
    regime::util::add(json, "repaymentFrequency", repayment_frequency);
    return json;
}

void BankingAccountDetail::deserialize(const Poco::JSON::Object::Ptr &data)
{
    account = BankingAccount();
    account.deserialize(data);
    regime::util::get(bsb, data, "bsb");
    regime::util::get(account_number, data, "accountNumber");
    regime::util::get(bundle_name, data, "bundleName");
    regime::util::get(specific_account_u_type, data, SpecificAccountUTypes, "specificAccountUType");
    regime::util::get(term_deposit, data, "termDeposit");
    regime::util::get(credit_card, data, "creditCard");
    regime::util::get(loan, data, "loan");
    regime::util::get(deposit_rate, data, "depositRate");
    regime::util::get(lending_rate, data, "lendingRate");
    regime::util::get(deposit_rates, data, "depositRates");
    regime::util::get(lending_rates, data, "lendingRates");
    regime::util::get(features, data, "features");
    regime::util::get(fees, data, "fees");
    regime::util::get(addresses, data, "addresses");
}

Poco::JSON::Object::Ptr BankingAccountDetail::to_json() const
{
    Poco::JSON::Object::Ptr json = account.to_json();
    regime::util::add(json, "bsb", bsb);
    regime::util::add(json, "accountNumber", account_number);
    regime::util::add(json, "bundleName", bundle_name);
    regime::util::add(json, "specificAccountUType", SpecificAccountUTypes, specific_account_u_type);
    regime::util::add(json, "termDeposit", term_deposit);
    regime::util::add(json, "creditCard", credit_card);
    regime::util::add(json, "loan", loan);
    regime::util::add(json, "depositRate", deposit_rate);
    regime::util::add(json, "lendingRate", lending_rate);
    regime::util::add(json, "depositRates", deposit_rates);
    regime::util::add(json, "lendingRates", lending_rates);
    regime::util::add(json, "features", features);
    regime::util::add(json, "fees", fees);
    regime::util::add(json, "addresses", addresses);
    return json;
}

void BankingTransaction::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(account_id, data, "accountId");
    regime::util::get(transaction_id, data, "transactionId");
    regime::util::get(is_detail_available, data, "isDetailAvailable");
    regime::util::get(type, data, TransactionTypes, "type");
    regime::util::get(status, data, TransactionStatuses, "status");
    regime::util::get(description, data, "description");
    regime::util::get(posting_date_time, data, "postingDateTime");
    regime::util::get(value_date_time, data, "valueDateTime");
    regime::util::get(execution_date_time, data, "executionDateTime");
    regime::util::get(amount, data, "amount");
    regime::util::get(currency, data, "currency");
    regime::util::get(reference, data, "reference");
    regime::util::get(merchant_name, data, "merchantName");
    regime::util::get(merchant_category_code, data, "merchantCategoryCode");
    regime::util::get(biller_code, data, "billerCode");
    regime::util::get(biller_name, data, "billerName");
    regime::util::get(crn, data, "crn");
    regime::util::get(apca_number, data, "apcaNumber");
}

Poco::JSON::Object::Ptr BankingTransaction::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "accountId", account_id);
    regime::util::add(json, "transactionId", transaction_id);
    regime::util::add(json, "isDetailAvailable", is_detail_available);
    regime::util::add(json, "type", TransactionTypes, type);
    regime::util::add(json, "status", TransactionStatuses, status);
    regime::util::add(json, "description", description);
    regime::util::add(json, "postingDateTime", posting_date_time);
    regime::util::add(json, "valueDateTime", value_date_time);
    regime::util::add(json, "executionDateTime", execution_date_time);
    regime::util::add(json, "amount", amount);
    regime::util::add(json, "currency", currency);
    regime::util::add(json, "reference", reference);
    regime::util::add(json, "merchantName", merchant_name);
    regime::util::add(json, "merchantCategoryCode", merchant_category_code);
    regime::util::add(json, "billerCode", biller_code);
    regime::util::add(json, "billerName", biller_name);
    regime::util::add(json, "crn", crn);
    regime::util::add(json, "apcaNumber", apca_number);
    return json;
}

void BankingTransactionDetail::deserialize(const Poco::JSON::Object::Ptr &data)
{
    transaction = BankingTransaction();
    transaction->deserialize(data);
    regime::util::get(extended_data, data, "extendedData");
}

Poco::JSON::Object::Ptr BankingTransactionDetail::to_json() const
{
    Poco::JSON::Object::Ptr json = transaction->to_json();
    regime::util::add(json, "extendedData", extended_data);
    return json;
}

void BankingBalancePurse::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(amount, data, "amount");
    regime::util::get(currency, data, "currency");
}

Poco::JSON::Object::Ptr BankingBalancePurse::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "amount", amount);
    regime::util::add(json, "currency", currency);
    return json;
}

void BankingBalance::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(account_id, data, "accountId");
    regime::util::get(current_balance, data, "currentBalance");
    regime::util::get(available_balance, data, "availableBalance");
    regime::util::get(credit_limit, data, "creditLimit");
    regime::util::get(amortised_limit, data, "amortisedLimit");
    regime::util::get(currency, data, "currency");
    regime::util::get(purses, data, "purses");
}

Poco::JSON::Object::Ptr BankingBalance::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "accountId", account_id);
    regime::util::add(json, "currentBalance", current_balance);
    regime::util::add(json, "availableBalance", available_balance);
    regime::util::add(json, "creditLimit", credit_limit);
    regime::util::add(json, "amortisedLimit", amortised_limit);
    regime::util::add(json, "currency", currency);
    regime::util::add(json, "purses", purses);
    return json;
}

void BankingPayee::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(payee_id, data, "payeeId");
    regime::util::get(nickname, data, "nickname");
    regime::util::get(description, data, "description");
    regime::util::get(type, data, PayeeTypes, "type");
    regime::util::get(creation_date, data, "creationDate");
}

Poco::JSON::Object::Ptr BankingPayee::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "payeeId", payee_id);
    regime::util::add(json, "nickname", payee_id);
    regime::util::add(json, "description", payee_id);
    regime::util::add(json, "type", PayeeTypes, type);
    regime::util::add(json, "creationDate", payee_id);
    return json;
}

void BankingDomesticPayeeAccount::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(account_name, data, "accountName");
    regime::util::get(bsb, data, "bsb");
    regime::util::get(account_number, data, "accountNumber");
}

Poco::JSON::Object::Ptr BankingDomesticPayeeAccount::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "accountName", account_name);
    regime::util::add(json, "bsb", bsb);
    regime::util::add(json, "accountNumber", account_number);
    return json;
}

void BankingDomesticPayeeCard::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(card_number, data, "cardNumber");
}

Poco::JSON::Object::Ptr BankingDomesticPayeeCard::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "cardNumber", card_number);
    return json;
}

void BankingDomesticPayeePayId::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(name, data, "name");
    regime::util::get(identifier, data, "identifier");
    regime::util::get(type, data, PayIdTypes, "type");
}

Poco::JSON::Object::Ptr BankingDomesticPayeePayId::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "name", name);
    regime::util::add(json, "identifier", identifier);
    regime::util::add(json, "type", PayIdTypes, type);
    return json;
}

void BankingDomesticPayee::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(payee_account_u_type, data, PayeeAccountUTypes, "payeeAccountUType");
    regime::util::get(account, data, "account");
    regime::util::get(card, data, "card");
    regime::util::get(pay_id, data, "payId");
}

Poco::JSON::Object::Ptr BankingDomesticPayee::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "payeeAccountUType", PayeeAccountUTypes, payee_account_u_type);
    regime::util::add(json, "account", account);
    regime::util::add(json, "card", card);
    regime::util::add(json, "payId", pay_id);
    return json;
}

void BankingBillerPayee::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(biller_code, data, "billerCode");
    regime::util::get(crn, data, "crn");
    regime::util::get(biller_name, data, "billerName");
}

Poco::JSON::Object::Ptr BankingBillerPayee::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "billerCode", biller_code);
    regime::util::add(json, "crn", crn);
    regime::util::add(json, "billerName", biller_name);
    return json;
}

void BankingInternationalPayee::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(beneficiary_details, data, "beneficiaryDetails");
    regime::util::get(bank_details, data, "bankDetails");
}

Poco::JSON::Object::Ptr BankingInternationalPayee::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "beneficiaryDetails", beneficiary_details);
    regime::util::add(json, "bankDetails", bank_details);
    return json;
}

void BankingPayeeDetail::deserialize(const Poco::JSON::Object::Ptr &data)
{
    payee = BankingPayee();
    payee->deserialize(data);
    regime::util::get(payee_u_type, data, PayeeUTypes, "payeeUType");
    regime::util::get(domestic, data, "domestic");
    regime::util::get(biller, data, "biller");
    regime::util::get(international, data, "international");
}

Poco::JSON::Object::Ptr BankingPayeeDetail::to_json() const
{
    Poco::JSON::Object::Ptr json = payee->to_json();
    regime::util::add(json, "payeeUType", PayeeUTypes, payee_u_type);
    regime::util::add(json, "domestic", domestic);
    regime::util::add(json, "biller", biller);
    regime::util::add(json, "international", international);
    return json;
}

void BankingAuthorisedEntity::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(description, data, "description");
    regime::util::get(financial_institution, data, "financialInstitution");
    regime::util::get(abn, data, "abn");
    regime::util::get(acn, data, "acn");
    regime::util::get(arbn, data, "arbn");
}

Poco::JSON::Object::Ptr BankingAuthorisedEntity::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "description", description);
    regime::util::add(json, "financialInstitution", financial_institution);
    regime::util::add(json, "abn", abn);
    regime::util::add(json, "acn", acn);
    regime::util::add(json, "arbn", arbn);
    return json;
}

void BankingDirectDebit::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(account_id, data, "accountId");
    regime::util::get(authorised_entity, data, "authorisedEntity");
    regime::util::get(last_debit_date_time, data, "lastDebitDateTime");
    regime::util::get(last_debit_amount, data, "lastDebitAmount");
}

Poco::JSON::Object::Ptr BankingDirectDebit::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "accountId", account_id);
    regime::util::add(json, "authorisedEntity", authorised_entity);
    regime::util::add(json, "lastDebitDateTime", last_debit_date_time);
    regime::util::add(json, "lastDebitAmount", last_debit_amount);
    return json;
}

void BankingScheduledPaymentTo::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(to_u_type, data, ToUTypes, "toUType");
    regime::util::get(account_id, data, "accountId");
    regime::util::get(payee_id, data, "payeeId");
    regime::util::get(domestic, data, "domestic");
    regime::util::get(biller, data, "biller");
    regime::util::get(international, data, "international");
}

Poco::JSON::Object::Ptr BankingScheduledPaymentTo::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "toUType", ToUTypes, to_u_type);
    regime::util::add(json, "accountId", account_id);
    regime::util::add(json, "payeeId", payee_id);
    regime::util::add(json, "domestic", domestic);
    regime::util::add(json, "biller", biller);
    regime::util::add(json, "international", international);
    return json;
}

void BankingScheduledPaymentSet::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(to, data, "to");
    regime::util::get(is_amount_calculated, data, "isAmountCalculated");
    regime::util::get(amount, data, "amount");
    regime::util::get(currency, data, "currency");
}

Poco::JSON::Object::Ptr BankingScheduledPaymentSet::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "to", to);
    regime::util::add(json, "isAmountCalculated", is_amount_calculated);
    regime::util::add(json, "amount", amount);
    regime::util::add(json, "currency", currency);
    return json;
}

void BankingScheduledPaymentFrom::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(account_id, data, "accountId");
}

Poco::JSON::Object::Ptr BankingScheduledPaymentFrom::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "accountId", account_id);
    return json;
}

void BankingScheduledPaymentInterval::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(interval, data, "interval");
    regime::util::get(day_in_interval, data, "dayInInterval");
}

Poco::JSON::Object::Ptr BankingScheduledPaymentInterval::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "interval", interval);
    regime::util::add(json, "dayInInterval", day_in_interval);
    return json;
}

void BankingScheduledPaymentRecurrenceIntervalSchedule::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(final_payment_date, data, "finalPaymentDate");
    regime::util::get(payments_remaining, data, "paymentsRemaining");
    regime::util::get(non_business_day_treatment, data, NonBusinessDayTreatments, "nonBusinessDayTreatment");
    regime::util::get(intervals, data, "intervals");
}

Poco::JSON::Object::Ptr BankingScheduledPaymentRecurrenceIntervalSchedule::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "finalPaymentDate", final_payment_date);
    regime::util::add(json, "paymentsRemaining", payments_remaining);
    regime::util::add(json, "nonBusinessDayTreatment", NonBusinessDayTreatments, non_business_day_treatment);
    regime::util::add(json, "intervals", intervals);
    return json;
}

void BankingScheduledPaymentRecurrenceLastWeekday::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(final_payment_date, data, "finalPaymentDate");
    regime::util::get(payments_remaining, data, "paymentsRemaining");
    regime::util::get(interval, data, "interval");
    regime::util::get(last_week_day, data, LastWeekDays, "lastWeekDay");
    regime::util::get(non_business_day_treatment, data, NonBusinessDayTreatments, "nonBusinessDayTreatment");
}

Poco::JSON::Object::Ptr BankingScheduledPaymentRecurrenceLastWeekday::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "finalPaymentDate", final_payment_date);
    regime::util::add(json, "paymentsRemaining", payments_remaining);
    regime::util::add(json, "interval", interval);
    regime::util::add(json, "lastWeekDay", LastWeekDays, last_week_day);
    regime::util::add(json, "nonBusinessDayTreatment", NonBusinessDayTreatments, non_business_day_treatment);
    return json;
}

void BankingScheduledPaymentRecurrenceEventBased::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(description, data, "description");
}

Poco::JSON::Object::Ptr BankingScheduledPaymentRecurrenceEventBased::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "description", description);
    return json;
}

void BankingScheduledPaymentRecurrenceOnceOff::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(payment_date, data, "paymentDate");
}

Poco::JSON::Object::Ptr BankingScheduledPaymentRecurrenceOnceOff::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "paymentDate", payment_date);
    return json;
}

void BankingScheduledPaymentRecurrence::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(next_payment_date, data, "nextPaymentDate");
    regime::util::get(recurrence_u_type, data, RecurrenceUTypes, "recurrenceUType");
    regime::util::get(once_off, data, "onceOff");
    regime::util::get(interval_schedule, data, "intervalSchedule");
    regime::util::get(last_week_day, data, "lastWeekDay");
    regime::util::get(event_based, data, "eventBased");
}

Poco::JSON::Object::Ptr BankingScheduledPaymentRecurrence::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "nextPaymentDate", next_payment_date);
    regime::util::add(json, "recurrenceUType", RecurrenceUTypes, recurrence_u_type);
    regime::util::add(json, "onceOff", once_off);
    regime::util::add(json, "intervalSchedule", interval_schedule);
    regime::util::add(json, "lastWeekDay", last_week_day);
    regime::util::add(json, "eventBased", event_based);
    return json;
}

void BankingScheduledPayment::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(scheduled_payment_id, data, "scheduledPaymentId");
    regime::util::get(nickname, data, "nickname");
    regime::util::get(payer_reference, data, "payerReference");
    regime::util::get(payee_reference, data, "payeeReference");
    regime::util::get(status, data, ScheduledPaymentStatuses, "status");
    regime::util::get(from, data, "from");
    regime::util::get(payment_set, data, "paymentSet");
    regime::util::get(recurrence, data, "recurrence");
}

Poco::JSON::Object::Ptr BankingScheduledPayment::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "scheduledPaymentId", scheduled_payment_id);
    regime::util::add(json, "nickname", nickname);
    regime::util::add(json, "payerReference", payer_reference);
    regime::util::add(json, "payeeReference", payee_reference);
    regime::util::add(json, "status", ScheduledPaymentStatuses, status);
    regime::util::add(json, "from", from);
    regime::util::add(json, "paymentSet", payment_set);
    regime::util::add(json, "recurrence", recurrence);
    return json;
}

void BankingProductV2::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(product_id, data, "productId");
    regime::util::get(last_updated, data, "lastUpdated");  // TODO convert type
    regime::util::get(product_category, data, ProductCategories, "productCategory");
    regime::util::get(name, data, "name");
    regime::util::get(description, data, "description");
    regime::util::get(brand, data, "brand");
    regime::util::get(is_tailored, data, "isTailored");
    regime::util::get(effective_from, data, "effectiveFrom");  // TODO convert type
    regime::util::get(effective_to, data, "effectiveTo");  // TODO convert type
    regime::util::get(brand_name, data, "brandName");
    regime::util::get(application_uri, data, "applicationUri");
    regime::util::get(additional_information, data, "additionalInformation");
    regime::util::get(card_art, data, "cardArt");
}

Poco::JSON::Object::Ptr BankingProductV2::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "productId", product_id);
    regime::util::add(json, "lastUpdated", last_updated);
    regime::util::add(json, "productCategory", ProductCategories, product_category);
    regime::util::add(json, "name", name);
    regime::util::add(json, "description", description);
    regime::util::add(json, "brand", brand);
    regime::util::add(json, "isTailored", is_tailored);
    regime::util::add(json, "effectiveFrom", effective_from);
    regime::util::add(json, "effectiveTo", effective_to);
    regime::util::add(json, "brandName", brand_name);
    regime::util::add(json, "applicationUri", application_uri);
    regime::util::add(json, "additionalInformation", additional_information);
    regime::util::add(json, "cardArt", card_art);
    return json;
}

void BankingProductDetail::deserialize(const Poco::JSON::Object::Ptr &data)
{
    product = BankingProductV2();
    product->deserialize(data);
    regime::util::get(bundles, data, "bundles");
    regime::util::get(features, data, "features");
    regime::util::get(constraints, data, "constraints");
    regime::util::get(eligibility, data, "eligibility");
    regime::util::get(fees, data, "fees");
    regime::util::get(deposit_rates, data, "depositRates");
    regime::util::get(lending_rates, data, "lendingRates");
}

Poco::JSON::Object::Ptr BankingProductDetail::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "product", product);
    regime::util::add(json, "bundles", bundles);
    regime::util::add(json, "features", features);
    regime::util::add(json, "constraints", constraints);
    regime::util::add(json, "eligibility", eligibility);
    regime::util::add(json, "fees", fees);
    regime::util::add(json, "depositRates", deposit_rates);
    regime::util::add(json, "lendingRates", lending_rates);
    return json;
}

void BankingProductFeatureToggled::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(feature_type, data, FeatureTypes, "featureType");
    regime::util::get(additional_value, data, "additionalValue");
    regime::util::get(additional_info, data, "additionalInfo");
    regime::util::get(additional_info_uri, data, "additionalInfoUri");
    regime::util::get(is_activated, data, "isActivated");
}

Poco::JSON::Object::Ptr BankingProductFeatureToggled::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "featureType", FeatureTypes, feature_type);
    regime::util::add(json, "additionalValue", additional_value);
    regime::util::add(json, "additionalInfo", additional_info);
    regime::util::add(json, "additionalInfoUri", additional_info_uri);
    regime::util::add(json, "isActivated", is_activated);
    return json;
}

void x2p101Payload::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(extended_description, data, "extendedDescription");
    regime::util::get(end_to_end_id, data, "endToEndId");
    regime::util::get(purpose_code, data, "purposeCode");
}

Poco::JSON::Object::Ptr x2p101Payload::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "extendedDescription", extended_description);
    regime::util::add(json, "endToEndId", end_to_end_id);
    regime::util::add(json, "purposeCode", purpose_code);
    return json;
}

void ExtendedData::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(service, data, TransactionOverlayServices, "service");
    regime::util::get(payer, data, "payer");
    regime::util::get(payee, data, "payee");
    regime::util::get(extension_u_type, data, ExtensionUTypes, "extensionUType");
    regime::util::get(x2p101_payload, data, "x2p101Payload");
}

Poco::JSON::Object::Ptr ExtendedData::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "service", TransactionOverlayServices, service);
    regime::util::add(json, "payer", payer);
    regime::util::add(json, "payee", payee);
    regime::util::add(json, "extensionUType", ExtensionUTypes, extension_u_type);
    regime::util::add(json, "x2p101Payload", x2p101_payload);
    return json;
}

void BeneficiaryDetails::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(name, data, "name");
    regime::util::get(country, data, "country");
    regime::util::get(message, data, "message");
}

Poco::JSON::Object::Ptr BeneficiaryDetails::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "name", name);
    regime::util::add(json, "country", country);
    regime::util::add(json, "message", message);
    return json;
}

void BankDetails::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(country, data, "country");
    regime::util::get(account_number, data, "accountNumber");
    regime::util::get(bank_address, data, "bankAddress");
    regime::util::get(beneficiary_bank_bic, data, "beneficiaryBankBIC");
    regime::util::get(fed_wire_number, data, "fedWireNumber");
    regime::util::get(sort_code, data, "sortCode");
    regime::util::get(chip_number, data, "chipNumber");
    regime::util::get(routing_number, data, "routingNumber");
    regime::util::get(legal_entity_identifier, data, "legalEntityIdentifier");
}

Poco::JSON::Object::Ptr BankDetails::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "country", country);
    regime::util::add(json, "accountNumber", account_number);
    regime::util::add(json, "bankAddress", bank_address);
    regime::util::add(json, "beneficiaryBankBIC", beneficiary_bank_bic);
    regime::util::add(json, "fedWireNumber", fed_wire_number);
    regime::util::add(json, "sortCode", sort_code);
    regime::util::add(json, "chipNumber", chip_number);
    regime::util::add(json, "routingNumber", routing_number);
    regime::util::add(json, "legalEntityIdentifier", legal_entity_identifier);
    return json;
}

void BankAddress::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(name, data, "name");
    regime::util::get(address, data, "address");
}

Poco::JSON::Object::Ptr BankAddress::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "name", name);
    regime::util::add(json, "address", address);
    return json;
}

void CardArt::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(image_uri, data, "imageUri");
    regime::util::get(title, data, "title");
}

Poco::JSON::Object::Ptr CardArt::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "imageUri", image_uri);
    regime::util::add(json, "title", title);
    return json;
}

void AdditionalInformation::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(overview_uri, data, "overviewUri");
    regime::util::get(terms_uri, data, "termsUri");
    regime::util::get(eligibility_uri, data, "eligibilityUri");
    regime::util::get(fees_and_pricing_uri, data, "feesAndPricingUri");
    regime::util::get(bundle_uri, data, "bundleUri");
}

Poco::JSON::Object::Ptr AdditionalInformation::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "overviewUri", overview_uri);
    regime::util::add(json, "termsUri", terms_uri);
    regime::util::add(json, "eligibilityUri", eligibility_uri);
    regime::util::add(json, "feesAndPricingUri", fees_and_pricing_uri);
    regime::util::add(json, "bundleUri", bundle_uri);
    return json;
}
