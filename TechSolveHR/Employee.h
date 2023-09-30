#pragma once
#include <chrono>

#include "json.hpp"
#include "User.h"

class Employee :
    protected User
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Employee,
        _employeeId, _firstName, _middleName, _lastName,
        _dateOfBirth, _dateOfHire,
        _gender, _address, _phoneNumber);

    std::string _employeeId;
    std::string _firstName;
    std::string _middleName;
    std::string _lastName;
    std::string _dateOfBirth;
    std::string _dateOfHire;
    std::string _gender;
    std::string _address;
    std::string _phoneNumber;
    std::string _tin;
    std::string _philHealth;
    std::string _sss;
    std::vector<std::string> _socialLinks;

public:
    /*
        PERSONAL INFORMATION
        *** NOT FUNCITONAL, PLACEHOLDER ONLY ***
        - Instantiates variables per case then pushes values into list
        - List is updated and overwrites data into a new XLSX or XML file (whichever is preferred)

        MISSING FEATURES:
        - use of up and down keys to move cursor to the next or previous field
    */
    void personalInfoMenu();

    void leaveMenu();

    void overtimeMenu();

    void documentMenu();

    bool operator ==(const Employee& other) const;
};
