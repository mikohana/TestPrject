#include "player.h"
#include "../GameLib/game_lib.h"
#include "SpriteData.h"
#include "Stage.h"
#include "../imgui/imgui.h"
#include <windows.h>
#include <iostream>
#include "Enemy.h"

namespace
{
	GameLib::AnimeData animeDrop_Effect[] = {
		{&sprDrop_Effect0,4 },
		{&sprDrop_Effect1,4},
		{&sprDrop_Effect2,4},
		{&sprDrop_Effect3,4},
		{&sprDrop_Effect4,4},

		{ nullptr, -1 },// 終了フラグ
	};

	GameLib::AnimeData animePlayer_Idle[] = {
		{&sprPlayer_Idle0,1},

		{nullptr,-1},
	};

	GameLib::AnimeData animeNormalAttack[] = {
		{&sprThunderAttack0,4},
		{&sprThunderAttack1,4},
		{&sprThunderAttack2,4},
		{&sprThunderAttack1,4},
		{&sprThunderAttack2,4},
		{&sprThunderAttack1,4},
		{&sprThunderAttack2,4},
		{&sprThunderAttack3,4},
		{&sprThunderAttack4,4},
		{&sprThunderAttack5,4},
		{&sprThunderAttack4,4},
		{&sprThunderAttack5,4},
		{&sprThunderAttack6,4},
		{&sprThunderAttack7,6},
		{&sprThunderAttack8,4},

		{nullptr,-1},
	};
	const int ultAnimeFrame = 3;
	GameLib::AnimeData animeUltAttack[] = {
		{&sprUltAttack0,ultAnimeFrame},
		{&sprUltAttack1,ultAnimeFrame},
		{&sprUltAttack2,ultAnimeFrame},
		{&sprUltAttack3,ultAnimeFrame},
		{&sprUltAttack4,ultAnimeFrame},
		{&sprUltAttack5,ultAnimeFrame},
		{&sprUltAttack6,ultAnimeFrame},
		{&sprUltAttack7,ultAnimeFrame},
		{&sprUltAttack8,ultAnimeFrame},
		{&sprUltAttack9,ultAnimeFrame},
		{&sprUltAttack10,ultAnimeFrame},
		{&sprUltAttack11,ultAnimeFrame},
		{&sprUltAttack12,ultAnimeFrame},
		{&sprUltAttack13,ultAnimeFrame},
		{&sprUltAttack14,ultAnimeFrame},
		{&sprUltAttack15,ultAnimeFrame},
		{&sprUltAttack16,ultAnimeFrame},
		{&sprUltAttack17,ultAnimeFrame},
		{&sprUltAttack18,ultAnimeFrame},
		{&sprUltAttack19,ultAnimeFrame},
		{&sprUltAttack20,ultAnimeFrame},
		{&sprUltAttack21,ultAnimeFrame},
		{&sprUltAttack22,ultAnimeFrame},
		{&sprUltAttack23,ultAnimeFrame},
		{&sprUltAttack24,ultAnimeFrame},
		{&sprUltAttack25,ultAnimeFrame},
		{&sprUltAttack26,ultAnimeFrame},
		{&sprUltAttack27,ultAnimeFrame},
		{&sprUltAttack28,ultAnimeFrame},
		{&sprUltAttack29,ultAnimeFrame},
		{&sprUltAttack30,ultAnimeFrame},
		{&sprUltAttack31,ultAnimeFrame},
		{&sprUltAttack32,ultAnimeFrame},
		{&sprUltAttack33,ultAnimeFrame},
		{&sprUltAttack34,ultAnimeFrame},
		{&sprUltAttack35,ultAnimeFrame},
		{&sprUltAttack36,ultAnimeFrame},
		{&sprUltAttack37,ultAnimeFrame},
		{&sprUltAttack38,ultAnimeFrame},
		{&sprUltAttack39,ultAnimeFrame},
		{&sprUltAttack40,ultAnimeFrame},
		{&sprUltAttack41,ultAnimeFrame},
		{&sprUltAttack42,ultAnimeFrame},
		{&sprUltAttack43,ultAnimeFrame},
		{&sprUltAttack44,ultAnimeFrame},
		{&sprUltAttack45,ultAnimeFrame},
		{&sprUltAttack46,ultAnimeFrame},
		{&sprUltAttack47,ultAnimeFrame},
		{&sprUltAttack48,ultAnimeFrame},
		{&sprUltAttack49,ultAnimeFrame},
		{&sprUltAttack50,ultAnimeFrame},
		{&sprUltAttack51,ultAnimeFrame},
		{&sprUltAttack52,ultAnimeFrame},
		{&sprUltAttack53,ultAnimeFrame},

		{nullptr,-1},

	};
}

void Player::Init()
{
	//UIテクスチャの読み込み
	GameLib::texture::load(loadUi);
	GameLib::texture::load(loadPlayer);
	GameLib::texture::load(loadAttack);
	GameLib::texture::load(loadEffect);

	for (int i = 0; i < NEXT_ELEMENT; i++) {
		nextBlock[i] = std::make_shared<Block>(false);
		nextBlock[i]->SetBlockType(nextBlock[i]->GetBlockType());
	}

	AUTO_DOWN_COUNT = 100;
	useBlock = std::make_shared<Block>(true);
	useBlock->SetBlockType(static_cast<BLOCK_TYPE>(rand() % 9 + 1));

	playerOBJ_ = std::make_shared<CharacterOBJ>(VECTOR2{65,300 },VECTOR2{ 1,1 }, 0.0f, VECTOR4{ 1,1,1,1 }, GameLib::Blender::BS_ALPHA);
	playerOBJ_->SetHP(Player::HP);
	playerOBJ_->SetSprData(&sprPlayer_Idle0);

	dropEffectOBJ_ = std::make_shared<OBJ2D>(VECTOR2{ static_cast<float>( useBlock->GetPosition().x),static_cast<float>(useBlock->GetPosition().y) }
	, VECTOR2{ 1,1 }, 0.0f, VECTOR4{ 1,1,1,1 }, GameLib::Blender::BS_ALPHA);

	dropEffectOBJ_->SetAnimeData(animeDrop_Effect);

	normalAttackOBJ_ = std::make_shared<OBJ2D>(VECTOR2{ 1320.0f,-80.0f }, VECTOR2{ 1.0f,1.0f },
		0.0f, VECTOR4{ 1,1,1,1 }, GameLib::Blender::BS_ALPHA);
	normalAttackOBJ_->SetAnimeData(nullptr);
	
	ultAttackOBJ_ = std::make_shared<OBJ2D>(VECTOR2{ 0.0f,0.0f, }, VECTOR2{ 2.0f,2.0f },
		0.0f, VECTOR4{ 1,1,1,1 }, GameLib::Blender::BS_ALPHA);
	ultAttackOBJ_->SetAnimeData(animeUltAttack);
	ultAnimeFlag_ = false;
	ultAttackFlag_ = false;
	ultTimer_ = 0;


	hp_Ui_ = std::make_shared<OBJ2D>
		(VECTOR2{ 101.0f,830.0f },VECTOR2{1,1},0.0f,
			VECTOR4{0,0,0,1}, GameLib::Blender::BS_ALPHA);
	hp_Ui_->SetSprData(&sprUi_Hp);

	hpGauge_ = std::make_shared<UI_Gauge>(
		VECTOR2{ hp_Ui_->GetPos().x+10,hp_Ui_->GetPos().y+3 },
		VECTOR2{ 1,1 }, 0.0f,
		VECTOR4{ 52/255.0f, 235.0f/255.0f , 152.0f/255.0f ,1.0f },
		GameLib::Blender::BS_ALPHA,
		Player::HP, 
		280.0f,
		VECTOR2{ 280.0f, 30.0f }
	);

	//ULT_ENERGY_MAX = 300.0f;

	ultGauge_ = std::make_shared<OBJ2D>
		(VECTOR2{ 580.0f,900.0f }, VECTOR2{ 1,1 }, 0.0f,
			VECTOR4{ 1,1,1,1 }, GameLib::Blender::BS_ALPHA);
	ultGauge_->SetSprData(&sprUi_UltGauge);

	currentEnergy_ = 0.0f;

	ultEnergy_ = std::make_shared<OBJ2D>
		(VECTOR2{ ultGauge_->GetPos().x,ultGauge_->GetPos().y}, 
		VECTOR2{0.98f,0.98}, 0.0f,
		VECTOR4{ 1.0f,1.0f,1.0f,1.0f }, 
		GameLib::Blender::BS_ALPHA
	);
	ultEnergy_->SetSprData(&sprUi_UltEnergy);

	dropFlag_ = false;

	normalAttackFlag_ = false;
	energyChargeFlag_ = false;

	workTimer_ = 0;
	workTimerFlag_ = true;
	putTimer_ = 0;

	for (auto& flag : keyPressed) {
		flag=false;
	}

	texPos_ = {};
	texSize_ = { 125,0 };
	savedEnergy_ = 0.0f;

	canUltFlag_ = false;
}

void Player::Deinit()
{
	GameLib::texture::release(loadUi);
}

void Player::Update()
{
	//ゲームオーバー判定
	if (!Stage::Instance().CanPutBlock(3, 0)) {
		gameOverFlag_ = false;
		workTimerFlag_ = false;
	}

	//ポジションの自動計算
	useBlock->AutoCalc();
	for (int i = 0; i < NEXT_ELEMENT; i++) {
		nextBlock[i]->AutoCalc();
	}

	if (putTimer_ >0) {
		dropEffectOBJ_->SetPos({ useBlock->GetPosition().x,useBlock->GetPosition().y });
		dropEffectOBJ_->SetAnimeData(animeDrop_Effect);
		dropEffectOBJ_->AnimationUpdate(false);
	}


	hpGauge_->BarUpdate(playerOBJ_->GetHP());

	ultChargeUpdate();

	UltAttack();


	NormalAttack();

	//タイマーのフラグがtrueの場合
	if (workTimerFlag_){
		MoveBlock();			//ブロックを動かす処理をまとめたやつ
		StagePutBlock();		//ステージ内にブロックを置いたりするための処理をまとめたやつ
	}

	ClearJudge();

#if _DEBUG
	//デバッグ用でスペースキー押したら自動落下が止まる
	if (GameLib::input::TRG(0) & GameLib::input::PAD_L1) {
		if (workTimerFlag_)workTimerFlag_ = false;
		else workTimerFlag_ = true;
	}

	//if (GameLib::input::TRG(0) & GameLib::input::PAD_START) {
	//	ultAnimeFlag_ = true;
	//}
	

	DebugChangeBlock();
#endif
}

void Player::Draw()
{
	playerOBJ_->draw();
	if (attackAnimeFlag_) {
		normalAttackOBJ_->draw();
	}
	UseBlockDraw();				//動かすブロックの表示
	NextBlockDraw();			//次のブロックの表示
	Ui_Draw();		
	ultChargeDraw();
}

//次のブロックを持ってくる処理
void Player::InstallBlock()
{
	Stage::Instance().SetStageBlock(useBlock, useBlock->GetGridPos().x, useBlock->GetGridPos().y);
	//Stage::Instance().JudgeConnectBlock(*useBlock);
	useBlock = nullptr;
}

void Player::AssignNextBlock()
{
	//if (!Stage::Instance().CanPutBlock(3, 0))workTimerFlag_ = false;
	if (!useBlock) {
		useBlock = nextBlock[0];
		dropFlag_ = false;
		useBlock->SetGridPos(3, 0);
		useBlock->SetOnStage(true);
		useBlock->AutoCalc(); 

		for (int i = 0; i < NEXT_ELEMENT; i++)
		{
			if (i + 1 >= NEXT_ELEMENT)continue;
			nextBlock[i] = nextBlock[i + 1];
		}
		nextBlock[NEXT_ELEMENT - 1] = std::make_shared<Block>(false);
		nextBlock[NEXT_ELEMENT - 1]->SetBlockType(nextBlock[NEXT_ELEMENT - 1]->GetBlockType());
	}
}

void Player::StagePutBlock()
{
	const auto gridPos = useBlock->GetGridPos();//省略するために作成

	if (!Stage::Instance().CanPutBlock(gridPos.x, gridPos.y + 1))
	{
		putTimer_++;
		if (putTimer_ >30 )
		{
			InstallBlock();
			AssignNextBlock();
			putTimer_ = 0;
			
		}
	}
	else {
		putTimer_ = 0;

	}

}

void Player::Ui_Draw()
{
	//HPの表示
	hp_Ui_->draw();
	hpGauge_->RectDraw(true);
}

void Player::ultChargeUpdate()
{
	UltEnergyCharge();

	ultRatio_ = currentEnergy_ / ULT_ENERGY_MAX;
	savedSize_ = ultRatio_ * sprUi_UltEnergy.height;
	texSize_.y = sprUi_UltEnergy.height - savedSize_;

	if (texSize_.y < 0) {
		texSize_.y = 0;
		canUltFlag_ = true;
	}
}

bool Player::UltEnergyCharge()
{
	if (energyChargeFlag_) {
		savedEnergy_ = Stage::Instance().GetDeleteGroupCount() * ENERGY_PER;

		currentEnergy_+=savedEnergy_;
		
		energyChargeFlag_ = false;
		return true;
	}
	return false;
}

void Player::ultChargeDraw()
{
	ultGauge_->draw();//下敷きのほうの黒いやつ

	//ゲージ動く法のやつ
	GameLib::texture::begin(TEXNO::UI_ULT_ENERGY);
	GameLib::texture::draw(TEXNO::UI_ULT_ENERGY,
		ultEnergy_->GetPos().x, ultEnergy_->GetPos().y,
		1, 1,
		texPos_.x, texPos_.y,
		texSize_.x, 640,
		0,640,
		0,
		1, 1, 1, 1
	);
	GameLib::texture::end(TEXNO::UI_ULT_ENERGY);

	GameLib::texture::begin(TEXNO::UI_ULT_GAUGE);
	GameLib::texture::draw(TEXNO::UI_ULT_GAUGE,
		ultEnergy_->GetPos().x, ultEnergy_->GetPos().y,
		1, 1,
		texPos_.x, texPos_.y,
		texSize_.x, texSize_.y,
		0, 640,
		0,
		1, 1, 1, 1
	);
	GameLib::texture::end(TEXNO::UI_ULT_GAUGE);

	if(ultAnimeFlag_)ultAttackOBJ_->draw();

}

void Player::UltAttack()
{

	if ( canUltFlag_&&(GameLib::input::TRG(0) & GameLib::input::PAD_START)) {
		ultAnimeFlag_ = true;
	}
	if (ultAnimeFlag_) {
		workTimerFlag_ = false;
		if (ultAttackOBJ_->GetAnimeData() == nullptr)ultAttackOBJ_->SetAnimeData(animeUltAttack);
		if (ultAttackOBJ_->AnimationUpdate(false)) {
			ultAttackFlag_ = true;
			ultAnimeFlag_ = false;
		}
	}

	if (ultAttackFlag_) {
		ultTimer_++;

		EnemyManeger::Instance().GetEnemy().GetEnemyOBJ()->ReciveDamage(ULT_ATTACK_STATUS_);
		workTimerFlag_ = true;
		canUltFlag_ = false;
		currentEnergy_ = 0.0;
		ultAttackFlag_ = false;
	}
	else {
		ultTimer_ = 0;
	}
}

void Player::NormalAttack()
{
	if (attackAnimeFlag_) {
		workTimerFlag_ = false;
		if (normalAttackOBJ_->GetAnimeData() == nullptr) {
			normalAttackOBJ_->SetAnimeData(animeNormalAttack);
		}
		if (normalAttackOBJ_->AnimationUpdate(false)) {
			normalAttackFlag_ = true;
		}

	}

	if (normalAttackFlag_) {
		workTimerFlag_ = true;

		if (ATK_Status_ > 0)ATK_Status_ = 0;
		ATK_Status_= DAMAGE_PER* Stage::Instance().GetDeleteGroupCount();

		EnemyManeger::Instance().GetEnemy().GetEnemyOBJ()->ReciveDamage(ATK_Status_);
		EnemyManeger::Instance().GetEnemy().SetAttackFlag(true);
		EnemyManeger::Instance().GetEnemy().SetAttackCount(EnemyManeger::Instance().GetEnemy().GetAttackCount()+1);

		normalAttackFlag_ = false;
		attackAnimeFlag_ = false;
		
	}

}

void Player::ClearJudge()
{
#if _DEBUG
	if (GameLib::input::TRG(0) & GameLib::input::PAD_TRG2) {
		workTimerFlag_ = false;
		clearFlag_ = true;
	}
#endif

	if (EnemyManeger::Instance().GetEnemy().GetEnemyOBJ()->GetHP() <= 0) {
		workTimerFlag_ = false;
		clearFlag_ = true;
	}


}


void Player::NextBlockDraw()
{
	GameLib::texture::begin(BLOCK);

	for (int n = 0; n < Player::NEXT_ELEMENT; n++)
	{
		//長いので代入
		
		VECTOR2 pos = { nextBlock[n]->GetPosition().x +Block::BLOCK_SIZE*2,
						nextBlock[n]->GetPosition().y +static_cast <float>(n * Block::BLOCK_SIZE*1.5 )};
		
		if (n == 0) {
			pos.x = nextBlock[0]->GetPosition().x + Block::BLOCK_SIZE * 1.8;
			pos.y = nextBlock[0]->GetPosition().y -	30;
		}
		nextBlock[0]->SetSize(1.3f);
		float size= nextBlock[n]->GetSize();
		GameLib::texture::draw(BLOCK,
			pos.x, pos.y,
			size, size,
			nextBlock[n]->GetTexPos(), 0,
			Block::BLOCK_SIZE,Block::BLOCK_SIZE,
			0, 0,
			0,
			1, 1, 1, 1
		);
	}

	GameLib::texture::end(BLOCK);
}

void Player::UseBlockDraw()
{
	GameLib::texture::begin(BLOCK);

	GameLib::texture::draw(
		TEXNO::BLOCK,
		useBlock->GetPosition().x, useBlock->GetPosition().y,
		1, 1,
		useBlock->GetTexPos(), 0,
		Block::BLOCK_SIZE, Block::BLOCK_SIZE,
		0, 0, 0,
		useBlock->GetColor().x, useBlock->GetColor().y,
		useBlock->GetColor().z, useBlock->GetColor().w);

	GameLib::texture::end(BLOCK);

	if(dropFlag_)dropEffectOBJ_->draw();

}

void Player::MoveBlock()
{
	workTimer_++;
	AutoDown();	//二秒に１マス落ちる
	InputDown();
	InputRight();
	InputLeft();
	if (GameLib::input::TRG(0) & GameLib::input::PAD_UP) {
		while (BlockMoveDown()){}
		//dropEffect_->SetAnimeData(animeDrop_Effect);
		//dropEffect_->SetPos({ useBlock->GetPosition().x,useBlock->GetPosition().y  });
		//dropEffect_->AnimationUpdate();
		putTimer_ = 25;
		dropFlag_ = true;
		dropEffectOBJ_->SetPos({ useBlock->GetPosition().x,useBlock->GetPosition().y });
	}
}

void Player::DebugChangeBlock()
{
		if (GetAsyncKeyState('1') & 0x01) {
			if (!keyPressed[0]) {
				useBlock->SetBlockType(CROSS);
				keyPressed[0] = true;
			}
		}
		else {
			keyPressed[0] = false;
		}
}

bool Player::BlockMoveDown()
{
	const auto gridPos = useBlock->GetGridPos();//省略するために作成

	//ステージ内あるか、１マス下に動かせるか判定
	if (!Stage::Instance().CanPutBlock(gridPos.x,gridPos.y+1)){
		return false;
	}
	useBlock->SetGridPos(gridPos.x, gridPos.y + 1);
	return true;
}

bool Player::BlockMoveRight()
{
	const auto gridPos = useBlock->GetGridPos();//省略するために作成

	//ステージ内あるか、１マス右に動かせるか判定
	if (!Stage::Instance().CanPutBlock(gridPos.x+1 , gridPos.y)) {
		return false;
	}

	useBlock->SetGridPos(gridPos.x+1, gridPos.y);
	return true;
}

bool Player::BlockMoveLeft()
{
	const auto gridPos = useBlock->GetGridPos();//省略するために作成

	//ステージ内あるか、１マス右に動かせるか判定
	if (!Stage::Instance().CanPutBlock(gridPos.x -1, gridPos.y)) {
		return false;
	}

	useBlock->SetGridPos(gridPos.x -1, gridPos.y);
	return true;
}

void Player::AutoDown()
{
	if (workTimer_ % AUTO_DOWN_COUNT == 0)
	{
		BlockMoveDown();
	}
}

void Player::InputDown()
{
	if (GameLib::input::TRG(0) & GameLib::input::PAD_DOWN)
	{
		BlockMoveDown();
		dropFlag_ = false;
	}
}

void Player::InputRight()
{
	if (GameLib::input::TRG(0) & GameLib::input::PAD_RIGHT)
	{
		BlockMoveRight();
		dropFlag_ = false;
	}
}

void Player::InputLeft()
{
	if (GameLib::input::TRG(0) & GameLib::input::PAD_LEFT)
	{
		BlockMoveLeft();
		dropFlag_ = false;
	}
}

void Player::DrawDebug()
{
	ImGui::Begin("Player");
	ImGui::InputInt("ONE_COUNT", &AUTO_DOWN_COUNT);
	//ImGui::InputFloat("texSizeY", &texSize_.y);
	ImGui::Text("PlayerHP%f", playerOBJ_->GetHP());
	ImGui::End();
}


