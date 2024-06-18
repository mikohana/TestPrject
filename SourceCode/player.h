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

    bool BlockMoveDown();       //�u���b�N�����ɍs����Ȃ�P�}�X�����������A�����Ȃ�������false��Ԃ�
    bool BlockMoveRight();      //�u���b�N���E�ɍs����Ȃ�P�}�X�����������A�����Ȃ�������false��Ԃ�
    bool BlockMoveLeft();       //�u���b�N�����ɍs����Ȃ�P�}�X�����������A�����Ȃ�������false��Ԃ�

    void AutoDown();            //�����ŗ������Ă�������
    void InputDown();           //���L�[����������P�}�X���ɓ���������
    void InputRight();          //�E�L�[����������P�}�X�E�ɓ���������
    void InputLeft();           //���L�[����������P�}�X���ɓ���������

    void InstallBlock();            //�u���b�N�̐ݒu
    void AssignNextBlock();         //nextBlock��useBlock�ɑ��;

    void StagePutBlock();           //�X�e�[�W��Ƀu���b�N��u������

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

    int AUTO_DOWN_COUNT ;        //���b�Ɉ�񗎂��邩�̒萔

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

    static constexpr float DAMAGE_PER = 5.0f;   //�����̒l��ς���ƍU���͂��ς��

    static constexpr float ENERGY_PER = 8.0f;  //�����̂�������ς���ƕK�E�Z�̒��܂�X�s�[�h���ς��

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

