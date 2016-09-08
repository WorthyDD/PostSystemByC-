#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include "Moderator.hpp"
#include "Post.hpp"

using namespace std;

//板块
class Model
{
    
public:
    
    Model();
    Model(string name, Moderator *moderator);
    ~Model();
    
    //板块名
    string name;
    
    //版主
    Moderator *moderator;
    
    //帖子
    map<string, Post*> *posts;
    
    //打印模块的基本信息
    void printModel();
    
    //查看该版本下所有的帖子
    void scanAllPosts();
    
};

#endif /* Model_hpp */
