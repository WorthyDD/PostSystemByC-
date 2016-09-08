#include "System.hpp"


System* System::instance = new System();
    
System* System::getInstance(){
    
    return instance;
}

System::System()
{
    administrator = new Administrator();
    loadUser();
    loadModel();
}

System::~System()
{
    
}



void System::initSystem()
{
    cout<<"初始化完毕!\n"<<endl;
    
    string flag = "";       //结束标志  Q结束
    while(flag != "Q"){
     
        cout<<"************************************************"<<endl;
        cout<<"*                                              *"<<endl;
        cout<<"*               By银论坛系统                     *"<<endl;
        cout<<"*                                              *"<<endl;
        cout<<"************************************************"<<endl;
        cout<<endl;
        
        cout<<"请选择管理员身份或者普通用户身份(管理员a/普通用户c) 退出(Q)"<<endl;
        string c = "";
        while(c != "c" || c != "a"){
            cin>>c;
            if(c == "a"){
                
                string line = "";
                while(line != "admin admin"){
                    cout<<"欢迎管理员用户!请输入用户名和密码(空格隔开,默认为admin admin)"<<endl;
                    getline(cin,line);
                    if(line == "admin admin"){
                        //管理员登录成功
                        cout<<"管理员登录成功!"<<endl;
                        administrator->printUser();
                        administrator->work();
                        break;
                    }
                    cout<<"用户名或密码错误"<<endl;
                }
                break;
            }
            else if(c == "c"){
                cout<<"欢迎用户!请选择注册或者登录"<<endl;
                break;
            }
            else if(c == "Q"){
                //退出
                return;
            }
        }
        
    }
    
}

void System::loadUser()
{
    users = new map<string, CommenUser*>();
    cout<<"加载用户列表..."<<endl;
    char buffer[256];
    fstream outFile;
    outFile.open("/Users/wuxi/Documents/workspace/C++/by银论坛/by银论坛/user.txt", ios::in);
    while(!outFile.eof()){
        //getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束  
        outFile.getline(buffer, 256, '\n');
//        cout<<buffer<<endl;
        if(buffer[0] == '#'){
            continue;
        }
        vector<string> strs = split(string(buffer), " ");
        string isModerator = strs[2];
//        cout<<strs[0]<<strs[1]<<strs[2]<<strs[3]<<endl;
        if(isModerator == "0"){
            CommenUser *user = new CommenUser(strs[0], strs[1], strs[3]);
            user->printUser();
            users->insert(pair<string, CommenUser*>(user->id, user));
        }
        else{
            Moderator *moderator = new Moderator(strs[0], strs[1], strs[3]);
            moderator->printUser();
            users->insert(pair<string, CommenUser*>(moderator->id, moderator));
        }
        
    }
    outFile.close();
}

void System::loadModel()
{
    models = new map<string, Model*>();
    cout<<"加载板块列表..."<<endl;
    char buffer[256];
    fstream outFile;
    outFile.open("/Users/wuxi/Documents/workspace/C++/by银论坛/by银论坛/model.txt", ios::in);
    while(!outFile.eof()){
        //getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束
        outFile.getline(buffer, 256, '\n');
        //        cout<<buffer<<endl;
        if(buffer[0] == '#'){
            continue;
        }
        vector<string> strs = split(string(buffer), " ");
        string modelUserID = strs[1];
        map<string, CommenUser*>::iterator i = users->find(modelUserID);
        Moderator *moderator = (Moderator *)i->second;
        Model *model = new Model(strs[0], moderator);
        models->insert(pair<string, Model*>(moderator->id, model));
    }
    outFile.close();
    
    
    loadPost();
}

void System::loadPost()
{
    //加载帖子
    cout<<"加载帖子..."<<endl;
//    /Users/wuxi/Documents/workspace/C++/by银论坛/by银论坛/post1
    string name1 = "/Users/wuxi/Documents/workspace/C++/by银论坛/by银论坛/post1.txt";
    string name2 = "/Users/wuxi/Documents/workspace/C++/by银论坛/by银论坛/post2.txt";
    string name3 = "/Users/wuxi/Documents/workspace/C++/by银论坛/by银论坛/post3.txt";
    string name4 = "/Users/wuxi/Documents/workspace/C++/by银论坛/by银论坛/post4.txt";
    string filenames[4] = {name1, name2, name3, name4};
    map<string, Model*>::iterator im = models->begin();
    int i = 0;
    while(im != models->end()){
        string filename = filenames[i];
        Model *model = im->second;
        loadPost(filename, model);
        
        i++;
        im++;
    }
    
    
}

void System::loadPost(string postFileName, Model *model)
{
    char buffer[1024];
    fstream outFile;
//    outFile.open("/Users/wuxi/Documents/workspace/C++/by银论坛/by银论坛/post1", ios::in);
    outFile.open(postFileName, ios::in);
    while(!outFile.eof()){
        //getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束
        outFile.getline(buffer, 1024, '\n');
        //        cout<<buffer<<endl;
        if(buffer[0] == '#'){
            continue;
        }
        vector<string> strs = split(string(buffer), " ");
        string postID = strs[0];
        string userID = strs[1];
        string title = strs[2];
        string content = strs[3];
        string time = strs[4];
        string commentStr = strs[5];
        Post *post = new Post(postID, title, time, content);
        //查找发帖人
        map<string, CommenUser*>::iterator ui = users->find(userID);
        if(ui != users->end()){
            CommenUser* user = ui->second;
            post->user = user;
        }
        
        //加载评论
        vector<string> comments = split(commentStr, "$");
        vector<string>::iterator ci = comments.begin();
        while(ci != comments.end()){
            
            string commentStr = *ci;
            vector<string> commentV = split(commentStr, "#");
            vector<string>::iterator cii = commentV.begin();
            string commentUserID = *cii;
            cii++;
            string commentTime = *cii;
            cii++;
            string commentContent = *(cii);
            //查找评论人
            map<string, CommenUser*>::iterator ui = users->find(commentUserID);
            if(ui != users->end()){
                CommenUser* user = ui->second;
                Comment *comment = new Comment(user,commentTime, commentContent);
                post->comments->insert(pair<string, Comment*>(commentUserID, comment));
            }
            
            ci++;
        }
        
        //添加帖子
        model->posts->insert(pair<string, Post*>(post->id, post));
    }
    outFile.close();
}

vector<string> System:: split(const string &s, const string &soperator)
{
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;
    
    while(i != s.size()){
        //找到字符串中首个不等于分隔符的字母；
        int flag = 0;
        while(i != s.size() && flag == 0){
            flag = 1;
            for(string_size x = 0; x < soperator.size(); ++x){
                if(s[i] == soperator[x]){
                    ++i;
                    flag = 0;
                    break;
                }
            }
        }
        
        //找到又一个分隔符，将两个分隔符之间的字符串取出；
        flag = 0;
        string_size j = i;
        while(j != s.size() && flag == 0){
            for(string_size x = 0; x < soperator.size(); ++x){
                if(s[j] == soperator[x]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                ++j;
            }
        }
        if(i != j){
            result.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return result;
}


