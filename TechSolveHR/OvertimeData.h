#pragma once
#include <string>

#include "EditableData.h"
#include "json.hpp"

class OvertimeData : EditableData
{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(OvertimeData,
        TimeIn, TimeOut, Amount, Type, Reason)

public:
    std::string TimeIn;
    std::string TimeOut;
    std::string Amount;
    std::string Type;
    std::string Reason;

    void PrintData() override;

    void EditData() override;
};
