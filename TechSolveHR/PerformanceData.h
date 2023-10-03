#pragma once

#include "json.hpp"
#include "EditableData.h"



class PerformanceData : EditableData
{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(PerformanceData,
        Date, EmployeeId, ManagerId,
        JobKnowledge, WorkQuality, Punctuality,
        Productivity, Communication, Overall, Comments)

public:
	void PrintData() override;
	void EditData() override;

    std::string Date;
	std::string EmployeeId;
	std::string ManagerId;
	std::string JobKnowledge;
	std::string WorkQuality;
	std::string Punctuality;
	std::string Productivity;
	std::string Communication;
	std::string Overall;
	std::string Comments;
};
