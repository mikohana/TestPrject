#include "Enemy.h"
#include "../GameLib/game_lib.h"
#include "SpriteData.h"
#include "../imgui/imgui.h"
#include <windows.h>
#include <iostream>
#include "playerManeger.h"

namespace
{
	const int IdleFrame = 5;
	GameLib::AnimeData animeEnemy_Idle[] = {
		{&sprEnemy_Idle0,IdleFrame},
		{&sprEnemy_Idle1,IdleFrame},
		{&sprEnemy_Idle2,IdleFrame},
		{&sprEnemy_Idle3,IdleFrame},
		{&sprEnemy_Idle4,IdleFrame},
		{&sprEnemy_Idle5,IdleFrame},
		{&sprEnemy_Idle6,IdleFrame},
		{&sprEnemy_Idle7,IdleFrame},
		{&sprEnemy_Idle8,IdleFrame},
		{&sprEnemy_Idle9,IdleFrame},
		{&sprEnemy_Idle10,IdleFrame},
		{&sprEnemy_Idle11,IdleFrame},
		{&sprEnemy_Idle12,IdleFrame},
		{&sprEnemy_Idle13,IdleFrame},
		{&sprEnemy_Idle14,IdleFrame},
		{&sprEnemy_Idle15,IdleFrame},
		{&sprEnemy_Idle16,IdleFrame},
		{&sprEnemy_Idle17,IdleFrame},
		{&sprEnemy_Idle18,IdleFrame},
		{&sprEnemy_Idle19,IdleFrame},
		{&sprEnemy_Idle20,IdleFrame},
		{&sprEnemy_Idle21,IdleFrame},
		{&sprEnemy_Idle22,IdleFrame},
		{&sprEnemy_Idle23,IdleFrame},
		{&sprEnemy_Idle24,IdleFrame},
		{&sprEnemy_Idle25,IdleFrame},
		{&sprEnemy_Idle26,IdleFrame},
		{&sprEnemy_Idle27,IdleFrame},
		{&sprEnemy_Idle28,IdleFrame},
		{&sprEnemy_Idle29,IdleFrame},
		{&sprEnemy_Idle30,IdleFrame},
		{&sprEnemy_Idle31,IdleFrame},
		{&sprEnemy_Idle32,IdleFrame},
		{&sprEnemy_Idle33,IdleFrame},
		{&sprEnemy_Idle34,IdleFrame},
		{&sprEnemy_Idle35,IdleFrame},
		{&sprEnemy_Idle36,IdleFrame},
		{&sprEnemy_Idle37,IdleFrame},
		{&sprEnemy_Idle38,IdleFrame},
		{&sprEnemy_Idle39,IdleFrame},
		{&sprEnemy_Idle40,IdleFrame},
		{&sprEnemy_Idle41,IdleFrame},
		{&sprEnemy_Idle42,IdleFrame},
		{&sprEnemy_Idle43,IdleFrame},
		{&sprEnemy_Idle44,IdleFrame},
		//{&sprEnemy_Idle45,1},

		{nullptr,-1},
	};
}

void Enemy::Init()
{
	GameLib::texture::load(loadEnemy);

	enemyOBJ_ = std::make_shared<CharacterOBJ>( VECTOR2{ 1455.0f,300.0f }, VECTOR2{ 1,1 }, 0.0f, VECTOR4{ 1,1,1,1 }, GameLib::Blender::BS_ALPHA);
	enemyOBJ_->SetHP(Enemy::HP);
	enemyOBJ_->SetAnimeData(animeEnemy_Idle);
	enemyOBJ_->turn = true;

	hp_Ui_ = std::make_shared<OBJ2D>
		(VECTOR2{ 1520.0f,830.0f }, VECTOR2{ 1,1 }, 0.0f,
			VECTOR4{ 0,0,0,1 }, GameLib::Blender::BS_DARKEN);
	hp_Ui_->SetSprData(&sprUi_Hp);

	hpGauge_ = std::make_shared<UI_Gauge>(
	VECTOR2{ hp_Ui_->GetPos().x + 10,hp_Ui_->GetPos().y + 3 },
		VECTOR2{ 1,1 }, 0.0f,
		VECTOR4{ 52 / 255.0f, 235.0f / 255.0f  ,  152.0f / 255.0f ,1 },
		GameLib::Blender::BS_ALPHA, 
		Enemy::HP,
		280.0f, VECTOR2{ 280.0f, 30.0f }
	);

}

void Enemy::Deinit()
{
}

void Enemy::Update()
{
	hpGauge_->BarUpdate(enemyOBJ_->GetHP());
	AttackAction();
	if (enemyOBJ_->GetCharaState() == CHARA_STATE::IDLE) {
		enemyOBJ_->AnimeUpdate(animeEnemy_Idle);
		enemyOBJ_->AnimationUpdate(true);
	}
	else if(enemyOBJ_->GetCharaState() == CHARA_STATE::DAMAGED)
	{

	}
}

void Enemy::Draw()
{
	enemyOBJ_->draw();
	
	hp_Ui_->draw();
	hpGauge_->RectDraw(true);
}

void Enemy::AttackAction()
{
	if (AttackJudge()) {
		PlayerManeger::Instance().GetPlayer().GetPlayerOBJ()->ReciveDamage(ATK_STATUS);
		attackCount_ = 0;
		attackFlag_ = false;
	}
}

bool Enemy::AttackJudge()
{
	if (!attackFlag_)return false;
	if (attackCount_ == ATTACK_COUNT_COST) {
		return true;
	}

	return false;
}



void EnemyManeger::Init()
{
	enemy_ = std::make_unique<Enemy>();
	GetEnemy().Init();
}

void EnemyManeger::Update()
{
	GetEnemy().Update();
}

void EnemyManeger::Deinit()
{
	GetEnemy().Deinit();
}

void EnemyManeger::Draw()
{
	GetEnemy().Draw();
}
