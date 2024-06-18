#pragma once
#include "bg.h"
#include "Block.h"
#include <vector>
#include <memory>
class Stage
{
private:
	Stage(){};
	~Stage(){}

private:

	//BLOCK_TYPE generaType(BLOCK_TYPE blockType);

public:
	static Stage& Instance()
	{
		static Stage instance_;
		return instance_;
	}

public:
	void Init();
	void Deinit();
	void Update();
	void Draw();



public:
	bool CanPutBlock(int x, int y);					//ステージ上にぶろっくを置けるかの判定

	void SetStageBlock(std::shared_ptr<Block> block, int x, int y); //ブロックがステージに設置された時の処理
	
	void SetDeleteGroupCount(int count) { deleteGroupNum_Count_= count; }
	int GetDeleteGroupCount() const{ return deleteGroupNum_Count_; }

public:
	static const int STAGE_W = 6;                   //フィールドの幅 
	static const int STAGE_H = 12;                   //フィールドの高さ 

	//ステージのX座標の基準
	static const int STAGE_X = (BG::WINDOW_W / 2) - Block::BLOCK_SIZE * (STAGE_W / 2);
	
	//ステージのY座標の基準
	static const int STAGE_Y = Block::BLOCK_SIZE * 3;

private:
void JudgeConnectBlock(Block& useblock);		//ブロックのつながりの判定

void ChangeGroupNumber(int reciveNumber,const int giveNumber);

 void ConnectedBlock( Block& useBlock, Block& stageBlock_);

 void JudgeEndToEndConnected();
 void RemoveBlock();

bool JudgeConnectLeft(INT_VEC2 gridPosition);	
bool JudgeConnectRight(INT_VEC2 gridPosition);
bool JudgeConnectDown(INT_VEC2 gridPosition);
bool JudgeConnectUp(INT_VEC2 gridPosition);

bool DropBlock(Block& fallBlock);
void AutoFallBlock();


private:
	std::shared_ptr<Block> stageBlock_[STAGE_H][STAGE_W];

	int totalGroupCount_;

	int leftGroupNumber_;
	int rightGroupNumber_;
	int downGroupNumber_;

	int deleteGroupNumber_;
	int deleteGroupNum_Count_;

	bool isEndToEnd_;

private:
	int state;

public:
	void DrawDebug();
private:
	


};

