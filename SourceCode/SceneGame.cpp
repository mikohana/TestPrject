#include "WinMain.h"
#include "SceneGame.h"
#include "../GameLib/game_lib.h"
#include "bg.h"
#include "Stage.h"
#include "Block.h"
#include "playerManeger.h"
#include "bgManeger.h"
#include "../imgui/imgui.h"
#include "Enemy.h"
#include "Clear.h"
#include "Audio.h"

void SceneGame::Init()
{
    BgManeger::Instance().Init();
    Stage::Instance().Init();
    PlayerManeger::Instance().Init();
    EnemyManeger::Instance().Init();
    ClearManeger::Instance().Init();
}

void SceneGame::Deinit()
{
    Stage::Instance().Deinit();
    PlayerManeger::Instance().Deinit();
    ClearManeger::Instance().Deinit();
}

void SceneGame::Update()
{
    //変えた部分
    switch (state_)
    {
    case 0:
       //ゲームBGMを再生させる
        audio_init_Game();
        GameLib::music::play(MUSIC::GAME_BGM, true);
        state_++;
    case 1:
        //GameLib::debug::setString("FLAG : %f", PlayerManeger::Instance().GetPlayer().GetWorkTimerFlag());
        BgManeger::Instance().Update();
        Stage::Instance().Update();
        PlayerManeger::Instance().Update();
        EnemyManeger::Instance().Update();
        ClearManeger::Instance().Update();
        break;
    }
  

   
    // シーン切り替えチェック
    //if (GameLib::input::STATE(0) & GameLib::input::PAD_TRG1) { setScene(SCENE::OVER); }
    //if (GameLib::input::STATE(0) & GameLib::input::PAD_TRG2) { setScene(SCENE::CLEAR); }
#if _DEBUG
    DrawDebug();

#endif // _DEBUG

}
 

void SceneGame::Draw()
{
    // 画面をクリア
    GameLib::clear(0, 0, 0);

    BgManeger::Instance().Draw();

    //ステージの描画
    Stage::Instance().Draw();

    
    EnemyManeger::Instance().Draw();
    PlayerManeger::Instance().Draw();
    ClearManeger::Instance().Draw();



}

void SceneGame::DrawDebug()
{
    ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(300, 300), ImGuiCond_Once);
    ImGui::Begin("Debug");

    if (ImGui::BeginMenu("Player")) {
        PlayerManeger::GetPlayer().DrawDebug();
        ImGui::EndMenu();
    }

    //if (ImGui::BeginMenu("Enemy")) {
    //    EnemyManeger::GetEnemy().DrawDebug();
    //    ImGui::EndMenu();
    //}

    if (ImGui::BeginMenu("Stage")) {
        Stage::Instance().DrawDebug();
        ImGui::EndMenu();
    }

    ImGui::End();
}
