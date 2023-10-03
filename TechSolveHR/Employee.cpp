#pragma execution_character_set("utf-8")

#include "Employee.h"

#include <fstream>

#include "boolinq.h"
#include "console.h"
#include "LeaveData.h"


std::vector<Employee> Employee::All()
{
    if (_all) return *_all;

    if (!std::filesystem::exists("employees.json"))
    {
        std::ofstream ofs("employees.json");
        ofs << "[]";
        ofs.close();
    }

    std::ifstream ifsEmployees("employees.json");
    return *_all = nlohmann::json::parse(ifsEmployees);
}

void Employee::Save()
{
    if (!_all) return;

    const nlohmann::json j = *_all;

    std::ofstream ofsEmployees("employees.json");
    ofsEmployees <<  j.dump(4);
}

void Employee::PersonalInfoMenu()
{
    Clear(ClearType::Screen);
    PersonalData.EditData();

    Clear(ClearType::Screen);
    EmergencyData.EditData();

    Clear(ClearType::Screen);
    WorkData.EditData();
}

void Employee::LeaveMenu()
{
    Clear(ClearType::Screen);
    XY(0, 0);
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                   [1] - Sick Leave                         ║" << std::endl;
    std::cout << "║                   [2] - Vacation Leave                     ║" << std::endl;
    std::cout << "║                   [3] - Leave List                         ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                     >                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

    XY(24, 15);
    int leaveOption;
    std::cin >> leaveOption;

    Clear(ClearType::Screen);
    XY(0, 0);

    LeaveData leave;
    switch (leaveOption)
    {
        case 1:
            leave.Type = "Sick";
            break;
        case 2:
            leave.Type = "Vacation";
            break;
        case 3:
            PrintLeaveData();
            return;
        default:
            break;
    }

    leave.EditData();
    Leaves.push_back(leave);
}

void Employee::PrintLeaveData()
{
    Clear(ClearType::Screen);
    XY(0, 0);
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║   Starting Date  |   End Date    |   Type    |   Status    ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;

    for (auto& leave : Leaves)
    {
        std::cout
            << "║ " << Center(leave.StartDate, 16) << " | "
            << Center(leave.EndDate, 14) << " | "
            << Center(leave.Type, 10) << " | "
            << Center(leave.Status, 10) << " ║"
            << std::endl;
    }

    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
}

void Employee::DocumentMenu()
{
    while (true)
    {
        std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
        std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
        std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
        std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
        std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║               [1] - Employee Assessment                    ║" << std::endl;
        std::cout << "║               [2] - View Performance Feedback              ║" << std::endl;
        std::cout << "║               [3] - Back                                   ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                     >                                      ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

        XY(24, 14);
        int documentOption;
        std::cin >> documentOption;

        switch (documentOption)
        {
            case 1:
            {
                Clear(ClearType::Screen);
                XY(0, 0);
                std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║         Employee ID:                                       ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

                XY(23, 10);
                std::string employeeId;
                std::cin >> employeeId;

                if (!boolinq::from(All()).any([&](const Employee& e) { return e.WorkData.EmployeeId == employeeId; }))
                {
                    Clear(ClearType::Screen);
                    XY(0, 0);
                    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║             Error! Unable to find that employee.           ║" << std::endl;
                    std::cout << "║               Press [Enter] to continue.                   ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                    _getch();
                    continue;
                }
                auto employee = boolinq::from(All()).first([&](const Employee& e) { return e.WorkData.EmployeeId == employeeId; });

                if (employee.WorkData.ManagerId != Current.WorkData.EmployeeId)
                {
                    Clear(ClearType::Screen);
                    XY(0, 0);
                    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║       Error! You are not a manager of this employee.       ║" << std::endl;
                    std::cout << "║               Press [Enter] to continue.                   ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "║                                                            ║" << std::endl;
                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                    _getch();
                    continue;
                }

                PerformanceData performance;
                performance.EmployeeId = employee.WorkData.EmployeeId;
                performance.ManagerId = Current.WorkData.EmployeeId;
                performance.EditData();
                employee.Performances.push_back(performance);

                break;
            }
            case 2:
            {
                auto reviews = boolinq::from(Performances)
                    .orderBy([&](const PerformanceData& p) { return p.Date; })
                    .reverse().toStdVector();

                std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║  Job Knowledge             ║                               ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║  Work Quality              ║                               ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║  Punctuality               ║                               ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║  Productivity              ║                               ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║  Communication Skills      ║                               ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║  Overall Rating:           ║                               ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║ Comments:                                                  ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║ Press any key to continue...       Use UP/DOWN to navigate.║" << std::endl;
                std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                _getch();
                break;
            }
            case 3:
                return;
            default:
                std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                      Invalid Entry!                        ║" << std::endl;
                std::cout << "║               [Press any key to try again]                 ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                _getch();
                break;
        }
    }
}

void Employee::OvertimeMenu()
{
    Clear(ClearType::Screen);
    XY(0, 0);
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                 |    OVERTIME RECORDS   |                  ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║               [1] - Add Record                             ║" << std::endl;
    std::cout << "║               [2] - View Records                           ║" << std::endl;
    std::cout << "║               [3] - Back                                   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 >                                          ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

    XY(20, 15);
    int overtimeOption;
    std::cin >> overtimeOption;

    Clear(ClearType::Screen);
    XY(0, 0);
    switch (overtimeOption)
    {
        case 1:
        {
            OvertimeData overtime;
            overtime.EditData();

            Overtimes.push_back(overtime);
            break;
        }
        case 2:
        {
            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║  Time In  |  Time Out  |  Amount  |  Type  |    Reason     ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;

            for (auto& overtime : Overtimes)
            {
                std::cout
                    << "║ " << Center(overtime.TimeIn, 9)
                    << " | " << Center(overtime.TimeOut, 10)
                    << " | " << Center(overtime.Amount, 8)
                    << " | " << Center(overtime.Type, 7)
                    << " | " << Center(overtime.Reason, 14) << " ║"
                    << std::endl;
            }

            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
            break;
        }
        case 3:
            return;
        default:
            OvertimeMenu();
    }
}

bool Employee::operator==(const Employee& other) const
{
    return WorkData.EmployeeId == other.WorkData.EmployeeId;
}
