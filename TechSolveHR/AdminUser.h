#pragma once

#include <vector>

#include "Employee.h"

class AdminUser : public Employee
{
public:
    static std::vector<AdminUser*>& All();

    static void Save();

    void CreateEmployeeMenu();

    void EditEmployeeMenu();

    void DeleteEmployeeMenu();

    void DocumentMenu();
};