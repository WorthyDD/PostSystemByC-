#include "Administrator.hpp"
#include "System.hpp"


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

void Administrator::work()
{
    string flag = "";
    
    while(flag != "Q"){
        cout<<"查看操作(1) 任命/撤销版主(2) 退出管理员(Q)"<<endl;
        string c;
        cin>>c;
        if(c == "1"){
            scanSystem();
        }
        else if(c == "2"){
            managerModerator();
        }
        else if(c == "Q"){
            break;
        }
    }
    
}

void Administrator::scanSystem()
{
    
    System *system = System::getInstance();
    map<string, Model*> *models = system->models;
    map<string, Model*>::iterator i = models->begin();
    while(i != models->end()){
        
        Model *model = i->second;
        model->printModel();
        i++;
    }
    
    cout<<"请选择需要浏览的版块的版主ID"<<endl;
    string userID = "";
    while(true){
        cin>>userID;
        map<string, Model*>::iterator i = models->find(userID);
        if(i != models->end()){
            
            //找到
            Model *model = i->second;
            model->printModel();
            model->scanAllPosts();
            break;
        }
    }
    
}

void Administrator::managerModerator()
{
    System *system = System::getInstance();
    map<string, Model*> *models = system->models;
    map<string, CommenUser*> *users = system->users;
    
    map<string, Model*>::iterator i = models->begin();
    while(i != models->end()){
        
        Model *model = i->second;
        model->printModel();
        i++;
    }
    
    cout<<"请选择需要撤销版主ID"<<endl;
    string userID = "";
    while(true){
        cin>>userID;
        map<string, Model*>::iterator i = models->find(userID);
        if(i != models->end()){
            
            //找到
            Model *model = i->second;
            model->moderator->isMedorator = false;
            models->erase(userID);
            cout<<"请输入新的版主的ID"<<endl;
            string newID = "";
            while(true){
                cin>>newID;
                map<string, CommenUser*>::iterator it = users->find(newID);
                if(it != users->end()){
                    
                    //找到
                    CommenUser *user = it->second;
                    user->isMedorator = true;
                    model->moderator = new Moderator(user);
                    model->printModel();
                    models->insert(pair<string, Model*>(user->id, model));
                    break;
                }
            }
            break;
        }
    }

}