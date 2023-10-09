#pragma execution_character_set("utf-8")

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>

#include "boolinq.h"
#include "console.h"
#include "Employee.h"
#include "AdminUser.h"

using namespace std;

void EmployeeMenu(Employee*);

void AdminMenu(AdminUser*);

/*
    LOGIN PANEL
    - there should be a list/data struct that should contain the login data
    - all previous logins should be persistent and should show up on the login panel
    - if filled, the bottom-most entry in the login panel would be overwritten if another user logs in.

    - there should be superadmin account that has access to all account data and some options that are not available to regular users

    MISSING FEATURES:
*/
int main()
{
    /*
        CONSOLE CONFIGURATION
        - sets the console window size to 537x900
        - sets the console window title to "TechSolve HR System"
        - sets the console output to UTF-8
    */

    SetConsoleTitleA("TechSolve HR System");
    SetConsoleOutputCP(65001);

    const HWND console = GetConsoleWindow();
    constexpr int consoleHeight = 900;
    constexpr int consoleWidth = 537;
    MoveWindow(console, 0, 0, consoleWidth, consoleHeight, SWP_NOMOVE | SWP_NOZORDER);

    while (true)
    {
        ResetColor();

        struct EmployeeAttendance
        {
            std::string Name;
            AttendanceData Attendance;
        };

        const auto adminAttendances = boolinq::from(AdminUser::All()).selectMany([](const AdminUser* e)
        {
            return boolinq::from(e->Attendances)
                .select([=](const AttendanceData& a) { return EmployeeAttendance{e->PersonalData.Name, a}; });
        });
        const auto employeeAttendances = boolinq::from(Employee::All()).selectMany([](const Employee* e)
        {
            return boolinq::from(e->Attendances)
                .select([=](const AttendanceData& a) { return EmployeeAttendance{e->PersonalData.Name, a}; });
        });

        const auto attendances =
            employeeAttendances
            .concat(adminAttendances)
            .orderBy([&](const EmployeeAttendance& e) { return e.Attendance.Date; })
            .toStdVector();

        Clear(ClearType::Screen);
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
        std::cout << "║               Username: __________________                 ║" << std::endl;
        std::cout << "║               Password: __________________                 ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║    DATE     |       NAME       |   TIME IN   |   TIME OUT  ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "║             |                  |             |             ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

        // Attendance records
        XY(2, 20);
        for (int i = 0; i < 17 && i < attendances.size(); i++)
        {
            auto current = XY();
            auto& [Date, TimeIn, TimeOut] = attendances[i].Attendance;
            auto& name = attendances[i].Name;
            std::cout
                << Center(Date, 11) << " | "
                << Center(name, 16) << " | "
                << Center(TimeIn, 11) << " | "
                << Center(TimeOut, 11);
            XY(current);
            MoveCursor(CursorDirection::Down, 1);
        }

        // Login
        std::string password;
        std::string username;

        XY(26, 12);
        std::cin >> username;
        XY(26, 13);
        std::cin >> password;

        const bool isAdmin = boolinq::from(AdminUser::All()).any([&](const auto& e) { return e->Login(username, password); });
        const bool isEmployee = boolinq::from(Employee::All()).any([&](const auto& e) { return e->Login(username, password); });

        if (!isAdmin && !isEmployee)
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
            std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                Wrong Username or Password                  ║" << std::endl;
            std::cout << "║               [Press any key to try again]                 ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
            _getch();
            continue;
        }

        if (isAdmin)
        {
            auto admin = boolinq::from(AdminUser::All()).first([&](const auto& e) { return e->Login(username, password); });

            AdminMenu(const_cast<AdminUser*>(admin));
            AdminUser::Save();
        }
        else
        {
            auto employee = boolinq::from(Employee::All()).first([&](const auto& e) { return e->Login(username, password); });

            EmployeeMenu(const_cast<Employee*>(employee));
            Employee::Save();
        }
    }
}

void EmployeeMenu(Employee* employee)
{
    while (true)
    {
        int choice = 0;
        while (choice != 5)
        {
            /*
                MAIN DASHBOARD.
                - the user would be able to get into the system after filling in the required fields
                - the user would be able to access the following:
                    - Personal Information
                    - Apply for Leave
                    - Access Company Resources
                    - Performance Feedback
                    - Overtime Records
                    - Logout
            */

        Clear(ClearType::Screen);
        std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
        std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
        std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
        std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
        std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║                |      Employee Menu     |                  ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║               [1] - Update Personal Details                ║" << std::endl;
        std::cout << "║               [2] - Apply for Leave                        ║" << std::endl;
        std::cout << "║               [3] - Access Company Resources               ║" << std::endl;
        std::cout << "║               [4] - Attendance Records                     ║" << std::endl;
        std::cout << "║               [5] - Overtime Records                       ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║               [6] - Back                                   ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║               >>                                           ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
        XY(19, 20);
        std::cin >> choice;

            switch (choice)
            {
            case 1:
                /*
                    PERSONAL INFORMATION
                    *** NOT FUNCITONAL, PLACEHOLDER ONLY ***
                    - Instantiates variables per case then pushes values into list
                    - List is updated and overwrites data into a new XLSX or XML file (whichever is preferred)

                    MISSING FEATURES:
                    - use of up and down keys to move cursor to the next or previous field
                */
                employee->EditInfoMenu();
                Employee::Save();
                break;
            case 2:
                /*
                    APPLY FOR LEAVE
                    *** NOT FUNCTIONAL, PLACEHOLDER ONLY ***
                    MISSING FEATURES:
                    - use of up and down keys to move cursor to the next or previous field
                */
                employee->LeaveMenu();
                Employee::Save();
                break;
            case 3:

                /*
                    ACCESS COMPANY RESOURCES
                    *** NOT FUNCTIONAL, PLACEHOLDER ONLY ***
                    MISSING FEATURES:
                    - user should input the necessary information being (name, department, etc.) of the employee to be assessed
                    - user should be able to access the following:
                        - Employee Assessment
                        - Request Performance Feedback
                    - use of up and down keys to move cursor to the next or previous field
                */
                employee->DocumentMenu();
                Employee::Save();
                break;
            case 4:
                employee->AttendanceMenu();
                Employee::Save();
                break;
            case 5:
                /*
                    OVERTIME RECORDS
                    *** NOT FUNCTIONAL, PLACEHOLDER ONLY ***
                    MISSING FEATURES:
                    - use of up and down keys to move cursor to the next or previous field
                */
                employee->OvertimeMenu();
                Employee::Save();
                break;
            case 6:
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
}

void AdminMenu(AdminUser* admin)
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
        std::cout << "║                  |      Admin Menu     |                   ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║               [1] - Create Employee                        ║" << std::endl;
        std::cout << "║               [2] - Edit Employee                          ║" << std::endl;
        std::cout << "║               [3] - Delete Employee                        ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║               [4] - Update Personal Details                ║" << std::endl;
        std::cout << "║               [5] - Apply for Leave                        ║" << std::endl;
        std::cout << "║               [6] - Access Company Resources               ║" << std::endl;
        std::cout << "║               [7] - Attendance Records                     ║" << std::endl;
        std::cout << "║               [8] - Overtime Records                       ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║               [9] - Back                                   ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║               >>                                           ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
        XY(19, 25);

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            admin->CreateEmployeeMenu();
            break;
        case 2:
            admin->EditEmployeeMenu();
            break;
        case 3:
            admin->DeleteEmployeeMenu();
            break;
        case 4:
            /*
                PERSONAL INFORMATION
                *** NOT FUNCITONAL, PLACEHOLDER ONLY ***
                - Instantiates variables per case then pushes values into list
                - List is updated and overwrites data into a new XLSX or XML file (whichever is preferred)

                MISSING FEATURES:
                - use of up and down keys to move cursor to the next or previous field
            */
            admin->EditInfoMenu();
            AdminUser::Save();
            break;
        case 5:
            /*
                APPLY FOR LEAVE
                MISSING FEATURES:
                - use of up and down keys to move cursor to the next or previous field
            */
            admin->LeaveMenu();
            AdminUser::Save();
            break;
        case 6:

            /*
                ACCESS COMPANY RESOURCES
                MISSING FEATURES:
                - user should input the necessary information being (name, department, etc.) of the employee to be assessed
                - user should be able to access the following:
                    - Employee Assessment
                    - Request Performance Feedback
                - use of up and down keys to move cursor to the next or previous field
            */
            admin->DocumentMenu();
            AdminUser::Save();
            break;
        case 7:
            admin->AttendanceMenu();
            AdminUser::Save();
            break;
        case 8:
            /*
                OVERTIME RECORDS
                MISSING FEATURES:
                - use of up and down keys to move cursor to the next or previous field
            */
            admin->OvertimeMenu();
            AdminUser::Save();
            break;
        case 9:
            return;
        default:
            Clear(ClearType::Screen);
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
