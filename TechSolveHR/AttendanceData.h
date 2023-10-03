#pragma once

#include "EditableData.h"
#include "json.hpp"

class AttendanceData : EditableData
{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(AttendanceData, Date, TimeIn, TimeOut)

public:
    std::string Date;
    std::string TimeIn;
    std::string TimeOut;

    void PrintData() override;

    void EditData() override;
};
