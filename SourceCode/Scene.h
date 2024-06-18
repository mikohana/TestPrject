#pragma once
#include "../GameLib/vector.h"

class Scene
{
protected:
    int timer;
    int state_;

public:
    virtual void Init() {}
    virtual void Deinit(){}
    virtual void Update() = 0;
    virtual void Draw() = 0;
};
