#pragma once
#include <chrono>

#include "AttendanceData.h"
#include "EmergencyData.h"
#include "json.hpp"
#include "LeaveData.h"
#include "OvertimeData.h"
#include "PersonalData.h"
#include "User.h"
#include "WorkData.h"
#include "PerformanceData.h"

class Employee : public User
{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Employee,
        Username, Password,
        PersonalData, EmergencyData, WorkData)

    static std::vector<Employee>* _all;

public:
    PersonalData PersonalData;
    EmergencyData EmergencyData;
    WorkData WorkData;
    std::vector<LeaveData> Leaves;
    std::vector<OvertimeData> Overtimes;
    std::vector<PerformanceData> Performances;

    static std::vector<Employee> All();

    void Save() override;

    /*
        PERSONAL INFORMATION
        - Instantiates variables per case then pushes values into list
        - List is updated and overwrites data into a new XLSX or XML file (whichever is preferred)
    */
    void EditInfoMenu();

    void LeaveMenu();

    void PrintLeaveData();

    void DocumentMenu();

    void OvertimeMenu();

    bool operator ==(const Employee& other) const;
};
