#include <iostream>
#include <string>
#include "Administrator.hpp"
#include "CommenUser.hpp"
#include "Moderator.hpp"
#include "System.hpp"
int main(int argc, const char * argv[]) {
    
    
    System *system = System::getInstance();
    system->initSystem();
    
    return 0;
}
