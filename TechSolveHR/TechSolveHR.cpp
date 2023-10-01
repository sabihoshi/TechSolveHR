﻿#pragma execution_character_set("utf-8")

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>

#include "boolinq.h"
#include "console.h"
#include "Employee.h"

using namespace std;

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
        - sets the console window title to "onboardingSystem"
        - sets the console output to UTF-8
    */

    SetConsoleTitleA("Tech Solve HR System");
    SetConsoleOutputCP(65001);

    const HWND console = GetConsoleWindow();
    constexpr int consoleHeight = 900;
    constexpr int consoleWidth = 537;
    MoveWindow(console, 0, 0, consoleWidth, consoleHeight, SWP_NOMOVE | SWP_NOZORDER);

    // Check if employee.json exists, if not create it with [] as content

    if (!std::filesystem::exists("employees.json"))
    {
        std::ofstream ofs("employees.json");
        ofs << "[]";
        ofs.close();
    }

    if (!std::filesystem::exists("logins.json"))
    {
        std::ofstream ofs("attendances.json");
        ofs << "[]";
        ofs.close();
    }

    std::ifstream ifsEmployees("employees.json");
    std::vector<Employee> employees = nlohmann::json::parse(ifsEmployees);

    std::ifstream ifsLogins("attendances.json");
    std::vector<AttendanceData> attendances = nlohmann::json::parse(ifsLogins);

    bool exitState = true;
    while (exitState)
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
        std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║               Username: __________________                 ║" << std::endl;
        std::cout << "║               Password: __________________                 ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                    Press [ESC] to exit                     ║" << std::endl;
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
            auto& [EmployeeId, Date, TimeIn, TimeOut] = attendances[i];
            auto& e = employees[i];
            std::cout
                << Center(Date, 11) << " | "
                << Center(e.PersonalData.Name, 16) << " | "
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

        if (boolinq::from(employees).any([&](const Employee& e) { return e.Login(username, password); }))
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
        auto employee = boolinq::from(employees).first([&](const Employee& e) { return e.Login(username, password); });

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
            XY(0, 0);
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
            std::cout << "║               [1] - Update Personal Details                ║" << std::endl;
            std::cout << "║               [2] - Apply for Leave                        ║" << std::endl;
            std::cout << "║               [3] - Access Company Resources               ║" << std::endl;
            std::cout << "║               [4] - Overtime Records                       ║" << std::endl;
            std::cout << "║               [5] - Logout                                 ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║               >>                                           ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
            XY(19, 19);
            std::cin >> choice;
            fflush(stdin);
            system("cls");
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
                    employee.PersonalInfoMenu();
                    break;
                case 2:
                    /*
                        APPLY FOR LEAVE
                        *** NOT FUNCTIONAL, PLACEHOLDER ONLY ***
                        MISSING FEATURES:
                        - use of up and down keys to move cursor to the next or previous field
                    */
                    employee.LeaveMenu();
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
                    employee.DocumentMenu();
                case 4:
                    /*
                        OVERTIME RECORDS
                        *** NOT FUNCTIONAL, PLACEHOLDER ONLY ***
                        MISSING FEATURES:
                        - use of up and down keys to move cursor to the next or previous field
                    */
                    employee.OvertimeMenu();
                case 5:
                    username.clear();
                    password.clear();
                    break;
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
                    system("cls");
                    break;
            }
        }
    }
}