#pragma once
#include "../GameLib/vector.h"
#include "SpriteData.h"
#include "OBJ2D.h"
class UI_Gauge:public OBJ2D
{
public:
	UI_Gauge(VECTOR2 pos, VECTOR2 scale, float rotation,
		VECTOR4 color, GameLib::Blender::BLEND_STATE blend
		, float maxValue, float changeSize, VECTOR2 texSize) :
		OBJ2D(pos, scale, rotation, color, blend),
		maxValue_(maxValue),
		changeSize_(changeSize),//”ä—¦ŒvŽZ
		texSize_(texSize){}
	~UI_Gauge(){}

public:
	void BarUpdate(float current);

	void RectDraw(bool XorY);

	void SprDraw();

private:
	VECTOR2 texPos_;
	VECTOR2 texSize_;

	float changeSize_;

	float currentValue_;
	float maxValue_;

	float gaugeRatio_;
	float barLength_;

};

