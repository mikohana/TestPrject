#pragma once
#include "Scene.h"
#include "OBJ2D.h"
#include "EasingOBJ.h"
#include <memory>
class SceneTitle : public Scene
{
private:
    void Init() override;
    void Update() override;
    void Draw() override;

private:
    void LogoUpdate();
    void TextBlockUpdate();

private:
    std::shared_ptr<OBJ2D> BgOBJ_;

    std::shared_ptr<EasingOBJ> title_logo_;
    std::shared_ptr<EasingOBJ> title_mu_;
    std::shared_ptr<EasingOBJ> title_su_;
    std::shared_ptr<EasingOBJ> title_nn_;
    std::shared_ptr<EasingOBJ> title_de_;
    std::shared_ptr<EasingOBJ> title_bikkuri_;
};
