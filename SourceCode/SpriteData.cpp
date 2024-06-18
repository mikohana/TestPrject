#include "SpriteData.h"


GameLib::LoadTexture loadBlockChip[] = {
	{ TEXNO::BLOCK,L"./Data/Images/block_chip.png",273U },
	{-1,nullptr},

};


GameLib::LoadTexture loadUi[] =
{
	{TEXNO::UI_HP,L"./Data/Images/UI_HP.png",1U},
	{TEXNO::UI_TIMELIMIT,L"./Data/Images/UI_timelimit.png",1U},
	{TEXNO::UI_ULT_GAUGE,L"./Data/Images/ultGauge.png",1U},
	{TEXNO::UI_ULT_ENERGY,L"./Data/Images/ultEnergy.png",1U},

	{-1,nullptr,},
};

GameLib::LoadTexture loadPlayer[] =
{
	{TEXNO::PLAYER_IDLE,L"./Data/Images/playerIdle.png",1U},
	{TEXNO::PALYER_DAMAGED,L"./Data/Images/playerDamaged.png",1U},

	{-1,nullptr,},
};

GameLib::LoadTexture loadAttack[] = {
	{TEXNO::THUNDER_ATTACK_ANIMATION,L"./Data/Images/thunderAnime.png",1U},
	{TEXNO::ULT_ATTACK_ANIMATION,L"./Data/Images/ultAnime.png",3U},

	{-1,nullptr},
};

GameLib::LoadTexture loadTitle[] = {
	{TEXNO::TITLE_BG,L"./Data/Images/title_bg.png",1U},
	{TEXNO::TITLE_LOGO,L"./Data/Images/title_logo.png",1U},
	{TEXNO::TITLE_MU,L"./Data/Images/mu.png",1U},
	{TEXNO::TITLE_SU,L"./Data/Images/su.png",1U},
	{TEXNO::TITLE_NN,L"./Data/Images/nn.png",1U},
	{TEXNO::TITLE_DE,L"./Data/Images/de.png",1U},
	{TEXNO::TITLE_BIKKURI,L"./Data/Images/bikkuri.png",1U},

	{-1,nullptr},
};

GameLib::LoadTexture loadBG[] =
{

	{TEXNO::SCREEN_BG,L"./Data/Images/bg.png",1U},
	{TEXNO::STAGE_BG,L"./Data/Images/stage_bg.png",1U},
	{TEXNO::NEXT_BLOCK_BG,L"./Data/Images/next_block_bg.png",1U},

	{-1,nullptr,},
};

GameLib::LoadTexture loadEffect[] =
{
	{TEXNO::DROP_EFFECT,L"./Data/Images/dropEffect.png",1U},

	{-1,nullptr,},
};

GameLib::LoadTexture loadEnemy[] = {
	{TEXNO::ENEMY_IDLE,L"./Data/Images/enemyIdle.png",1U},
	{TEXNO::ENEMY_ANIME,L"./Data/Images/enemyAnime.png",1U},
	{-1,nullptr, },
};

GameLib::LoadTexture loadPlayer[] = {
	{TEXNO::PLAYER_IDLE,L"./Data/Images/playerIdle.png",1U},
	{TEXNO::PALYER_DAMAGED,L"./Data/Images/playerDamaged.png",1U},
	{-1,nullptr,},
};

GameLib::LoadTexture loadClear[] = {
	{TEXNO::CLEAR_LOGO,L"./Data/Images/clearAnime.png",1U},
	{TEXNO::CLEAR_PAKA,L"./Data/Images/paka.png",1U},
	{-1,nullptr},
};

//------< マクロ >--------------------------------------------------------------
#define SPRITE_CENTER(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)/2 }  // 画像の真ん中が中心
#define SPRITE_BOTTOM(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)   }  // 画像の足元が中心

GameLib::SpriteData sprClearLogo0 = { TEXNO::CLEAR_LOGO,640 * 0,360 * 0,640,360,640/2,360/2 };
GameLib::SpriteData sprClearLogo1 = { TEXNO::CLEAR_LOGO,640 * 1,360 * 0,640,360,640/2,360/2 };
GameLib::SpriteData sprClearLogo2 = { TEXNO::CLEAR_LOGO,640 * 2,360 * 0,640,360,640 / 2,360 / 2 };
GameLib::SpriteData sprClearLogo3 = { TEXNO::CLEAR_LOGO,640 * 3,360 * 0,640,360,640 / 2,360 / 2 };
GameLib::SpriteData sprClearLogo4 = { TEXNO::CLEAR_LOGO,640 * 4,360 * 0,640,360,640 / 2,360 / 2 };
GameLib::SpriteData sprClearLogo5 = { TEXNO::CLEAR_LOGO,640 * 5,360 * 0,640,360,640 / 2,360 / 2 };
GameLib::SpriteData sprClearLogo6 = { TEXNO::CLEAR_LOGO,640 * 6,360 * 0,640,360,640 / 2,360 / 2 };
GameLib::SpriteData sprClearLogo7 = { TEXNO::CLEAR_LOGO,640 * 7,360 * 0,640,360,640 / 2,360 / 2 };
GameLib::SpriteData sprClearLogo8 = { TEXNO::CLEAR_LOGO,640 * 8,360 * 0,640,360,640 / 2,360 / 2 };
GameLib::SpriteData sprClearLogo9 = { TEXNO::CLEAR_LOGO,640 * 9,360 * 0,640,360,640 / 2,360 / 2 };
GameLib::SpriteData sprClearLogo10 = { TEXNO::CLEAR_LOGO,640 * 10,360 * 0,640,360,640 / 2,360 / 2 };
GameLib::SpriteData sprClearLogo11 = { TEXNO::CLEAR_LOGO,640 * 11,360 * 0,640,360,640 / 2,360 / 2 };

GameLib::SpriteData sprClrear_Paka0 =  { TEXNO::CLEAR_PAKA, 960 * 0, 540 * 0,  960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka1 =  { TEXNO::CLEAR_PAKA, 960 * 1, 540 * 0,  960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka2 =  { TEXNO::CLEAR_PAKA, 960 * 2, 540 * 0,  960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka3 =  { TEXNO::CLEAR_PAKA, 960 * 3, 540 * 0,  960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka4 =  { TEXNO::CLEAR_PAKA, 960 * 4, 540 * 0,  960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka5 =  { TEXNO::CLEAR_PAKA, 960 * 5, 540 * 0,  960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka6 =  { TEXNO::CLEAR_PAKA, 960 * 6, 540 * 0,  960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka7 =  { TEXNO::CLEAR_PAKA, 960 * 0, 540 * 1,  960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka8 =  { TEXNO::CLEAR_PAKA, 960 * 1, 540 * 1,  960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka9 =  { TEXNO::CLEAR_PAKA, 960 * 2, 540 * 1,  960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka10 = { TEXNO::CLEAR_PAKA, 960 * 3, 540 * 1, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka11 = { TEXNO::CLEAR_PAKA, 960 * 4, 540 * 1, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka12 = { TEXNO::CLEAR_PAKA, 960 * 5, 540 * 1, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka13 = { TEXNO::CLEAR_PAKA, 960 * 6, 540 * 1, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka14 = { TEXNO::CLEAR_PAKA, 960 * 0, 540 * 2, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka15 = { TEXNO::CLEAR_PAKA, 960 * 1, 540 * 2, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka16 = { TEXNO::CLEAR_PAKA, 960 * 2, 540 * 2, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka17 = { TEXNO::CLEAR_PAKA, 960 * 3, 540 * 2, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka18 = { TEXNO::CLEAR_PAKA, 960 * 4, 540 * 2, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka19 = { TEXNO::CLEAR_PAKA, 960 * 5, 540 * 2, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka20 = { TEXNO::CLEAR_PAKA, 960 * 6, 540 * 2, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka21 = { TEXNO::CLEAR_PAKA, 960 * 0, 540 * 3, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka22 = { TEXNO::CLEAR_PAKA, 960 * 1, 540 * 3, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka23 = { TEXNO::CLEAR_PAKA, 960 * 2, 540 * 3, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka24 = { TEXNO::CLEAR_PAKA, 960 * 3, 540 * 3, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka25 = { TEXNO::CLEAR_PAKA, 960 * 4, 540 * 3, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka26 = { TEXNO::CLEAR_PAKA, 960 * 5, 540 * 3, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka27 = { TEXNO::CLEAR_PAKA, 960 * 6, 540 * 3, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka28 = { TEXNO::CLEAR_PAKA, 960 * 0, 540 * 4, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka29 = { TEXNO::CLEAR_PAKA, 960 * 1, 540 * 4, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka30 = { TEXNO::CLEAR_PAKA, 960 * 2, 540 * 4, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka31 = { TEXNO::CLEAR_PAKA, 960 * 3, 540 * 4, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka32 = { TEXNO::CLEAR_PAKA, 960 * 4, 540 * 4, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka33 = { TEXNO::CLEAR_PAKA, 960 * 5, 540 * 4, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka34 = { TEXNO::CLEAR_PAKA, 960 * 6, 540 * 4, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka35 = { TEXNO::CLEAR_PAKA, 960 * 0, 540 * 5, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka36 = { TEXNO::CLEAR_PAKA, 960 * 1, 540 * 5, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka37 = { TEXNO::CLEAR_PAKA, 960 * 2, 540 * 5, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka38 = { TEXNO::CLEAR_PAKA, 960 * 3, 540 * 5, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka39 = { TEXNO::CLEAR_PAKA, 960 * 4, 540 * 5, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka40 = { TEXNO::CLEAR_PAKA, 960 * 5, 540 * 5, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka41 = { TEXNO::CLEAR_PAKA, 960 * 6, 540 * 5, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka42 = { TEXNO::CLEAR_PAKA, 960 * 0, 540 * 6, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka43 = { TEXNO::CLEAR_PAKA, 960 * 1, 540 * 6, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka44 = { TEXNO::CLEAR_PAKA, 960 * 2, 540 * 6, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka45 = { TEXNO::CLEAR_PAKA, 960 * 3, 540 * 6, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka46 = { TEXNO::CLEAR_PAKA, 960 * 4, 540 * 6, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka47 = { TEXNO::CLEAR_PAKA, 960 * 5, 540 * 6, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka48 = { TEXNO::CLEAR_PAKA, 960 * 6, 540 * 6, 960, 540,0,0 };
GameLib::SpriteData sprClrear_Paka49 = { TEXNO::CLEAR_PAKA, 960 * 7, 540 * 6, 960, 540,0,0 };


GameLib::SpriteData sprTitleBG = { TEXNO::TITLE_BG,0,0,1920,1080,0,0 };
GameLib::SpriteData sprTitleLogo = { TEXNO::TITLE_LOGO,0,0,1578,978,1578/2,978/2 };

GameLib::SpriteData sprTitle_Mu = { TEXNO::TITLE_MU,0,0,130,130,0,0 };
GameLib::SpriteData sprTitle_Su = { TEXNO::TITLE_SU,0,0,130,130,0,0 };
GameLib::SpriteData sprTitle_Nn = { TEXNO::TITLE_NN,0,0,130,130,0,0 };
GameLib::SpriteData sprTitle_De = { TEXNO::TITLE_DE,0,0,130,130,0,0 };
GameLib::SpriteData sprTitle_Bikk = { TEXNO::TITLE_BIKKURI,0,0,130,130,0,0 };


GameLib::SpriteData sprDrop_Effect0 = { TEXNO::DROP_EFFECT, 60 * 0, 420 * 0, 60, 420,0,420 };
GameLib::SpriteData sprDrop_Effect1 = { TEXNO::DROP_EFFECT, 60 * 1, 420 * 0, 60, 420,0,420 };
GameLib::SpriteData sprDrop_Effect2 = { TEXNO::DROP_EFFECT, 60 * 2, 420 * 0, 60, 420,0,420 };
GameLib::SpriteData sprDrop_Effect3 = { TEXNO::DROP_EFFECT, 60 * 3, 420 * 0, 60, 420,0,420 };
GameLib::SpriteData sprDrop_Effect4 = { TEXNO::DROP_EFFECT, 60 * 4, 420 * 0, 60, 420,0,420 };

GameLib::SpriteData sprPlayer_Idle0 = { TEXNO::PLAYER_IDLE,400 * 0,480 * 0,400,480,0,0 };

GameLib::SpriteData sprEnemy_Idle0 = { TEXNO::ENEMY_ANIME,400 * 0,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle1 = { TEXNO::ENEMY_ANIME,400 * 1,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle2 = { TEXNO::ENEMY_ANIME,400 * 2,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle3 = { TEXNO::ENEMY_ANIME,400 * 3,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle4 = { TEXNO::ENEMY_ANIME,400 * 4,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle5 = { TEXNO::ENEMY_ANIME,400 * 5,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle6 = { TEXNO::ENEMY_ANIME,400 * 6,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle7 = { TEXNO::ENEMY_ANIME,400 * 7,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle8 = { TEXNO::ENEMY_ANIME,400 * 8,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle9 = { TEXNO::ENEMY_ANIME,400 * 9,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle10 = { TEXNO::ENEMY_ANIME,400 * 10,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle11 = { TEXNO::ENEMY_ANIME,400 * 11,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle12 = { TEXNO::ENEMY_ANIME,400 * 12,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle13 = { TEXNO::ENEMY_ANIME,400 * 13,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle14 = { TEXNO::ENEMY_ANIME,400 * 14,480 * 0,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle15 = { TEXNO::ENEMY_ANIME,400 * 15,480 * 0,400,480,0,0 };

GameLib::SpriteData sprEnemy_Idle16 = { TEXNO::ENEMY_ANIME,400 * 0,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle17 = { TEXNO::ENEMY_ANIME,400 * 1,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle18 = { TEXNO::ENEMY_ANIME,400 * 2,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle19 = { TEXNO::ENEMY_ANIME,400 * 3,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle20 = { TEXNO::ENEMY_ANIME,400 * 4,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle21 = { TEXNO::ENEMY_ANIME,400 * 5,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle22 = { TEXNO::ENEMY_ANIME,400 * 6,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle23 = { TEXNO::ENEMY_ANIME,400 * 7,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle24 = { TEXNO::ENEMY_ANIME,400 * 8,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle25 = { TEXNO::ENEMY_ANIME,400 * 9,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle26 = { TEXNO::ENEMY_ANIME,400 * 10,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle27 = { TEXNO::ENEMY_ANIME,400 * 11,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle28 = { TEXNO::ENEMY_ANIME,400 * 12,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle29 = { TEXNO::ENEMY_ANIME,400 * 13,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle30 = { TEXNO::ENEMY_ANIME,400 * 14,480 * 1,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle31 = { TEXNO::ENEMY_ANIME,400 * 15,480 * 1,400,480,0,0 };

GameLib::SpriteData sprEnemy_Idle32 = { TEXNO::ENEMY_ANIME,400 * 0,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle33 = { TEXNO::ENEMY_ANIME,400 * 1,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle34 = { TEXNO::ENEMY_ANIME,400 * 2,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle35 = { TEXNO::ENEMY_ANIME,400 * 3,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle36 = { TEXNO::ENEMY_ANIME,400 * 4,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle37 = { TEXNO::ENEMY_ANIME,400 * 5,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle38 = { TEXNO::ENEMY_ANIME,400 * 6,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle39 = { TEXNO::ENEMY_ANIME,400 * 7,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle40 = { TEXNO::ENEMY_ANIME,400 * 8,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle41 = { TEXNO::ENEMY_ANIME,400 * 9,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle42 = { TEXNO::ENEMY_ANIME,400 * 10,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle43 = { TEXNO::ENEMY_ANIME,400 * 11,480 * 2,400,480,0,0 };
GameLib::SpriteData sprEnemy_Idle44 = { TEXNO::ENEMY_ANIME,400 * 12,480 * 2,400,480,0,0 };
//GameLib::SpriteData sprEnemy_Idle45 = { TEXNO::ENEMY_ANIME,400 * 13,48 * 2,400,480,0,0 };


GameLib::SpriteData sprUi_Hp = { TEXNO::UI_HP,300 * 0,35 * 0,300,35,0,0 };
GameLib::SpriteData sprUi_UltGauge{ TEXNO::UI_ULT_GAUGE,125 * 0,640 * 0,125,640,0,640 };
GameLib::SpriteData sprUi_UltEnergy{ TEXNO::UI_ULT_ENERGY,125 * 0,640 * 0,125,640,0,0};

GameLib::SpriteData sprThunderAttack0 = { TEXNO::THUNDER_ATTACK_ANIMATION,660 * 0,880 * 0,660,880,0,0 };
GameLib::SpriteData sprThunderAttack1 = { TEXNO::THUNDER_ATTACK_ANIMATION,660 * 1,880 * 0,660,880,0,0 };
GameLib::SpriteData sprThunderAttack2 = { TEXNO::THUNDER_ATTACK_ANIMATION,660 * 2,880 * 0,660,880,0,0 };
GameLib::SpriteData sprThunderAttack3 = { TEXNO::THUNDER_ATTACK_ANIMATION,660 * 3,880 * 0,660,880,0,0 };
GameLib::SpriteData sprThunderAttack4 = { TEXNO::THUNDER_ATTACK_ANIMATION,660 * 4,880 * 0,660,880,0,0 };
GameLib::SpriteData sprThunderAttack5 = { TEXNO::THUNDER_ATTACK_ANIMATION,660 * 5,880 * 0,660,880,0,0 };
GameLib::SpriteData sprThunderAttack6 = { TEXNO::THUNDER_ATTACK_ANIMATION,660 * 6,880 * 0,660,880,0,0 };
GameLib::SpriteData sprThunderAttack7 = { TEXNO::THUNDER_ATTACK_ANIMATION,660 * 7,880 * 0,660,880,0,0 };
GameLib::SpriteData sprThunderAttack8 = { TEXNO::THUNDER_ATTACK_ANIMATION,660 * 8,880 * 0,660,880,0,0 };

const float ultAnimeWidht = 960;
const float ultAnimeheight = 540;

GameLib::SpriteData sprUltAttack0 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 0,ultAnimeheight * 0,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack1 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 1,ultAnimeheight * 0,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack2 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 2,ultAnimeheight * 0,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack3 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 3,ultAnimeheight * 0,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack4 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 4,ultAnimeheight * 0,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack5 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 5,ultAnimeheight * 0,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack6 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 6,ultAnimeheight * 0,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack7 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 0,ultAnimeheight * 1,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack8 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 1,ultAnimeheight * 1,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack9 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 2,ultAnimeheight * 1,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack10 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 3,ultAnimeheight * 1,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack11 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 4,ultAnimeheight * 1,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack12 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 5,ultAnimeheight * 1,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack13 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 6,ultAnimeheight * 1,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack14 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 0,ultAnimeheight * 2,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack15 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 1,ultAnimeheight * 2,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack16 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 2,ultAnimeheight * 2,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack17 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 3,ultAnimeheight * 2,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack18 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 4,ultAnimeheight * 2,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack19 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 5,ultAnimeheight * 2,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack20 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 6,ultAnimeheight * 2,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack21 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 0,ultAnimeheight * 3,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack22 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 1,ultAnimeheight * 3,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack23 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 2,ultAnimeheight * 3,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack24 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 3,ultAnimeheight * 3,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack25 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 4,ultAnimeheight * 3,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack26 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 5,ultAnimeheight * 3,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack27 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 6,ultAnimeheight * 3,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack28 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 0,ultAnimeheight * 4,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack29 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 1,ultAnimeheight * 4,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack30 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 2,ultAnimeheight * 4,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack31 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 3,ultAnimeheight * 4,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack32 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 4,ultAnimeheight * 4,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack33 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 5,ultAnimeheight * 4,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack34 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 6,ultAnimeheight * 4,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack35 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 0,ultAnimeheight * 5,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack36 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 1,ultAnimeheight * 5,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack37 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 2,ultAnimeheight * 5,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack38 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 3,ultAnimeheight * 5,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack39 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 4,ultAnimeheight * 5,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack40 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 5,ultAnimeheight * 5,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack41 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 6,ultAnimeheight * 5,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack42 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 0,ultAnimeheight * 6,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack43 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 1,ultAnimeheight * 6,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack44 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 2,ultAnimeheight * 6,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack45 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 3,ultAnimeheight * 6,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack46 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 4,ultAnimeheight * 6,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack47 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 5,ultAnimeheight * 6,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack48 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 6,ultAnimeheight * 6,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack49 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 0,ultAnimeheight * 7,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack50 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 1,ultAnimeheight * 7,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack51 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 2,ultAnimeheight * 7,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack52 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 3,ultAnimeheight * 7,ultAnimeWidht,ultAnimeheight,0,0 };
GameLib::SpriteData sprUltAttack53 = { TEXNO::ULT_ATTACK_ANIMATION,ultAnimeWidht * 4,ultAnimeheight * 7,ultAnimeWidht,ultAnimeheight,0,0 };

const float PWidht = 400;
const float Pheight = 480;
//プレイヤーの待機時
GameLib::SpriteData sprPlayerIdle0 = { TEXNO::PLAYER_IDLE, PWidht * 0, Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle1 = { TEXNO::PLAYER_IDLE, PWidht * 1, Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle2 = { TEXNO::PLAYER_IDLE, PWidht * 2, Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle3 = { TEXNO::PLAYER_IDLE, PWidht * 3, Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle4 = { TEXNO::PLAYER_IDLE, PWidht * 4, Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle5 = { TEXNO::PLAYER_IDLE, PWidht * 5, Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle6 = { TEXNO::PLAYER_IDLE, PWidht * 6, Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle7 = { TEXNO::PLAYER_IDLE, PWidht * 7, Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle8 = { TEXNO::PLAYER_IDLE, PWidht * 8, Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle9 = { TEXNO::PLAYER_IDLE, PWidht * 9, Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle10 ={ TEXNO::PLAYER_IDLE, PWidht * 10,Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle11 = { TEXNO::PLAYER_IDLE, PWidht * 11,Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle12 = { TEXNO::PLAYER_IDLE, PWidht * 12,Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle13 = { TEXNO::PLAYER_IDLE, PWidht * 13,Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle14 = { TEXNO::PLAYER_IDLE, PWidht * 14,Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle15 = { TEXNO::PLAYER_IDLE, PWidht * 15,Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle16 = { TEXNO::PLAYER_IDLE, PWidht * 16,Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle17 = { TEXNO::PLAYER_IDLE, PWidht * 17,Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle18 = { TEXNO::PLAYER_IDLE, PWidht * 18,Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle19 = { TEXNO::PLAYER_IDLE, PWidht * 19,Pheight * 0, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle20 = { TEXNO::PLAYER_IDLE, PWidht * 0, Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle21 = { TEXNO::PLAYER_IDLE, PWidht * 1, Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle22 = { TEXNO::PLAYER_IDLE, PWidht * 2, Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle23 = { TEXNO::PLAYER_IDLE, PWidht * 3, Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle24 = { TEXNO::PLAYER_IDLE, PWidht * 4, Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle25 = { TEXNO::PLAYER_IDLE, PWidht * 5, Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle26 = { TEXNO::PLAYER_IDLE, PWidht * 6, Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle27 = { TEXNO::PLAYER_IDLE, PWidht * 7, Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle28 = { TEXNO::PLAYER_IDLE, PWidht * 8, Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle29 = { TEXNO::PLAYER_IDLE, PWidht * 9, Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle30 = { TEXNO::PLAYER_IDLE, PWidht * 10,Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle31 = { TEXNO::PLAYER_IDLE, PWidht * 11,Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle32 = { TEXNO::PLAYER_IDLE, PWidht * 12,Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle33 = { TEXNO::PLAYER_IDLE, PWidht * 13,Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle34 = { TEXNO::PLAYER_IDLE, PWidht * 14,Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle35 = { TEXNO::PLAYER_IDLE, PWidht * 15,Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle36 = { TEXNO::PLAYER_IDLE, PWidht * 16,Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle37 = { TEXNO::PLAYER_IDLE, PWidht * 17,Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle38 = { TEXNO::PLAYER_IDLE, PWidht * 18,Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle39 = { TEXNO::PLAYER_IDLE, PWidht * 19,Pheight * 1, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle40 = { TEXNO::PLAYER_IDLE, PWidht * 0, Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle41 = { TEXNO::PLAYER_IDLE, PWidht * 1, Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle42 = { TEXNO::PLAYER_IDLE, PWidht * 2, Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle43 = { TEXNO::PLAYER_IDLE, PWidht * 3, Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle44 = { TEXNO::PLAYER_IDLE, PWidht * 4, Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle45 = { TEXNO::PLAYER_IDLE, PWidht * 5, Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle46 = { TEXNO::PLAYER_IDLE, PWidht * 6, Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle47 = { TEXNO::PLAYER_IDLE, PWidht * 7, Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle48 = { TEXNO::PLAYER_IDLE, PWidht * 8, Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle49 = { TEXNO::PLAYER_IDLE, PWidht * 9, Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle50 = { TEXNO::PLAYER_IDLE, PWidht * 10,Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle51 = { TEXNO::PLAYER_IDLE, PWidht * 11,Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle52 = { TEXNO::PLAYER_IDLE, PWidht * 12,Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle53 = { TEXNO::PLAYER_IDLE, PWidht * 13,Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle54 = { TEXNO::PLAYER_IDLE, PWidht * 14,Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle55 = { TEXNO::PLAYER_IDLE, PWidht * 15,Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle56 = { TEXNO::PLAYER_IDLE, PWidht * 16,Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle57 = { TEXNO::PLAYER_IDLE, PWidht * 17,Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle58 = { TEXNO::PLAYER_IDLE, PWidht * 18,Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle59 = { TEXNO::PLAYER_IDLE, PWidht * 19,Pheight * 2, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle60 = { TEXNO::PLAYER_IDLE, PWidht * 0, Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle61 = { TEXNO::PLAYER_IDLE, PWidht * 1, Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle62 = { TEXNO::PLAYER_IDLE, PWidht * 2, Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle63 = { TEXNO::PLAYER_IDLE, PWidht * 3, Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle64 = { TEXNO::PLAYER_IDLE, PWidht * 4, Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle65 = { TEXNO::PLAYER_IDLE, PWidht * 5, Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle66 = { TEXNO::PLAYER_IDLE, PWidht * 6, Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle67 = { TEXNO::PLAYER_IDLE, PWidht * 7, Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle68 = { TEXNO::PLAYER_IDLE, PWidht * 8, Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle69 = { TEXNO::PLAYER_IDLE, PWidht * 9, Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle70 = { TEXNO::PLAYER_IDLE, PWidht * 10,Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle71 = { TEXNO::PLAYER_IDLE, PWidht * 11,Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle72 = { TEXNO::PLAYER_IDLE, PWidht * 12,Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle73 = { TEXNO::PLAYER_IDLE, PWidht * 13,Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle74 = { TEXNO::PLAYER_IDLE, PWidht * 14,Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle75 = { TEXNO::PLAYER_IDLE, PWidht * 15,Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle76 = { TEXNO::PLAYER_IDLE, PWidht * 16,Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle77 = { TEXNO::PLAYER_IDLE, PWidht * 17,Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle78 = { TEXNO::PLAYER_IDLE, PWidht * 18,Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle79 = { TEXNO::PLAYER_IDLE, PWidht * 19,Pheight * 3, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle80 = { TEXNO::PLAYER_IDLE, PWidht * 0, Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle81 = { TEXNO::PLAYER_IDLE, PWidht * 1, Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle82 = { TEXNO::PLAYER_IDLE, PWidht * 2, Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle83 = { TEXNO::PLAYER_IDLE, PWidht * 3, Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle84 = { TEXNO::PLAYER_IDLE, PWidht * 4, Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle85 = { TEXNO::PLAYER_IDLE, PWidht * 5, Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle86 = { TEXNO::PLAYER_IDLE, PWidht * 6, Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle87 = { TEXNO::PLAYER_IDLE, PWidht * 7, Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle88 = { TEXNO::PLAYER_IDLE, PWidht * 8, Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle89 = { TEXNO::PLAYER_IDLE, PWidht * 9, Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle90 = { TEXNO::PLAYER_IDLE, PWidht * 10,Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle91 = { TEXNO::PLAYER_IDLE, PWidht * 11,Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle92 = { TEXNO::PLAYER_IDLE, PWidht * 12,Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle93 = { TEXNO::PLAYER_IDLE, PWidht * 13,Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle94 = { TEXNO::PLAYER_IDLE, PWidht * 14,Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle95 = { TEXNO::PLAYER_IDLE, PWidht * 15,Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle96 = { TEXNO::PLAYER_IDLE, PWidht * 16,Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle97 = { TEXNO::PLAYER_IDLE, PWidht * 17,Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle98 = { TEXNO::PLAYER_IDLE, PWidht * 18,Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle99 = { TEXNO::PLAYER_IDLE, PWidht * 19,Pheight * 4, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle100 = { TEXNO::PLAYER_IDLE, PWidht * 0, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle101 = { TEXNO::PLAYER_IDLE, PWidht * 1, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle102 = { TEXNO::PLAYER_IDLE, PWidht * 2, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle103 = { TEXNO::PLAYER_IDLE, PWidht * 3, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle104 = { TEXNO::PLAYER_IDLE, PWidht * 4, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle105 = { TEXNO::PLAYER_IDLE, PWidht * 5, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle106 = { TEXNO::PLAYER_IDLE, PWidht * 6, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle107 = { TEXNO::PLAYER_IDLE, PWidht * 7, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle108 = { TEXNO::PLAYER_IDLE, PWidht * 8, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle109 = { TEXNO::PLAYER_IDLE, PWidht * 9, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle110 = { TEXNO::PLAYER_IDLE, PWidht * 10, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle111 = { TEXNO::PLAYER_IDLE, PWidht * 11, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle112 = { TEXNO::PLAYER_IDLE, PWidht * 12, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle113 = { TEXNO::PLAYER_IDLE, PWidht * 13, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle114 = { TEXNO::PLAYER_IDLE, PWidht * 14, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle115 = { TEXNO::PLAYER_IDLE, PWidht * 15, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle116 = { TEXNO::PLAYER_IDLE, PWidht * 16, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle117 = { TEXNO::PLAYER_IDLE, PWidht * 17, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle118 = { TEXNO::PLAYER_IDLE, PWidht * 18, Pheight * 5, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerIdle119 = { TEXNO::PLAYER_IDLE, PWidht * 19, Pheight * 5, PWidht,Pheight,0,0 };

//プレイヤーがダメージを受けた時
GameLib::SpriteData sprPlayerDamaged0 = { TEXNO::PALYER_DAMAGED,PWidht * 0, Pheight * 6, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged1 = { TEXNO::PALYER_DAMAGED,PWidht * 1, Pheight * 6, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged2 = { TEXNO::PALYER_DAMAGED,PWidht * 2, Pheight * 6, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged3 = { TEXNO::PALYER_DAMAGED,PWidht * 3, Pheight * 6, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged4 = { TEXNO::PALYER_DAMAGED,PWidht * 4, Pheight * 6, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged5 = { TEXNO::PALYER_DAMAGED,PWidht * 5, Pheight * 6, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged6 = { TEXNO::PALYER_DAMAGED,PWidht * 6, Pheight * 6, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged7 = { TEXNO::PALYER_DAMAGED,PWidht * 7, Pheight * 6, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged8 = { TEXNO::PALYER_DAMAGED,PWidht * 8, Pheight * 6, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged9 = { TEXNO::PALYER_DAMAGED,PWidht * 9, Pheight * 6, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged10 = { TEXNO::PALYER_DAMAGED,PWidht * 0, Pheight * 7, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged11 = { TEXNO::PALYER_DAMAGED,PWidht * 1, Pheight * 7, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged12 = { TEXNO::PALYER_DAMAGED,PWidht * 2, Pheight * 7, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged13 = { TEXNO::PALYER_DAMAGED,PWidht * 3, Pheight * 7, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged14 = { TEXNO::PALYER_DAMAGED,PWidht * 4, Pheight * 7, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged15 = { TEXNO::PALYER_DAMAGED,PWidht * 5, Pheight * 7, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged16 = { TEXNO::PALYER_DAMAGED,PWidht * 6, Pheight * 7, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged17 = { TEXNO::PALYER_DAMAGED,PWidht * 7, Pheight * 7, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged18 = { TEXNO::PALYER_DAMAGED,PWidht * 8, Pheight * 7, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged19 = { TEXNO::PALYER_DAMAGED,PWidht * 9, Pheight * 7, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged20 = { TEXNO::PALYER_DAMAGED,PWidht * 0, Pheight * 8, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged21 = { TEXNO::PALYER_DAMAGED,PWidht * 1, Pheight * 8, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged22 = { TEXNO::PALYER_DAMAGED,PWidht * 2, Pheight * 8, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged23 = { TEXNO::PALYER_DAMAGED,PWidht * 3, Pheight * 8, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged24 = { TEXNO::PALYER_DAMAGED,PWidht * 4, Pheight * 8, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged25 = { TEXNO::PALYER_DAMAGED,PWidht * 5, Pheight * 8, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged26 = { TEXNO::PALYER_DAMAGED,PWidht * 6, Pheight * 8, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged27 = { TEXNO::PALYER_DAMAGED,PWidht * 7, Pheight * 8, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged28 = { TEXNO::PALYER_DAMAGED,PWidht * 8, Pheight * 8, PWidht,Pheight,0,0 };
GameLib::SpriteData sprPlayerDamaged29 = { TEXNO::PALYER_DAMAGED,PWidht * 9, Pheight * 8, PWidht,Pheight,0,0 };