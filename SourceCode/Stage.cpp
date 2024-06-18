#include "Stage.h"
#include "SpriteData.h"
#include <stdlib.h>
#include <time.h>
#include "../imgui/imgui.h"
#include<sstream>
#include<iomanip>
#include "playerManeger.h"


bool Stage::CanPutBlock(int x,int y)
{
	if (x>=0 && x<STAGE_W && y>=0 && y<STAGE_H)
	{
		if (stageBlock_[y][x]->GetBlockType() == BLOCK_TYPE::NONE)
		{
			return true;
		}
	}
	return false;
}

void Stage::JudgeConnectBlock(Block& useblock)
{
	if (&useblock != nullptr)
	{
		INT_VEC2 gridPos = { useblock.GetGridPos() };

		//////////右のつながるか判定////////////////////////
		if (JudgeConnectRight(gridPos)) {

			rightGroupNumber_ = stageBlock_[gridPos.y][gridPos.x + 1]->GetMyGroupNumber();
		}

		//////////左のつながるか判定////////////////////////
		if (JudgeConnectLeft(gridPos)) {
			leftGroupNumber_ = stageBlock_[gridPos.y][gridPos.x - 1]->GetMyGroupNumber();
		}

		//////////下のつながるか判定////////////////////////
		if (JudgeConnectDown(gridPos)) {
			downGroupNumber_ = stageBlock_[gridPos.y + 1][gridPos.x]->GetMyGroupNumber();

		}
		ChangeGroupNumber(rightGroupNumber_, useblock.GetMyGroupNumber());
		ChangeGroupNumber(leftGroupNumber_, useblock.GetMyGroupNumber());
		ChangeGroupNumber(downGroupNumber_, useblock.GetMyGroupNumber());

		//端から端までつながっているかを判定
		//JudgeEndToEndConnected();

		leftGroupNumber_ = 0;
		downGroupNumber_ = 0;
		rightGroupNumber_ = 0;
	}
}

 void Stage::ChangeGroupNumber(int reciveNumber,const  int giveNumber)
 {
	 for (int y = 0; y < STAGE_H; y++)
	 {
		 for (int x = 0; x < STAGE_W; x++)
		 {
			 if (stageBlock_[y][x]->GetMyGroupNumber() == 0)continue;

			 if (stageBlock_[y][x]->GetMyGroupNumber() == reciveNumber) {
				 stageBlock_[y][x]->SetMyGroupNumber(giveNumber);
			 }
		 }
	 }
 }

 void Stage::ConnectedBlock( Block& puttedBlock, Block& stageBlock)
{
	if (stageBlock.GetMyGroupNumber() != 0) {
		puttedBlock.SetMyGroupNumber(stageBlock.GetMyGroupNumber()) ;
	}
	else {
		stageBlock.SetMyGroupNumber(totalGroupCount_ + 1);
		puttedBlock.SetMyGroupNumber(stageBlock.GetMyGroupNumber()) ;
		totalGroupCount_ ++;
	}
}

 void Stage::JudgeEndToEndConnected()
 {
	 for (int y = STAGE_H-1; y> 0; y--) {
		 if (isEndToEnd_)continue;//つながりフラグがtrueならやらない
		 if (y < 0)continue;
		 //if (STAGE_W - 1 < 0)continue;//
		 if (this->stageBlock_[y][STAGE_W - 1]==nullptr)continue;
		 if (stageBlock_[y][STAGE_W - 1]->GetMyGroupNumber()==0)continue;
		 if (!((stageBlock_[y][STAGE_W - 1]->GetCanConnect()) & PIPE_RIGHT))continue;
		 for (int x = STAGE_H-1; x > 0; x--) {
			 if (x < 0)continue;
			 if (this->stageBlock_[x][0] == nullptr)continue;
			 if (stageBlock_[x][0]->GetMyGroupNumber() == 0)continue;
			 if (!(stageBlock_[x][0]->GetCanConnect() & PIPE_LEFT))continue;
			 if (stageBlock_[x][0]->GetMyGroupNumber() == stageBlock_[y][STAGE_W - 1]->GetMyGroupNumber()) {
				 deleteGroupNumber_ = stageBlock_[y][STAGE_W - 1]->GetMyGroupNumber();
				 isEndToEnd_ = true;
			 }
		 }
	 }
		
 }

 bool Stage::JudgeConnectLeft(INT_VEC2 gridPosition)
 {
	 if (gridPosition.x-1 < 0) return false;
	 if (!(stageBlock_[gridPosition.y][gridPosition.x]->GetCanConnect() & PIPE_LEFT) )
	 {
		 return false;
	 }
	 if (stageBlock_[gridPosition.y][gridPosition.x - 1] == nullptr)return false;

	 //長いので代入(設置ブロックの1つ左のブロック)
	 Block& puttedBlock = *stageBlock_[gridPosition.y][gridPosition.x];
	 Block& leftBlock = *stageBlock_[gridPosition.y][gridPosition.x - 1];

	 // 参照渡しをしたleftBlockが無効なアドレスじゃないかの確認をしてから
	 if (&leftBlock == nullptr) return false;

	 //左ブロックのタイプがステージタイプじゃなかの確認
	if (leftBlock.GetBlockType() < BLOCK_TYPE::NONE)return false;

    //もし設置ブロックに左向きのパイプがあり、
	if ((puttedBlock.GetCanConnect() & PIPE_LEFT) &&

		//もし左ブロックに右向きのパイプがあれば
		(leftBlock.GetCanConnect() & PIPE_RIGHT)) {

		puttedBlock.SetIsConnectedFlag(true);

		//ブロックがつながった場合の関数を呼ぶ
		ConnectedBlock(puttedBlock, leftBlock);
	}
 }

 bool Stage::JudgeConnectRight(INT_VEC2 gridPosition)
 {
	 if (gridPosition.x >= STAGE_W - 1)
	 {
		 return false;
	 }
	 if (!(stageBlock_[gridPosition.y][gridPosition.x]->GetCanConnect() & PIPE_RIGHT)) {
		 return false;
	 }
	 if (stageBlock_[gridPosition.y][gridPosition.x + 1] == nullptr)return false;

	 Block& puttedBlock = *stageBlock_[gridPosition.y][gridPosition.x];
	 Block& rightBlock = *stageBlock_[gridPosition.y][gridPosition.x + 1];

	 if (&rightBlock == nullptr) return false;
	 if (rightBlock.GetBlockType() < BLOCK_TYPE::NONE)return false;

	 if ((puttedBlock.GetCanConnect() & PIPE_RIGHT) &&
		 (rightBlock.GetCanConnect() & PIPE_LEFT)) {

			 puttedBlock.SetIsConnectedFlag(true);
		 ConnectedBlock(puttedBlock, rightBlock);

		 return true;
	 }
 }

 bool Stage::JudgeConnectDown(INT_VEC2 gridPosition)
 {
	 if (gridPosition.y >= STAGE_H - 1)return false;
	 if (!(stageBlock_[gridPosition.y][gridPosition.x]->GetCanConnect() & PIPE_DOWN)) { 
		 return false; }
	 if (stageBlock_[gridPosition.y+1][gridPosition.x ] == nullptr)return false;

	 Block& puttedBlock = *stageBlock_[gridPosition.y][gridPosition.x];
	 Block& downBlock = *stageBlock_[gridPosition.y + 1][gridPosition.x];

	 if (&downBlock == nullptr)return false;
	 if (downBlock.GetBlockType() < BLOCK_TYPE::NONE)return false;

	 if ((puttedBlock.GetCanConnect() & PIPE_DOWN) &&
		 (downBlock.GetCanConnect() & PIPE_UP)) {

		puttedBlock.SetIsConnectedFlag(true);

		 ConnectedBlock(puttedBlock, downBlock);

		 return true;
	 }
 }

 bool Stage::JudgeConnectUp(INT_VEC2 gridPosition)
 {
	 if (gridPosition.y > 0)return false;
	 if (!(stageBlock_[gridPosition.y][gridPosition.x]->GetCanConnect() & PIPE_UP)) {
		 return false;
	 }
	if ((stageBlock_[gridPosition.y - 1][gridPosition.x])== nullptr)return false;

	 Block& puttedBlock = *stageBlock_[gridPosition.y][gridPosition.x];
	 Block& upBlock = (*stageBlock_[gridPosition.y - 1][gridPosition.x]);
	 if (&upBlock == nullptr)return false;
	 if (upBlock.GetBlockType() < BLOCK_TYPE::NONE)return true;
	 if ((puttedBlock.GetCanConnect() & PIPE_UP) &&
		 (upBlock.GetCanConnect() & PIPE_DOWN)) {
		 if (!puttedBlock.GetIsConnectedFlag())puttedBlock.SetIsConnectedFlag(true);
		 ConnectedBlock(puttedBlock, upBlock);
		 return true;
	 }
 }

 void Stage::RemoveBlock()
 {
	 deleteGroupNum_Count_ = NULL;
	 for (int y = STAGE_H-1; y >=0; y--) {
		 for (int x = 0; x < STAGE_W; x++) {
			 if (stageBlock_[y][x]->GetMyGroupNumber() != deleteGroupNumber_)continue;
			 if (stageBlock_[y][x]->GetBlockType() == BLOCK_TYPE::NONE)continue;
			 if (stageBlock_[y][x] == nullptr)continue;
			    
			 //AutoBlockFall(*stageBlock_[y][x]);
			 stageBlock_[y][x]->SetBlockType(NONE);
			 stageBlock_[y][x]->AutoCalc();


			 deleteGroupNum_Count_++;
		 }
	 }
 }

 bool Stage::DropBlock(Block& fallBlock)
 {
	 INT_VEC2 pos{ fallBlock.GetGridPos().x ,fallBlock.GetGridPos().y };
	 
	 if (CanPutBlock(pos.x, pos.y + 1)) {

		 if (stageBlock_[pos.y+1][pos.x]->GetBlockType() != BLOCK_TYPE::NONE)return false;

		 fallBlock.SetGridPos(pos.x, pos.y + 1);
		 *stageBlock_[pos.y + 1][pos.x] = fallBlock;
		 stageBlock_[pos.y + 1][pos.x]->BlockReset();
		 stageBlock_[pos.y + 1][pos.x]->AutoCalc();
		 fallBlock.SetGridPos(pos.x, pos.y - 1);
		 fallBlock.SetBlockType(NONE);
		 fallBlock.AutoCalc();
		 return true;
	 }

	 return false;

	 //int fallCount = 0;
	 //while (CanPutBlock(pos.x, pos.y + fallCount)) {
		// fallCount++;
	 //}
	 //fallBlock.SetGridPos(pos.x, pos.y + fallCount);
	 //*stageBlock_[pos.y+fallCount][pos.x]= fallBlock ;
	 //fallBlock.SetBlockType(NONE);
	 //return true;
 }

 void Stage::AutoFallBlock()
 {
	 for (int y = STAGE_H; y > 0; y--)
	 {
		 for (int x = 0; x < STAGE_W; x++)
		 {
			 if (y + 1 >= STAGE_H)continue;
			 if (!stageBlock_[y + 1][x])continue;
			 if (stageBlock_[y][x]->GetBlockType() == BLOCK_TYPE::NONE)continue;
			 Block& fallBlock = *stageBlock_[y][x];
			 int posY = y;
			 if (fallBlock.GetBlockType() != NONE) {
				 while (DropBlock(fallBlock)) {
					 fallBlock.SetGridPos(fallBlock.GetGridPos().x, posY++);
					 fallBlock.SetGridPos(fallBlock.GetGridPos().x, posY - 1);
					 fallBlock.SetBlockType(NONE);
					 fallBlock.AutoCalc();
				 }
			 }
			 JudgeConnectBlock(*stageBlock_[y + 1][x]);

		 }
	 }


	 //for (int y = STAGE_H; y > 0; y--)
 //{
	// for (int x = 0; x < STAGE_W; x++)
	// {
		//	 if (stageBlock_[y][x]->GetBlockType() == BLOCK_TYPE::NONE)continue;
		//	 Block& fallBlock = *stageBlock_[y][x];
		//	 if (DropBlock(fallBlock)) {
		//		 fallBlock.AutoCalc();
		//	}
		// }
	 //}
 }

void Stage::SetStageBlock(std::shared_ptr<Block> block, int x, int y)
{
	stageBlock_[y][x] = block;
	stageBlock_[y][x]->SetBlockType(block->GetBlockType());
	stageBlock_[y][x]->SetIsSetBlock(true);
	JudgeConnectBlock(*stageBlock_[y][x]);
}

void Stage::Init()
{
	//テクスチャのロード
	GameLib::texture::load(loadBlockChip);

	//ステージデータ初期化
	int y, x;
	for (y = 0; y < STAGE_H; y++)
	{
		for (x = 0; x < STAGE_W; x++)
		{
			stageBlock_[y][x] = std::make_shared<Block>(true);
			stageBlock_[y][x]->SetGridPos(x, y);
			stageBlock_[y][x]->SetBlockType(NONE);
			stageBlock_[y][x]->AutoCalc();
		}
	}
	//ステートの初期化
	state = 0;
	
	totalGroupCount_ = 0;

	rightGroupNumber_ = 0;
	leftGroupNumber_ = 0;
	downGroupNumber_ = 0;

	deleteGroupNumber_ = NULL;
	deleteGroupNum_Count_ = NULL;

	isEndToEnd_ = false;
}

void Stage::Deinit()
{
	GameLib::texture::release(loadBlockChip);


}

void Stage::Update()
{

	JudgeEndToEndConnected();
	if (PlayerManeger::GetPlayer().GetWorkTimerFlag()) {
		AutoFallBlock();
	}

	if (isEndToEnd_) {
		RemoveBlock();
		PlayerManeger::Instance().GetPlayer().SetEnergyChageFlag(true);
		PlayerManeger::Instance().GetPlayer().SetNormalAttackAnimeFlag(true);
		deleteGroupNumber_ = NULL;
		isEndToEnd_ = false;
	}




	//for (int y = 0; y < STAGE_H; y++)
	//{
	//	for (int x = 0; x < STAGE_W; x++)
	//	{
	//		JudgeConnectBlock(*stageBlock_[y][x]);
	//	}
	//}
}

void Stage::Draw()
{
	//int y, x;
	//ステージの表示
	GameLib::texture::begin(TEXNO::BLOCK);
	for (const auto& blo : stageBlock_)
	{
		for (auto& block : blo)
		{	
			GameLib::texture::draw(TEXNO::BLOCK,
				block->GetPosition().x, block->GetPosition().y,
				1, 1,
				block->GetTexPos(), 0,
				Block::BLOCK_SIZE, Block::BLOCK_SIZE,
				0, 0, 0,
				block->GetColor().x, block->GetColor().y,
				block->GetColor().z, block->GetColor().w);
		}
	}
	GameLib::texture::end(TEXNO::BLOCK);

#if _DEBUG

	for (const auto& blo : stageBlock_)
	{
		for (auto& block : blo)
		{
			std::ostringstream ss;
			ss << block->GetMyGroupNumber();
			GameLib::font::textOut(6,
				ss.str(),
				{ (static_cast<float>(block->GetPosition().x) + Block::BLOCK_SIZE * 0.5f),
				(static_cast<float>(block->GetPosition().y) + Block::BLOCK_SIZE * 0.5f) },
				{ 0.5f, 0.5f }, { 1, 1, 1, 1 }, GameLib::TEXT_ALIGN::MIDDLE); 
		}
	}
#endif// _DEBUG
}

void Stage::DrawDebug()
{

	ImGui::Begin("Stage");
	ImGui::Text("TotalGroupCount:%d", totalGroupCount_);
	if (ImGui::BeginMenu("Block")) {
		for (int y = 0; y < STAGE_H; y++) {
			for (int x = 0; x < STAGE_W; x++) {
				Block& stageBlock = *stageBlock_[y][x];
				if (stageBlock.GetBlockType() == BLOCK_TYPE::NONE)continue;
				ImGui::TreeNode("Block");
				ImGui::Text("BlockType:%d", stageBlock.GetBlockType());
				ImGui::Text("Connected:%d", stageBlock.GetIsConnectedFlag());
				ImGui::End();
			}
		}
		ImGui::EndMenu();
	}
	ImGui::End();
}
