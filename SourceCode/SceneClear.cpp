#include "SceneClear.h"
#include "../GameLib/game_lib.h"
#include "WinMain.h"

void SceneClear::Init()
{
    timer = 0;
}

void SceneClear::Update()
{
    if (timer > 60 * 5)
    {
        setScene(SCENE::TITLE);
    }
    if (timer > 0x40 && GameLib::input::TRG(0))
    {
        setScene(SCENE::TITLE);
    }

    timer++;
}

void SceneClear::Draw()
{
    GameLib::clear(0, 0, 0);

    if (timer / 20 % 2 == 0)
    {
        GameLib::font::textOut(4, "GAME CLEAR",
            { 640, 360 }, { 5, 5 }, { 0, 1, 1, 1 },
            GameLib::TEXT_ALIGN::MIDDLE);
    }
}
