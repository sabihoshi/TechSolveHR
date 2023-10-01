#include "WorkData.h"

#include <iostream>

#include "console.h"

void WorkData::PrintData()
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
    std::cout << "║                            Work                            ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║            Hire Date:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║           Employee #:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 Role:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║           Department:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║             Division:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║             Location:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║              Manager:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 Use Up/Down to Navigate.                   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║   [Esc] Exit/Cancel                    [Enter] Edit/Save   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
}

void WorkData::EditData()
{
    PrintData();

    std::vector data = {
        &HireDate, &EmployeeId,
        &Role, &Department, &Division,
        &Location, &ManagerId,
    };

    EditableData::EditData(data, 2, 24, 11, 35);
}
