#pragma execution_character_set("utf-8")

#include "AdminUser.h"

#include <fstream>
#include <iostream>

#include "boolinq.h"
#include "console.h"

std::vector<AdminUser> AdminUser::All()
{
    if (_all) return *_all;

    if (!std::filesystem::exists("admins.json"))
    {
        std::ofstream ofs("admins.json");
        ofs << "[]";
        ofs.close();
    }

    std::ifstream ifsEmployees("admins.json");
    return *_all = nlohmann::json::parse(ifsEmployees);
}

void AdminUser::Save()
{
    if (!_all) return;
}

void AdminUser::CreateEmployeeMenu()
{
    XY(24, 12);
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║" << Center("Create Employee", 64) <<"║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║            User Type:                                      ║" << std::endl; // 24, 11
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    std::string userType;
    std::cin >> userType;

    Clear(ClearType::Screen);
    XY(24, 12);
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║" << Center("Create Employee", 64) <<"║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║             Username:                                      ║" << std::endl; // 24, 11
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    std::string username;
    std::cin >> username;

    Clear(ClearType::Screen);
    XY(24, 12);
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║" << Center("Create Employee", 64) <<"║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║             Password:                                      ║" << std::endl; // 24, 11
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    std::string password;
    std::cin >> password;

    switch (userType[0])
    {
        case 'A':
        {
            AdminUser user;
            user.EditInfoMenu();

            All().push_back(user);
            Save();
            break;
        }
        case 'E':
        {
            Employee user;
            user.EditInfoMenu();

            Employee::All().push_back(user);
            Employee::Save();
            break;
        }
        default:
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
            std::cout << "║               |    CREATE EMPLOYEE MENU    |                 ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                      Invalid Entry!                        ║" << std::endl;
            std::cout << "║               [Press any key to try again]                 ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
        }
    }
}

void AdminUser::EditEmployeeMenu()
{
    std::cout << "Enter employee ID";
    std::string employeeId;
    std::cin >> employeeId;

    bool isAdmin = boolinq::from(All()).any([&](const auto& user) { return user.WorkData.EmployeeId == employeeId; });
    bool isEmployee = boolinq::from(Employee::All()).any([&](const auto& user) { return user.WorkData.EmployeeId == employeeId; });

    e.EditInfoMenu();
}
