#pragma execution_character_set("utf-8")

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "console.h"

using namespace std;

int main()
{
    /*
        CONSOLE CONFIGURATION
        - sets the console window size to 537x900
        - sets the console window title to "onboardingSystem"
        - sets the console output to UTF-8
    */

    SetConsoleTitleA("onboardingSystem");
    SetConsoleOutputCP(65001);
    HWND console = GetConsoleWindow();
    int consoleHeight = 900;
    int consoleWidth = 537;
    MoveWindow(console, 0, 0, consoleWidth, consoleHeight, SWP_NOMOVE | SWP_NOZORDER);

    /* TEMP DECLARATIONS *** CAN BE OPTIMIZED ***
        NOTE: MOST OF THE OUTPUTS ARE TEMPORARY AND CAN BE MIGRATED TO HEADERS OR SEPARATE FUNCTIONS TO OPTIMIZE THE MAIN FUNCTION
    */

    // LOGIN DECLARATIONS
    const string userlog[] = {"admin", "user"};
    const string userpass[] = {"admin", "user"};

    // PERSONAL INFORMATION DECLARATIONS
    char name[100], gender[100], maritalStatus[100], address[100], tin[100], philhealth[100], sss[100], phone[100], socialLinks[100]; // personal information
    char name2[100], relationship[100], phone2[100], email[100], address2[100];                                                       // emergency information
    char hireDate[100], employeeNumber[100], role[100], department[100], division[100], location[100], manager[100];                  // work information

    string password;
    string username;
    const int yposoverride = 9; // for update personal details case 1
    int ypos = 9;
    const int xpos1 = 25;
    int choice = 0;
    string extinput;
    int extinput2 = 0;
    int extinput3 = 0;
    bool exitstate = true;

    /*
        LOGIN PANEL
        - there should be a list/data struct that should contain the login data
        - all previous logins should be persistent and should show up on the login panel
        - if filled, the bottom-most entry in the login panel would be overwritten if another user logs in.

        - there should be superadmin account that has access to all account data and some options that are not available to regular users

        MISSING FEATURES:
    */

    while (exitstate)
    {
        //refresh inputs
        username = "";
        password = "";
        choice = 0;
        extinput = "";
        extinput2 = 0;
        extinput3 = 0;

        std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
        std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
        std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
        std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
        std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║               Username: __________________                 ║" << std::endl;
        std::cout << "║               Password: __________________                 ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "║                    Press [ESC] to exit                     ║" << std::endl;
        std::cout << "║                                                            ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║    DATE     |       NAME       |   TIME IN    |  TIME OUT  ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "║             |                  |              |            ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
        XY(26, 12);
        std::cin >> username;
        XY(26, 13);
        std::cin >> password;
        fflush(stdin);
        system("cls");

        if (username == userlog[0] && password == userpass[0])
        {
            while (choice != 5)
            {
                /*
                    MAIN DASHBOARD.
                    - the user would be able to get into the system after filling in the required fields
                    - the user would be able to access the following:
                        - Personal Information
                        - Apply for Leave
                        - Access Company Resources
                        - Performance Feedback
                        - Overtime Records
                        - Logout
                */

                //refresh inputs
                username = "";
                password = "";
                choice = 0;
                extinput = "";
                extinput2 = 0;
                extinput3 = 0;
                std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
                std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║               [1] - Update Personal Details                ║" << std::endl;
                std::cout << "║               [2] - Apply for Leave                        ║" << std::endl;
                std::cout << "║               [3] - Access Company Resources               ║" << std::endl;
                std::cout << "║               [4] - Overtime Records                       ║" << std::endl;
                std::cout << "║               [5] - Logout                                 ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║               >>                                           ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "║                                                            ║" << std::endl;
                std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                XY(19, 19);
                std::cin >> choice;
                fflush(stdin);
                system("cls");
                switch (choice)
                {
                    case 1:
                        /*
                            PERSONAL INFORMATION
                            *** NOT FUNCITONAL, PLACEHOLDER ONLY ***
                            - Instantiates variables per case then pushes values into list
                            - List is updated and overwrites data into a new XLSX or XML file (whichever is preferred)
    
                            MISSING FEATURES:
                            - use of up and down keys to move cursor to the next or previous field
                        */

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
                        std::cout << "║      Full legal Name:                                      ║" << std::endl;
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
                        XY(xpos1, ypos += 2);
                        std::cin >> name;
                        XY(xpos1, ypos += 2);
                        std::cin >> gender;
                        XY(xpos1, ypos += 2);
                        std::cin >> maritalStatus;
                        XY(xpos1, ypos += 2);
                        std::cin >> address;
                        XY(xpos1, ypos += 2);
                        std::cin >> tin;
                        XY(xpos1, ypos += 2);
                        std::cin >> philhealth;
                        XY(xpos1, ypos += 2);
                        std::cin >> sss;
                        XY(xpos1, ypos += 2);
                        std::cin >> phone;
                        XY(xpos1, ypos += 2);
                        std::cin >> socialLinks;
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
                        break;
                    case 2:
                        /*
                            APPLY FOR LEAVE
                            *** NOT FUNCTIONAL, PLACEHOLDER ONLY ***
                            MISSING FEATURES:
                            - use of up and down keys to move cursor to the next or previous field
                        */
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
                        std::cin >> extinput;
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
                        std::cout << "║                                                            ║" << std::endl;
                        std::cout << "║ (mm-dd-yy)                                                 ║" << std::endl;
                        std::cout << "║                                                            ║" << std::endl;
                        std::cout << "║  Enter Starting Date:                                       ║" << std::endl;
                        std::cout << "║       Enter End Date:                                       ║" << std::endl;
                        std::cout << "║                                                            ║" << std::endl;
                        std::cout << "║                                                            ║" << std::endl;
                        std::cout << "║                                                            ║" << std::endl;
                        std::cout << "║                Press UP/DOWN to navigate.                  ║" << std::endl;
                        std::cout << "║                                                            ║" << std::endl;
                        std::cout << "║ [1] Exit without Saving                  [2] Save and Exit ║" << std::endl;
                        std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                        XY(24, 11);
                        std::cin >> extinput;
                        XY(24, 11);
                        std::cin >> extinput;
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
                        std::cout << "║   Starting Date  |   End Date    |   Type    |   Status    ║" << std::endl;
                        std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                        std::cout << "║    09-18-23         09-24-23         Sick        Pending   ║" << std::endl;
                        std::cout << "║                                                            ║" << std::endl;
                        std::cout << "║                     PLACEHOLDER ONLY                       ║" << std::endl;
                        std::cout << "║                                                            ║" << std::endl;
                        std::cout << "║                                                            ║" << std::endl;
                        std::cout << "║                Press any key to continue...                ║" << std::endl;
                        std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                        getch();
                        system("cls");
                        break;
                    case 3:

                        /*
                            ACCESS COMPANY RESOURCES
                            *** NOT FUNCTIONAL, PLACEHOLDER ONLY ***
                            MISSING FEATURES:
                            - user should input the necessary information being (name, department, etc.) of the employee to be assessed
                            - user should be able to access the following:
                                - Employee Assessment
                                - Request Performance Feedback
                            - use of up and down keys to move cursor to the next or previous field
                        */
                        while (extinput2 != 4)
                        {
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
                            std::cout << "║        ║ Department:                               ║       ║" << std::endl; // add function: left and right keys to scroll through possible options
                            std::cout << "║        ║    Manager:                               ║       ║" << std::endl; // complexities: view performance feedback using dates
                            std::cout << "║        ║                                           ║       ║" << std::endl;
                            std::cout << "║        ╚═══════════════════════════════════════════╝       ║" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "║               [1] - Employee Assessment                    ║" << std::endl;
                            std::cout << "║               [2] - Request Performance Feedback           ║" << std::endl;
                            std::cout << "║               [3] - View Performance Feedback              ║" << std::endl;
                            std::cout << "║               [4] - Back                                   ║" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "║                     >                                      ║" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                            XY(22, 11);
                            std::cin >> extinput;
                            XY(22, 12);
                            std::cin >> extinput;
                            XY(22, 13);
                            std::cin >> extinput;
                            XY(25, 22);
                            std::cin >> extinput2;
                            fflush(stdin);
                            system("cls");
                            switch (extinput2)
                            {
                                case 1:
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
                                    extinput2 = 0;
                                    getch();
                                    fflush(stdin);
                                    system("cls");
                                    break;
                                case 2:
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
                                    std::cout << "║                 Choose HR/Manager to Request:              ║" << std::endl;
                                    std::cout << "║               [1] - exampleHr1                             ║" << std::endl;
                                    std::cout << "║               [2] - exampleHr2                             ║" << std::endl;
                                    std::cout << "║               [3] - Back                                   ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                    >                                       ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                                    XY(23, 15);
                                    std::cin >> extinput3;
                                    fflush(stdin);
                                    system("cls");
                                    switch (extinput3)
                                    {
                                        case 1:
                                            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                                            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                                            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                                            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                                            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                                            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl; //placeholders should contain their respective prompts  
                                            std::cout << "║       You have requested for a performance feedback.       ║" << std::endl;
                                            std::cout << "║                       HR:placeholder                       ║" << std::endl;
                                            std::cout << "║                     DATE:placeholder                       ║" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "║                 [press a key to continue]                  ║" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                                            getch();
                                            fflush(stdin);
                                            extinput3 = 0;
                                            system("cls");
                                            break;
                                        case 2:
                                            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                                            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                                            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                                            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                                            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                                            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl; //placeholders should contain their respective prompts  
                                            std::cout << "║       You have requested for a performance feedback.       ║" << std::endl;
                                            std::cout << "║                       HR:placeholder                       ║" << std::endl;
                                            std::cout << "║                     DATE:placeholder                       ║" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "║                 [press a key to continue]                  ║" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                                            getch();
                                            fflush(stdin);
                                            extinput3 = 0;
                                            system("cls");
                                            break;
                                        case 3:
                                            extinput3 = 0;
                                            system("cls");
                                            break;
                                        default:
                                            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                                            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                                            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                                            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                                            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                                            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                                            std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
                                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "║                      Invalid Entry!                        ║" << std::endl;
                                            std::cout << "║               [Press any key to try again]                 ║" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "║                                                            ║" << std::endl;
                                            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                                            getch();
                                            system("cls");
                                            break;
                                    }
                                    break;
                                case 3:
                                    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                                    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                                    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                                    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                                    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                                    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                                    std::cout << "║  Job Knowledge             ║                               ║" << std::endl;
                                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                                    std::cout << "║  Work Quality              ║                               ║" << std::endl;
                                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                                    std::cout << "║  Punctuality               ║                               ║" << std::endl;
                                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl; //Meant to access your accounts feedback from other employees
                                    std::cout << "║  Productivity              ║                               ║" << std::endl; //This should show multiple assessments from other employees
                                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl; //Controls: User can use up or down arrow to navigate through their feedback
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
                                    std::cout << "║ Press any key to continue...       Use UP/DOWN to navigate.║" << std::endl;
                                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                                    getch();
                                    system("cls");
                                    break;
                                case 4:
                                    system("cls");
                                    break;
                                default:
                                    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                                    std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                                    std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                                    std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                                    std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                                    std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                                    std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
                                    std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                      Invalid Entry!                        ║" << std::endl;
                                    std::cout << "║               [Press any key to try again]                 ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                                    getch();
                                    extinput2 = 0;
                                    fflush(stdin);
                                    system("cls");
                                    break;
                            }
                        }
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
                    // getch();
                    // fflush(stdin);
                    // system("cls");
                        break;
                    case 4:
                        while (extinput2 != 3)
                        {
                            extinput2 = 0;
                            extinput3 = 0;
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
                            std::cin >> extinput2;
                            fflush(stdin);
                            system("cls");
                            switch (extinput2)
                            {
                                case 1:
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
                                    std::cout << "║ Time In:                                                   ║" << std::endl;
                                    std::cout << "║ Time Out:                                                  ║" << std::endl;
                                    std::cout << "║ Amount:                                                    ║" << std::endl;
                                    std::cout << "║ Type (Holiday/Overtime/Nighttime):                         ║" << std::endl;
                                    std::cout << "║ Reason:                                                    ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║ Press UP/DOWN to navigate.                                 ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║ [1] Exit without Saving                  [2] Save and Exit ║" << std::endl;
                                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                                    XY(11, 11);
                                    std::cin >> extinput3;
                                    XY(12, 12);
                                    std::cin >> extinput3;
                                    XY(10, 13);
                                    std::cin >> extinput3;
                                    XY(37, 14);
                                    std::cin >> extinput3;
                                    XY(10, 15);
                                    std::cin >> extinput3;
                                    fflush(stdin);
                                    system("cls");
                                    break;
                                case 2:
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
                                    std::cout << "║                                                            ║" << std::endl; // Uses the same interface as above but user is allowed to scroll through them
                                    std::cout << "║ Time In:                                                   ║" << std::endl; // Controls: user can use up or down arrows to navigate through the records
                                    std::cout << "║ Time Out:                                                  ║" << std::endl;
                                    std::cout << "║ Amount:                                                    ║" << std::endl;
                                    std::cout << "║ Type (Holiday/Overtime/Nighttime):                         ║" << std::endl;
                                    std::cout << "║ Reason:                                                    ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "║                [Press UP/DOWN to navigate.]                ║" << std::endl;
                                    std::cout << "║                                                            ║" << std::endl;
                                    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                                    getch();
                                    fflush(stdin);
                                    system("cls");
                                    break;
                                case 3:
                                    fflush(stdin);
                                    break;
                                default:
                                    break;
                            }
                        case 5:
                            username.clear();
                            password.clear();
                            break;
                        default:
                            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
                            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
                            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
                            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
                            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
                            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                            std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
                            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "║                      Invalid Entry!                        ║" << std::endl;
                            std::cout << "║               [Press any key to try again]                 ║" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "║                                                            ║" << std::endl;
                            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
                            getch();
                            system("cls");
                            break;
                        }
                }
            }
        }
        else
        {
            std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
            std::cout << "║   ____    _    ____  _   _ ____   ___    _    ____  ____   ║" << std::endl;
            std::cout << "║  |  _ \\  / \\  / ___|| | | | __ ) / _ \\  / \\  |  _ \\|  _ \\  ║" << std::endl;
            std::cout << "║  | | | |/ _ \\ \\___ \\| |_| |  _ \\| | | |/ _ \\ | |_) | | | | ║" << std::endl;
            std::cout << "║  | |_| / ___ \\ ___) |  _  | |_) | |_| / ___ \\|  _ <| |_| | ║" << std::endl;
            std::cout << "║  |____/_/   \\_\\____/|_| |_|____/ \\___/_/   \\_\\_| \\_\\____/  ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║                |    LOGIN SYSTEM MENU   |                  ║" << std::endl;
            std::cout << "╠════════════════════════════════════════════════════════════╣" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                Wrong Username or Password                  ║" << std::endl;
            std::cout << "║               [Press any key to try again]                 ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "║                                                            ║" << std::endl;
            std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
            getch();
            system("cls");
        }
    }
}
