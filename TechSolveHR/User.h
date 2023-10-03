#pragma once
#include <string>

#include "EditableData.h"

class User
{
public:
    std::string Username;
    std::string Password;

    virtual void Save() = 0;

    void ChangePasswordMenu();

    void ChangeUsernameMenu();

    [[nodiscard]] bool Login(const std::string& username, const std::string& password) const;
};