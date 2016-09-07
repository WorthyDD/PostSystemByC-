#ifndef Post_hpp
#define Post_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Comment.hpp"
#include "CommenUser.hpp"
using namespace std;

//帖子
class Post
{
    
public:
    
    
    //id
    string id;
    
    //发帖人
    CommenUser *user;
    
    //发帖时间
    time_t time;
    
    //标题
    string title;
    //内容
    string content;
    
    //评论列表
    vector<Comment *> comments;
    
    Post();
    Post(string id, string title, time_t time, string content);
    ~Post();
    
    //打印帖子
    void printPost();
    
};

#endif /* Post_hpp */
