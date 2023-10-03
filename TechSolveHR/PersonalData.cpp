#include "PersonalData.h"

#include <iostream>

#include "console.h"

void PersonalData::PrintData()
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
    std::cout << "║                     Personal Information                   ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║      Full legal Name:                                      ║" << std::endl; // 24, 11
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║               Gender:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║       Marital Status:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║              Address:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                  TIN:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║           PhilHealth:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                  SSS:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                Phone:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 Use Up/Down to Navigate.                   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║   [Esc] Exit/Cancel                    [Enter] Edit/Save   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
}

void PersonalData::EditData()
{
    PrintData();

    const std::vector data = {
        &Name, &Gender,
        &MaritalStatus, &Address,
        &Tin, &PhilHealth, &Sss,
        &PhoneNumber,
    };

    EditableData::EditData(data, 2, 24, 11, 35);
}
