#include "User.h"

bool User::Login(const std::string& username, const std::string& password) const
{
    return username == Username && password == Password;
}
