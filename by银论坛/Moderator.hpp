#ifndef Moderator_hpp
#define Moderator_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "CommenUser.hpp"

using namespace std;


//版主
class Moderator : public CommenUser
{
public:
    
    Moderator();
    Moderator(string id, string nickname, string password);
    
    ~Moderator();
    
    //删帖：删除其管理版块下的某一帖子
    void deletePost();
    
    //查看个人信息
    void printUser();
    
};


#endif