#pragma once
#include "OBJ2D.h"
class EasingOBJ  : public OBJ2D
{
public:
	EasingOBJ(VECTOR2 pos,VECTOR2 scale,float rota,VECTOR4 color, GameLib::Blender::BLEND_STATE blendState, int current,int end,float max,float min):
		OBJ2D(pos,scale,rota,color,blendState),
		currentTime_(current),endTime_(end),maxPos_(max),minPos_(min)
	{}

public:
	bool TimeUpdate();

public:
	float currentTime_;
    float endTime_;
	float maxPos_;
	float minPos_;


};

