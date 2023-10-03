#pragma once
#include "Employee.h"

class AdminUser : Employee
{

    static std::vector<AdminUser>* _all;
public:

    static std::vector<AdminUser> All();

    void Save() override;

    void CreateEmployeeMenu();

    void EditEmployeeMenu();
};

