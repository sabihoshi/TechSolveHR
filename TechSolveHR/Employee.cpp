#pragma execution_character_set("utf-8")

#include "Employee.h"

#include <fstream>

#include "boolinq.h"
#include "console.h"
#include "LeaveData.h"

namespace
{
    std::vector<const Employee*>* all;
}

std::vector<const Employee*>& Employee::All()
{
    if (all) return *all;

    if (!std::filesystem::exists("employees.json"))
    {
        std::ofstream ofs("employees.json");
        ofs << "[]";
        ofs.close();
    }

    std::ifstream ifsEmployees("employees.json");
    all = new std::vector<const Employee*>();

    for (const auto& j : nlohmann::json::parse(ifsEmployees).get<std::vector<Employee>>())
    {
        all->push_back(new Employee(j));
    }

    return *all;
}

void Employee::Save()
{
    if (!all) return;

    const nlohmann::json j
        = boolinq::from(*all)
          .select([&](const auto& x) { return *x; })
          .toStdVector();

    std::ofstream ofsEmployees("employees.json");
    ofsEmployees << j.dump(4);
}

void Employee::EditInfoMenu()
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
    std::cout << "║                   [4] - Back                               ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                     >                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

    XY(24, 16);
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
            return;
    }

    leave.EditData();
    Leaves.push_back(leave);
}

void Employee::PrintLeaveData()
{
    Clear(ClearType::Screen);
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
                std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

                XY(23, 10);
                std::string employeeId;
                std::cin >> employeeId;

                if (!boolinq::from(All()).any([&](const Employee* e) { return e->WorkData.EmployeeId == employeeId; }))
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
                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                    _getch();
                    continue;
                }
                auto* employee = const_cast<Employee*>(boolinq::from(All()).first([&](const Employee* e) { return e->WorkData.EmployeeId == employeeId; }));

                if (employee->WorkData.ManagerId != WorkData.EmployeeId)
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
                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                    _getch();
                    continue;
                }

                PerformanceData performance;
                performance.EmployeeId = employee->WorkData.EmployeeId;
                performance.ManagerId = WorkData.EmployeeId;
                performance.EditData();
                employee->Performances.push_back(performance);

                break;
            }
            case 2:
            {
                auto reviews = boolinq::from(Performances)
                               .orderBy([&](const PerformanceData& p) { return p.Date; })
                               .reverse().toStdVector();

                int index = 0;
                bool repeat = true;

                while (repeat)
                {
                    switch (_getch())
                    {
                        case 224:
                        {
                            switch (_getch())
                            {
                                case KEY_UP:
                                {
                                    index = index > 0 ? index - 1 : 0;
                                    break;
                                }
                                case KEY_DOWN:
                                {
                                    index = index < reviews.size() - 1 ? index + 1 : reviews.size() - 1;
                                    break;
                                }
                            }

                            constexpr int spacing = 29;
                            auto review = reviews[index];
                            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                            std::cout << "║  Job Knowledge             ║ " << Center(review.JobKnowledge, spacing) << " ║" << std::endl;
                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                            std::cout << "║  Work Quality              ║ " << Center(review.WorkQuality, spacing) << " ║" << std::endl;
                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                            std::cout << "║  Punctuality               ║ " << Center(review.Punctuality, spacing) << " ║" << std::endl;
                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                            std::cout << "║  Productivity              ║ " << Center(review.Productivity, spacing) << " ║" << std::endl;
                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                            std::cout << "║  Communication Skills      ║ " << Center(review.Communication, spacing) << " ║" << std::endl;
                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                            std::cout << "║  Overall Rating:           ║ " << Center(review.Overall, spacing) << " ║" << std::endl;
                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                            std::cout << "║ Comments:                                                  ║" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            for (const auto& comment : Chunk(review.Comments, 58))
                            {
                                std::cout << "║ " << Left(comment, 58) << " ║" << std::endl;
                            }
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "║ Press [Esc] to exit              Use [Up/Down] to navigate.║" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                            break;
                        }
                        case KEY_ESC:
                            repeat = false;
                            break;
                    }
                }

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

void Employee::AttendanceMenu()
{
    while (true)
    {
        Clear(ClearType::Screen);
        std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
        std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
        std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
        std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
        std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║                |    ATTENDANCE RECORDS   |                 ║" << std::endl;
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
        int attendanceOption;
        std::cin >> attendanceOption;

        switch (attendanceOption)
        {
            case 1:
            {
                AttendanceData attendance;
                attendance.EditData();

                Attendances.push_back(attendance);
                break;
            }
            case 2:
            {
                Clear(ClearType::Screen);
                std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║        DATE        |      TIME IN      |      TIME OUT     ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;

                for (const auto& a : Attendances)
                {
                    std::cout
                        << "║ " << Center(a.Date, 18)
                        << " | " << Center(a.TimeIn, 17)
                        << " | " << Center(a.TimeOut, 17) << " ║"
                        << std::endl;
                }
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                [Press any key to continue]                 ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                _getch();
                break;
            }
            case 3:
                return;
            default:
                OvertimeMenu();
        }
    }
}

void Employee::OvertimeMenu()
{
    while (true)
    {
        Clear(ClearType::Screen);
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
                Clear(ClearType::Screen);
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

                for (auto& [TimeIn, TimeOut, Amount, Type, Reason] : Overtimes)
                {
                    std::cout
                        << "║ " << Center(TimeIn, 9)
                        << " | " << Center(TimeOut, 10)
                        << " | " << Center(Amount, 8)
                        << " | " << Center(Type, 7)
                        << " | " << Center(Reason, 14) << " ║"
                        << std::endl;
                }

                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                [Press any key to continue]                 ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                _getch();
                break;
            }
            case 3:
                return;
            default:
                OvertimeMenu();
        }
    }
}

bool Employee::operator==(const Employee& other) const
{
    return WorkData.EmployeeId == other.WorkData.EmployeeId;
}
