#include "Model.hpp"


Model::Model()
{

}

Model::Model(string name, Moderator *moderator)
{
    this->name = name;
    this->moderator = moderator;
}

Model::~Model()
{
    vector<Post*>::iterator i = posts.begin();
    while(i != posts.end()){
        
        delete *i;
        i++;
    }
}

void Model::printModel()
{
    cout<<"板块名称 : "<<name<<", 版主 : "<<moderator->nickname<<", 版主ID : "<<moderator->id<<", 帖子数量 : "<<posts.size()<<endl;
}

void Model::scanAllPosts()
{
    vector<Post*>::iterator i = posts.begin();
    while(i != posts.end()){
        
        Post *post = *i;
        post->printPost();
        i++;
    }
}