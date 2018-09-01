#pragma once
#include "IApplication.hpp"


namespace Fc{
class BaseApplication : implements IApplication{
public:
    // BaseApplication(){};
    virtual int Init();
    virtual void Finalize();
    virtual void Tick();
    virtual bool IsQuit();
protected:
    bool quit_flag;
};


}