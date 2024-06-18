#include "SceneTitle.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"
#include "SpriteData.h"
#include "EasingOBJ.h"
#include "Audio.h"

void SceneTitle::Init()
{
    timer = 0;
    state_ = 0;
}

void SceneTitle::Update()
{

    using namespace GameLib::input;
    switch (state_)
    {
    case 0:
    {
        //•Ï‚¦‚½•”•ª
        //BGM
        audio_init_Title();
        //ƒ^ƒCƒgƒ‹BGM‚ğÄ¶
        GameLib::music::play(MUSIC::TITLE_BGM, true);


        GameLib::texture::load(loadTitle);
        BgOBJ_ = std::make_shared<OBJ2D>(VECTOR2{ 0, 0 }, VECTOR2{ 1, 1 }, 0, VECTOR4{ 1, 1, 1, 1 }, GameLib::Blender::BS_ALPHA);
        BgOBJ_->SetSprData(&sprTitleBG);

        title_logo_ = std::make_shared<EasingOBJ>(VECTOR2{ 920,480 },
            VECTOR2{ 0,0 }, 0, VECTOR4{ 1,1,1,1 },
            GameLib::Blender::BS_ALPHA,
            0, 60*0.5, 1, 0);
        title_logo_->SetSprData(&sprTitleLogo);

        title_mu_=std::make_shared<EasingOBJ>(VECTOR2{ 100, 0 },
            VECTOR2{ 1,1 }, 0, VECTOR4{ 1,1,1,1 },
            GameLib::Blender::BS_ALPHA,
            0, 60 * 0.8, 1, 0);
        title_mu_->SetSprData(&sprTitle_Mu);

        title_su_ = std::make_shared<EasingOBJ>(VECTOR2{ 250, 0 },
            VECTOR2{ 1,1 }, 0, VECTOR4{ 1,1,1,1 },
            GameLib::Blender::BS_ALPHA,
            0, 60 * 1.0, 1, 0);
        title_su_->SetSprData(&sprTitle_Su);

        title_nn_ = std::make_shared<EasingOBJ>(VECTOR2{ 400, 0 },
            VECTOR2{ 1,1 }, 0, VECTOR4{ 1,1,1,1 },
            GameLib::Blender::BS_ALPHA,
            0, 60 * 1, 1, 0);
        title_nn_->SetSprData(&sprTitle_Nn);

        title_de_ = std::make_shared<EasingOBJ>(VECTOR2{ 550, 0 },
            VECTOR2{ 1,1 }, 0, VECTOR4{ 1,1,1,1 },
            GameLib::Blender::BS_ALPHA,
            0, 60 * 0.6, 1, 0);
        title_de_->SetSprData(&sprTitle_De);

        title_bikkuri_ = std::make_shared<EasingOBJ>(VECTOR2{ 700, 0 },
            VECTOR2{ 1,1 }, 0, VECTOR4{ 1,1,1,1 },
            GameLib::Blender::BS_ALPHA,
            0, 60 * 0.4, 1, 0);
        title_bikkuri_->SetSprData(&sprTitle_Bikk);

        state_++;
    }
    case 1:
    {
        TextBlockUpdate();
        LogoUpdate();

    }

    }

    if (TRG(0) & PAD_START)
    {
        setScene(SCENE::GAME);
        GameLib::music::stop(MUSIC::TITLE_BGM);

        
       
    }

    timer++;
}

void SceneTitle::Draw()
{
    GameLib::clear(0, 0, 0);

    BgOBJ_->draw();

    title_logo_->draw();

    title_mu_->draw();
    title_su_->draw();
    title_nn_->draw();
    title_de_->draw();
    title_bikkuri_->draw();

    //GameLib::font::textOut(4, "C++ Shooting", { 640, 360 }, { 5, 5 },
    //    { 1, 1, 1, 1 }, GameLib::TEXT_ALIGN::MIDDLE);
    //if (timer / 30 % 2)
    //{
    //    GameLib::font::textOut(4, "Push space key", { 640, 540 }, { 2, 2 },
    //        { 1, 1, 0, 1 }, GameLib::TEXT_ALIGN::MIDDLE);
    //}
}

void SceneTitle::LogoUpdate()
{
    static float scaleTimer = 0;
    scaleTimer++;
    float sca = 0;
    sca+=sinf(scaleTimer*0.1f ) * 0.02f;
    if (title_bikkuri_->TimeUpdate()) {
        title_logo_->TimeUpdate();
    }

    float back = 0.5f;

    float scaleX = Easing::OutBack(title_logo_->currentTime_, title_logo_->endTime_,3.0f, 0.65f, 5.0f);
    //float scaleY = Easing::OutBack(title_logo_->currentTime_, title_logo_->endTime_, back, title_logo_->maxPos_, title_logo_->minPos_);
    float opacity = Easing::OutCubic(title_logo_->currentTime_, title_logo_->endTime_, title_logo_->maxPos_, title_logo_->minPos_);

    title_logo_->SetScale(VECTOR2{ scaleX+sca,scaleX+sca });

    title_logo_->SetColor(VECTOR4{ 1,1,1,opacity });

    

}

void SceneTitle::TextBlockUpdate()
{

    title_mu_->TimeUpdate();
    title_su_->TimeUpdate();
    title_nn_->TimeUpdate();
    title_de_->TimeUpdate();
    title_bikkuri_->TimeUpdate();

    float maxP = 100.0f;

    float muPos = Easing::OutExp(title_mu_->currentTime_, title_mu_->endTime_, maxP, -200.0f);
    title_mu_->SetPos({ title_mu_->GetPos().x,muPos });

    float suPos = Easing::OutExp(title_su_->currentTime_, title_su_->endTime_, maxP, -200.0f);
    title_su_->SetPos({ title_su_->GetPos().x,suPos });

     float nnPos = Easing::OutExp(title_nn_->currentTime_, title_nn_->endTime_, maxP, -200.0f);
    title_nn_->SetPos({ title_nn_->GetPos().x,nnPos });

    float dePos = Easing::OutExp(title_de_->currentTime_, title_de_->endTime_, maxP, -200.0f);
    title_de_->SetPos({ title_de_->GetPos().x,dePos });

    float bikkPos = Easing::OutExp(title_bikkuri_->currentTime_, title_bikkuri_->endTime_, maxP, -200.0f);
    title_bikkuri_->SetPos({ title_bikkuri_->GetPos().x,bikkPos });


}
