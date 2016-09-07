#include "Administrator.hpp"

Administrator::Administrator()
{
    this->id = "admin";
    this->nickname = "admin";
    this->password = "admin";
}

Administrator::Administrator(string id, string nickname, string password):User(id,nickname,password)
{

}

Administrator::~Administrator()
{
    
}


void Administrator::printUser()
{
    cout<<"Administrator"<<endl;
    cout<<"id : "<<id<<endl;
    cout<<"nickname : "<<nickname<<endl;
}