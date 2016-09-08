#include "Post.hpp"

Post::Post()
{
    comments = new map<string, Comment*>();
}

Post::Post(string id, string title, string time, string content):Post::Post()
{
    this->id = id;
    this->title = title;
    this->time = time;
    this->content = content;
}

Post::~Post()
{
    
    delete comments;
}

void Post::printPost()
{
    cout<<"----------------------------------"<<endl;
    cout<<title<<endl;
    cout<<content<<endl;
    cout<<time<<endl;
    cout<<"----------------------------------"<<endl;
    map<string, Comment *>::iterator i = comments->begin();
    while(i != comments->end()){
        
        Comment *comment = i->second;
        comment->printComment();
        i++;
    }
    
}