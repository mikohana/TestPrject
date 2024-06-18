
//------< インクルード >---------------------------------------------------------
#include "SpriteData.h"
#include "../GameLib/game_lib.h"
#include "bg.h"

//------< データ >---------------------------------------------------------------

//----------------------------------------------------------------------
//  コンストラクタ
//----------------------------------------------------------------------
BG::BG()
{
}
;
//----------------------------------------------------------------------
//  デストラクタ
//----------------------------------------------------------------------
BG::~BG()
{
}

//----------------------------------------------------------------------
//  初期設定
//----------------------------------------------------------------------
void BG::Init()
{
    GameLib::texture::load(loadBG);

}

void BG::DeInit()
{
    GameLib::texture::release(loadBG);
}

//----------------------------------------------------------------------
//  更新処理
//----------------------------------------------------------------------
void BG::Update()
{
   
}

void BG::Draw()
{
    GameLib::texture::begin(TEXNO::SCREEN_BG);
    GameLib::texture::draw(TEXNO::SCREEN_BG,
        0, 0,
        1, 1,
        0, 0,
        1920, 1080,
        0, 0,
        0,
        1,1,1,1
    );
    GameLib::texture::end(TEXNO::SCREEN_BG);

    GameLib::texture::begin(TEXNO::STAGE_BG);
    GameLib::texture::draw(TEXNO::STAGE_BG,
        525, 40,
        1, 1,
        0, 0,
        900, 980,
        0, 0,
        0,
        1, 1, 1, 1
    );
    GameLib::texture::end(TEXNO::STAGE_BG);

    GameLib::texture::end(TEXNO::SCREEN_BG);

    GameLib::texture::begin(TEXNO::NEXT_BLOCK_BG);
    GameLib::texture::draw(TEXNO::NEXT_BLOCK_BG,
        1220, 170,
        1, 1,
        0, 0,
        150, 440,
        0, 0,
        0,
        1, 1, 1, 1
    );
    GameLib::texture::end(TEXNO::NEXT_BLOCK_BG);
}








