#include "playerManeger.h"

void PlayerManeger::Init()
{
	player_=std::make_unique<Player>();
	GetPlayer().Init();
}

void PlayerManeger::Update()
{
	GetPlayer().Update();
}

void PlayerManeger::Deinit()
{
	GetPlayer().Deinit();
	
}

void PlayerManeger::Draw()
{
	GetPlayer().Draw();
}
