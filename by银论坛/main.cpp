#include <iostream>
#include <string>
#include "Administrator.hpp"
#include "CommenUser.hpp"
#include "Moderator.hpp"
#include "System.hpp"
int main(int argc, const char * argv[]) {
    
    
    System *system = new System();
    system->initSystem();
    
    delete system;
    return 0;
}
