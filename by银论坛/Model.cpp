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