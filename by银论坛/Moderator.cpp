#include "Moderator.hpp"

Moderator::Moderator()
{
    
}

Moderator::Moderator(string id, string nickname, string password):CommenUser(id,nickname,password)
{
    
}

Moderator::~Moderator()
{
    
}

void Moderator::printUser()
{
    cout<<"Moderator"<<endl;
    cout<<"id : "<<id<<"\nnickname : "<<nickname<<endl;
}