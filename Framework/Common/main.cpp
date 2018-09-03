#include <cstdio>
#include "IApplication.hpp"
#include "Allocator.hpp"
#include <iostream>
using namespace Fc;

namespace Fc{
    extern IApplication* g_pApp;
}

void test_allocator(){
    Allocator allocator(16, 24, 8);
    for(int i = 0; i < 64; i++){
        void *ptr = allocator.allocate();
        std::cout << ptr << std::endl;
        // allocator.free(ptr);
        // allocator.free_all();
    }
    exit(0);
}

int main(int argc, char *argv[]){
    int ret;
    test_allocator();
    if((ret = g_pApp->Init()) != 0){
        printf("App Init failed\n");
        return ret;
    }

    while(!g_pApp->IsQuit()){
        g_pApp->Tick();
    }
    g_pApp->Finalize();
    return 0;
}