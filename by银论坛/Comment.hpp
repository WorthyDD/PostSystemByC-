#ifndef Comment_hpp
#define Comment_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "CommenUser.hpp"

//评论
class Comment
{
    
public:
    
    Comment();
    Comment(CommenUser *user, time_t time, string content);
    ~Comment();
    
    //评论者
    CommenUser *user;
    
    //评论时间
    time_t time;
    
    //评论内容
    string content;
    
    
};

#endif /* Comment_hpp */
