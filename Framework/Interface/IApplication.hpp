#pragma once
#include "Interface.hpp"
#include "IRuntimeModule.hpp"

namespace Fc{


Interface IApplication : implements IRuntimeModule{
public:
    virtual int Init() = 0;
    virtual void Finalize() = 0;
    virtual void Tick() = 0;
    virtual bool IsQuit() = 0;


};

}