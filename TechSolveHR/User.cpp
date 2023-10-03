#include "User.h"

#include <iostream>
#include <ostream>

#include "Employee.h"

void User::ChangePasswordMenu()
{
    std::string oldPassword;
    std::string newPassword;
    std::string newPasswordRepeat;

    std::cout << "Enter old password: ";
    std::cin >> oldPassword;

    if (oldPassword != Password)
    {
        std::cout << "Wrong password!" << std::endl;
        return;
    }

    std::cout << "Enter new password: ";
    std::cin >> newPassword;

    std::cout << "Repeat new password: ";
    std::cin >> newPasswordRepeat;

    if (newPassword != newPasswordRepeat)
    {
        std::cout << "Passwords do not match!" << std::endl;
        return;
    }

    Password = newPassword;
    std::cout << "Password changed successfully!" << std::endl;
}

void User::ChangeUsernameMenu()
{
    std::string newUsername;
    std::cout << "Enter new username: ";
    std::cin >> newUsername;

    Username = newUsername;
    std::cout << "Username changed successfully!" << std::endl;
}

bool User::Login(const std::string& username, const std::string& password) const
{
    return username == Username && password == Password;
}
