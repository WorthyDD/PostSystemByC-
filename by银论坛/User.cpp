#include "User.hpp"

User::User()
{
    id = "admin";
    nickname = "admin";
    password = "admin";
}

User::User(string id, string nickname, string password)
{
    this->id = id;
    this->nickname = nickname;
    this->password = password;
}

User::~User()
{
    
}
