#ifndef System_hpp
#define System_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Model.hpp"
#include <string>
#include <map>
#include <fstream>
#include "Administrator.hpp"

using namespace std;

class System
{
    
private:
    
    System();
    ~System();
    System(const System&);
    System& operator=(const System&);
    
private:
    static System* instance;
    
public:
    
    //单例
    static System* getInstance();
    
    //所有模块
    map<string, Model*> *models;
    
    //所有用户
    map<string, CommenUser*> *users;
    
    //管理员
    Administrator *administrator;
    
    //系统初始化:
    void initSystem();
    
private:
    //加载板块
    void loadModel();
    
    //加载用户
    void loadUser();
    
    //分割字符串
    vector<string> split(const string &s, const string &soperator);
};

#endif