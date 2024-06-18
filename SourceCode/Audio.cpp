#include "Audio.h"
#include "../GameLib/game_lib.h"

using namespace GameLib;

//
////--------------------------------------
////  BGMの初期設定
////--------------------------------------
void audio_init_Title()
{
	//------< タイトルの音楽の読み込み >----------------------------------------------------------
	music::load(MUSIC::TITLE_BGM, L"./Data/Musics/タイトルBGM/ピコピコチップチューン日和.wav", 0.1f);
}

void audio_init_Select()
{
	//------< キャラセレクトの音楽の読み込み >----------------------------------------------------------
	music::load(MUSIC::CHARACTER_SELECTION_BGM, L"./Data/Musics/キャラセレクトBGM/CharacterSelection.wav");
}

void audio_init_Game()
{
	//------< ゲームの音楽の読み込み >----------------------------------------------------------
	music::load(MUSIC::GAME_BGM, L"./Data/Musics/ゲームBGM/パズルゲーム.wav",0.5f);
	//music::load(MUSIC::GAMEPINC_BGM, L"./Data/Musics/ゲームBGM/敵のHPが少なくなった時/lobby.wav");
}

//--------------------------------------
//  SEの初期設定
//--------------------------------------
void audio_init_Gage()
{
	//------< ゲージの効果音の読み込み >----------------------------------------------------------
	music::load(SOUND::CUT_IN, L"./Data/Sounds/ゲージ/クリック時カットイン/cut_in.wav");
	music::load(SOUND::GAUGE_GAMAGE, L"./Data/Sounds/ゲージ/ダメージを与えた時/gauge_damage.wav");
}

void audio_init_GameOver()
{
	//------< ゲームオーバーの効果音の読み込み >----------------------------------------------------------
	music::load(SOUND::GAMEOVER03, L"./Data/Sounds/ランプ/ゲームオーバー/Gameover03.wav");
}

void audio_init_GameClear()
{
	//------< ゲームクリアの効果音の読み込み >----------------------------------------------------------
	music::load(SOUND::GAMECLEAR, L"./Data/Sounds/ランプ/ゲームクリア/Gameclear.wav");
}

void audio_init_System()
{
	//------< システムの効果音の読み込み >----------------------------------------------------------
	music::load(SOUND::CANCEL, L"./Data/Sounds/システム/キャンセル/Cancel.wav");
	music::load(SOUND::SOUND_LOGO, L"./Data/Sounds/システム/タイトルロゴが出るまで/sound_logo.wav");
	music::load(SOUND::DECISION, L"./Data/Sounds/システム/決定/decision.wav");
	music::load(SOUND::SELECTION, L"./Data/Sounds/システム/選択/selection/wav");
}

void audio_init_Player()
{
	//------< プレイヤーの効果音の読み込み >----------------------------------------------------------
	music::load(SOUND::ACTION, L"./Data/Sounds/プレイヤー/相手への攻撃/攻撃の瞬間の音/action.wav");
	music::load(SOUND::CALLING_ACTION, L"./Data/Sounds/プレイヤー/相手への攻撃/攻撃までの音/calling action.wav");
}

void audio_init_Block()
{
	//------< ブロックの効果音の読み込み >----------------------------------------------------------
	music::load(SOUND::DISAPPER, L"./Data/Sounds/ブロック/消滅/disappear.wav");
	music::load(SOUND::PUT, L"./Data/Sounds/ブロック/置いた時/put,wav");
	music::load(SOUND::ELECTRIC_CURRENT, L"./Data/Sounds/ブロック/通電している最中/the passage of electric current.wav");
}

void audio_init_ModeSelection()
{
	//------< モード選択の効果音の読み込み >----------------------------------------------------------
	music::load(SOUND::NOTICE, L"./Data/Sounds/モード選択/画面が出た時/Notice.wav");
}

void audio_init_Lamp()
{
	//------< ランプの効果音の読み込み >----------------------------------------------------------
	music::load(SOUND::LUMINESCENCE, L"./Data/Sounds/ランプ/ランプがついた時/luminescence.wav");
	music::load(SOUND::HEAL, L"./Data/Sounds/ランプ/回復/heal.wav");
	music::load(SOUND::BUFFING, L"./Data/Sounds/ランプ/攻撃力UP/buffing.wav");
	music::load(SOUND::OBTAINING, L"./Data/Sounds/ランプ/爆弾/アイテム入手/obtaining.wav");
	music::load(SOUND::EXPLOSION, L"./Data/Sounds/ランプ/爆弾/爆破/explosion");
}

//--------------------------------------
//  オーディオの終了処理
//--------------------------------------
void audio_deinit()
{
	//音楽をすべて解放
	music::clear();
}