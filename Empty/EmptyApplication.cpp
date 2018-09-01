#include "BaseApplication.hpp"

namespace Fc{
    BaseApplication g_App;
    IApplication* g_pApp = &g_App;
}