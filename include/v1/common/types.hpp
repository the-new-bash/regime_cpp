#ifndef REGIME_V1_COMMON_TYPES_HPP
#define REGIME_V1_COMMON_TYPES_HPP

#include "enums.hpp"
#include "objects.hpp"

#define DECLARE_COMMON_TYPE(type_name, ...) \
        struct type_name : public Object \
        { \
            ~type_name() = default; \
            void deserialize(const Poco::JSON::Object::Ptr &payload) override; \
            Poco::JSON::Object::Ptr to_json(void) const override; \
            __VA_ARGS__ \
        };

DECLARE_COMMON_TYPE(CommonPerson,
                    std::string last_name;
                            std::vector<std::string> middle_names;
                            std::optional<std::string> last_updated_time;  // TODO DateTimeString
                            std::optional<std::string> first_name;
                            std::optional<std::string> prefix;
                            std::optional<std::string> suffix;
                            std::optional<std::string> occupation_code;  // TODO ANZCO v1.2
)

DECLARE_COMMON_TYPE(CommonPhoneNumber,
                    PhoneNumberPurpose purpose;
                            std::string number;
                            std::string full_number;  // TODO RFC 3966
                            std::optional<bool> is_preferred;
                            std::optional<std::string> country_code;
                            std::optional<std::string> area_code;
                            std::optional<std::string> extension;
)

DECLARE_COMMON_TYPE(CommonEmailAddress,
                    EmailAddressPurpose purpose;
                            std::string address;  // TODO RFC 5322
                            std::optional<bool> is_preferred;
)

DECLARE_COMMON_TYPE(CommonSimpleAddress,
                    std::string address_line1;
                            std::string city;
                            std::string state;
                            std::optional<std::string> mailing_name;
                            std::optional<std::string> address_line2;
                            std::optional<std::string> address_line3;
                            std::optional<std::string> postcode;
                            std::optional<std::string> country;  // TODO ISO 3166 Alpha-3
)

DECLARE_COMMON_TYPE(CommonPAFAddress,
                    std::string locality_name;
                            std::string postcode;
                            std::string state;  // TODO State type abbreviation
                            std::optional<std::string> dpid;
                            std::optional<int> thoroughfare_number1;
                            std::optional<std::string> thoroughfare_number1_suffix;
                            std::optional<int> thoroughfare_number2;
                            std::optional<std::string> thoroughfare_number2_suffix;
                            std::optional<std::string> flat_unit_type;
                            std::optional<std::string> flat_unit_number;
                            std::optional<std::string> floor_level_type;
                            std::optional<std::string> floor_level_number;
                            std::optional<std::string> lot_number;
                            std::optional<std::string> building_name1;
                            std::optional<std::string> building_name2;
                            std::optional<std::string> street_name;
                            std::optional<std::string> street_type;
                            std::optional<std::string> street_suffix;
                            std::optional<std::string> postal_delivery_type;
                            std::optional<int> postal_delivery_number;
                            std::optional<std::string> postal_delivery_number_prefix;
                            std::optional<std::string> postal_delivery_number_suffix;
)

DECLARE_COMMON_TYPE(CommonPhysicalAddress,
                    AddressUType address_u_type;
                            std::optional<CommonSimpleAddress> simple;
                            std::optional<CommonPAFAddress> paf;
)

DECLARE_COMMON_TYPE(CommonPhysicalAddressWithPurpose,
                    CommonPhysicalAddress address;
                            PhysicalAddressPurpose purpose;
)

DECLARE_COMMON_TYPE(CommonPersonDetail,
                    CommonPerson person;
                            std::vector<CommonPhoneNumber> phone_numbers;
                            std::vector<CommonEmailAddress> email_addresses;
                            std::vector<CommonPhysicalAddressWithPurpose> physical_addresses;
)

DECLARE_COMMON_TYPE(CommonOrganisation,
                    std::string agent_last_name;
                            std::string agent_role;
                            std::string business_name;
                            OrganisationType organisation_type;
                            std::optional<std::string> last_update_time; // TODO DateTimeString
                            std::optional<std::string> agent_first_name;
                            std::optional<std::string> legal_name;
                            std::optional<std::string> short_name;
                            std::optional<std::string> abn;
                            std::optional<std::string> acn;
                            std::optional<bool> is_acnc_registered;
                            std::optional<std::string> industry_code;  // TODO ANZSIC (2006) code
                            std::optional<std::string> registered_country;  // TODO ISO 3166 Alpha-3
                            std::optional<std::string> establishment_date;  // TODO DateString
)

DECLARE_COMMON_TYPE(CommonOrganisationDetail,
                    CommonOrganisation organisation;
                            std::vector<CommonPhysicalAddressWithPurpose> physical_addresses;
)

#endif //REGIME_V1_COMMON_TYPES_HPP
