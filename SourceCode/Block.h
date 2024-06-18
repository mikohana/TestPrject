#pragma once
#include "../GameLib/vector.h"
#include <memory>

enum BLOCK_TYPE
{
	NONE,			//ステージ
	CROSS,			//十字
	T_DOWN,			//T字
	T_UP,			//上向きT字
	T_LEFT,			//左向きT字
	T_RIGHT,		//右向きT字
	L_DOWN_LEFT,	//左下L字
	L_DOWN_RIGHT,	//右下L字
	L_UP_LEFT,		//左上L字
	L_UP_RIGHT,		//右上L字
};

struct INT_VEC2
{
	int x;
	int y;
};

//四方向の銅線があるか
const int PIPE_UP		= 1 << 0;	
const int PIPE_RIGHT	= 1 << 1;
const int PIPE_DOWN		= 1 << 2;
const int PIPE_LEFT		= 1 << 3;

struct BlockData
{
	int			type;
	int			canConnect;
	VECTOR4		color;
};

class Block
{
public:
	static const int BLOCK_SIZE = 60;		//ブロックのサイズ

public:
	Block(){}
	Block(bool onStage);
	void OnStageInit();						//ステージ内に生成するブロックの初期化
	void OutStageInit();					//ステージ外に生成するブロックの初期化

public:
	BLOCK_TYPE generateType(const Block* block);

	void AutoCalc();

	void BlockReset();

public://セッターとゲッター
	void SetBlockType(BLOCK_TYPE blockType);
	BLOCK_TYPE GetBlockType() const {return this->blockType_;}

	void SetGridPos(int x, int y) { this->gridPos_ = { x,y }; }

	INT_VEC2 GetGridPos() const { return this->gridPos_; }

	VECTOR4 GetColor() const { return this->color_; }

	VECTOR2 GetPosition() { return this->position_; }

	int GetTexPos()const { return this->texPos_; }

	void SetIsSetBlock(bool setBlock) { isSetBlock_ = setBlock; }

	void SetOnStage(bool onstage) { onStage_ = onstage; }

	void SetSize(float s) { this->size_ = s; }
	float GetSize()const { return this->size_; }

	int GetCanConnect()const { return this->canConnect_; }

	void SetMyGroupNumber(int num) { myGroupNumber_ = num; }
	int GetMyGroupNumber()const { return this->myGroupNumber_; }

	void SetIsConnectedFlag(bool flag) { this->isConnectedFlag_ = flag; }
	int GetIsConnectedFlag()const { return this->isConnectedFlag_; }

private:
	INT_VEC2 gridPos_;		//ますめ上の座標

	VECTOR2 position_;		//画面上の座標

	float size_;				//サイズ	

	int		texPos_;		//画像の切り抜き位置
	
	VECTOR4 color_;			//色
	
	BLOCK_TYPE blockType_;	//ブロックのタイプ
	
	int	canConnect_;		//四方向の銅線判定	

	bool isConnectedFlag_;

	bool onStage_;			//ステージ内にいるか

	bool isSetBlock_;			//ブロックがステージに置かれているか

	int myGroupNumber_;			//自分がつながっているブロックのグループ
};