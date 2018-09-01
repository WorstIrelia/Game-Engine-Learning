#include <cstdio>
#include "IApplication.hpp"

using namespace Fc;

namespace Fc{
    extern IApplication* g_pApp;
}

int main(int argc, char *argv[]){
    int ret;
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