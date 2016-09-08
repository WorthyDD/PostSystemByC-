#include "Model.hpp"


Model::Model()
{
    posts = new map<string, Post*>();
}

Model::Model(string name, Moderator *moderator):Model::Model()
{
    this->name = name;
    this->moderator = moderator;
}

Model::~Model()
{
    delete posts;
}

void Model::printModel()
{
    cout<<"板块名称 : "<<name<<", 版主 : "<<moderator->nickname<<", 版主ID : "<<moderator->id<<", 帖子数量 : "<<posts->size()<<endl;
}

void Model::scanAllPosts()
{
    cout<<"--------------------------------------------------"<<endl;
    map<string, Post*>::iterator i = posts->begin();
    while(i != posts->end()){
        
        Post *post = i->second;
        post->printPost();
        i++;
    }
}