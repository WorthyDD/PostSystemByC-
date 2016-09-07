#include "CommenUser.hpp"

CommenUser::CommenUser()
{
    
}

CommenUser::CommenUser(string id, string nickname, string password):User(id,nickname,password)
{
    
}

CommenUser::~CommenUser()
{
    
}

void CommenUser::printUser()
{
    cout<<"Commen user"<<endl;
    cout<<"id : "<<id<<"\nnickname : "<<nickname<<endl;
}