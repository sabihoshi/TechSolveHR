#pragma execution_character_set("utf-8")

#include "Employee.h"

#include <iostream>
#include "console.h"

void Employee::personalInfoMenu()
{
    COORD top = { 24, 11 };

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
    std::cout << "║         Social Links:                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

    // Fill up existing data
    XY(24, 11);

    std::cout << _lastName << ", " << _firstName << " " << _middleName;
    MoveCursor(CursorDirection::Down, 2);

    std::cout << _gender;
    MoveCursor(CursorDirection::Down, 2);






    fflush(stdin);
    system("cls");
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
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    ypos = yposoverride;
    XY(xpos1, ypos += 2);
    std::cin >> name2;
    XY(xpos1, ypos += 2);
    std::cin >> relationship;
    XY(xpos1, ypos += 2);
    std::cin >> phone2;
    XY(xpos1, ypos += 2);
    std::cin >> email;
    XY(xpos1, ypos += 2);
    std::cin >> address2;
    fflush(stdin);
    system("cls");
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
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 Use Up/Down to Navigate.                   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║ [1] Exit without Saving                 [2] Exit and Save  ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    ypos = yposoverride;
    XY(xpos1, ypos += 2);
    std::cin >> hireDate;
    XY(xpos1, ypos += 2);
    std::cin >> employeeNumber;
    XY(xpos1, ypos += 2);
    std::cin >> role;
    XY(xpos1, ypos += 2);
    std::cin >> department;
    XY(xpos1, ypos += 2);
    std::cin >> division;
    XY(xpos1, ypos += 2);
    std::cin >> location;
    XY(xpos1, ypos += 2);
    std::cin >> manager;
    fflush(stdin);
    system("cls");
}
