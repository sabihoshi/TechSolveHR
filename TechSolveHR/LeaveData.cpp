#include "LeaveData.h"

#include <iostream>

#include "console.h"

void LeaveData::PrintData()
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
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║  Enter Starting Date: yyyy-mm-dd                           ║" << std::endl;
    std::cout << "║       Enter End Date: yyyy-mm-dd                           ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 Use Up/Down to Navigate.                   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║   [Esc] Exit/Cancel                    [Enter] Edit/Save   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
}

void LeaveData::EditData()
{
    PrintData();

    const std::vector data = {
        &StartDate, &EndDate
    };

    EditableData::EditData(data, 1, 24, 11, 35);
}
