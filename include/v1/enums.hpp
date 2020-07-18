#ifndef REGIME_V1_ENUMS_HPP
#define REGIME_V1_ENUMS_HPP

#include <array>
#include <string>
#include "utils.hpp"

namespace regime::v1
{
    template<class T>
    struct EnumStringPair
    {
        using value_type = T;
        const T _enum;
        std::string _string;
    };

    enum class Bank
    {
        ANZ,
        CBA,
        NAB,
        WBC,
    };

    enum class AddressUType
    {
        SIMPLE,
        PAF
    };

    enum class OrganisationType
    {
        SOLE_TRADER,
        COMPANY,
        PARTNERSHIP,
        TRUST,
        GOVERNMENT_ENTITY,
        OTHER
    };

    enum class PhoneNumberPurpose
    {
        MOBILE,
        HOME,
        WORK,
        OTHER,
        INTERNATIONAL,
        UNSPECIFIED
    };

    enum class EmailAddressPurpose
    {
        WORK,
        HOME,
        OTHER,
        UNSPECIFIED
    };

    enum class PhysicalAddressPurpose
    {
        REGISTERED,
        MAIL,
        PHYSICAL,
        WORK,
        OTHER
    };

    enum class Effective
    {
        CURRENT,
        FUTURE,
        ALL
    };

    enum class ProductCategory
    {
        TRANS_AND_SAVINGS_ACCOUNTS,
        TERM_DEPOSITS,
        TRAVEL_CARDS,
        REGULATED_TRUST_ACCOUNTS,
        RESIDENTIAL_MORTGAGES,
        CRED_AND_CHRG_CARDS,
        PERS_LOANS,
        MARGIN_LOANS,
        LEASES,
        TRADE_FINANCE,
        OVERDRAFTS,
        BUSINESS_LOANS
    };

    enum class FeatureType
    {
        CARD_ACCESS,
        ADDITIONAL_CARDS,
        UNLIMITED_TXNS,
        FREE_TXNS,
        FREE_TXNS_ALLOWANCE,
        LOYALTY_PROGRAM,
        OFFSET,
        OVERDRAFT,
        REDRAW,
        INSURANCE,
        BALANCE_TRANSFERS,
        INTEREST_FREE,
        INTEREST_FREE_TRANSFERS,
        DIGITAL_WALLET,
        DIGITAL_BANKING,
        NPP_PAYID,
        NPP_ENABLED,
        DONATE_INTEREST,
        BILL_PAYMENT,
        COMPLEMENTARY_PRODUCT_DISCOUNTS,
        BONUS_REWARDS,
        NOTIFICATIONS,
        OTHER
    };

    enum class ConstraintType
    {
        MIN_BALANCE,
        MAX_BALANCE,
        OPENING_BALANCE,
        MAX_LIMIT,
        MIN_LIMIT
    };

    enum class EligibilityType
    {
        BUSINESS,
        PENSION_RECIPIENT,
        MIN_AGE,
        MAX_AGE,
        MIN_INCOME,
        MIN_TURNOVER,
        STAFF,
        STUDENT,
        EMPLOYMENT_STATUS,
        RESIDENCY_STATUS,
        NATURAL_PERSON,
        OTHER
    };

    enum class FeeType
    {
        PERIODIC,
        TRANSACTION,
        WITHDRAWAL,
        DEPOSIT,
        PAYMENT,
        PURCHASE,
        EVENT,
        UPFRONT,
        EXIT
    };

    enum class DiscountType
    {
        BALANCE,
        DEPOSITS,
        PAYMENTS,
        FEE_CAP,
        ELIGIBILITY_ONLY
    };

    enum class DiscountEligibilityType
    {
        BUSINESS,
        PENSION_RECIPIENT,
        MIN_AGE,
        MAX_AGE,
        MIN_INCOME,
        MIN_TURNOVER,
        STAFF,
        STUDENT,
        EMPLOYMENT_STATUS,
        RESIDENCY_STATUS,
        NATURAL_PERSON,
        INTRODUCTORY,
        OTHER
    };

    enum class DepositRateType
    {
        FIXED,
        BONUS,
        BUNDLE_BONUS,
        VARIABLE,
        INTRODUCTORY,
        FLOATING,
        MARKET_LINKED
    };

    enum class LendingRateType
    {
        FIXED,
        VARIABLE,
        INTRODUCTORY,
        DISCOUNT,
        PENALTY,
        FLOATING,
        MARKET_LINKED,
        CASH_ADVANCE,
        PURCHASE,
        BUNDLE_DISCOUNT_FIXED,
        BUNDLE_DISCOUNT_VARIABLE
    };

    enum class InterestPaymentDue
    {
        IN_ARREARS,
        IN_ADVANCE
    };

    enum class RateApplicationMethod
    {
        WHOLE_BALANCE,
        PER_TIER
    };

    enum class UnitOfMeasure
    {
        DOLLAR,
        PERCENT,
        MONTH,
        DAY
    };

    enum class OpenStatus
    {
        OPEN,
        CLOSED
    };

    enum class SpecificAccountUType
    {
        TERM_DEPOSIT,
        CREDIT_CARD,
        LOAN
    };

    enum class MaturityInstructions
    {
        ROLLED_OVER,
        PAID_OUT_AT_MATURITY
    };

    enum class RepaymentType
    {
        INTEREST_ONLY,
        PRINCIPAL_AND_INTEREST
    };

    enum class TransactionType
    {
        FEE,
        INTEREST_CHARGED,
        INTEREST_PAID,
        TRANSFER_OUTGOING,
        TRANSFER_INCOMING,
        PAYMENT,
        DIRECT_DEBIT,
        OTHER
    };

    enum class TransactionStatus
    {
        PENDING,
        POSTED
    };

    enum class ExtensionUType
    {
        X2P101PAYLOAD
    };

    enum class TransactionOverlayService
    {
        X2P101
    };

    enum class PayeeType
    {
        DOMESTIC,
        INTERNATIONAL,
        BILLER
    };

    enum class PayeeUType
    {
        DOMESTIC,
        BILLER,
        INTERNATIONAL
    };

    enum class PayeeAccountUType
    {
        ACCOUNT,
        CARD,
        PAYID
    };

    enum class PayIdType
    {
        EMAIL,
        TELEPHONE,
        ABN,
        ORG_IDENTIFIER
    };

    enum class ScheduledPaymentStatus
    {
        ACTIVE,
        SKIP,
        INACTIVE
    };

    enum class ToUType
    {
        ACCOUNT_ID,
        PAYEE_ID,
        DOMESTIC,
        BILLER,
        INTERNATIONAL
    };

    enum class RecurrenceUType
    {
        ONCE_OFF,
        INTERVAL_SCHEDULE,
        LAST_WEEK_DAY,
        EVENT_BASED
    };

    enum class NonBusinessDayTreatment
    {
        AFTER,
        BEFORE,
        ON,
        ONLY
    };

    enum class LastWeekDay
    {
        MON,
        TUE,
        WED,
        THU,
        FRI,
        SAT,
        SUN
    };

    const std::array<const EnumStringPair <Bank>, 4> Banks
            {
                    {
                            {Bank::ANZ, "api.anz"},
                            {Bank::CBA, "api.commbank.com.au"},
                            {Bank::NAB, "openbank.api.nab.com.au"},
                            {Bank::WBC, "digital-api.westpac.com.au"}
                    }
            };

    const std::array<const EnumStringPair <Effective>, 3> EffectiveFields
            {
                    {
                            {Effective::CURRENT, "CURRENT"},
                            {Effective::FUTURE, "FUTURE"},
                            {Effective::ALL, "ALL"}
                    }
            };

    const std::array<const EnumStringPair <ProductCategory>, 12> ProductCategories
            {
                    {
                            {ProductCategory::TRANS_AND_SAVINGS_ACCOUNTS, "TRANS_AND_SAVINGS_ACCOUNTS"},
                            {ProductCategory::TERM_DEPOSITS, "TERM_DEPOSITS"},
                            {ProductCategory::TRAVEL_CARDS, "TRAVEL_CARDS"},
                            {ProductCategory::REGULATED_TRUST_ACCOUNTS, "REGULATED_TRUST_ACCOUNTS"},
                            {ProductCategory::RESIDENTIAL_MORTGAGES, "RESIDENTIAL_MORTGAGES"},
                            {ProductCategory::CRED_AND_CHRG_CARDS, "CRED_AND_CHRG_CARDS"},
                            {ProductCategory::PERS_LOANS, "PERS_LOANS"},
                            {ProductCategory::MARGIN_LOANS, "MARGIN_LOANS"},
                            {ProductCategory::LEASES, "LEASES"},
                            {ProductCategory::TRADE_FINANCE, "TRADE_FINANCE"},
                            {ProductCategory::OVERDRAFTS, "OVERDRAFTS"},
                            {ProductCategory::BUSINESS_LOANS, "BUSINESS_LOANS"}
                    }
            };

    const std::array<const EnumStringPair <FeatureType>, 23> FeatureTypes
            {
                    {
                            {FeatureType::CARD_ACCESS, "CARD_ACCESS"},
                            {FeatureType::ADDITIONAL_CARDS, "ADDITIONAL_CARDS"},
                            {FeatureType::UNLIMITED_TXNS, "UNLIMITED_TXNS"},
                            {FeatureType::FREE_TXNS, "FREE_TXNS"},
                            {FeatureType::FREE_TXNS_ALLOWANCE, "FREE_TXNS_ALLOWANCE"},
                            {FeatureType::LOYALTY_PROGRAM, "LOYALTY_PROGRAM"},
                            {FeatureType::OFFSET, "OFFSET"},
                            {FeatureType::OVERDRAFT, "OVERDRAFT"},
                            {FeatureType::REDRAW, "REDRAW"},
                            {FeatureType::INSURANCE, "INSURANCE"},
                            {FeatureType::BALANCE_TRANSFERS, "BALANCE_TRANSFERS"},
                            {FeatureType::INTEREST_FREE, "INTEREST_FREE"},
                            {FeatureType::INTEREST_FREE_TRANSFERS, "INTEREST_FREE_TRANSFERS"},
                            {FeatureType::DIGITAL_WALLET, "DIGITAL_WALLET"},
                            {FeatureType::DIGITAL_BANKING, "DIGITAL_BANKING"},
                            {FeatureType::NPP_PAYID, "NPP_PAYID"},
                            {FeatureType::NPP_ENABLED, "NPP_ENABLED"},
                            {FeatureType::DONATE_INTEREST, "DONATE_INTEREST"},
                            {FeatureType::BILL_PAYMENT, "BILL_PAYMENT"},
                            {FeatureType::COMPLEMENTARY_PRODUCT_DISCOUNTS, "COMPLEMENTARY_PRODUCT_DISCOUNTS"},
                            {FeatureType::BONUS_REWARDS, "BONUS_REWARDS"},
                            {FeatureType::NOTIFICATIONS, "NOTIFICATIONS"},
                            {FeatureType::OTHER, "OTHER"}
                    }
            };


    const std::array<const EnumStringPair <ConstraintType>, 5> ConstraintTypes
            {
                    {
                            {ConstraintType::MIN_BALANCE, "MIN_BALANCE"},
                            {ConstraintType::MAX_BALANCE, "MAX_BALANCE"},
                            {ConstraintType::OPENING_BALANCE, "OPENING_BALANCE"},
                            {ConstraintType::MAX_LIMIT, "MAX_LIMIT"},
                            {ConstraintType::MIN_LIMIT, "MIN_LIMIT"}
                    }
            };

    const std::array<const EnumStringPair <EligibilityType>, 12> EligibilityTypes
            {
                    {
                            {EligibilityType::BUSINESS, "BUSINESS"},
                            {EligibilityType::PENSION_RECIPIENT, "PENSION_RECIPIENT"},
                            {EligibilityType::MIN_AGE, "MIN_AGE"},
                            {EligibilityType::MAX_AGE, "MAX_AGE"},
                            {EligibilityType::MIN_INCOME, "MIN_INCOME"},
                            {EligibilityType::MIN_TURNOVER, "MIN_TURNOVER"},
                            {EligibilityType::STAFF, "STAFF"},
                            {EligibilityType::STUDENT, "STUDENT"},
                            {EligibilityType::EMPLOYMENT_STATUS, "EMPLOYMENT_STATUS"},
                            {EligibilityType::RESIDENCY_STATUS, "RESIDENCY_STATUS"},
                            {EligibilityType::NATURAL_PERSON, "NATURAL_PERSON"},
                            {EligibilityType::OTHER, "OTHER"},
                    }
            };

    const std::array<const EnumStringPair <FeeType>, 9> FeeTypes
            {
                    {
                            {FeeType::PERIODIC, "PERIODIC"},
                            {FeeType::TRANSACTION, "TRANSACTION"},
                            {FeeType::WITHDRAWAL, "WITHDRAWAL"},
                            {FeeType::DEPOSIT, "DEPOSIT"},
                            {FeeType::PAYMENT, "PAYMENT"},
                            {FeeType::PURCHASE, "PURCHASE"},
                            {FeeType::EVENT, "EVENT"},
                            {FeeType::UPFRONT, "UPFRONT"},
                            {FeeType::EXIT, "EXIT"},
                    }
            };

    const std::array<const EnumStringPair <DiscountType>, 5> DiscountTypes
            {
                    {
                            {DiscountType::BALANCE, "BALANCE"},
                            {DiscountType::DEPOSITS, "DEPOSITS"},
                            {DiscountType::PAYMENTS, "PAYMENTS"},
                            {DiscountType::FEE_CAP, "FEE_CAP"},
                            {DiscountType::ELIGIBILITY_ONLY, "ELIGIBILITY_ONLY"}
                    }
            };

    const std::array<const EnumStringPair <DiscountEligibilityType>, 13> DiscountEligibilityTypes
            {
                    {
                            {DiscountEligibilityType::BUSINESS, "BUSINESS"},
                            {DiscountEligibilityType::PENSION_RECIPIENT, "PENSION_RECIPIENT"},
                            {DiscountEligibilityType::MIN_AGE, "MIN_AGE"},
                            {DiscountEligibilityType::MAX_AGE, "MAX_AGE"},
                            {DiscountEligibilityType::MIN_INCOME, "MIN_INCOME"},
                            {DiscountEligibilityType::MIN_TURNOVER, "MIN_TURNOVER"},
                            {DiscountEligibilityType::STAFF, "STAFF"},
                            {DiscountEligibilityType::STUDENT, "STUDENT"},
                            {DiscountEligibilityType::EMPLOYMENT_STATUS, "EMPLOYMENT_STATUS"},
                            {DiscountEligibilityType::RESIDENCY_STATUS, "RESIDENCY_STATUS"},
                            {DiscountEligibilityType::NATURAL_PERSON, "NATURAL_PERSON"},
                            {DiscountEligibilityType::INTRODUCTORY, "INTRODUCTORY"},
                            {DiscountEligibilityType::OTHER, "OTHER"}
                    }
            };

    const std::array<const EnumStringPair <DepositRateType>, 7> DepositRateTypes
            {
                    {
                            {DepositRateType::FIXED, "FIXED"},
                            {DepositRateType::BONUS, "BONUS"},
                            {DepositRateType::BUNDLE_BONUS, "BUNDLE_BONUS"},
                            {DepositRateType::VARIABLE, "VARIABLE"},
                            {DepositRateType::INTRODUCTORY, "INTRODUCTORY"},
                            {DepositRateType::FLOATING, "FLOATING"},
                            {DepositRateType::MARKET_LINKED, "MARKET_LINKED"}
                    }
            };

    const std::array<const EnumStringPair <LendingRateType>, 11> LendingRateTypes
            {
                    {
                            {LendingRateType::FIXED, "FIXED"},
                            {LendingRateType::VARIABLE, "VARIABLE"},
                            {LendingRateType::INTRODUCTORY, "INTRODUCTORY"},
                            {LendingRateType::DISCOUNT, "DISCOUNT"},
                            {LendingRateType::PENALTY, "PENALTY"},
                            {LendingRateType::FLOATING, "FLOATING"},
                            {LendingRateType::MARKET_LINKED, "MARKET_LINKED"},
                            {LendingRateType::CASH_ADVANCE, "CASH_ADVANCE"},
                            {LendingRateType::PURCHASE, "PURCHASE"},
                            {LendingRateType::BUNDLE_DISCOUNT_FIXED, "BUNDLE_DISCOUNT_FIXED"},
                            {LendingRateType::BUNDLE_DISCOUNT_VARIABLE, "BUNDLE_DISCOUNT_VARIABLE"},
                    }
            };

    const std::array<const EnumStringPair <InterestPaymentDue>, 2> InterestPaymentDueFields
            {
                    {
                            {InterestPaymentDue::IN_ARREARS, "IN_ARREARS"},
                            {InterestPaymentDue::IN_ADVANCE, "IN_ADVANCE"}
                    }
            };

    const std::array<const EnumStringPair <RateApplicationMethod>, 2> RateApplicationMethods
            {
                    {
                            {RateApplicationMethod::WHOLE_BALANCE, "WHOLE_BALANCE"},
                            {RateApplicationMethod::PER_TIER, "PER_TIER"}
                    }
            };

    const std::array<const EnumStringPair <UnitOfMeasure>, 4> UnitsOfMeasure
            {
                    {
                            {UnitOfMeasure::DOLLAR, "DOLLAR"},
                            {UnitOfMeasure::PERCENT, "PERCENT"},
                            {UnitOfMeasure::MONTH, "MONTH"},
                            {UnitOfMeasure::DAY, "DAY"}
                    }
            };

    const std::array<const EnumStringPair <OpenStatus>, 2> OpenStatuses
            {
                    {
                            {OpenStatus::OPEN, "OPEN"},
                            {OpenStatus::CLOSED, "CLOSED"}
                    }
            };

    const std::array<const EnumStringPair <SpecificAccountUType>, 3> SpecificAccountUTypes
            {
                    {
                            {SpecificAccountUType::TERM_DEPOSIT, "termDeposit"},
                            {SpecificAccountUType::CREDIT_CARD, "creditCard"},
                            {SpecificAccountUType::LOAN, "loan"}
                    }
            };

    const std::array<const EnumStringPair <MaturityInstructions>, 2> MaturityInstructionReflections
            {
                    {
                            {MaturityInstructions::ROLLED_OVER, "ROLLED_OVER"},
                            {MaturityInstructions::PAID_OUT_AT_MATURITY, "PAID_OUT_AT_MATURITY"}

                    }
            };

    const std::array<const EnumStringPair <RepaymentType>, 2> RepaymentTypes
            {
                    {
                            {RepaymentType::INTEREST_ONLY, "INTEREST_ONLY"},
                            {RepaymentType::PRINCIPAL_AND_INTEREST, "PRINCIPAL_AND_INTEREST"}
                    }
            };

    const std::array<const EnumStringPair <TransactionType>, 8> TransactionTypes
            {
                    {
                            {TransactionType::FEE, "FEE"},
                            {TransactionType::INTEREST_CHARGED, "INTEREST_CHARGED"},
                            {TransactionType::INTEREST_PAID, "INTEREST_PAID"},
                            {TransactionType::TRANSFER_OUTGOING, "TRANSFER_OUTGOING"},
                            {TransactionType::TRANSFER_INCOMING, "TRANSFER_INCOMING"},
                            {TransactionType::PAYMENT, "PAYMENT"},
                            {TransactionType::DIRECT_DEBIT, "DIRECT_DEBIT"},
                            {TransactionType::OTHER, "OTHER"}
                    }
            };

    const std::array<const EnumStringPair <TransactionStatus>, 2> TransactionStatuses
            {
                    {
                            {TransactionStatus::PENDING, "PENDING"},
                            {TransactionStatus::POSTED, "POSTED"}
                    }
            };

    const std::array<const EnumStringPair <ExtensionUType>, 1> ExtensionUTypes
            {
                    {
                            {ExtensionUType::X2P101PAYLOAD, "x2p101Payload"}
                    }
            };

    const std::array<const EnumStringPair <TransactionOverlayService>, 1> TransactionOverlayServices
            {
                    {
                            {TransactionOverlayService::X2P101, "X2P1.01"}
                    }
            };

    const std::array<const EnumStringPair <PayeeType>, 3> PayeeTypes
            {
                    {
                            {PayeeType::DOMESTIC, "DOMESTIC"},
                            {PayeeType::INTERNATIONAL, "INTERNATIONAL"},
                            {PayeeType::BILLER, "BILLER"}
                    }
            };

    const std::array<const EnumStringPair <PayeeUType>, 3> PayeeUTypes
            {
                    {
                            {PayeeUType::DOMESTIC, "domestic"},
                            {PayeeUType::BILLER, "biller"},
                            {PayeeUType::INTERNATIONAL, "international"},
                    }
            };

    const std::array<const EnumStringPair <PayeeAccountUType>, 3> PayeeAccountUTypes
            {
                    {
                            {PayeeAccountUType::ACCOUNT, "account"},
                            {PayeeAccountUType::CARD, "card"},
                            {PayeeAccountUType::PAYID, "payId"}
                    }
            };

    const std::array<const EnumStringPair <PayIdType>, 4> PayIdTypes
            {
                    {
                            {PayIdType::EMAIL, "EMAIL"},
                            {PayIdType::TELEPHONE, "TELEPHONE"},
                            {PayIdType::ABN, "ABN"},
                            {PayIdType::ORG_IDENTIFIER, "ORG_IDENTIFIER"},
                    }
            };

    const std::array<const EnumStringPair <ScheduledPaymentStatus>, 3> ScheduledPaymentStatuses
            {
                    {
                            {ScheduledPaymentStatus::ACTIVE, "ACTIVE"},
                            {ScheduledPaymentStatus::SKIP, "SKIP"},
                            {ScheduledPaymentStatus::INACTIVE, "INACTIVE"}
                    }
            };

    const std::array<const EnumStringPair <ToUType>, 5> ToUTypes
            {
                    {
                            {ToUType::ACCOUNT_ID, "accountId"},
                            {ToUType::PAYEE_ID, "payeeId"},
                            {ToUType::DOMESTIC, "domestic"},
                            {ToUType::BILLER, "biller"},
                            {ToUType::INTERNATIONAL, "international"},
                    }
            };

    const std::array<const EnumStringPair <RecurrenceUType>, 4> RecurrenceUTypes
            {
                    {
                            {RecurrenceUType::ONCE_OFF, "onceOff"},
                            {RecurrenceUType::INTERVAL_SCHEDULE, "intervalSchedule"},
                            {RecurrenceUType::LAST_WEEK_DAY, "lastWeekDay"},
                            {RecurrenceUType::EVENT_BASED, "eventBased"},
                    }
            };

    const std::array<const EnumStringPair <NonBusinessDayTreatment>, 4> NonBusinessDayTreatments
            {
                    {
                            {NonBusinessDayTreatment::AFTER, "AFTER"},
                            {NonBusinessDayTreatment::BEFORE, "BEFORE"},
                            {NonBusinessDayTreatment::ON, "ON"},
                            {NonBusinessDayTreatment::ONLY, "ONLY"},
                    }
            };

    const std::array<const EnumStringPair <LastWeekDay>, 7> LastWeekDays
            {
                    {
                            {LastWeekDay::MON, "MON"},
                            {LastWeekDay::TUE, "TUE"},
                            {LastWeekDay::WED, "WED"},
                            {LastWeekDay::THU, "THU"},
                            {LastWeekDay::FRI, "FRI"},
                            {LastWeekDay::SAT, "SAT"},
                            {LastWeekDay::SUN, "SUN"}
                    }
            };
    const std::array<const EnumStringPair<AddressUType>, 2> AddressUTypes
            {
                    {
                            {AddressUType::SIMPLE, "simple"},
                            {AddressUType::PAF, "paf"}
                    }
            };

    const std::array<const EnumStringPair<OrganisationType>, 6> OrganisationTypes
            {
                    {
                            {OrganisationType::SOLE_TRADER, "SOLE_TRADER"},
                            {OrganisationType::COMPANY, "COMPANY"},
                            {OrganisationType::PARTNERSHIP, "PARTNERSHIP"},
                            {OrganisationType::TRUST, "TRUST"},
                            {OrganisationType::GOVERNMENT_ENTITY, "GOVERNMENT_ENTITY"},
                            {OrganisationType::OTHER, "OTHER"},
                    }
            };

    const std::array<const EnumStringPair<PhoneNumberPurpose>, 6> PhoneNumberPurposes
            {
                    {
                            {PhoneNumberPurpose::MOBILE, "MOBILE"},
                            {PhoneNumberPurpose::HOME, "HOME"},
                            {PhoneNumberPurpose::WORK, "WORK"},
                            {PhoneNumberPurpose::OTHER, "OTHER"},
                            {PhoneNumberPurpose::INTERNATIONAL, "INTERNATIONAL"},
                            {PhoneNumberPurpose::UNSPECIFIED, "UNSPECIFIED"}
                    }
            };

    const std::array<const EnumStringPair<EmailAddressPurpose>, 4> EmailAddressPurposes
            {
                    {
                            {EmailAddressPurpose::WORK, "WORK"},
                            {EmailAddressPurpose::HOME, "HOME"},
                            {EmailAddressPurpose::OTHER, "OTHER"},
                            {EmailAddressPurpose::UNSPECIFIED, "UNSPECIFIED"}
                    }
            };

    const std::array<const EnumStringPair<PhysicalAddressPurpose>, 5> PhysicalAddressPurposes
            {
                    {
                            {PhysicalAddressPurpose::REGISTERED, "REGISTERED"},
                            {PhysicalAddressPurpose::MAIL, "MAIL"},
                            {PhysicalAddressPurpose::PHYSICAL, "PHYSICAL"},
                            {PhysicalAddressPurpose::WORK, "WORK"},
                            {PhysicalAddressPurpose::OTHER, "OTHER"}
                    }
            };
}

#endif //REGIME_V1_ENUMS_HPP
