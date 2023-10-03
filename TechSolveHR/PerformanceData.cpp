#include "PerformanceData.h"

#include <iostream>

#include "console.h"

void PerformanceData::PrintData()
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
	std::cout << "║        ╔═══════════════════════════════════════════╗       ║" << std::endl;
	std::cout << "║        ║           Employee Information            ║       ║" << std::endl;
	std::cout << "║        ║                                           ║       ║" << std::endl;
	std::cout << "║        ║       Name:                               ║       ║" << std::endl;
	std::cout << "║        ║ Department:                               ║       ║" << std::endl;
	std::cout << "║        ║    Manager:                               ║       ║" << std::endl;
	std::cout << "║        ║                                           ║       ║" << std::endl;
	std::cout << "║        ╚═══════════════════════════════════════════╝       ║" << std::endl;
	std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
	std::cout << "║  Job Knowledge             ║                               ║" << std::endl;
	std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
	std::cout << "║  Work Quality              ║                               ║" << std::endl;
	std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
	std::cout << "║  Punctuality               ║                               ║" << std::endl;
	std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
	std::cout << "║  Productivity              ║                               ║" << std::endl;
	std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
	std::cout << "║  Communication Skills      ║                               ║" << std::endl;
	std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
	std::cout << "║  Overall Rating:           ║                               ║" << std::endl;
	std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ Comments:                                                  ║" << std::endl;
	std::cout << "║                                                            ║" << std::endl;
	std::cout << "║                                                            ║" << std::endl;
	std::cout << "║                                                            ║" << std::endl;
	std::cout << "║                                                            ║" << std::endl;
	std::cout << "║                                                            ║" << std::endl;
	std::cout << "║                                                            ║" << std::endl;
	std::cout << "║                                                            ║" << std::endl;
	std::cout << "║                                                            ║" << std::endl;
	std::cout << "║                                                            ║" << std::endl;
	std::cout << "║                                    Use UP/DOWN to navigate.║" << std::endl;
	std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
}

void PerformanceData::EditData()
{
	PrintData();

	const std::vector data = {
		&JobKnowledge, &WorkQuality, &Punctuality,
		&Productivity, &Communication, &Overall, &Comments,
	};

	EditableData::EditData(data, 2, 31, 17, 29);
}
