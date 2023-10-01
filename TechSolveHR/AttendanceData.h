#pragma once
#include "Employee.h"
#include "json.hpp"

class AttendanceData
{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(AttendanceData,
        EmployeeId, Date, TimeIn, TimeOut)

public:
    std::string EmployeeId;
    std::string Date;
    std::string TimeIn;
    std::string TimeOut;
};
