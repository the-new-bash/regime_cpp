#include "../../include/v1/types.hpp"

namespace regime::v1
{
    void CommonPerson::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(last_updated_time, data, "lastUpdateTime");
        get(first_name, data, "firstName");
        get(last_name, data, "lastName");
        get(middle_names, data, "middleNames");
        get(prefix, data, "prefix");
        get(suffix, data, "suffix");
        get(occupation_code, data, "occupationCode");
    }

    Poco::JSON::Object::Ptr CommonPerson::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "lastUpdatedTime", last_updated_time);
        add(json, "firstName", first_name);
        add(json, "lastName", last_name);
        add(json, "middleNames", middle_names);
        add(json, "prefix", prefix);
        add(json, "suffix", suffix);
        add(json, "occupationCode", occupation_code);
        return json;
    }

    void CommonPhoneNumber::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(is_preferred, data, "isPreferred");
        get(purpose, data, PhoneNumberPurposes, "purpose");
        get(country_code, data, "countryCode");
        get(area_code, data, "areaCode");
        get(number, data, "number");
        get(extension, data, "extension");
        get(full_number, data, "fullNumber");
    }

    Poco::JSON::Object::Ptr CommonPhoneNumber::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "isPreferred", is_preferred);
        add(json, "purpose", PhoneNumberPurposes, purpose);
        add(json, "countryCode", country_code);
        add(json, "areaCode", area_code);
        add(json, "number", number);
        add(json, "fullNumber", full_number);
        return json;
    }

    void CommonEmailAddress::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(is_preferred, data, "isPreferred");
        get(purpose, data, EmailAddressPurposes, "purpose");
        get(address, data, "address");
    }

    Poco::JSON::Object::Ptr CommonEmailAddress::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "isPreferred", is_preferred);
        add(json, "purpose", EmailAddressPurposes, purpose);
        add(json, "Regime::Utils::address", address);
        return json;
    }

    void CommonSimpleAddress::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(mailing_name, data, "mailingName");
        get(address_line1, data, "addressLine1");
        get(address_line2, data, "addressLine2");
        get(address_line3, data, "addressLine3");
        get(postcode, data, "postcode");
        get(city, data, "city");
        get(state, data, "state");
        get(country, data, "country");
    }

    Poco::JSON::Object::Ptr CommonSimpleAddress::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "mailingName", mailing_name);
        add(json, "addressLine1", address_line1);
        add(json, "addressLine2", address_line2);
        add(json, "addressLine3", address_line3);
        add(json, "postcode", postcode);
        add(json, "city", city);
        add(json, "state", state);
        add(json, "country", country);
        return json;
    }

    void CommonPAFAddress::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(dpid, data, "dpid");
        get(thoroughfare_number1, data, "thoroughfareNumber1");
        get(thoroughfare_number1_suffix, data, "thoroughfareNumber1Suffix");
        get(thoroughfare_number2, data, "thoroughfareNumber2");
        get(thoroughfare_number2_suffix, data, "thoroughfareNumber2Suffix");
        get(flat_unit_type, data, "flatUnitType");
        get(flat_unit_number, data, "flatUnitNumber");
        get(floor_level_type, data, "floorLevelType");
        get(floor_level_number, data, "floorLevelNumber");
        get(lot_number, data, "lotNumber");
        get(building_name1, data, "buildingName1");
        get(building_name2, data, "buildingName2");
        get(street_name, data, "streetName");
        get(street_type, data, "streetType");
        get(street_suffix, data, "streetSuffix");
        get(postal_delivery_type, data, "postalDeliveryType");
        get(postal_delivery_number, data, "postalDeliveryNumber");
        get(postal_delivery_number_prefix, data, "postalDeliveryNumberPrefix");
        get(postal_delivery_number_suffix, data, "postalDeliveryNumberSuffix");
        get(locality_name, data, "localityName");
        get(postcode, data, "postcode");
        get(state, data, "state");
    }

    Poco::JSON::Object::Ptr CommonPAFAddress::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "dpid", dpid);
        add(json, "thoroughfareNumber1", thoroughfare_number1);
        add(json, "thoroughfareNumber1Suffix", thoroughfare_number1_suffix);
        add(json, "thoroughfareNumber2", thoroughfare_number2);
        add(json, "thoroughfareNumber2Suffix", thoroughfare_number2_suffix);
        add(json, "flatUnitType", flat_unit_type);
        add(json, "flatUnitNumber", flat_unit_number);
        add(json, "floorLevelType", floor_level_type);
        add(json, "lotNumber", lot_number);
        add(json, "buildingName1", building_name1);
        add(json, "buildingName2", building_name2);
        add(json, "streetName", street_name);
        add(json, "streetType", street_type);
        add(json, "streetSuffix", street_suffix);
        add(json, "postalDeliveryType", postal_delivery_type);
        add(json, "postalDeliveryNumber", postal_delivery_number);
        add(json, "postalDeliveryNumberPrefix", postal_delivery_number_prefix);
        add(json, "postalDeliveryNumberSuffix", postal_delivery_number_suffix);
        add(json, "localityName", locality_name);
        add(json, "postcode", postcode);
        add(json, "state", state);
        return json;
    }

    void CommonPhysicalAddress::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(address_u_type, data, AddressUTypes, "addressUType");
        get(simple, data, "simple");
        get(paf, data, "paf");
    }

    Poco::JSON::Object::Ptr CommonPhysicalAddress::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "addressUType", AddressUTypes, address_u_type);
        add(json, "simple", simple);
        add(json, "paf", paf);
        return json;
    }

    void CommonPhysicalAddressWithPurpose::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        address = CommonPhysicalAddress();
        address.deserialize(data);
        get(purpose, data, PhysicalAddressPurposes, "purpose");
    }

    Poco::JSON::Object::Ptr CommonPhysicalAddressWithPurpose::to_json() const
    {
        Poco::JSON::Object::Ptr json = address.to_json();
        add(json, "purpose", PhysicalAddressPurposes, purpose);
        return json;
    }

    void CommonPersonDetail::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        person = CommonPerson();
        person.deserialize(data);
        get(phone_numbers, data, "phoneNumbers");
        get(email_addresses, data, "emailAddresses");
        get(physical_addresses, data, "physicalAddresses");
    }

    Poco::JSON::Object::Ptr CommonPersonDetail::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "phoneNumbers", phone_numbers);
        add(json, "emailAddresses", email_addresses);
        add(json, "physicalAddresses", physical_addresses);
        return json;
    }

    void CommonOrganisation::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(last_update_time, data, "lastUpdateTime");
        get(agent_first_name, data, "agentFirstName");
        get(agent_last_name, data, "agentLastName");
        get(agent_role, data, "agentRole");
        get(business_name, data, "businessName");
        get(legal_name, data, "legalName");
        get(short_name, data, "shortName");
        get(abn, data, "abn");
        get(acn, data, "acn");
        get(is_acnc_registered, data, "isACNCRegistered");
        get(industry_code, data, "industryCode");
        get(organisation_type, data, OrganisationTypes, "organisationType");
        get(registered_country, data, "registeredCountry");
        get(establishment_date, data, "establishmentDate");
    }

    Poco::JSON::Object::Ptr CommonOrganisation::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "lastUpdateTime", last_update_time);
        add(json, "agentFirstName", agent_first_name);
        add(json, "agentLastName", agent_last_name);
        add(json, "agentRole", agent_role);
        add(json, "businessName", business_name);
        add(json, "legalName", legal_name);
        add(json, "shortName", short_name);
        add(json, "abn", abn);
        add(json, "acn", acn);
        add(json, "isACNCRegistered", is_acnc_registered);
        add(json, "industryCode", industry_code);
        add(json, "organisationType", OrganisationTypes, organisation_type);
        add(json, "registeredCountry", registered_country);
        add(json, "establishmentDate", establishment_date);
        return json;
    }

    void CommonOrganisationDetail::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        organisation = CommonOrganisation();
        organisation.deserialize(data);
        get(physical_addresses, data, "physicalAddresses");
    }

    Poco::JSON::Object::Ptr CommonOrganisationDetail::to_json() const
    {
        Poco::JSON::Object::Ptr json = organisation.to_json();
        add(json, "physicalAddresses", physical_addresses);
        return json;
    }

    void BankingProductBundle::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(name, data, "name");
        get(description, data, "description");
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
        get(product_ids, data, "productIds");
    }

    Poco::JSON::Object::Ptr BankingProductBundle::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "name", name);
        add(json, "description", description);
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        add(json, "productIds", product_ids);
        return json;
    }

    void BankingProductFeature::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(feature_type, data, FeatureTypes, "featureType");
        get(additional_value, data, "additionalValue");
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
    }

    Poco::JSON::Object::Ptr BankingProductFeature::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "featureType", FeatureTypes, feature_type);
        add(json, "additionalValue", additional_value);
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        return json;
    }

    void BankingProductConstraint::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(constraint_type, data, ConstraintTypes, "constraintType");
        get(additional_value, data, "additionalValue");
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
    }

    Poco::JSON::Object::Ptr BankingProductConstraint::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "constraintType", ConstraintTypes, constraint_type);
        add(json, "additionalValue", additional_value);
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        return json;
    }

    void BankingProductEligibility::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(eligibility_type, data, EligibilityTypes, "eligibilityType");
        get(additional_value, data, "additionalValue");
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
    }

    Poco::JSON::Object::Ptr BankingProductEligibility::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "eligibilityType", EligibilityTypes, eligibility_type);
        add(json, "additionalValue", additional_value);
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        return json;
    }

    void BankingProductDiscountEligibility::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(discount_eligibility_type, data, DiscountEligibilityTypes, "discountEligibilityType");
        get(additional_value, data, "additionalValue");
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
    }

    Poco::JSON::Object::Ptr BankingProductDiscountEligibility::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "discountEligibilityType", DiscountEligibilityTypes, discount_eligibility_type);
        add(json, "additionalValue", additional_value);
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        return json;
    }

    void BankingProductDiscount::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(description, data, "description");
        get(discount_type, data, DiscountTypes, "discountType");
        get(amount, data, "amount");
        get(balance_rate, data, "balanceRate");
        get(transaction_rate, data, "transactionRate");
        get(accrued_rate, data, "accruedRate");
        get(fee_rate, data, "feeRate");
        get(additional_value, data, "additionalValue");
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
        get(eligibility, data, "eligibility");
    }

    Poco::JSON::Object::Ptr BankingProductDiscount::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "description", description);
        add(json, "discountType", DiscountTypes, discount_type);
        add(json, "amount", amount);
        add(json, "balanceRate", balance_rate);
        add(json, "transactionRate", transaction_rate);
        add(json, "accruedRate", accrued_rate);
        add(json, "feeRate", fee_rate);
        add(json, "additionalValue", additional_value);
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        add(json, "eligibility", eligibility);
        return json;
    }

    void BankingProductFee::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(name, data, "name");
        get(fee_type, data, FeeTypes, "feeType");
        get(amount, data, "amount");
        get(balance_rate, data, "balanceRate");
        get(transaction_rate, data, "transactionRate");
        get(accrued_rate, data, "accruedRate");
        get(accrual_frequency, data, "accrualFrequency");
        get(currency, data, "currency");  // TODO convert type
        get(additional_value, data, "additionalValue");
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
        get(discounts, data, "discounts");
    }

    Poco::JSON::Object::Ptr BankingProductFee::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "name", name);
        add(json, "feeType", FeeTypes, fee_type);
        add(json, "amount", amount);
        add(json, "balanceRate", balance_rate);
        add(json, "transactionRate", transaction_rate);
        add(json, "accruedRate", accrued_rate);
        add(json, "accrualFrequency", accrual_frequency);
        add(json, "currency", currency);
        add(json, "additionalValue", additional_value);
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        add(json, "discounts", discounts);
        return json;
    }

    void BankingProductRateCondition::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
    }

    Poco::JSON::Object::Ptr BankingProductRateCondition::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        return json;
    }

    void BankingProductRateSubTier::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(name, data, "name");
        get(unit_of_measure, data, UnitsOfMeasure, "unitOfMeasure");
        get(minimum_value, data, "minimumValue");
        get(maximum_value, data, "maximumValue");
        get(rate_application_method, data, RateApplicationMethods, "rateApplicationMethod");
        get(applicability_conditions, data, "applicabilityConditions");
    }

    Poco::JSON::Object::Ptr BankingProductRateSubTier::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "name", name);
        add(json, "unitOfMeasure", UnitsOfMeasure, unit_of_measure);
        add(json, "minimumValue", minimum_value);
        add(json, "maximumValue", maximum_value);
        add(json, "rateApplicationMethod", RateApplicationMethods, rate_application_method);
        add(json, "applicabilityConditions", applicability_conditions);
        return json;
    }

    void BankingProductRateTier::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(name, data, "name");
        get(unit_of_measure, data, UnitsOfMeasure, "unitOfMeasure");
        get(minimum_value, data, "minimumValue");
        get(maximum_value, data, "maximumValue");
        get(rate_application_method, data, RateApplicationMethods, "rateApplicationMethod");
        get(applicability_conditions, data, "applicabilityConditions");
        get(sub_tier, data, "subTier");
    }

    Poco::JSON::Object::Ptr BankingProductRateTier::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "name", name);
        add(json, "unitOfMeasure", UnitsOfMeasure, unit_of_measure);
        add(json, "minimumValue", minimum_value);
        add(json, "maximumValue", maximum_value);
        add(json, "rateApplicationMethod", RateApplicationMethods, rate_application_method);
        add(json, "applicabilityConditions", applicability_conditions);
        add(json, "subTier", sub_tier);
        return json;
    }

    void BankingProductDepositRate::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(deposit_rate_type, data, DepositRateTypes, "depositRateType");
        get(rate, data, "rate");
        get(calculation_frequency, data, "calculationFrequency");
        get(application_frequency, data, "applicationFrequency");
        get(tiers, data, "tiers");
        get(additional_value, data, "additionalValue");
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
    }

    Poco::JSON::Object::Ptr BankingProductDepositRate::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "depositRateType", DepositRateTypes, deposit_rate_type);
        add(json, "rate", rate);
        add(json, "calculationFrequency", calculation_frequency);
        add(json, "applicationFrequency", application_frequency);
        add(json, "tiers", tiers);
        add(json, "additionalValue", additional_value);
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        return json;
    }

    void BankingProductLendingRate::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(lending_rate_type, data, LendingRateTypes, "lendingRateType");
        get(rate, data, "rate");
        get(comparison_rate, data, "comparisonRate");
        get(calculation_frequency, data, "calculationFrequency");
        get(application_frequency, data, "applicationFrequency");
        get(interest_payment_due, data, InterestPaymentDueFields, "interestPaymentDue");
        get(tiers, data, "tiers");
        get(additional_value, data, "additionalValue");
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
    }

    Poco::JSON::Object::Ptr BankingProductLendingRate::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "lendingRateType", LendingRateTypes, lending_rate_type);
        add(json, "rate", rate);
        add(json, "comparisonRate", comparison_rate);
        add(json, "calculationFrequency", calculation_frequency);
        add(json, "applicationFrequency", application_frequency);
        add(json, "interestPaymentDue", InterestPaymentDueFields, interest_payment_due);
        add(json, "tiers", tiers);
        add(json, "additionalValue", additional_value);
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        return json;
    }

    void BankingAccount::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(account_id, data, "accountId");
        get(creation_date, data, "creationDate");
        get(display_name, data, "displayName");
        get(nickname, data, "nickname");
        get(open_status, data, OpenStatuses, "openStatus");
        get(is_owned, data, "isOwned");
        get(masked_number, data, "maskedNumber");
        get(product_category, data, ProductCategories, "productCategory");
        get(product_name, data, "productName");
    }

    Poco::JSON::Object::Ptr BankingAccount::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "accountId", account_id);
        add(json, "creationDate", creation_date);
        add(json, "displayName", display_name);
        add(json, "nickname", nickname);
        add(json, "openStatus", OpenStatuses, open_status);
        add(json, "isOwned", is_owned);
        add(json, "maskedNumber", masked_number);
        add(json, "productCategory", ProductCategories, product_category);
        add(json, "productName", product_name);
        return json;
    }

    void BankingTermDepositAccount::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(lodgement_date, data, "lodgementDate");
        get(maturity_date, data, "maturityDate");
        get(maturity_amount, data, "maturityAmount");
        get(maturity_currency, data, "maturityCurrency");
        get(maturity_instructions, data, MaturityInstructionReflections, "maturityInstructions");
    }

    Poco::JSON::Object::Ptr BankingTermDepositAccount::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "lodgementDate", lodgement_date);
        add(json, "maturityDate", maturity_date);
        add(json, "maturityAmount", maturity_amount);
        add(json, "maturityCurrency", maturity_currency);
        add(json, "maturityInstructions", MaturityInstructionReflections, maturity_instructions);
        return json;
    }

    void BankingCreditCardAccount::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(min_payment_amount, data, "minPaymentAmount");
        get(payment_due_amount, data, "paymentDueAmount");
        get(payment_currency, data, "paymentCurrency");
        get(payment_due_date, data, "paymentDueDate");
    }

    Poco::JSON::Object::Ptr BankingCreditCardAccount::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "minPaymentAmount", min_payment_amount);
        add(json, "paymentDueAmount", payment_due_date);
        add(json, "paymentCurrency", payment_currency);
        add(json, "paymentDueDate", payment_due_date);
        return json;
    }

    void BankingLoanAccount::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(original_start_date, data, "originalStartDate");
        get(original_loan_amount, data, "originalLoanAmount");
        get(original_loan_currency, data, "originalLoanCurrency");
        get(loan_end_date, data, "loanEndDate");
        get(next_instalment_date, data, "nextInstalmentDate");
        get(min_instalment_amount, data, "minInstalmentAmount");
        get(min_instalment_currency, data, "minInstalmentCurrency");
        get(max_redraw, data, "maxRedraw");
        get(max_redraw_currency, data, "maxRedrawCurrency");
        get(min_redraw, data, "minRedraw");
        get(min_redraw_currency, data, "minRedrawCurrency");
        get(offset_account_enabled, data, "offsetAccountEnabled");
        get(offset_account_ids, data, "offsetAccountIds");
        get(repayment_type, data, RepaymentTypes, "repaymentType");
        get(repayment_frequency, data, "repaymentFrequency");
    }

    Poco::JSON::Object::Ptr BankingLoanAccount::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "originalStartDate", original_start_date);
        add(json, "originalLoanAmount", original_start_date);
        add(json, "originalLoanCurrency", original_start_date);
        add(json, "loanEndDate", original_start_date);
        add(json, "nextInstalmentDate", original_start_date);
        add(json, "minInstalmentAmount", original_start_date);
        add(json, "minInstalmentCurrency", original_start_date);
        add(json, "maxRedraw", original_start_date);
        add(json, "maxRedrawCurrency", original_start_date);
        add(json, "minRedraw", original_start_date);
        add(json, "minRedrawCurrency", original_start_date);
        add(json, "offsetAccountEnabled", original_start_date);
        add(json, "offsetAccountIds", original_start_date);
        add(json, "repaymentType", RepaymentTypes, repayment_type);
        add(json, "repaymentFrequency", repayment_frequency);
        return json;
    }

    void BankingAccountDetail::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        account = BankingAccount();
        account.deserialize(data);
        get(bsb, data, "bsb");
        get(account_number, data, "accountNumber");
        get(bundle_name, data, "bundleName");
        get(specific_account_u_type, data, SpecificAccountUTypes, "specificAccountUType");
        get(term_deposit, data, "termDeposit");
        get(credit_card, data, "creditCard");
        get(loan, data, "loan");
        get(deposit_rate, data, "depositRate");
        get(lending_rate, data, "lendingRate");
        get(deposit_rates, data, "depositRates");
        get(lending_rates, data, "lendingRates");
        get(features, data, "features");
        get(fees, data, "fees");
        get(addresses, data, "addresses");
    }

    Poco::JSON::Object::Ptr BankingAccountDetail::to_json() const
    {
        Poco::JSON::Object::Ptr json = account.to_json();
        add(json, "bsb", bsb);
        add(json, "accountNumber", account_number);
        add(json, "bundleName", bundle_name);
        add(json, "specificAccountUType", SpecificAccountUTypes, specific_account_u_type);
        add(json, "termDeposit", term_deposit);
        add(json, "creditCard", credit_card);
        add(json, "loan", loan);
        add(json, "depositRate", deposit_rate);
        add(json, "lendingRate", lending_rate);
        add(json, "depositRates", deposit_rates);
        add(json, "lendingRates", lending_rates);
        add(json, "features", features);
        add(json, "fees", fees);
        add(json, "addresses", addresses);
        return json;
    }

    void BankingTransaction::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(account_id, data, "accountId");
        get(transaction_id, data, "transactionId");
        get(is_detail_available, data, "isDetailAvailable");
        get(type, data, TransactionTypes, "type");
        get(status, data, TransactionStatuses, "status");
        get(description, data, "description");
        get(posting_date_time, data, "postingDateTime");
        get(value_date_time, data, "valueDateTime");
        get(execution_date_time, data, "executionDateTime");
        get(amount, data, "amount");
        get(currency, data, "currency");
        get(reference, data, "reference");
        get(merchant_name, data, "merchantName");
        get(merchant_category_code, data, "merchantCategoryCode");
        get(biller_code, data, "billerCode");
        get(biller_name, data, "billerName");
        get(crn, data, "crn");
        get(apca_number, data, "apcaNumber");
    }

    Poco::JSON::Object::Ptr BankingTransaction::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "accountId", account_id);
        add(json, "transactionId", transaction_id);
        add(json, "isDetailAvailable", is_detail_available);
        add(json, "type", TransactionTypes, type);
        add(json, "status", TransactionStatuses, status);
        add(json, "description", description);
        add(json, "postingDateTime", posting_date_time);
        add(json, "valueDateTime", value_date_time);
        add(json, "executionDateTime", execution_date_time);
        add(json, "amount", amount);
        add(json, "currency", currency);
        add(json, "reference", reference);
        add(json, "merchantName", merchant_name);
        add(json, "merchantCategoryCode", merchant_category_code);
        add(json, "billerCode", biller_code);
        add(json, "billerName", biller_name);
        add(json, "crn", crn);
        add(json, "apcaNumber", apca_number);
        return json;
    }

    void BankingTransactionDetail::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        transaction = BankingTransaction();
        transaction->deserialize(data);
        get(extended_data, data, "extendedData");
    }

    Poco::JSON::Object::Ptr BankingTransactionDetail::to_json() const
    {
        Poco::JSON::Object::Ptr json = transaction->to_json();
        add(json, "extendedData", extended_data);
        return json;
    }

    void BankingBalancePurse::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(amount, data, "amount");
        get(currency, data, "currency");
    }

    Poco::JSON::Object::Ptr BankingBalancePurse::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "amount", amount);
        add(json, "currency", currency);
        return json;
    }

    void BankingBalance::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(account_id, data, "accountId");
        get(current_balance, data, "currentBalance");
        get(available_balance, data, "availableBalance");
        get(credit_limit, data, "creditLimit");
        get(amortised_limit, data, "amortisedLimit");
        get(currency, data, "currency");
        get(purses, data, "purses");
    }

    Poco::JSON::Object::Ptr BankingBalance::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "accountId", account_id);
        add(json, "currentBalance", current_balance);
        add(json, "availableBalance", available_balance);
        add(json, "creditLimit", credit_limit);
        add(json, "amortisedLimit", amortised_limit);
        add(json, "currency", currency);
        add(json, "purses", purses);
        return json;
    }

    void BankingPayee::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(payee_id, data, "payeeId");
        get(nickname, data, "nickname");
        get(description, data, "description");
        get(type, data, PayeeTypes, "type");
        get(creation_date, data, "creationDate");
    }

    Poco::JSON::Object::Ptr BankingPayee::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "payeeId", payee_id);
        add(json, "nickname", payee_id);
        add(json, "description", payee_id);
        add(json, "type", PayeeTypes, type);
        add(json, "creationDate", payee_id);
        return json;
    }

    void BankingDomesticPayeeAccount::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(account_name, data, "accountName");
        get(bsb, data, "bsb");
        get(account_number, data, "accountNumber");
    }

    Poco::JSON::Object::Ptr BankingDomesticPayeeAccount::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "accountName", account_name);
        add(json, "bsb", bsb);
        add(json, "accountNumber", account_number);
        return json;
    }

    void BankingDomesticPayeeCard::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(card_number, data, "cardNumber");
    }

    Poco::JSON::Object::Ptr BankingDomesticPayeeCard::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "cardNumber", card_number);
        return json;
    }

    void BankingDomesticPayeePayId::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(name, data, "name");
        get(identifier, data, "identifier");
        get(type, data, PayIdTypes, "type");
    }

    Poco::JSON::Object::Ptr BankingDomesticPayeePayId::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "name", name);
        add(json, "identifier", identifier);
        add(json, "type", PayIdTypes, type);
        return json;
    }

    void BankingDomesticPayee::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(payee_account_u_type, data, PayeeAccountUTypes, "payeeAccountUType");
        get(account, data, "account");
        get(card, data, "card");
        get(pay_id, data, "payId");
    }

    Poco::JSON::Object::Ptr BankingDomesticPayee::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "payeeAccountUType", PayeeAccountUTypes, payee_account_u_type);
        add(json, "account", account);
        add(json, "card", card);
        add(json, "payId", pay_id);
        return json;
    }

    void BankingBillerPayee::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(biller_code, data, "billerCode");
        get(crn, data, "crn");
        get(biller_name, data, "billerName");
    }

    Poco::JSON::Object::Ptr BankingBillerPayee::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "billerCode", biller_code);
        add(json, "crn", crn);
        add(json, "billerName", biller_name);
        return json;
    }

    void BankingInternationalPayee::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(beneficiary_details, data, "beneficiaryDetails");
        get(bank_details, data, "bankDetails");
    }

    Poco::JSON::Object::Ptr BankingInternationalPayee::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "beneficiaryDetails", beneficiary_details);
        add(json, "bankDetails", bank_details);
        return json;
    }

    void BankingPayeeDetail::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        payee = BankingPayee();
        payee->deserialize(data);
        get(payee_u_type, data, PayeeUTypes, "payeeUType");
        get(domestic, data, "domestic");
        get(biller, data, "biller");
        get(international, data, "international");
    }

    Poco::JSON::Object::Ptr BankingPayeeDetail::to_json() const
    {
        Poco::JSON::Object::Ptr json = payee->to_json();
        add(json, "payeeUType", PayeeUTypes, payee_u_type);
        add(json, "domestic", domestic);
        add(json, "biller", biller);
        add(json, "international", international);
        return json;
    }

    void BankingAuthorisedEntity::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(description, data, "description");
        get(financial_institution, data, "financialInstitution");
        get(abn, data, "abn");
        get(acn, data, "acn");
        get(arbn, data, "arbn");
    }

    Poco::JSON::Object::Ptr BankingAuthorisedEntity::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "description", description);
        add(json, "financialInstitution", financial_institution);
        add(json, "abn", abn);
        add(json, "acn", acn);
        add(json, "arbn", arbn);
        return json;
    }

    void BankingDirectDebit::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(account_id, data, "accountId");
        get(authorised_entity, data, "authorisedEntity");
        get(last_debit_date_time, data, "lastDebitDateTime");
        get(last_debit_amount, data, "lastDebitAmount");
    }

    Poco::JSON::Object::Ptr BankingDirectDebit::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "accountId", account_id);
        add(json, "authorisedEntity", authorised_entity);
        add(json, "lastDebitDateTime", last_debit_date_time);
        add(json, "lastDebitAmount", last_debit_amount);
        return json;
    }

    void BankingScheduledPaymentTo::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(to_u_type, data, ToUTypes, "toUType");
        get(account_id, data, "accountId");
        get(payee_id, data, "payeeId");
        get(domestic, data, "domestic");
        get(biller, data, "biller");
        get(international, data, "international");
    }

    Poco::JSON::Object::Ptr BankingScheduledPaymentTo::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "toUType", ToUTypes, to_u_type);
        add(json, "accountId", account_id);
        add(json, "payeeId", payee_id);
        add(json, "domestic", domestic);
        add(json, "biller", biller);
        add(json, "international", international);
        return json;
    }

    void BankingScheduledPaymentSet::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(to, data, "to");
        get(is_amount_calculated, data, "isAmountCalculated");
        get(amount, data, "amount");
        get(currency, data, "currency");
    }

    Poco::JSON::Object::Ptr BankingScheduledPaymentSet::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "to", to);
        add(json, "isAmountCalculated", is_amount_calculated);
        add(json, "amount", amount);
        add(json, "currency", currency);
        return json;
    }

    void BankingScheduledPaymentFrom::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(account_id, data, "accountId");
    }

    Poco::JSON::Object::Ptr BankingScheduledPaymentFrom::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "accountId", account_id);
        return json;
    }

    void BankingScheduledPaymentInterval::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(interval, data, "interval");
        get(day_in_interval, data, "dayInInterval");
    }

    Poco::JSON::Object::Ptr BankingScheduledPaymentInterval::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "interval", interval);
        add(json, "dayInInterval", day_in_interval);
        return json;
    }

    void BankingScheduledPaymentRecurrenceIntervalSchedule::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(final_payment_date, data, "finalPaymentDate");
        get(payments_remaining, data, "paymentsRemaining");
        get(non_business_day_treatment, data, NonBusinessDayTreatments, "nonBusinessDayTreatment");
        get(intervals, data, "intervals");
    }

    Poco::JSON::Object::Ptr BankingScheduledPaymentRecurrenceIntervalSchedule::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "finalPaymentDate", final_payment_date);
        add(json, "paymentsRemaining", payments_remaining);
        add(json, "nonBusinessDayTreatment", NonBusinessDayTreatments, non_business_day_treatment);
        add(json, "intervals", intervals);
        return json;
    }

    void BankingScheduledPaymentRecurrenceLastWeekday::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(final_payment_date, data, "finalPaymentDate");
        get(payments_remaining, data, "paymentsRemaining");
        get(interval, data, "interval");
        get(last_week_day, data, LastWeekDays, "lastWeekDay");
        get(non_business_day_treatment, data, NonBusinessDayTreatments, "nonBusinessDayTreatment");
    }

    Poco::JSON::Object::Ptr BankingScheduledPaymentRecurrenceLastWeekday::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "finalPaymentDate", final_payment_date);
        add(json, "paymentsRemaining", payments_remaining);
        add(json, "interval", interval);
        add(json, "lastWeekDay", LastWeekDays, last_week_day);
        add(json, "nonBusinessDayTreatment", NonBusinessDayTreatments, non_business_day_treatment);
        return json;
    }

    void BankingScheduledPaymentRecurrenceEventBased::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(description, data, "description");
    }

    Poco::JSON::Object::Ptr BankingScheduledPaymentRecurrenceEventBased::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "description", description);
        return json;
    }

    void BankingScheduledPaymentRecurrenceOnceOff::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(payment_date, data, "paymentDate");
    }

    Poco::JSON::Object::Ptr BankingScheduledPaymentRecurrenceOnceOff::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "paymentDate", payment_date);
        return json;
    }

    void BankingScheduledPaymentRecurrence::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(next_payment_date, data, "nextPaymentDate");
        get(recurrence_u_type, data, RecurrenceUTypes, "recurrenceUType");
        get(once_off, data, "onceOff");
        get(interval_schedule, data, "intervalSchedule");
        get(last_week_day, data, "lastWeekDay");
        get(event_based, data, "eventBased");
    }

    Poco::JSON::Object::Ptr BankingScheduledPaymentRecurrence::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "nextPaymentDate", next_payment_date);
        add(json, "recurrenceUType", RecurrenceUTypes, recurrence_u_type);
        add(json, "onceOff", once_off);
        add(json, "intervalSchedule", interval_schedule);
        add(json, "lastWeekDay", last_week_day);
        add(json, "eventBased", event_based);
        return json;
    }

    void BankingScheduledPayment::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(scheduled_payment_id, data, "scheduledPaymentId");
        get(nickname, data, "nickname");
        get(payer_reference, data, "payerReference");
        get(payee_reference, data, "payeeReference");
        get(status, data, ScheduledPaymentStatuses, "status");
        get(from, data, "from");
        get(payment_set, data, "paymentSet");
        get(recurrence, data, "recurrence");
    }

    Poco::JSON::Object::Ptr BankingScheduledPayment::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "scheduledPaymentId", scheduled_payment_id);
        add(json, "nickname", nickname);
        add(json, "payerReference", payer_reference);
        add(json, "payeeReference", payee_reference);
        add(json, "status", ScheduledPaymentStatuses, status);
        add(json, "from", from);
        add(json, "paymentSet", payment_set);
        add(json, "recurrence", recurrence);
        return json;
    }

    void BankingProductV2::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(product_id, data, "productId");
        get(last_updated, data, "lastUpdated");  // TODO convert type
        get(product_category, data, ProductCategories, "productCategory");
        get(name, data, "name");
        get(description, data, "description");
        get(brand, data, "brand");
        get(is_tailored, data, "isTailored");
        get(effective_from, data, "effectiveFrom");  // TODO convert type
        get(effective_to, data, "effectiveTo");  // TODO convert type
        get(brand_name, data, "brandName");
        get(application_uri, data, "applicationUri");
        get(additional_information, data, "additionalInformation");
        get(card_art, data, "cardArt");
    }

    Poco::JSON::Object::Ptr BankingProductV2::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "productId", product_id);
        add(json, "lastUpdated", last_updated);
        add(json, "productCategory", ProductCategories, product_category);
        add(json, "name", name);
        add(json, "description", description);
        add(json, "brand", brand);
        add(json, "isTailored", is_tailored);
        add(json, "effectiveFrom", effective_from);
        add(json, "effectiveTo", effective_to);
        add(json, "brandName", brand_name);
        add(json, "applicationUri", application_uri);
        add(json, "additionalInformation", additional_information);
        add(json, "cardArt", card_art);
        return json;
    }

    void BankingProductDetail::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        product = BankingProductV2();
        product->deserialize(data);
        get(bundles, data, "bundles");
        get(features, data, "features");
        get(constraints, data, "constraints");
        get(eligibility, data, "eligibility");
        get(fees, data, "fees");
        get(deposit_rates, data, "depositRates");
        get(lending_rates, data, "lendingRates");
    }

    Poco::JSON::Object::Ptr BankingProductDetail::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "product", product);
        add(json, "bundles", bundles);
        add(json, "features", features);
        add(json, "constraints", constraints);
        add(json, "eligibility", eligibility);
        add(json, "fees", fees);
        add(json, "depositRates", deposit_rates);
        add(json, "lendingRates", lending_rates);
        return json;
    }

    void BankingProductFeatureToggled::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(feature_type, data, FeatureTypes, "featureType");
        get(additional_value, data, "additionalValue");
        get(additional_info, data, "additionalInfo");
        get(additional_info_uri, data, "additionalInfoUri");
        get(is_activated, data, "isActivated");
    }

    Poco::JSON::Object::Ptr BankingProductFeatureToggled::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "featureType", FeatureTypes, feature_type);
        add(json, "additionalValue", additional_value);
        add(json, "additionalInfo", additional_info);
        add(json, "additionalInfoUri", additional_info_uri);
        add(json, "isActivated", is_activated);
        return json;
    }

    void x2p101Payload::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(extended_description, data, "extendedDescription");
        get(end_to_end_id, data, "endToEndId");
        get(purpose_code, data, "purposeCode");
    }

    Poco::JSON::Object::Ptr x2p101Payload::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "extendedDescription", extended_description);
        add(json, "endToEndId", end_to_end_id);
        add(json, "purposeCode", purpose_code);
        return json;
    }

    void ExtendedData::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(service, data, TransactionOverlayServices, "service");
        get(payer, data, "payer");
        get(payee, data, "payee");
        get(extension_u_type, data, ExtensionUTypes, "extensionUType");
        get(x2p101_payload, data, "x2p101Payload");
    }

    Poco::JSON::Object::Ptr ExtendedData::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "service", TransactionOverlayServices, service);
        add(json, "payer", payer);
        add(json, "payee", payee);
        add(json, "extensionUType", ExtensionUTypes, extension_u_type);
        add(json, "x2p101Payload", x2p101_payload);
        return json;
    }

    void BeneficiaryDetails::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(name, data, "name");
        get(country, data, "country");
        get(message, data, "message");
    }

    Poco::JSON::Object::Ptr BeneficiaryDetails::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "name", name);
        add(json, "country", country);
        add(json, "message", message);
        return json;
    }

    void BankDetails::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(country, data, "country");
        get(account_number, data, "accountNumber");
        get(bank_address, data, "bankAddress");
        get(beneficiary_bank_bic, data, "beneficiaryBankBIC");
        get(fed_wire_number, data, "fedWireNumber");
        get(sort_code, data, "sortCode");
        get(chip_number, data, "chipNumber");
        get(routing_number, data, "routingNumber");
        get(legal_entity_identifier, data, "legalEntityIdentifier");
    }

    Poco::JSON::Object::Ptr BankDetails::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "country", country);
        add(json, "accountNumber", account_number);
        add(json, "bankAddress", bank_address);
        add(json, "beneficiaryBankBIC", beneficiary_bank_bic);
        add(json, "fedWireNumber", fed_wire_number);
        add(json, "sortCode", sort_code);
        add(json, "chipNumber", chip_number);
        add(json, "routingNumber", routing_number);
        add(json, "legalEntityIdentifier", legal_entity_identifier);
        return json;
    }

    void BankAddress::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(name, data, "name");
        get(address, data, "address");
    }

    Poco::JSON::Object::Ptr BankAddress::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "name", name);
        add(json, "address", address);
        return json;
    }

    void CardArt::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(image_uri, data, "imageUri");
        get(title, data, "title");
    }

    Poco::JSON::Object::Ptr CardArt::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "imageUri", image_uri);
        add(json, "title", title);
        return json;
    }

    void AdditionalInformation::deserialize(const Poco::JSON::Object::Ptr &data)
    {
        get(overview_uri, data, "overviewUri");
        get(terms_uri, data, "termsUri");
        get(eligibility_uri, data, "eligibilityUri");
        get(fees_and_pricing_uri, data, "feesAndPricingUri");
        get(bundle_uri, data, "bundleUri");
    }

    Poco::JSON::Object::Ptr AdditionalInformation::to_json() const
    {
        Poco::JSON::Object::Ptr json;
        add(json, "overviewUri", overview_uri);
        add(json, "termsUri", terms_uri);
        add(json, "eligibilityUri", eligibility_uri);
        add(json, "feesAndPricingUri", fees_and_pricing_uri);
        add(json, "bundleUri", bundle_uri);
        return json;
    }

    std::string IObject::serialize() const
    {
        const auto obj = to_json();
        std::ostringstream oss;
        obj->stringify(oss);
        return oss.str();
    }
}
