#include "Comment.hpp"


Comment::Comment(){}

Comment::Comment(CommenUser *user, time_t time, string content)
{
    this->user = user;
    this->time = time;
    this->content = content;
}

Comment::~Comment()
{
    if(this->user != NULL){
        
        delete this->user;
    }
}