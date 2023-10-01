#pragma once
#include "EditableData.h"
#include "json.hpp"

class EmergencyData : EditableData
{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(EmergencyData,
        Name, Relationship, PhoneNumber,
        EmailAddress, Address)


public:
    std::string Name;
    std::string Relationship;
    std::string PhoneNumber;
    std::string EmailAddress;
    std::string Address;

    void EditData() override;

    void PrintData() override;
};
