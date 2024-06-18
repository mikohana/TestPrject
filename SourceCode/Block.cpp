#include "Block.h"
#include "Stage.h"
#include <stdlib.h>
#include "Audio.h"
//#include "stage.h"
////void ONE_Block_Draw()
//{
//	//srand((unsigned int)time(NULL));
//	//int blockTypeY = rand() % 2;
//	//int rnd_blockType;
//	//int rnd_Type1 = rand() %BLOCK_TYPE1::L_UP_RIGHT ;
//
//	//switch (blockTypeY)
//	//{
//	//case 0:
//	//	rnd_blockType = rand() % 5 + 2;
//	//	break;
//	//case 1:
//	//	rnd_blockType = rand() % 4;
//	//	break;
//	//}
//
//}

BlockData blockData_[] =
{
	{NONE,0,{1,1,1,1}},
	{CROSS,{ PIPE_UP | PIPE_RIGHT | PIPE_DOWN | PIPE_LEFT},{1,1,1,1} },
	{T_DOWN,{PIPE_RIGHT | PIPE_DOWN | PIPE_LEFT},{1,1,1,1} },
	{T_UP,{PIPE_UP | PIPE_RIGHT | PIPE_LEFT},{1,1,1,1} },
	{T_LEFT,{PIPE_UP | PIPE_DOWN | PIPE_LEFT},{1,1,1,1} },
	{T_RIGHT,{PIPE_UP | PIPE_RIGHT | PIPE_DOWN},{1,1,1,1} },
	{L_DOWN_LEFT,{PIPE_DOWN | PIPE_LEFT},{1,1,1,1} },
	{L_DOWN_RIGHT,{PIPE_RIGHT | PIPE_DOWN},{1,1,1,1} },
	{L_UP_LEFT,{PIPE_UP | PIPE_LEFT},{1,1,1,1} },
	{L_UP_RIGHT,{PIPE_UP | PIPE_RIGHT},{1,1,1,1} },

	{-1,-1,{0,0,0,0}}
};

Block::Block(bool onStage):onStage_(onStage)
{
	if (onStage_)OnStageInit();
	else {
		OutStageInit();
	}
	isSetBlock_ = false;
	size_ = 1;
	AutoCalc();
	canConnect_=  blockData_[this->blockType_].canConnect;
	myGroupNumber_ = 0;
	isConnectedFlag_ = false;
}


void Block::OnStageInit()
{
	gridPos_ = { 3,0 };
	blockType_ = static_cast<BLOCK_TYPE>(rand() % 9 + 1);
	
}

void Block::OutStageInit()
{
	gridPos_ = {};

	position_ = { Stage::STAGE_X + Stage::STAGE_W * Block::BLOCK_SIZE,
		Stage::STAGE_Y + 1 * Block::BLOCK_SIZE };

	blockType_ = static_cast<BLOCK_TYPE>(rand() % 9 + 1);

}

BLOCK_TYPE Block::generateType(const Block* block)
{
	BLOCK_TYPE newType;
	if(block){
		do {
			newType = static_cast<BLOCK_TYPE>(rand() % BLOCK_TYPE::L_UP_LEFT+1);
		} while (newType == block->blockType_);
		return newType;
	}

}

void Block::AutoCalc()
{
	if (onStage_)
	{
		position_ = {static_cast<float> (gridPos_.x * BLOCK_SIZE + Stage::STAGE_X),
			static_cast<float>(gridPos_.y * BLOCK_SIZE + Stage::STAGE_Y) };
	}
	texPos_ = blockType_ * BLOCK_SIZE;
	
}

void Block::BlockReset()
{
	isConnectedFlag_ = false;
	myGroupNumber_ = NULL;
}

void Block::SetBlockType(BLOCK_TYPE blockType)
{
	color_ = blockData_[blockType].color;
	blockType_ = blockType;
	canConnect_ = blockData_[blockType].canConnect;

	if (blockType == BLOCK_TYPE::NONE) {
		myGroupNumber_ = 0;
		isConnectedFlag_ = false;
	}
}

//void Block::MoveBlock()
//{
//
//}
//
//bool Block::blockMoveR()
//{
//
//	return false;
//}
//
//bool Block::blockMoveL()
//{
//	return false;
//}
//
//bool Block::blockMoveD()
//{
//	return false;
//}
