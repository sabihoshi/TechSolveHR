#pragma once

#include "json.hpp"

class AttendanceData
{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(AttendanceData,
        EmployeeId, Date, TimeIn, TimeOut)

    static std::vector<AttendanceData>* _current;

public:
    std::string EmployeeId;
    std::string Date;
    std::string TimeIn;
    std::string TimeOut;

    static std::vector<AttendanceData> Current();
};
