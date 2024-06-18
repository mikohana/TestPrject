#pragma once
#include "player.h"
#include <memory>
class PlayerManeger
{


private:
	PlayerManeger(){}
	~PlayerManeger(){}

public:
	static PlayerManeger& Instance() {
		static PlayerManeger instance;
		return instance;
	}

	static Player& GetPlayer() { return *Instance().player_.get(); }

public:
	void Init();
	void Update();
	void Deinit();
	void Draw();

private:
	std::unique_ptr<Player>	player_;
};

