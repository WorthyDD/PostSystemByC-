#include "Post.hpp"

Post::Post(){}

Post::Post(string id, string title, time_t time, string content)
{
    this->id = id;
    this->title = title;
    this->time = time;
    this->content = content;
}

Post::~Post()
{
    
    vector<Comment *>::iterator i = comments.begin();
    while(i != comments.end()){
        
        delete *i;
        i++;
    }
}