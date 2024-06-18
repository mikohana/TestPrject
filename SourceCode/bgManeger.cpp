#include "bgManeger.h"

void BgManeger::Init()
{
	bg_ = std::make_unique<BG>();
	GetBG().Init();
}

void BgManeger::Update()
{
	GetBG().Update();
}

void BgManeger::Deinit()
{
}

void BgManeger::Draw()
{
	GetBG().Draw();
}
