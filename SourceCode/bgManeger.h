#pragma once
#include "bg.h"
#include <memory>
class BgManeger
{
private:
	BgManeger(){}
	~BgManeger(){}

public:
	static BgManeger& Instance() {
		static BgManeger instance;
		return instance;
	}

	static BG& GetBG() { return *Instance().bg_.get(); }

public:
	void Init();
	void Update();
	void Deinit();
	void Draw();

private:
	std::unique_ptr<BG>bg_;
};

