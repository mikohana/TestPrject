#pragma once
#include "Block.h"
#include "Ui.h"
#include <memory>
#include "OBJ2D.h"

class Player
{
public:
    void Init();
    void Deinit();
    void Update();
    void Draw();

    void DrawDebug();

public: 
    void SetWorkTimerFlag(bool tf) { workTimerFlag_ = tf; }
    bool GetWorkTimerFlag()const { return workTimerFlag_; }

    void SetNormalAttackAnimeFlag(bool flag) { attackAnimeFlag_ = flag; }
    bool GetNormalAttackAnimeFlag()const { return attackAnimeFlag_; }

    void SetEnergyChageFlag(bool flag) { energyChargeFlag_ = flag; }
    bool GetEnergyChargeFlag()const { return energyChargeFlag_; }

    std::shared_ptr<CharacterOBJ> GetPlayerOBJ() { return playerOBJ_; }

public:
    static const int NEXT_ELEMENT = 4;
    static constexpr float HP = 1000.0f;
    static const int TIMELIMIT = 10;

    bool clearFlag_;


private:
    void NextBlockDraw();
    void UseBlockDraw();
    void MoveBlock();

    bool UltEnergyCharge();

    void DebugChangeBlock();

    bool BlockMoveDown();       //ブロックが下に行けるなら１マス動かす処理、動けなかったらfalseを返す
    bool BlockMoveRight();      //ブロックが右に行けるなら１マス動かす処理、動けなかったらfalseを返す
    bool BlockMoveLeft();       //ブロックが左に行けるなら１マス動かす処理、動けなかったらfalseを返す

    void AutoDown();            //自動で落下していく処理
    void InputDown();           //下キーを押したら１マス下に動かす処理
    void InputRight();          //右キーを押したら１マス右に動かす処理
    void InputLeft();           //左キーを押したら１マス左に動かす処理

    void InstallBlock();            //ブロックの設置
    void AssignNextBlock();         //nextBlockをuseBlockに代入;

    void StagePutBlock();           //ステージ上にブロックを置く処理

    void Ui_Draw();

    void ultChargeUpdate();
    void ultChargeDraw();

    //void SetNormalAttackFlag(bool flag) { normalAttackFlag_ = flag; }
    //bool GetNormalAttackFlag()const { return normalAttackFlag_; }
    void UltAttack();

    void NormalAttack();

    void ClearJudge();


    //void SetWorkTimerFlag(bool flag) { workTimerFlag_ = flag; }
    //bool GetWorkTimerFlag() { return workTimerFlag_; }

private:
    std::shared_ptr<Block> useBlock;
    std::shared_ptr<Block> nextBlock[NEXT_ELEMENT];

    std::shared_ptr<OBJ2D> hp_Ui_;
    std::shared_ptr<UI_Gauge>hpGauge_;

    std::shared_ptr<OBJ2D> ultGauge_;
    std::shared_ptr<OBJ2D>ultEnergy_;
    std::shared_ptr<OBJ2D>ultAttackOBJ_;

    std::shared_ptr<OBJ2D> dropEffectOBJ_;
    std::shared_ptr<OBJ2D> normalAttackOBJ_;

    std::shared_ptr<CharacterOBJ> playerOBJ_;

    int AUTO_DOWN_COUNT ;        //何秒に一回落ちるかの定数

    int MOMENT_COUNT = 1;    

    float currentEnergy_;

    int workTimer_;
    bool workTimerFlag_;
    int putTimer_;

    bool gameOverFlag_;
    bool gameClearFlag_;

    float timeLimit_;

    float ATK_Status_;

    bool dropFlag_;

    bool normalAttackFlag_;
    bool attackAnimeFlag_;
    bool energyChargeFlag_;

    bool keyPressed[9] ;

    static constexpr float DAMAGE_PER = 5.0f;   //ここの値を変えると攻撃力が変わる

    static constexpr float ENERGY_PER = 8.0f;  //ここのあたいを変えると必殺技の貯まるスピードが変わる

    VECTOR2 texPos_;
    VECTOR2 texSize_;
    float savedSize_;
    float ultRatio_;
    float savedEnergy_;

    bool canUltFlag_;
    bool ultAnimeFlag_;
    bool ultAttackFlag_;
    int ultTimer_;

    float ULT_ENERGY_MAX=500;
    float ULT_ATTACK_STATUS_ = 20;
};

