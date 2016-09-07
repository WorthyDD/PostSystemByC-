#include "CommenUser.hpp"

CommenUser::CommenUser()
{
    this->isMedorator = false;
}

CommenUser::CommenUser(string id, string nickname, string password):User(id,nickname,password)
{
    this->isMedorator = false;
}

CommenUser::~CommenUser()
{
    
}

void CommenUser::printUser()
{
    cout<<"Commen user"<<endl;
    cout<<"id : "<<id<<"\nnickname : "<<nickname<<endl;
}