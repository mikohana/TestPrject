#pragma once
#include "../GameLib/game_lib.h"
#include "../GameLib/obj2d_data.h"

enum TEXNO
{

	

	//プレイヤー関連
	PLAYER_IDLE,
	PALYER_DAMAGED,

	//攻撃関連
	THUNDER_ATTACK_ANIMATION,
	ULT_ATTACK_ANIMATION,


	//エネミー関連
	ENEMY_IDLE,
	ENEMY_ANIME,

	BLOCK,

	//UI関連
	UI_HP,
	UI_TIMELIMIT,

	UI_ULT_GAUGE,
	UI_ULT_ENERGY,

	//タイトル関連
	TITLE_BG,
	TITLE_LOGO,
	TITLE_MU,
	TITLE_SU,
	TITLE_NN,
	TITLE_DE,
	TITLE_BIKKURI,


	//背景関連
	SCREEN_BG,
	STAGE_BG,
	NEXT_BLOCK_BG,

	//クリア関連
	CLEAR_LOGO,
	CLEAR_PAKA,

	//エフェクト関連
	DROP_EFFECT,

};

extern GameLib::LoadTexture loadBlockChip[];
extern GameLib::LoadTexture loadUi[];
extern GameLib::LoadTexture loadPlayer[];
extern GameLib::LoadTexture loadAttack[];
extern GameLib::LoadTexture loadEffect[];
extern GameLib::LoadTexture loadBG[];
extern GameLib::LoadTexture loadEnemy[];
extern GameLib::LoadTexture loadTitle[];

extern GameLib::LoadTexture loadClear[];


extern GameLib::SpriteData sprClearLogo0;
extern GameLib::SpriteData sprClearLogo1;
extern GameLib::SpriteData sprClearLogo2;
extern GameLib::SpriteData sprClearLogo3;
extern GameLib::SpriteData sprClearLogo4;
extern GameLib::SpriteData sprClearLogo5;
extern GameLib::SpriteData sprClearLogo6;
extern GameLib::SpriteData sprClearLogo7;
extern GameLib::SpriteData sprClearLogo8;
extern GameLib::SpriteData sprClearLogo9;
extern GameLib::SpriteData sprClearLogo10;
extern GameLib::SpriteData sprClearLogo11;

extern GameLib::SpriteData sprClrear_Paka0;
extern GameLib::SpriteData sprClrear_Paka1;
extern GameLib::SpriteData sprClrear_Paka2;
extern GameLib::SpriteData sprClrear_Paka3;
extern GameLib::SpriteData sprClrear_Paka4;
extern GameLib::SpriteData sprClrear_Paka5;
extern GameLib::SpriteData sprClrear_Paka6;
extern GameLib::SpriteData sprClrear_Paka7;
extern GameLib::SpriteData sprClrear_Paka8;
extern GameLib::SpriteData sprClrear_Paka9;
extern GameLib::SpriteData sprClrear_Paka10;
extern GameLib::SpriteData sprClrear_Paka11;
extern GameLib::SpriteData sprClrear_Paka12;
extern GameLib::SpriteData sprClrear_Paka13;
extern GameLib::SpriteData sprClrear_Paka14;
extern GameLib::SpriteData sprClrear_Paka15;
extern GameLib::SpriteData sprClrear_Paka16;
extern GameLib::SpriteData sprClrear_Paka17;
extern GameLib::SpriteData sprClrear_Paka18;
extern GameLib::SpriteData sprClrear_Paka19;
extern GameLib::SpriteData sprClrear_Paka20;
extern GameLib::SpriteData sprClrear_Paka21;
extern GameLib::SpriteData sprClrear_Paka22;
extern GameLib::SpriteData sprClrear_Paka23;
extern GameLib::SpriteData sprClrear_Paka24;
extern GameLib::SpriteData sprClrear_Paka25;
extern GameLib::SpriteData sprClrear_Paka26;
extern GameLib::SpriteData sprClrear_Paka27;
extern GameLib::SpriteData sprClrear_Paka28;
extern GameLib::SpriteData sprClrear_Paka29;
extern GameLib::SpriteData sprClrear_Paka30;
extern GameLib::SpriteData sprClrear_Paka31;
extern GameLib::SpriteData sprClrear_Paka32;
extern GameLib::SpriteData sprClrear_Paka33;
extern GameLib::SpriteData sprClrear_Paka34;
extern GameLib::SpriteData sprClrear_Paka35;
extern GameLib::SpriteData sprClrear_Paka36;
extern GameLib::SpriteData sprClrear_Paka37;
extern GameLib::SpriteData sprClrear_Paka38;
extern GameLib::SpriteData sprClrear_Paka39;
extern GameLib::SpriteData sprClrear_Paka40;
extern GameLib::SpriteData sprClrear_Paka41;
extern GameLib::SpriteData sprClrear_Paka42;
extern GameLib::SpriteData sprClrear_Paka43;
extern GameLib::SpriteData sprClrear_Paka44;
extern GameLib::SpriteData sprClrear_Paka45;
extern GameLib::SpriteData sprClrear_Paka46;
extern GameLib::SpriteData sprClrear_Paka47;
extern GameLib::SpriteData sprClrear_Paka48;
extern GameLib::SpriteData sprClrear_Paka49;

extern GameLib::SpriteData sprTitleBG;
extern GameLib::SpriteData sprTitleLogo;

extern GameLib::SpriteData sprTitle_Mu ;
extern GameLib::SpriteData sprTitle_Su ;
extern GameLib::SpriteData sprTitle_Nn ;
extern GameLib::SpriteData sprTitle_De ;
extern GameLib::SpriteData sprTitle_Bikk;

extern GameLib::SpriteData sprDrop_Effect0;
extern GameLib::SpriteData sprDrop_Effect1;
extern GameLib::SpriteData sprDrop_Effect2;
extern GameLib::SpriteData sprDrop_Effect3;
extern GameLib::SpriteData sprDrop_Effect4;

extern GameLib::SpriteData sprPlayer_Idle0;

extern GameLib::SpriteData sprEnemy_Idle0;
extern GameLib::SpriteData sprEnemy_Idle1;
extern GameLib::SpriteData sprEnemy_Idle2;
extern GameLib::SpriteData sprEnemy_Idle3;
extern GameLib::SpriteData sprEnemy_Idle4;
extern GameLib::SpriteData sprEnemy_Idle5; 
extern GameLib::SpriteData sprEnemy_Idle6;
extern GameLib::SpriteData sprEnemy_Idle7;
extern GameLib::SpriteData sprEnemy_Idle8;
extern GameLib::SpriteData sprEnemy_Idle9;
extern GameLib::SpriteData sprEnemy_Idle10;
extern GameLib::SpriteData sprEnemy_Idle11;
extern GameLib::SpriteData sprEnemy_Idle12;
extern GameLib::SpriteData sprEnemy_Idle13;
extern GameLib::SpriteData sprEnemy_Idle14;
extern GameLib::SpriteData sprEnemy_Idle15;
								   
extern GameLib::SpriteData sprEnemy_Idle16;
extern GameLib::SpriteData sprEnemy_Idle17;
extern GameLib::SpriteData sprEnemy_Idle18;
extern GameLib::SpriteData sprEnemy_Idle19;
extern GameLib::SpriteData sprEnemy_Idle20;
extern GameLib::SpriteData sprEnemy_Idle21;
extern GameLib::SpriteData sprEnemy_Idle22;
extern GameLib::SpriteData sprEnemy_Idle23;
extern GameLib::SpriteData sprEnemy_Idle24;
extern GameLib::SpriteData sprEnemy_Idle25;
extern GameLib::SpriteData sprEnemy_Idle26;
extern GameLib::SpriteData sprEnemy_Idle27;
extern GameLib::SpriteData sprEnemy_Idle28;
extern GameLib::SpriteData sprEnemy_Idle29;
extern GameLib::SpriteData sprEnemy_Idle30;
extern GameLib::SpriteData sprEnemy_Idle31;
extern GameLib::SpriteData sprEnemy_Idle32;
								   
extern GameLib::SpriteData sprEnemy_Idle33;
extern GameLib::SpriteData sprEnemy_Idle34;
extern GameLib::SpriteData sprEnemy_Idle35;
extern GameLib::SpriteData sprEnemy_Idle36;
extern GameLib::SpriteData sprEnemy_Idle37;
extern GameLib::SpriteData sprEnemy_Idle38;
extern GameLib::SpriteData sprEnemy_Idle39;
extern GameLib::SpriteData sprEnemy_Idle40;
extern GameLib::SpriteData sprEnemy_Idle41;
extern GameLib::SpriteData sprEnemy_Idle42;
extern GameLib::SpriteData sprEnemy_Idle43;
extern GameLib::SpriteData sprEnemy_Idle44;
//extern GameLib::SpriteData sprEnemy_Idle45;

extern GameLib::SpriteData sprUi_Hp;
extern GameLib::SpriteData sprUi_UltGauge;
extern GameLib::SpriteData sprUi_UltEnergy;

extern GameLib::SpriteData sprThunderAttack0;
extern GameLib::SpriteData sprThunderAttack1;
extern GameLib::SpriteData sprThunderAttack2;
extern GameLib::SpriteData sprThunderAttack3;
extern GameLib::SpriteData sprThunderAttack4;
extern GameLib::SpriteData sprThunderAttack5;
extern GameLib::SpriteData sprThunderAttack6;
extern GameLib::SpriteData sprThunderAttack7;
extern GameLib::SpriteData sprThunderAttack8;

extern GameLib::SpriteData sprUltAttack0;
extern GameLib::SpriteData sprUltAttack1;
extern GameLib::SpriteData sprUltAttack2;
extern GameLib::SpriteData sprUltAttack3;
extern GameLib::SpriteData sprUltAttack4;
extern GameLib::SpriteData sprUltAttack5;
extern GameLib::SpriteData sprUltAttack6;
extern GameLib::SpriteData sprUltAttack7;
extern GameLib::SpriteData sprUltAttack8;
extern GameLib::SpriteData sprUltAttack9;
extern GameLib::SpriteData sprUltAttack10;
extern GameLib::SpriteData sprUltAttack11;
extern GameLib::SpriteData sprUltAttack12;
extern GameLib::SpriteData sprUltAttack13;
extern GameLib::SpriteData sprUltAttack14;
extern GameLib::SpriteData sprUltAttack15;
extern GameLib::SpriteData sprUltAttack16;
extern GameLib::SpriteData sprUltAttack17;
extern GameLib::SpriteData sprUltAttack18;
extern GameLib::SpriteData sprUltAttack19;
extern GameLib::SpriteData sprUltAttack20;
extern GameLib::SpriteData sprUltAttack21;
extern GameLib::SpriteData sprUltAttack22;
extern GameLib::SpriteData sprUltAttack23;
extern GameLib::SpriteData sprUltAttack24;
extern GameLib::SpriteData sprUltAttack25;
extern GameLib::SpriteData sprUltAttack26;
extern GameLib::SpriteData sprUltAttack27;
extern GameLib::SpriteData sprUltAttack28;
extern GameLib::SpriteData sprUltAttack29;
extern GameLib::SpriteData sprUltAttack30;
extern GameLib::SpriteData sprUltAttack31;
extern GameLib::SpriteData sprUltAttack32;
extern GameLib::SpriteData sprUltAttack33;
extern GameLib::SpriteData sprUltAttack34;
extern GameLib::SpriteData sprUltAttack35;
extern GameLib::SpriteData sprUltAttack36;
extern GameLib::SpriteData sprUltAttack37;
extern GameLib::SpriteData sprUltAttack38;
extern GameLib::SpriteData sprUltAttack39;
extern GameLib::SpriteData sprUltAttack40;
extern GameLib::SpriteData sprUltAttack41;
extern GameLib::SpriteData sprUltAttack42;
extern GameLib::SpriteData sprUltAttack43;
extern GameLib::SpriteData sprUltAttack44;
extern GameLib::SpriteData sprUltAttack45;
extern GameLib::SpriteData sprUltAttack46;
extern GameLib::SpriteData sprUltAttack47;
extern GameLib::SpriteData sprUltAttack48;
extern GameLib::SpriteData sprUltAttack49;
extern GameLib::SpriteData sprUltAttack50;
extern GameLib::SpriteData sprUltAttack51;
extern GameLib::SpriteData sprUltAttack52;
extern GameLib::SpriteData sprUltAttack53;

//プレイヤーの待機
extern GameLib::SpriteData sprPlayerIdle0;
extern GameLib::SpriteData sprPlayerIdle1;
extern GameLib::SpriteData sprPlayerIdle2;
extern GameLib::SpriteData sprPlayerIdle3;
extern GameLib::SpriteData sprPlayerIdle4;
extern GameLib::SpriteData sprPlayerIdle5;
extern GameLib::SpriteData sprPlayerIdle6;
extern GameLib::SpriteData sprPlayerIdle7;
extern GameLib::SpriteData sprPlayerIdle8;
extern GameLib::SpriteData sprPlayerIdle9;
extern GameLib::SpriteData sprPlayerIdle10;
extern GameLib::SpriteData sprPlayerIdle11;
extern GameLib::SpriteData sprPlayerIdle12;
extern GameLib::SpriteData sprPlayerIdle13;
extern GameLib::SpriteData sprPlayerIdle14;
extern GameLib::SpriteData sprPlayerIdle15;
extern GameLib::SpriteData sprPlayerIdle16;
extern GameLib::SpriteData sprPlayerIdle17;
extern GameLib::SpriteData sprPlayerIdle18;
extern GameLib::SpriteData sprPlayerIdle19;
extern GameLib::SpriteData sprPlayerIdle20;
extern GameLib::SpriteData sprPlayerIdle21;
extern GameLib::SpriteData sprPlayerIdle22;
extern GameLib::SpriteData sprPlayerIdle23;
extern GameLib::SpriteData sprPlayerIdle24;
extern GameLib::SpriteData sprPlayerIdle25;
extern GameLib::SpriteData sprPlayerIdle26;
extern GameLib::SpriteData sprPlayerIdle27;
extern GameLib::SpriteData sprPlayerIdle28;
extern GameLib::SpriteData sprPlayerIdle29;
extern GameLib::SpriteData sprPlayerIdle30;
extern GameLib::SpriteData sprPlayerIdle31;
extern GameLib::SpriteData sprPlayerIdle32;
extern GameLib::SpriteData sprPlayerIdle33;
extern GameLib::SpriteData sprPlayerIdle34;
extern GameLib::SpriteData sprPlayerIdle35;
extern GameLib::SpriteData sprPlayerIdle36;
extern GameLib::SpriteData sprPlayerIdle37;
extern GameLib::SpriteData sprPlayerIdle38;
extern GameLib::SpriteData sprPlayerIdle39;
extern GameLib::SpriteData sprPlayerIdle40;
extern GameLib::SpriteData sprPlayerIdle41;
extern GameLib::SpriteData sprPlayerIdle42;
extern GameLib::SpriteData sprPlayerIdle43;
extern GameLib::SpriteData sprPlayerIdle44;
extern GameLib::SpriteData sprPlayerIdle45;
extern GameLib::SpriteData sprPlayerIdle46;
extern GameLib::SpriteData sprPlayerIdle47;
extern GameLib::SpriteData sprPlayerIdle48;
extern GameLib::SpriteData sprPlayerIdle49;
extern GameLib::SpriteData sprPlayerIdle50;
extern GameLib::SpriteData sprPlayerIdle51;
extern GameLib::SpriteData sprPlayerIdle52;
extern GameLib::SpriteData sprPlayerIdle53;
extern GameLib::SpriteData sprPlayerIdle54;
extern GameLib::SpriteData sprPlayerIdle55;
extern GameLib::SpriteData sprPlayerIdle56;
extern GameLib::SpriteData sprPlayerIdle57;
extern GameLib::SpriteData sprPlayerIdle58;
extern GameLib::SpriteData sprPlayerIdle59;
extern GameLib::SpriteData sprPlayerIdle60;
extern GameLib::SpriteData sprPlayerIdle61;
extern GameLib::SpriteData sprPlayerIdle62;
extern GameLib::SpriteData sprPlayerIdle63;
extern GameLib::SpriteData sprPlayerIdle64;
extern GameLib::SpriteData sprPlayerIdle65;
extern GameLib::SpriteData sprPlayerIdle66;
extern GameLib::SpriteData sprPlayerIdle67;
extern GameLib::SpriteData sprPlayerIdle68;
extern GameLib::SpriteData sprPlayerIdle69;
extern GameLib::SpriteData sprPlayerIdle70;
extern GameLib::SpriteData sprPlayerIdle71;
extern GameLib::SpriteData sprPlayerIdle72;
extern GameLib::SpriteData sprPlayerIdle73;
extern GameLib::SpriteData sprPlayerIdle75;
extern GameLib::SpriteData sprPlayerIdle76;
extern GameLib::SpriteData sprPlayerIdle77;
extern GameLib::SpriteData sprPlayerIdle78;
extern GameLib::SpriteData sprPlayerIdle79;
extern GameLib::SpriteData sprPlayerIdle80;
extern GameLib::SpriteData sprPlayerIdle81;
extern GameLib::SpriteData sprPlayerIdle82;
extern GameLib::SpriteData sprPlayerIdle83;
extern GameLib::SpriteData sprPlayerIdle84;
extern GameLib::SpriteData sprPlayerIdle85;
extern GameLib::SpriteData sprPlayerIdle86;
extern GameLib::SpriteData sprPlayerIdle87;
extern GameLib::SpriteData sprPlayerIdle88;
extern GameLib::SpriteData sprPlayerIdle89;
extern GameLib::SpriteData sprPlayerIdle90;
extern GameLib::SpriteData sprPlayerIdle91;
extern GameLib::SpriteData sprPlayerIdle92;
extern GameLib::SpriteData sprPlayerIdle93;
extern GameLib::SpriteData sprPlayerIdle94;
extern GameLib::SpriteData sprPlayerIdle95;
extern GameLib::SpriteData sprPlayerIdle96;
extern GameLib::SpriteData sprPlayerIdle97;
extern GameLib::SpriteData sprPlayerIdle98;
extern GameLib::SpriteData sprPlayerIdle99;
extern GameLib::SpriteData sprPlayerIdle100;
extern GameLib::SpriteData sprPlayerIdle101;
extern GameLib::SpriteData sprPlayerIdle102;
extern GameLib::SpriteData sprPlayerIdle103;
extern GameLib::SpriteData sprPlayerIdle104;
extern GameLib::SpriteData sprPlayerIdle105;
extern GameLib::SpriteData sprPlayerIdle106;
extern GameLib::SpriteData sprPlayerIdle107;
extern GameLib::SpriteData sprPlayerIdle108;
extern GameLib::SpriteData sprPlayerIdle109;
extern GameLib::SpriteData sprPlayerIdle110;
extern GameLib::SpriteData sprPlayerIdle111;
extern GameLib::SpriteData sprPlayerIdle112;
extern GameLib::SpriteData sprPlayerIdle113;
extern GameLib::SpriteData sprPlayerIdle114;
extern GameLib::SpriteData sprPlayerIdle115;
extern GameLib::SpriteData sprPlayerIdle116;
extern GameLib::SpriteData sprPlayerIdle117;
extern GameLib::SpriteData sprPlayerIdle118;
extern GameLib::SpriteData sprPlayerIdle119;

//プレイヤーがダメージを受けた時
extern GameLib::SpriteData sprPlayerDamaged0;
extern GameLib::SpriteData sprPlayerDamaged1;
extern GameLib::SpriteData sprPlayerDamaged2;
extern GameLib::SpriteData sprPlayerDamaged3;
extern GameLib::SpriteData sprPlayerDamaged4;
extern GameLib::SpriteData sprPlayerDamaged5;
extern GameLib::SpriteData sprPlayerDamaged6;
extern GameLib::SpriteData sprPlayerDamaged7;
extern GameLib::SpriteData sprPlayerDamaged8;
extern GameLib::SpriteData sprPlayerDamaged9;
extern GameLib::SpriteData sprPlayerDamaged10;
extern GameLib::SpriteData sprPlayerDamaged11;
extern GameLib::SpriteData sprPlayerDamaged12;
extern GameLib::SpriteData sprPlayerDamaged13;
extern GameLib::SpriteData sprPlayerDamaged14;
extern GameLib::SpriteData sprPlayerDamaged15;
extern GameLib::SpriteData sprPlayerDamaged16;
extern GameLib::SpriteData sprPlayerDamaged17;
extern GameLib::SpriteData sprPlayerDamaged18;
extern GameLib::SpriteData sprPlayerDamaged19;
extern GameLib::SpriteData sprPlayerDamaged20;
extern GameLib::SpriteData sprPlayerDamaged21;
extern GameLib::SpriteData sprPlayerDamaged22;
extern GameLib::SpriteData sprPlayerDamaged23;
extern GameLib::SpriteData sprPlayerDamaged24;
extern GameLib::SpriteData sprPlayerDamaged25;
extern GameLib::SpriteData sprPlayerDamaged26;
extern GameLib::SpriteData sprPlayerDamaged27;
extern GameLib::SpriteData sprPlayerDamaged28;
extern GameLib::SpriteData sprPlayerDamaged29;
