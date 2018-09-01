#include "BaseApplication.hpp"

int Fc::BaseApplication::Init(){

    quit_flag = false;
    return 0;
}

void Fc::BaseApplication::Finalize(){}

void Fc::BaseApplication::Tick(){}

bool Fc::BaseApplication::IsQuit(){
    return quit_flag; 
}


