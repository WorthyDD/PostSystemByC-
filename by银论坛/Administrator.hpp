#ifndef Administrator_hpp
#define Administrator_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "User.hpp"

using namespace std;

//管理员
class Administrator: User
{

public:
    
    Administrator();
    Administrator(string id, string nickname, string password);
    ~Administrator();
    
    //查看操作：查看论坛当前已有的板块及各板块下的帖子
    void scanSystem();
    
    //任命和撤销版主功能：管理员可以任命和撤销某一版块的版主
    void managerModerator();
    
    //管理员开始工作
    void work();
    //打印个人信息
    void printUser();
};

#endif