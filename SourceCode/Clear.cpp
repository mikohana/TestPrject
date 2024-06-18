#include "Clear.h"
#include "SpriteData.h"
#include "Easing.h"
#include "player.h"
#include "playerManeger.h"
#include "Audio.h"


namespace {
	const int logoFrame = 4;
	const int pakaFrame = 2;
	GameLib::AnimeData animeClearLogo[] = {
		{&sprClearLogo0,logoFrame},
		{&sprClearLogo1,logoFrame},
		{&sprClearLogo2,logoFrame},
		{&sprClearLogo3,logoFrame},
		{&sprClearLogo4,logoFrame},
		{&sprClearLogo5,logoFrame},
		{&sprClearLogo6,logoFrame},
		{&sprClearLogo7,logoFrame},
		{&sprClearLogo8,logoFrame},
		{&sprClearLogo9,logoFrame},
		{&sprClearLogo10,logoFrame},
		{&sprClearLogo11,logoFrame},
		{nullptr,-1},
	};

	GameLib::AnimeData animePaka[] = {
		{&sprClrear_Paka0,logoFrame},
		{&sprClrear_Paka1,logoFrame},
		{&sprClrear_Paka2,logoFrame},
		{&sprClrear_Paka3,logoFrame},
		{&sprClrear_Paka4,logoFrame},
		{&sprClrear_Paka5,logoFrame},
		{&sprClrear_Paka6,logoFrame},
		{&sprClrear_Paka7,logoFrame},
		{&sprClrear_Paka8,logoFrame},
		{&sprClrear_Paka9,logoFrame},
		{&sprClrear_Paka10,logoFrame},
		{&sprClrear_Paka11,logoFrame},
		{&sprClrear_Paka12,logoFrame},
		{&sprClrear_Paka13,logoFrame},
		{&sprClrear_Paka14,logoFrame},
		{&sprClrear_Paka15,logoFrame},
		{&sprClrear_Paka16,logoFrame},
		{&sprClrear_Paka17,logoFrame},
		{&sprClrear_Paka18,logoFrame},
		{&sprClrear_Paka19,logoFrame},
		{&sprClrear_Paka20,logoFrame},
		{&sprClrear_Paka21,logoFrame},
		{&sprClrear_Paka22,logoFrame},
		{&sprClrear_Paka23,logoFrame},
		{&sprClrear_Paka24,logoFrame},
		{&sprClrear_Paka25,logoFrame},
		{&sprClrear_Paka26,logoFrame},
		{&sprClrear_Paka27,logoFrame},
		{&sprClrear_Paka28,logoFrame},
		{&sprClrear_Paka29,logoFrame},
		{&sprClrear_Paka30,logoFrame},
		{&sprClrear_Paka31,logoFrame},
		{&sprClrear_Paka32,logoFrame},
		{&sprClrear_Paka33,logoFrame},
		{&sprClrear_Paka34,logoFrame},
		{&sprClrear_Paka35,logoFrame},
		{&sprClrear_Paka36,logoFrame},
		{&sprClrear_Paka38,logoFrame},
		{&sprClrear_Paka39,logoFrame},
		{&sprClrear_Paka40,logoFrame},
		{&sprClrear_Paka41,logoFrame},
		{&sprClrear_Paka42,logoFrame},
		{&sprClrear_Paka43,logoFrame},
		{&sprClrear_Paka44,logoFrame},
		{&sprClrear_Paka45,logoFrame},
		{&sprClrear_Paka46,logoFrame},
		{&sprClrear_Paka47,logoFrame},
		{&sprClrear_Paka48,logoFrame},
		{&sprClrear_Paka49,logoFrame},
		{nullptr,-1},
	};
}

void Clear::Init()
{
	

	GameLib::texture::load(loadClear);
	backScreen = std::make_shared<EasingOBJ>(VECTOR2{ 0,0 }, VECTOR2{ 1,1 }, 0,
		VECTOR4{ 0,0,0,0 }, GameLib::Blender::BS_ALPHA,
		0, 60 * 1, 0.95f, 0);

	pakapaka = std::make_shared<OBJ2D>(VECTOR2{ 0,0 }, VECTOR2{ 2.0f,2.0f },
		0, VECTOR4{ 1,1,1,1 }, GameLib::Blender::BS_ALPHA);
	pakapaka->SetAnimeData(animePaka);

	clearLogo = std::make_shared<EasingOBJ>(VECTOR2{ 1920 / 2,1080 / 2 }, VECTOR2{ 0,0 },
		0, VECTOR4{ 1,1,1,1 }, GameLib::Blender::BS_ALPHA, 0, 60.0f * 1.0f, 1.0f, 0);
	clearLogo->SetAnimeData(animeClearLogo);


}

void Clear::Deinit()
{
	GameLib::texture::release(loadClear);
}

void Clear::Update()
{
	//•Ï‚¦‚½•”•ª
	//ƒQ[ƒ€BGM‚ð’âŽ~‚³‚¹‚ÄAƒQ[ƒ€ƒNƒŠƒABGM‚ðÄ¶‚³‚¹‚é
	if (PlayerManeger::Instance().GetPlayer().clearFlag_) {
		audio_init_GameClear();
		GameLib::music::stop(MUSIC::GAME_BGM);
		GameLib::music::play(SOUND::GAMECLEAR, true);
	}
	BackScreenUpdate();
	ClearLogoUpdate();
	pakapakaUpdate();

}

void Clear::Draw()
{
	GameLib::primitive::rect(0, 0,
		1920.0f, 1080.0f,
		0, 0,
		0,
		backScreen->GetColor().x, backScreen->GetColor().y, backScreen->GetColor().z, backScreen->GetColor().w);
	if (logoFlag) {
		clearLogo->draw();
	}
	if (pakaFlag) {
		pakapaka->draw();
	}

}

void Clear::BackScreenUpdate()
{
	if (PlayerManeger::Instance().GetPlayer().clearFlag_) {
		backScreen->TimeUpdate();
		float opacity = Easing::OutQuint(backScreen->currentTime_, 60.0f*2.0f,backScreen->maxPos_, 0.0f);

		backScreen->SetColor({ VECTOR4{0,0,0,opacity} });
		if (opacity > 0.5f) {
		logoFlag = true;
		}
	}
}

void Clear::ClearLogoUpdate()
{
	if (logoFlag) {
		clearLogo->TimeUpdate();

		float scale = Easing::OutExp(clearLogo->currentTime_, 40.0f, 2.0f, 0.0f);

		clearLogo->SetScale({ scale,scale });
		clearLogo->AnimationUpdate(true);
	}
}

void Clear::pakapakaUpdate()
{
	if (clearLogo->GetScale().x > 1.8f) {
		
		pakaFlag = true;
	}
	if (pakaFlag) {
		pakapaka->AnimationUpdate(false);
	}
}

void ClearManeger::Init()
{
	clear_ = std::make_unique<Clear>();
	GetClear().Init();
}

void ClearManeger::Update()
{
	GetClear().Update();
}

void ClearManeger::Deinit()
{
	GetClear().Deinit();
}

void ClearManeger::Draw()
{
	GetClear().Draw();
}
