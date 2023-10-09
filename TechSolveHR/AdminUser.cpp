#pragma execution_character_set("utf-8")

#include "AdminUser.h"

#include <fstream>
#include <iostream>

#include "boolinq.h"
#include "console.h"

namespace
{
    std::vector<const AdminUser*>* all;
}

std::vector<const AdminUser*>& AdminUser::All()
{
    if (all != nullptr) return *all;

    if (!std::filesystem::exists("admins.json"))
    {
        AdminUser u;
        u.Username = "admin";
        u.Password = "admin";

        all = new std::vector<const AdminUser*>{&u};

        std::ofstream ofs("admins.json");
        ofs << nlohmann::json(boolinq::from(*all).select([&](const auto& x) { return *x; }).toStdVector()).dump(4);
        ofs.close();
    }

    std::ifstream ifsEmployees("admins.json");
    all = new std::vector<const AdminUser*>;

    for (const auto& admin : nlohmann::json::parse(ifsEmployees).get<std::vector<AdminUser>>())
    {
        all->push_back(new AdminUser(admin));
    }

    if (all->empty())
    {
        AdminUser u;
        u.Username = "admin";
        u.Password = "admin";

        all->push_back(&u);
        Save();
    }

    return *all;
}

void AdminUser::Save()
{
    if (!all) return;

    std::vector<AdminUser> v;
    for (const auto& admin : *all)
    {
        v.push_back(*admin);
    }

    const nlohmann::json j = v;
    std::ofstream ofsAdmins("admins.json");
    ofsAdmins << j.dump(4);
}

void AdminUser::CreateEmployeeMenu()
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
    std::cout << "║               |    CREATE EMPLOYEE MENU    |               ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║            User Type:                                      ║" << std::endl; // 24, 11
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                     [A]dmin  [E]mployee                    ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    XY(24, 12);
    std::string userType;
    std::cin >> userType;

    Clear(ClearType::Screen);
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║               |    CREATE EMPLOYEE MENU    |               ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║             Username:                                      ║" << std::endl; // 24, 11
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    XY(24, 12);
    std::string username;
    std::cin >> username;

    Clear(ClearType::Screen);
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║               |    CREATE EMPLOYEE MENU    |               ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║             Password:                                      ║" << std::endl; // 24, 11
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    XY(24, 12);
    std::string password;
    std::cin >> password;

    switch (userType[0])
    {
        case 'A':
        case 'a':
        {
            AdminUser user;
            user.Username = username;
            user.Password = password;
            user.EditInfoMenu();

            All().push_back(new AdminUser(user));
            Save();

            Clear(ClearType::Screen);
            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║               |    CREATE EMPLOYEE MENU    |               ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                      Admin created                         ║" << std::endl;
            std::cout << "║                [Press any key to continue]                 ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
            _getch();
            break;
        }
        case 'E':
        case 'e':
        {
            Employee user;
            user.Username = username;
            user.Password = password;
            user.EditInfoMenu();

            Employee::All().push_back(new Employee(user));
            Employee::Save();

            Clear(ClearType::Screen);
            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║               |    CREATE EMPLOYEE MENU    |               ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                      Employee created                      ║" << std::endl;
            std::cout << "║                [Press any key to continue]                 ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
            _getch();
            break;
        }
        default:
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
            std::cout << "║               |    CREATE EMPLOYEE MENU    |               ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                      Invalid Entry!                        ║" << std::endl;
            std::cout << "║               [Press any key to try again]                 ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
            _getch();
        }
    }
}

void AdminUser::EditEmployeeMenu()
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
    std::cout << "║       Enter Employee ID:                                   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    XY(27, 10);
    std::string employeeId;
    std::cin >> employeeId;

    const bool isAdmin = boolinq::from(All()).any([&](const AdminUser* user) { return user->WorkData.EmployeeId == employeeId; });
    const bool isEmployee = boolinq::from(Employee::All()).any([&](const Employee* user) { return user->WorkData.EmployeeId == employeeId; });

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
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║             Error! Unable to find that employee.           ║" << std::endl;
        std::cout << "║               Press [Enter] to continue.                   ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
        _getch();
        return;
    }

    if (isAdmin)
    {
        const auto admin = boolinq::from(All()).first([&](const AdminUser* user) { return user->WorkData.EmployeeId == employeeId; });
        const_cast<AdminUser*>(admin)->EditInfoMenu();
    }
    else
    {
        const auto employee = boolinq::from(Employee::All()).first([&](const Employee* user) { return user->WorkData.EmployeeId == employeeId; });
        const_cast<Employee*>(employee)->EditInfoMenu();
    }
}

void AdminUser::DeleteEmployeeMenu()
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
    std::cout << "║       Enter Employee ID:                                   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    XY(27, 10);
    std::string employeeId;
    std::cin >> employeeId;

    const bool isAdmin = boolinq::from(All()).any([&](const AdminUser* user) { return user->WorkData.EmployeeId == employeeId; });
    const bool isEmployee = boolinq::from(Employee::All()).any([&](const Employee* user) { return user->WorkData.EmployeeId == employeeId; });

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
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║             Error! Unable to find that employee.           ║" << std::endl;
        std::cout << "║               Press [Enter] to continue.                   ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
        _getch();
        return;
    }

    if (isAdmin)
    {
        const auto admin = boolinq::from(All()).first([&](const AdminUser* user) { return user->WorkData.EmployeeId == employeeId; });
        auto _ = std::remove(All().begin(), All().end(), admin);
        Save();
    }
    else
    {
        const auto employee = boolinq::from(Employee::All()).first([&](const Employee* user) { return user->WorkData.EmployeeId == employeeId; });
        auto _ = std::remove(Employee::All().begin(), Employee::All().end(), employee);
        Employee::Save();
    }
}
