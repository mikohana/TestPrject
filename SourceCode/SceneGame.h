#pragma once
#include "Scene.h"

class SceneGame : public Scene
{
private:
    void Init() override;
    void Deinit() override;
    void Update() override;
    void Draw() override;
    void DrawDebug();
};

