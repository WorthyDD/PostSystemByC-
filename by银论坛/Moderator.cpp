#include "Moderator.hpp"

Moderator::Moderator()
{
    this->isMedorator = true;
}

Moderator::Moderator(string id, string nickname, string password):CommenUser(id,nickname,password)
{
    this->isMedorator = true;
}

Moderator::Moderator(CommenUser *user)
{
    this->id = user->id;
    this->nickname = user->nickname;
    this->password = user->password;
    this->isMedorator = true;
}

Moderator::~Moderator()
{
    
}

void Moderator::printUser()
{
    cout<<"Moderator"<<endl;
    cout<<"id : "<<id<<"\nnickname : "<<nickname<<endl;
}

string Moderator::getName()
{
    return nickname;
}