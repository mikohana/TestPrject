#pragma once
#include "../GameLib/vector.h"
#include <memory>

enum BLOCK_TYPE
{
	NONE,			//�X�e�[�W
	CROSS,			//�\��
	T_DOWN,			//T��
	T_UP,			//�����T��
	T_LEFT,			//������T��
	T_RIGHT,		//�E����T��
	L_DOWN_LEFT,	//����L��
	L_DOWN_RIGHT,	//�E��L��
	L_UP_LEFT,		//����L��
	L_UP_RIGHT,		//�E��L��
};

struct INT_VEC2
{
	int x;
	int y;
};

//�l�����̓��������邩
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
	static const int BLOCK_SIZE = 60;		//�u���b�N�̃T�C�Y

public:
	Block(){}
	Block(bool onStage);
	void OnStageInit();						//�X�e�[�W���ɐ�������u���b�N�̏�����
	void OutStageInit();					//�X�e�[�W�O�ɐ�������u���b�N�̏�����

public:
	BLOCK_TYPE generateType(const Block* block);

	void AutoCalc();

	void BlockReset();

public://�Z�b�^�[�ƃQ�b�^�[
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
	INT_VEC2 gridPos_;		//�܂��ߏ�̍��W

	VECTOR2 position_;		//��ʏ�̍��W

	float size_;				//�T�C�Y	

	int		texPos_;		//�摜�̐؂蔲���ʒu
	
	VECTOR4 color_;			//�F
	
	BLOCK_TYPE blockType_;	//�u���b�N�̃^�C�v
	
	int	canConnect_;		//�l�����̓�������	

	bool isConnectedFlag_;

	bool onStage_;			//�X�e�[�W���ɂ��邩

	bool isSetBlock_;			//�u���b�N���X�e�[�W�ɒu����Ă��邩

	int myGroupNumber_;			//�������Ȃ����Ă���u���b�N�̃O���[�v
};