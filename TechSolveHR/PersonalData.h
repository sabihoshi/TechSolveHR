#pragma once

#include <string>

#include "EditableData.h"
#include "json.hpp"

class PersonalData : EditableData
{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(PersonalData,
        Name, MaritalStatus,
        DateOfBirth, DateOfHire,
        Gender, Address, PhoneNumber,
        Tin, PhilHealth, Sss)

public:
    std::string Name;
    std::string MaritalStatus;
    std::string DateOfBirth;
    std::string DateOfHire;
    std::string Gender;
    std::string Address;
    std::string PhoneNumber;
    std::string Tin;
    std::string PhilHealth;
    std::string Sss;

    void PrintData() override;

    void EditData() override;
};
