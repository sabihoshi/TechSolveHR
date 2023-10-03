#pragma once

#include "EditableData.h"


class PerformanceData : EditableData
{
public:
	~PerformanceData() override;
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

