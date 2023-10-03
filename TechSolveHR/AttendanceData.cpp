#include "AttendanceData.h"

#include <fstream>

std::vector<AttendanceData> AttendanceData::Current()
{
	if (_current) return *_current;

	if (!std::filesystem::exists("attendances.json"))
	{
		std::ofstream ofs("attendances.json");
		ofs << "[]";
		ofs.close();
	}

	std::ifstream ifsEmployees("attendances.json");
	return *_current = nlohmann::json::parse(ifsEmployees);
}