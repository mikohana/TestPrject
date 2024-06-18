#pragma once
#include "OBJ2D.h"
#include <memory>
#include "Ui.h"
class Enemy
{
public:
    void Init();
    void Deinit();
    void Update();
    void Draw();

   // void DrawDebug();

public:
    std::shared_ptr<CharacterOBJ> GetEnemyOBJ()const { return enemyOBJ_; }

    void SetAttackCount(int count) { attackCount_ = count; }
    int GetAttackCount()const { return attackCount_; }

    void SetAttackFlag(bool flag) { attackFlag_ = flag; }
public:
    static constexpr float HP = 1000.0f;

private:
    void AttackAction();

    bool AttackJudge();

private:
	std::shared_ptr<CharacterOBJ> enemyOBJ_;

    std::shared_ptr<OBJ2D>hp_Ui_;
    std::shared_ptr<UI_Gauge>hpGauge_;

private:

    float ATK_STATUS = 70;

    int ATTACK_COUNT_COST=3;

    int attackCount_;

    bool attackFlag_;


};

class EnemyManeger
{
private:
    EnemyManeger(){}
    ~EnemyManeger(){}
public:
    static EnemyManeger& Instance() {
        static EnemyManeger instance;
        return instance;
    }
    
    static Enemy& GetEnemy() { return *Instance().enemy_.get(); }

public:
    void Init();
    void Update();
    void Deinit();
    void Draw();

private:
    std::unique_ptr<Enemy>	enemy_;

};

