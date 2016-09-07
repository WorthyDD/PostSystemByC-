#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "Moderator.hpp"
#include "Post.hpp"

using namespace std;

//板块
class Model
{
    
public:
    
    //板块名
    string name;
    
    //版主
    Moderator *moderator;
    
    //帖子
    vector<Post*> posts;
    
    Model();
    Model(string name, Moderator *moderator);
    ~Model();
    
};

#endif /* Model_hpp */
