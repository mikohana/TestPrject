#pragma once
#include "Block.h"

enum class LAMP_TYPE {
	YELLOW,
	BLUE,
	GEREEN,
	RED,
	PURPLE,
};

class Lamp
{
public:
	Lamp() {}
	~Lamp(){}

private:
	static const int LAMP_SIZE = 40;
	
	//static const int LEFT_POS_X=
	//static const int RIGT_POS_X=
	
	INT_VEC2 position_;

};

