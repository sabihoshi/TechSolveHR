#pragma once
#include "EditableData.h"
#include "json.hpp"

class WorkData : EditableData
{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(WorkData,
        HireDate, EmployeeId,
        Role, Department, Division,
        Location, ManagerId)

public:
    std::string HireDate = "01/01/1990";
    std::string EmployeeId;
    std::string Role;
    std::string Department;
    std::string Division;
    std::string Location;
    std::string ManagerId = "0";

    void PrintData() override;

    void EditData() override;
};
