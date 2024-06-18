#pragma once
#include "OBJ2D.h"
#include "EasingOBJ.h"
#include <memory>
class Clear
{
public:
    int state_;

public:
    void Init();
    void Deinit();
    void Update() ;
    void Draw();

private:
    void BackScreenUpdate();

    void ClearLogoUpdate();

    void pakapakaUpdate();


private:
    std::shared_ptr<EasingOBJ> backScreen;
    std::shared_ptr<EasingOBJ> clearLogo;
    std::shared_ptr<OBJ2D> pakapaka;

    bool logoFlag;
    bool pakaFlag;

};

class ClearManeger
{
private:
    ClearManeger(){}
    ~ClearManeger(){}

public:
    static ClearManeger& Instance() {
        static ClearManeger instance;
        return instance;
    }

    static Clear& GetClear() { return *Instance().clear_.get(); }

public:
    void Init();
    void Update();
    void Deinit();
    void Draw();

private:
    std::unique_ptr<Clear> clear_;
};

