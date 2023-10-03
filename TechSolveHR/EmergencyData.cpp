#include "EmergencyData.h"

#include <iostream>

#include "console.h"

void EmergencyData::PrintData()
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
    std::cout << "║                          Emergency                         ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 Name:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║         Relationship:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                Phone:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                Email:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║              Address:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 Use Up/Down to Navigate.                   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║   [Esc] Exit/Cancel                    [Enter] Edit/Save   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
}

void EmergencyData::EditData()
{
    PrintData();

    const std::vector data = {
        &Name, &Relationship, &PhoneNumber,
        &EmailAddress, &Address
    };

    EditableData::EditData(data, 2, 24, 11, 35);
}
