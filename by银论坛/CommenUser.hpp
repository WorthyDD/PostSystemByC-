#ifndef CommenUser_hpp
#define CommenUser_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "User.hpp"

using namespace std;


//普通用户
class CommenUser : public User
{

public:
    
    bool isMedorator;   //是否是版主
    
    CommenUser();
    CommenUser(string id, string nickname, string password);
    ~CommenUser();
    
    
    //发帖：用户可以选择在某一板块下发帖
    void post();
    
    //评论：用户可以在某一帖子下评论
    void comment();
    
    //查看：查看论坛当前已有的板块及各板块下的帖子
    void scanPost();
    
    //查看个人信息
    void printUser();
};

#endif