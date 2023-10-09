#pragma execution_character_set("utf-8")

#include "AttendanceData.h"

#include <iostream>

#include "console.h"

void AttendanceData::PrintData()
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
    std::cout << "║                 |    ATTENDANCE RECORDS   |                ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 Date:                                      ║" << std::endl;
    std::cout << "║              Time In:                                      ║" << std::endl;
    std::cout << "║             Time Out:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 Use Up/Down to Navigate.                   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║   [Esc] Exit/Cancel                    [Enter] Edit/Save   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
}

void AttendanceData::EditData()
{
    PrintData();

    Date = CurrentDate();
    TimeIn = CurrentTime();
    TimeOut = CurrentTime();

    const std::vector data = {
        &Date, &TimeIn, &TimeOut
    };

    EditableData::EditData(data, 1, 24, 11, 35);
}
