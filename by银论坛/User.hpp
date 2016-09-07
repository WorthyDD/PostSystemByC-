#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class User
{
public:
    string nickname;    //昵称
    string id;          //用户ID
    string password;    //登录密码
    
    //构造函数
    User();
    User(string id, string nickname, string password);
    ~User();
    //查看个人信息 : 虚函数
    virtual void printUser() = 0;
};

#endif