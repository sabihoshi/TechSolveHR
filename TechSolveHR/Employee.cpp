#pragma execution_character_set("utf-8")

#include "Employee.h"

#include "console.h"
#include "LeaveData.h"

void Employee::PersonalInfoMenu()
{
    PersonalData.EditData();
    Clear(ClearType::Screen);
    EmergencyData.EditData();
    Clear(ClearType::Screen);
    WorkData.EditData();
}

void Employee::LeaveMenu()
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
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                   [1] - Sick Leave                         ║" << std::endl;
    std::cout << "║                   [2] - Vacation Leave                     ║" << std::endl;
    std::cout << "║                   [3] - Leave List                         ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                     >                                      ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

    XY(24, 15);
    int leaveOption;
    std::cin >> leaveOption;

    Clear(ClearType::Screen);
    XY(0, 0);

    LeaveData leave;
    switch (leaveOption)
    {
        case 1:
            leave.Type = "Sick";
            break;
        case 2:
            leave.Type = "Vacation";
            break;
        case 3:
            PrintLeaveData();
            return;
        default:
            break;
    }

    leave.EditData();
    Leaves.push_back(leave);
}

void Employee::PrintLeaveData()
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
    std::cout << "║   Starting Date  |   End Date    |   Type    |   Status    ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;

    for (auto& leave : Leaves)
    {
        std::cout
            << "║ " << Center(leave.StartDate, 16) << " | "
            << Center(leave.EndDate, 14) << " | "
            << Center(leave.Type, 10) << " | "
            << Center(leave.Status, 10) << " ║"
            << std::endl;
    }

    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
}

void Employee::DocumentMenu()
{
    //while (extinput2 != 4)
    //{
    //    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    //    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    //    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    //    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    //    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    //    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    //    std::cout << "║                                                            ║" << std::endl;
    //    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //    std::cout << "║        ╔═══════════════════════════════════════════╗       ║" << std::endl;
    //    std::cout << "║        ║           Employee Information            ║       ║" << std::endl;
    //    std::cout << "║        ║                                           ║       ║" << std::endl;
    //    std::cout << "║        ║       Name:                               ║       ║" << std::endl;
    //    std::cout << "║        ║ Department:                               ║       ║" << std::endl; // add function: left and right keys to scroll through possible options
    //    std::cout << "║        ║    Manager:                               ║       ║" << std::endl; // complexities: view performance feedback using dates
    //    std::cout << "║        ║                                           ║       ║" << std::endl;
    //    std::cout << "║        ╚═══════════════════════════════════════════╝       ║" << std::endl;
    //    std::cout << "║                                                            ║" << std::endl;
    //    std::cout << "║               [1] - Employee Assessment                    ║" << std::endl;
    //    std::cout << "║               [2] - Request Performance Feedback           ║" << std::endl;
    //    std::cout << "║               [3] - View Performance Feedback              ║" << std::endl;
    //    std::cout << "║               [4] - Back                                   ║" << std::endl;
    //    std::cout << "║                                                            ║" << std::endl;
    //    std::cout << "║                     >                                      ║" << std::endl;
    //    std::cout << "║                                                            ║" << std::endl;
    //    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    //    XY(22, 11);
    //    std::cin >> extinput;
    //    XY(22, 12);
    //    std::cin >> extinput;
    //    XY(22, 13);
    //    std::cin >> extinput;
    //    XY(25, 22);
    //    std::cin >> extinput2;
    //    fflush(stdin);
    //    system("cls");
    //    switch (extinput2)
    //    {
    //        case 1:
    //            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    //            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    //            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    //            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    //            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    //            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║        ╔═══════════════════════════════════════════╗       ║" << std::endl;
    //            std::cout << "║        ║           Employee Information            ║       ║" << std::endl;
    //            std::cout << "║        ║                                           ║       ║" << std::endl;
    //            std::cout << "║        ║       Name:                               ║       ║" << std::endl;
    //            std::cout << "║        ║ Department:                               ║       ║" << std::endl;
    //            std::cout << "║        ║    Manager:                               ║       ║" << std::endl;
    //            std::cout << "║        ║                                           ║       ║" << std::endl;
    //            std::cout << "║        ╚═══════════════════════════════════════════╝       ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║  Job Knowledge             ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║  Work Quality              ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║  Punctuality               ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║  Productivity              ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║  Communication Skills      ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║  Overall Rating:           ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║ Comments:                                                  ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                    Use UP/DOWN to navigate.║" << std::endl;
    //            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    //            extinput2 = 0;
    //            _getch();
    //            fflush(stdin);
    //            system("cls");
    //            break;
    //        case 2:
    //            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    //            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    //            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    //            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    //            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    //            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                 Choose HR/Manager to Request:              ║" << std::endl;
    //            std::cout << "║               [1] - exampleHr1                             ║" << std::endl;
    //            std::cout << "║               [2] - exampleHr2                             ║" << std::endl;
    //            std::cout << "║               [3] - Back                                   ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                    >                                       ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    //            XY(23, 15);
    //            std::cin >> extinput3;
    //            fflush(stdin);
    //            system("cls");
    //            switch (extinput3)
    //            {
    //                case 1:
    //                    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    //                    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    //                    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    //                    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    //                    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    //                    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl; //placeholders should contain their respective prompts  
    //                    std::cout << "║       You have requested for a performance feedback.       ║" << std::endl;
    //                    std::cout << "║                       HR:placeholder                       ║" << std::endl;
    //                    std::cout << "║                     DATE:placeholder                       ║" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "║                 [press a key to continue]                  ║" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    //                    _getch();
    //                    fflush(stdin);
    //                    extinput3 = 0;
    //                    system("cls");
    //                    break;
    //                case 2:
    //                    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    //                    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    //                    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    //                    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    //                    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    //                    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl; //placeholders should contain their respective prompts  
    //                    std::cout << "║       You have requested for a performance feedback.       ║" << std::endl;
    //                    std::cout << "║                       HR:placeholder                       ║" << std::endl;
    //                    std::cout << "║                     DATE:placeholder                       ║" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "║                 [press a key to continue]                  ║" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    //                    _getch();
    //                    fflush(stdin);
    //                    extinput3 = 0;
    //                    system("cls");
    //                    break;
    //                case 3:
    //                    extinput3 = 0;
    //                    system("cls");
    //                    break;
    //                default:
    //                    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    //                    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    //                    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    //                    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    //                    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    //                    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //                    std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
    //                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "║                      Invalid Entry!                        ║" << std::endl;
    //                    std::cout << "║               [Press any key to try again]                 ║" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "║                                                            ║" << std::endl;
    //                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    //                    _getch();
    //                    system("cls");
    //                    break;
    //            }
    //            break;
    //        case 3:
    //            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    //            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    //            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    //            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    //            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    //            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║  Job Knowledge             ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║  Work Quality              ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║  Punctuality               ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl; //Meant to access your accounts feedback from other employees
    //            std::cout << "║  Productivity              ║                               ║" << std::endl; //This should show multiple assessments from other employees
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl; //Controls: User can use up or down arrow to navigate through their feedback
    //            std::cout << "║  Communication Skills      ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║  Overall Rating:           ║                               ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║ Comments:                                                  ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║ Press any key to continue...       Use UP/DOWN to navigate.║" << std::endl;
    //            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    //            _getch();
    //            system("cls");
    //            break;
    //        case 4:
    //            system("cls");
    //            break;
    //        default:
    //            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    //            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    //            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    //            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    //            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    //            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
    //            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                      Invalid Entry!                        ║" << std::endl;
    //            std::cout << "║               [Press any key to try again]                 ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "║                                                            ║" << std::endl;
    //            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    //            _getch();
    //            extinput2 = 0;
    //            fflush(stdin);
    //            system("cls");
    //            break;
    //    }
    /*
        following fields should take inputs from the user
        inputs provided would be saved as the employee's performance
    */
    // std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    // std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
    // std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
    // std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
    // std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
    // std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
    // std::cout << "║                                                            ║" << std::endl;
    // std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    // std::cout << "║        ╔═══════════════════════════════════════════╗       ║" << std::endl;
    // std::cout << "║        ║           Employee Information            ║       ║" << std::endl;
    // std::cout << "║        ║                                           ║       ║" << std::endl;
    // std::cout << "║        ║       Name:                               ║       ║" << std::endl;
    // std::cout << "║        ║ Department:                               ║       ║" << std::endl;
    // std::cout << "║        ║    Manager:                               ║       ║" << std::endl;
    // std::cout << "║        ║                                           ║       ║" << std::endl;
    // std::cout << "║        ╚═══════════════════════════════════════════╝       ║" << std::endl;
    // std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    // std::cout << "║  Job Knowledge             ║                               ║" << std::endl;
    // std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    // std::cout << "║  Work Quality              ║                               ║" << std::endl;
    // std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    // std::cout << "║  Punctuality               ║                               ║" << std::endl;
    // std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    // std::cout << "║  Productivity              ║                               ║" << std::endl;
    // std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    // std::cout << "║  Communication Skills      ║                               ║" << std::endl;
    // std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    // std::cout << "║  Overall Rating:           ║                               ║" << std::endl;
    // std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    // std::cout << "║ Comments:                                                  ║" << std::endl;
    // std::cout << "║                                                            ║" << std::endl;
    // std::cout << "║                                                            ║" << std::endl;
    // std::cout << "║                                                            ║" << std::endl;
    // std::cout << "║                                                            ║" << std::endl;
    // std::cout << "║                                                            ║" << std::endl;
    // std::cout << "║                                                            ║" << std::endl;
    // std::cout << "║                                                            ║" << std::endl;
    // std::cout << "║                                                            ║" << std::endl;
    // std::cout << "║                                                            ║" << std::endl;
    // std::cout << "║ Press any key to continue...       Use UP/DOWN to navigate.║" << std::endl;
    // std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    // _getch();
    // fflush(stdin);
    // system("cls");
}

void Employee::OvertimeMenu()
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
    std::cout << "║                 |    OVERTIME RECORDS   |                  ║" << std::endl;
    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║               [1] - Add Record                             ║" << std::endl;
    std::cout << "║               [2] - View Records                           ║" << std::endl;
    std::cout << "║               [3] - Back                                   ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "║                 >                                          ║" << std::endl;
    std::cout << "║                                                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

    XY(20, 15);
    int overtimeOption;
    std::cin >> overtimeOption;

    Clear(ClearType::Screen);
    XY(0, 0);
    switch (overtimeOption)
    {
        case 1:
        {
            OvertimeData overtime;
            overtime.EditData();

            Overtimes.push_back(overtime);
            break;
        }
        case 2:
        {
            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║  Time In  |  Time Out  |  Amount  |  Type  |    Reason     ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;

            for (auto& overtime : Overtimes)
            {
                std::cout
                    << "║ " << Center(overtime.TimeIn, 9)
                    << " | " << Center(overtime.TimeOut, 10)
                    << " | " << Center(overtime.Amount, 8)
                    << " | " << Center(overtime.Type, 7)
                    << " | " << Center(overtime.Reason, 14) << " ║"
                    << std::endl;
            }

            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
            break;
        }
        case 3:
            return;
        default:
            OvertimeMenu();
    }
}

bool Employee::operator==(const Employee& other) const
{
    return WorkData.EmployeeId == other.WorkData.EmployeeId;
}
