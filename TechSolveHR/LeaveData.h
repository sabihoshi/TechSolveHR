#pragma once

#include <string>

#include "EditableData.h"
#include "json.hpp"

class LeaveData : EditableData
{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(LeaveData,
        StartDate, EndDate, Type, Status)

public:
    std::string StartDate = "yyyy-mm-dd";
    std::string EndDate = "yyyy-mm-dd";
    std::string Type = "Pending";
    std::string Status;

    void PrintData() override;

    void EditData() override;
};
