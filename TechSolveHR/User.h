#pragma once
#include <string>

#include "EditableData.h"

class User
{
public:
    std::string Username;
    std::string Password;

    [[nodiscard]] bool Login(const std::string& username, const std::string& password) const;
};