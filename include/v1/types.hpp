#ifndef REGIME_V1_TYPES_HPP
#define REGIME_V1_TYPES_HPP

#include "v1/common/utils.hpp"
#include "enums.hpp"
#include "common/types.hpp"
#include <typeinfo>

DECLARE_COMMON_TYPE(BankingProductBundle,
                    std::string name;
                            std::string description;
                            std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
                            std::optional<std::vector<std::string>> product_ids;
)

DECLARE_COMMON_TYPE(BankingProductFeature,
                    FeatureType feature_type;
                            std::optional<std::string> additional_value;
                            std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
)

DECLARE_COMMON_TYPE(BankingProductConstraint,
                    ConstraintType constraint_type;
                            std::optional<std::string> additional_value;
                            std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
)

DECLARE_COMMON_TYPE(BankingProductEligibility,
                    EligibilityType eligibility_type;
                            std::optional<std::string> additional_value;
                            std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
)

DECLARE_COMMON_TYPE(BankingProductDiscountEligibility,
                    DiscountEligibilityType discount_eligibility_type;
                            std::optional<std::string> additional_value;
                            std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
)

DECLARE_COMMON_TYPE(BankingProductDiscount,
                    std::string description;
                            DiscountType discount_type;
                            std::optional<std::string> amount;
                            std::optional<std::string> balance_rate;
                            std::optional<std::string> transaction_rate;
                            std::optional<std::string> accrued_rate;
                            std::optional<std::string> fee_rate;
                            std::optional<std::string> additional_value;
                            std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
                            std::optional<std::vector<BankingProductDiscountEligibility>> eligibility;
)

DECLARE_COMMON_TYPE(BankingProductFee,
                    std::string name;
                            FeeType fee_type;
                            std::optional<std::string> amount;
                            std::optional<std::string> balance_rate;
                            std::optional<std::string> transaction_rate;
                            std::optional<std::string> accrued_rate;
                            std::optional<std::string> accrual_frequency;
                            std::optional<std::string> currency; // FIXME
                            std::optional<std::string> additional_value;
                            std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
                            std::optional<std::vector<BankingProductDiscount>> discounts;
)

DECLARE_COMMON_TYPE(BankingProductRateCondition,
                    std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
)

DECLARE_COMMON_TYPE(BankingProductRateSubTier,
                    std::string name;
                            UnitOfMeasure unit_of_measure;
                            float minimum_value;
                            float maximum_value;
                            std::optional<RateApplicationMethod> rate_application_method;
                            std::optional<BankingProductRateCondition> applicability_conditions;
)

DECLARE_COMMON_TYPE(BankingProductRateTier,
                    std::string name;
                            UnitOfMeasure unit_of_measure;
                            float minimum_value;
                            std::optional<float> maximum_value;
                            std::optional<RateApplicationMethod> rate_application_method;
                            std::optional<BankingProductRateCondition> applicability_conditions;
                            std::optional<BankingProductRateSubTier> sub_tier;
)

DECLARE_COMMON_TYPE(BankingProductDepositRate,
                    DepositRateType deposit_rate_type;
                            std::string rate;
                            std::optional<std::string> calculation_frequency;
                            std::optional<std::string> application_frequency;
                            std::optional<std::vector<BankingProductRateTier>> tiers;
                            std::optional<std::string> additional_value;
                            std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
)

DECLARE_COMMON_TYPE(BankingProductLendingRate,
                    LendingRateType lending_rate_type;
                            std::string rate;
                            std::optional<std::string> comparison_rate;
                            std::optional<std::string> calculation_frequency;
                            std::optional<std::string> application_frequency;
                            std::optional<InterestPaymentDue> interest_payment_due;
                            std::optional<std::vector<BankingProductRateTier>> tiers;
                            std::optional<std::string> additional_value;
                            std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
)

DECLARE_COMMON_TYPE(BankingAccount,
                    std::string account_id;
                            std::string display_name;
                            std::string masked_number;  // TODO MaskedAccountString type
                            ProductCategory product_category;
                            std::string product_name;
                            std::optional<std::string> creation_date;  // TODO DateString
                            std::optional<std::string> nickname;
                            std::optional<OpenStatus> open_status;
                            std::optional<bool> is_owned;
)

DECLARE_COMMON_TYPE(BankingTermDepositAccount,
                    std::string lodgement_date;  // TODO DateString
                            std::string maturity_date;  // TODO DateString
                            MaturityInstructions maturity_instructions;
                            std::optional<std::string> maturity_amount;
                            std::optional<std::string> maturity_currency;  // TODO CurrencyString
)

DECLARE_COMMON_TYPE(BankingCreditCardAccount,
                    std::string min_payment_amount;
                            std::string payment_due_amount;
                            std::string payment_due_date;  // TODO DateString
                            std::optional<std::string> payment_currency;  // TODO CurrencyString
)

DECLARE_COMMON_TYPE(BankingLoanAccount,
                    std::string loan_end_date;  // TODO DateString
                            std::string next_instalment_date;  // TODO DateString
                            std::string repayment_frequency;
                            std::optional<std::string> original_start_date;  // TODO DateString
                            std::optional<std::string> original_loan_amount;
                            std::optional<std::string> original_loan_currency;  // TODO CurrencyString
                            std::optional<std::string> min_instalment_amount;
                            std::optional<std::string> min_instalment_currency;  // TODO CurrencyString
                            std::optional<std::string> max_redraw;
                            std::optional<std::string> max_redraw_currency;  // TODO CurrencyString
                            std::optional<std::string> min_redraw;
                            std::optional<std::string> min_redraw_currency;  // TODO CurrencyString
                            std::optional<bool> offset_account_enabled;
                            std::optional<std::vector<std::string>> offset_account_ids;
                            std::optional<RepaymentType> repayment_type;
)

DECLARE_COMMON_TYPE(BankingProductFeatureToggled,
                    FeatureType feature_type;
                            std::optional<std::string> additional_value;
                            std::optional<std::string> additional_info;
                            std::optional<std::string> additional_info_uri;
                            std::optional<bool> is_activated;
)

DECLARE_COMMON_TYPE(BankingAccountDetail,
                    BankingAccount account;
                            std::optional<std::string> bsb;
                            std::optional<std::string> account_number;
                            std::optional<std::string> bundle_name;
                            std::optional<SpecificAccountUType> specific_account_u_type;
                            std::optional<std::vector<BankingTermDepositAccount>> term_deposit;
                            std::optional<BankingCreditCardAccount> credit_card;
                            std::optional<BankingLoanAccount> loan;
                            std::optional<std::string> deposit_rate;
                            std::optional<std::string> lending_rate;
                            std::optional<std::vector<BankingProductDepositRate>> deposit_rates;
                            std::optional<std::vector<BankingProductLendingRate>> lending_rates;
                            std::optional<std::vector<BankingProductFeatureToggled>> features;
                            std::optional<std::vector<BankingProductFee>> fees;
                            std::optional<std::vector<CommonPhysicalAddress>> addresses;
)

DECLARE_COMMON_TYPE(BankingTransaction,
                    std::string account_id;
                            bool is_detail_available;
                            TransactionType type;
                            TransactionStatus status;
                            std::string description;
                            std::string amount;
                            std::string reference;
                            std::optional<std::string> transaction_id;
                            std::optional<std::string> posting_date_time;  // TODO DateTimeString
                            std::optional<std::string> value_date_time;  // TODO DateTimeString
                            std::optional<std::string> execution_date_time;  // TODO DateTimeString
                            std::optional<std::string> currency;  // TODO CurrencyString
                            std::optional<std::string> merchant_name;
                            std::optional<std::string> merchant_category_code;
                            std::optional<std::string> biller_code;
                            std::optional<std::string> biller_name;
                            std::optional<std::string> crn;
                            std::optional<std::string> apca_number;
)

DECLARE_COMMON_TYPE(x2p101Payload,
                    std::string extended_description;
                            std::optional<std::string> end_to_end_id;
                            std::optional<std::string> purpose_code;
)

DECLARE_COMMON_TYPE(ExtendedData,
                    TransactionOverlayService service;
                            std::optional<std::string> payer;
                            std::optional<std::string> payee;
                            std::optional<ExtensionUType> extension_u_type;
                            std::optional<x2p101Payload> x2p101_payload;
)

DECLARE_COMMON_TYPE(BankingTransactionDetail,
                    ExtendedData extended_data;
                            std::optional<BankingTransaction> transaction;
)

DECLARE_COMMON_TYPE(BankingBalancePurse,
                    std::string amount;
                            std::optional<std::string> currency;  // TODO CurrencyString
)

DECLARE_COMMON_TYPE(BankingBalance,
                    std::string account_id;
                            std::string current_balance;
                            std::string available_balance;
                            std::optional<std::string> credit_limit;
                            std::optional<std::string> amortised_limit;
                            std::optional<std::string> currency;  // TODO CurrencyString
                            std::optional<std::vector<BankingBalancePurse>> purses;
)

DECLARE_COMMON_TYPE(BankingPayee,
                    std::string payee_id;
                            std::string nickname;
                            PayeeType type;
                            std::optional<std::string> description;
                            std::optional<std::string> creation_date;  // TODO DateString
)

DECLARE_COMMON_TYPE(BankingDomesticPayeeAccount,
                    std::string bsb;
                            std::string account_number;
                            std::optional<std::string> account_name;
)

DECLARE_COMMON_TYPE(BankingDomesticPayeeCard,
                    std::string card_number;  // TODO MaskedPANString
)

DECLARE_COMMON_TYPE(BankingDomesticPayeePayId,
                    std::string identifier;
                            PayIdType type;
                            std::optional<std::string> name;
)

DECLARE_COMMON_TYPE(BankingDomesticPayee,
                    PayeeAccountUType payee_account_u_type;
                            std::optional<BankingDomesticPayeeAccount> account;
                            std::optional<BankingDomesticPayeeCard> card;
                            std::optional<BankingDomesticPayeePayId> pay_id;
)

DECLARE_COMMON_TYPE(BankingBillerPayee,
                    std::string biller_code;
                            std::string biller_name;
                            std::optional<std::string> crn;
)

DECLARE_COMMON_TYPE(BeneficiaryDetails,
                    std::string country;  // TODO ISO 3166 Alpha-3
                            std::optional<std::string> name;
                            std::optional<std::string> message;
)

DECLARE_COMMON_TYPE(BankAddress,
                    std::string name;
                            std::string address;
)

DECLARE_COMMON_TYPE(BankDetails,
                    std::string country;  // TODO ISO 3166 Alpha-3
                            std::string account_number;
                            BankAddress bank_address;
                            std::optional<std::string> beneficiary_bank_bic;  // TODO ISO 9362
                            std::optional<std::string> fed_wire_number;
                            std::optional<std::string> sort_code;
                            std::optional<std::string> chip_number;
                            std::optional<std::string> routing_number;
                            std::optional<std::string> legal_entity_identifier;  // TODO ISO 17442
)

DECLARE_COMMON_TYPE(BankingInternationalPayee,
                    BeneficiaryDetails beneficiary_details;
                            BankDetails bank_details;
)

DECLARE_COMMON_TYPE(BankingPayeeDetail,
                    PayeeUType payee_u_type;
                            std::optional<BankingPayee> payee;
                            std::optional<BankingDomesticPayee> domestic;
                            std::optional<BankingBillerPayee> biller;
                            std::optional<BankingInternationalPayee> international;
)

DECLARE_COMMON_TYPE(BankingAuthorisedEntity,
                    std::optional<std::string> description;
                            std::optional<std::string> financial_institution;
                            std::optional<std::string> abn;
                            std::optional<std::string> acn;
                            std::optional<std::string> arbn;
)

DECLARE_COMMON_TYPE(BankingDirectDebit,
                    std::string account_id;
                            BankingAuthorisedEntity authorised_entity;
                            std::optional<std::string> last_debit_date_time;  // TODO DateTimeString
                            std::optional<std::string> last_debit_amount;
)

DECLARE_COMMON_TYPE(BankingScheduledPaymentTo,
                    ToUType to_u_type;
                            std::optional<std::string> account_id;
                            std::optional<std::string> payee_id;
                            std::optional<BankingDomesticPayee> domestic;
                            std::optional<BankingBillerPayee> biller;
                            std::optional<BankingInternationalPayee> international;
)

DECLARE_COMMON_TYPE(BankingScheduledPaymentSet,
                    BankingScheduledPaymentTo to;
                            std::optional<bool> is_amount_calculated;
                            std::optional<std::string> amount;
                            std::optional<std::string> currency;  // TODO CurrencyString
)

DECLARE_COMMON_TYPE(BankingScheduledPaymentFrom,
                    std::string account_id;
)

DECLARE_COMMON_TYPE(BankingScheduledPaymentInterval,
                    std::string interval;  // TODO ISO 8601
                            std::optional<std::string> day_in_interval;  // TODO ISO 8601
)

DECLARE_COMMON_TYPE(BankingScheduledPaymentRecurrenceIntervalSchedule,
                    std::vector<BankingScheduledPaymentInterval> intervals;
                            std::optional<std::string> final_payment_date;  // TODO DateString
                            std::optional<int> payments_remaining;
                            std::optional<NonBusinessDayTreatment> non_business_day_treatment;
)

DECLARE_COMMON_TYPE(BankingScheduledPaymentRecurrenceLastWeekday,
                    std::string interval;  // TODO ISO 8601
                            LastWeekDay last_week_day;
                            std::optional<std::string> final_payment_date;  // TODO DateString
                            std::optional<int> payments_remaining;
                            std::optional<NonBusinessDayTreatment> non_business_day_treatment;
)

DECLARE_COMMON_TYPE(BankingScheduledPaymentRecurrenceEventBased,
                    std::string description;
)

DECLARE_COMMON_TYPE(BankingScheduledPaymentRecurrenceOnceOff,
                    std::string payment_date;  // TODO DateString
)

DECLARE_COMMON_TYPE(BankingScheduledPaymentRecurrence,
                    RecurrenceUType recurrence_u_type;
                            std::optional<std::string> next_payment_date;  // TODO DateString
                            std::optional<BankingScheduledPaymentRecurrenceOnceOff> once_off;
                            std::optional<BankingScheduledPaymentRecurrenceIntervalSchedule> interval_schedule;
                            std::optional<BankingScheduledPaymentRecurrenceLastWeekday> last_week_day;
                            std::optional<BankingScheduledPaymentRecurrenceEventBased> event_based;
)

DECLARE_COMMON_TYPE(BankingScheduledPayment,
                    std::string scheduled_payment_id;
                            std::string payer_reference;
                            std::string payee_reference;
                            ScheduledPaymentStatus status;
                            BankingScheduledPaymentFrom from;
                            std::vector<BankingScheduledPaymentSet> payment_set;
                            BankingScheduledPaymentRecurrence recurrence;
                            std::optional<std::string> nickname;
)

DECLARE_COMMON_TYPE(CardArt,
                    std::string image_uri;
                            std::optional<std::string> title;
)

DECLARE_COMMON_TYPE(AdditionalInformation,
                    std::optional<std::string> overview_uri;
                            std::optional<std::string> terms_uri;
                            std::optional<std::string> eligibility_uri;
                            std::optional<std::string> fees_and_pricing_uri;
                            std::optional<std::string> bundle_uri;
)

DECLARE_COMMON_TYPE(BankingProductV2,
                    std::string product_id;
                            std::string last_updated;
                            ProductCategory product_category;
                            std::string name;
                            std::string description;
                            std::string brand;
                            bool is_tailored;
                            std::optional<std::string> effective_from;
                            std::optional<std::string> effective_to;
                            std::optional<std::string> brand_name;
                            std::optional<std::string> application_uri;
                            std::optional<AdditionalInformation> additional_information;
                            std::optional<std::vector<CardArt>> card_art;
)

DECLARE_COMMON_TYPE(BankingProductDetail,
                    std::optional<BankingProductV2> product;
                            std::optional<std::vector<BankingProductBundle>> bundles;
                            std::optional<std::vector<BankingProductFeature>> features;
                            std::optional<std::vector<BankingProductConstraint>> constraints;
                            std::optional<std::vector<BankingProductEligibility>> eligibility;
                            std::optional<std::vector<BankingProductFee>> fees;
                            std::optional<std::vector<BankingProductDepositRate>> deposit_rates;
                            std::optional<std::vector<BankingProductLendingRate>> lending_rates;
)

#endif //REGIME_V1_TYPES_HPP
