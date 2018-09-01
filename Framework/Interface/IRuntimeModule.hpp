#pragma once
#include "Interface.hpp"
namespace Fc{


//全局变量初始化顺序未知?
//

Interface IRuntimeModule{
public:
    virtual ~IRuntimeModule(){};
    virtual int Init() = 0;
    virtual void Finalize() = 0;
    virtual void Tick() = 0;
};







}
