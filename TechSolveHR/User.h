#pragma once
#include <string>

#include "EditableData.h"

class User
{
public:
    virtual ~User() = default;

    std::string Username;
    std::string Password;

    void ChangePasswordMenu();

    void ChangeUsernameMenu();

    [[nodiscard]] bool Login(const std::string& username, const std::string& password) const;
};