#ifndef REGIME_V1_COMMON_ENUMS_HPP
#define REGIME_V1_COMMON_ENUMS_HPP

#include <string>
#include <array>

template<class T>
struct EnumStringPair
{
    using value_type = T;
    const T _enum;
    std::string _string;
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

#endif //REGIME_V1_COMMON_ENUMS_HPP
