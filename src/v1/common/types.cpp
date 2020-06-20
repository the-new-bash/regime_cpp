#include <v1/common/utils.hpp>

void CommonPerson::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(last_updated_time, data, "lastUpdateTime");
    regime::util::get(first_name, data, "firstName");
    regime::util::get(last_name, data, "lastName");
    regime::util::get(middle_names, data, "middleNames");
    regime::util::get(prefix, data, "prefix");
    regime::util::get(suffix, data, "suffix");
    regime::util::get(occupation_code, data, "occupationCode");
}

Poco::JSON::Object::Ptr CommonPerson::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "lastUpdatedTime", last_updated_time);
    regime::util::add(json, "firstName", first_name);
    regime::util::add(json, "lastName", last_name);
    regime::util::add(json, "middleNames", middle_names);
    regime::util::add(json, "prefix", prefix);
    regime::util::add(json, "suffix", suffix);
    regime::util::add(json, "occupationCode", occupation_code);
    return json;
}

void CommonPhoneNumber::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(is_preferred, data, "isPreferred");
    regime::util::get(purpose, data, PhoneNumberPurposes, "purpose");
    regime::util::get(country_code, data, "countryCode");
    regime::util::get(area_code, data, "areaCode");
    regime::util::get(number, data, "number");
    regime::util::get(extension, data, "extension");
    regime::util::get(full_number, data, "fullNumber");
}

Poco::JSON::Object::Ptr CommonPhoneNumber::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "isPreferred", is_preferred);
    regime::util::add(json, "purpose", PhoneNumberPurposes, purpose);
    regime::util::add(json, "countryCode", country_code);
    regime::util::add(json, "areaCode", area_code);
    regime::util::add(json, "number", number);
    regime::util::add(json, "fullNumber", full_number);
    return json;
}

void CommonEmailAddress::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(is_preferred, data, "isPreferred");
    regime::util::get(purpose, data, EmailAddressPurposes, "purpose");
    regime::util::get(address, data, "address");
}

Poco::JSON::Object::Ptr CommonEmailAddress::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "isPreferred", is_preferred);
    regime::util::add(json, "purpose", EmailAddressPurposes, purpose);
    regime::util::add(json, "Regime::Utils::address", address);
    return json;
}

void CommonSimpleAddress::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(mailing_name, data, "mailingName");
    regime::util::get(address_line1, data, "addressLine1");
    regime::util::get(address_line2, data, "addressLine2");
    regime::util::get(address_line3, data, "addressLine3");
    regime::util::get(postcode, data, "postcode");
    regime::util::get(city, data, "city");
    regime::util::get(state, data, "state");
    regime::util::get(country, data, "country");
}

Poco::JSON::Object::Ptr CommonSimpleAddress::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "mailingName", mailing_name);
    regime::util::add(json, "addressLine1", address_line1);
    regime::util::add(json, "addressLine2", address_line2);
    regime::util::add(json, "addressLine3", address_line3);
    regime::util::add(json, "postcode", postcode);
    regime::util::add(json, "city", city);
    regime::util::add(json, "state", state);
    regime::util::add(json, "country", country);
    return json;
}

void CommonPAFAddress::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(dpid, data, "dpid");
    regime::util::get(thoroughfare_number1, data, "thoroughfareNumber1");
    regime::util::get(thoroughfare_number1_suffix, data, "thoroughfareNumber1Suffix");
    regime::util::get(thoroughfare_number2, data, "thoroughfareNumber2");
    regime::util::get(thoroughfare_number2_suffix, data, "thoroughfareNumber2Suffix");
    regime::util::get(flat_unit_type, data, "flatUnitType");
    regime::util::get(flat_unit_number, data, "flatUnitNumber");
    regime::util::get(floor_level_type, data, "floorLevelType");
    regime::util::get(floor_level_number, data, "floorLevelNumber");
    regime::util::get(lot_number, data, "lotNumber");
    regime::util::get(building_name1, data, "buildingName1");
    regime::util::get(building_name2, data, "buildingName2");
    regime::util::get(street_name, data, "streetName");
    regime::util::get(street_type, data, "streetType");
    regime::util::get(street_suffix, data, "streetSuffix");
    regime::util::get(postal_delivery_type, data, "postalDeliveryType");
    regime::util::get(postal_delivery_number, data, "postalDeliveryNumber");
    regime::util::get(postal_delivery_number_prefix, data, "postalDeliveryNumberPrefix");
    regime::util::get(postal_delivery_number_suffix, data, "postalDeliveryNumberSuffix");
    regime::util::get(locality_name, data, "localityName");
    regime::util::get(postcode, data, "postcode");
    regime::util::get(state, data, "state");
}

Poco::JSON::Object::Ptr CommonPAFAddress::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "dpid", dpid);
    regime::util::add(json, "thoroughfareNumber1", thoroughfare_number1);
    regime::util::add(json, "thoroughfareNumber1Suffix", thoroughfare_number1_suffix);
    regime::util::add(json, "thoroughfareNumber2", thoroughfare_number2);
    regime::util::add(json, "thoroughfareNumber2Suffix", thoroughfare_number2_suffix);
    regime::util::add(json, "flatUnitType", flat_unit_type);
    regime::util::add(json, "flatUnitNumber", flat_unit_number);
    regime::util::add(json, "floorLevelType", floor_level_type);
    regime::util::add(json, "lotNumber", lot_number);
    regime::util::add(json, "buildingName1", building_name1);
    regime::util::add(json, "buildingName2", building_name2);
    regime::util::add(json, "streetName", street_name);
    regime::util::add(json, "streetType", street_type);
    regime::util::add(json, "streetSuffix", street_suffix);
    regime::util::add(json, "postalDeliveryType", postal_delivery_type);
    regime::util::add(json, "postalDeliveryNumber", postal_delivery_number);
    regime::util::add(json, "postalDeliveryNumberPrefix", postal_delivery_number_prefix);
    regime::util::add(json, "postalDeliveryNumberSuffix", postal_delivery_number_suffix);
    regime::util::add(json, "localityName", locality_name);
    regime::util::add(json, "postcode", postcode);
    regime::util::add(json, "state", state);
    return json;
}

void CommonPhysicalAddress::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(address_u_type, data, AddressUTypes, "addressUType");
    regime::util::get(simple, data, "simple");
    regime::util::get(paf, data, "paf");
}

Poco::JSON::Object::Ptr CommonPhysicalAddress::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "addressUType", AddressUTypes, address_u_type);
    regime::util::add(json, "simple", simple);
    regime::util::add(json, "paf", paf);
    return json;
}

void CommonPhysicalAddressWithPurpose::deserialize(const Poco::JSON::Object::Ptr &data)
{
    address = CommonPhysicalAddress();
    address.deserialize(data);
    regime::util::get(purpose, data, PhysicalAddressPurposes, "purpose");
}

Poco::JSON::Object::Ptr CommonPhysicalAddressWithPurpose::to_json() const
{
    Poco::JSON::Object::Ptr json = address.to_json();
    regime::util::add(json, "purpose", PhysicalAddressPurposes, purpose);
    return json;
}

void CommonPersonDetail::deserialize(const Poco::JSON::Object::Ptr &data)
{
    person = CommonPerson();
    person.deserialize(data);
    regime::util::get(phone_numbers, data, "phoneNumbers");
    regime::util::get(email_addresses, data, "emailAddresses");
    regime::util::get(physical_addresses, data, "physicalAddresses");
}

Poco::JSON::Object::Ptr CommonPersonDetail::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "phoneNumbers", phone_numbers);
    regime::util::add(json, "emailAddresses", email_addresses);
    regime::util::add(json, "physicalAddresses", physical_addresses);
    return json;
}

void CommonOrganisation::deserialize(const Poco::JSON::Object::Ptr &data)
{
    regime::util::get(last_update_time, data, "lastUpdateTime");
    regime::util::get(agent_first_name, data, "agentFirstName");
    regime::util::get(agent_last_name, data, "agentLastName");
    regime::util::get(agent_role, data, "agentRole");
    regime::util::get(business_name, data, "businessName");
    regime::util::get(legal_name, data, "legalName");
    regime::util::get(short_name, data, "shortName");
    regime::util::get(abn, data, "abn");
    regime::util::get(acn, data, "acn");
    regime::util::get(is_acnc_registered, data, "isACNCRegistered");
    regime::util::get(industry_code, data, "industryCode");
    regime::util::get(organisation_type, data, OrganisationTypes, "organisationType");
    regime::util::get(registered_country, data, "registeredCountry");
    regime::util::get(establishment_date, data, "establishmentDate");
}

Poco::JSON::Object::Ptr CommonOrganisation::to_json() const
{
    Poco::JSON::Object::Ptr json;
    regime::util::add(json, "lastUpdateTime", last_update_time);
    regime::util::add(json, "agentFirstName", agent_first_name);
    regime::util::add(json, "agentLastName", agent_last_name);
    regime::util::add(json, "agentRole", agent_role);
    regime::util::add(json, "businessName", business_name);
    regime::util::add(json, "legalName", legal_name);
    regime::util::add(json, "shortName", short_name);
    regime::util::add(json, "abn", abn);
    regime::util::add(json, "acn", acn);
    regime::util::add(json, "isACNCRegistered", is_acnc_registered);
    regime::util::add(json, "industryCode", industry_code);
    regime::util::add(json, "organisationType", OrganisationTypes, organisation_type);
    regime::util::add(json, "registeredCountry", registered_country);
    regime::util::add(json, "establishmentDate", establishment_date);
    return json;
}

void CommonOrganisationDetail::deserialize(const Poco::JSON::Object::Ptr &data)
{
    organisation = CommonOrganisation();
    organisation.deserialize(data);
    regime::util::get(physical_addresses, data, "physicalAddresses");
}

Poco::JSON::Object::Ptr CommonOrganisationDetail::to_json() const
{
    Poco::JSON::Object::Ptr json = organisation.to_json();
    regime::util::add(json, "physicalAddresses", physical_addresses);
    return json;
}

std::string Object::serialize() const
{
    const auto obj = to_json();
    std::ostringstream oss;
    obj->stringify(oss);
    return oss.str();
}
