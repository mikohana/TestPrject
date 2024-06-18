#pragma once
#include "Scene.h"

class SceneClear : public Scene
{
private:
    void Init() override;
    void Update() override;
    void Draw() override;
};
