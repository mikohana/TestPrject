#include "Audio.h"
#include "../GameLib/game_lib.h"

using namespace GameLib;

//
////--------------------------------------
////  BGM�̏����ݒ�
////--------------------------------------
void audio_init_Title()
{
	//------< �^�C�g���̉��y�̓ǂݍ��� >----------------------------------------------------------
	music::load(MUSIC::TITLE_BGM, L"./Data/Musics/�^�C�g��BGM/�s�R�s�R�`�b�v�`���[�����a.wav", 0.1f);
}

void audio_init_Select()
{
	//------< �L�����Z���N�g�̉��y�̓ǂݍ��� >----------------------------------------------------------
	music::load(MUSIC::CHARACTER_SELECTION_BGM, L"./Data/Musics/�L�����Z���N�gBGM/CharacterSelection.wav");
}

void audio_init_Game()
{
	//------< �Q�[���̉��y�̓ǂݍ��� >----------------------------------------------------------
	music::load(MUSIC::GAME_BGM, L"./Data/Musics/�Q�[��BGM/�p�Y���Q�[��.wav",0.5f);
	//music::load(MUSIC::GAMEPINC_BGM, L"./Data/Musics/�Q�[��BGM/�G��HP�����Ȃ��Ȃ�����/lobby.wav");
}

//--------------------------------------
//  SE�̏����ݒ�
//--------------------------------------
void audio_init_Gage()
{
	//------< �Q�[�W�̌��ʉ��̓ǂݍ��� >----------------------------------------------------------
	music::load(SOUND::CUT_IN, L"./Data/Sounds/�Q�[�W/�N���b�N���J�b�g�C��/cut_in.wav");
	music::load(SOUND::GAUGE_GAMAGE, L"./Data/Sounds/�Q�[�W/�_���[�W��^������/gauge_damage.wav");
}

void audio_init_GameOver()
{
	//------< �Q�[���I�[�o�[�̌��ʉ��̓ǂݍ��� >----------------------------------------------------------
	music::load(SOUND::GAMEOVER03, L"./Data/Sounds/�����v/�Q�[���I�[�o�[/Gameover03.wav");
}

void audio_init_GameClear()
{
	//------< �Q�[���N���A�̌��ʉ��̓ǂݍ��� >----------------------------------------------------------
	music::load(SOUND::GAMECLEAR, L"./Data/Sounds/�����v/�Q�[���N���A/Gameclear.wav");
}

void audio_init_System()
{
	//------< �V�X�e���̌��ʉ��̓ǂݍ��� >----------------------------------------------------------
	music::load(SOUND::CANCEL, L"./Data/Sounds/�V�X�e��/�L�����Z��/Cancel.wav");
	music::load(SOUND::SOUND_LOGO, L"./Data/Sounds/�V�X�e��/�^�C�g�����S���o��܂�/sound_logo.wav");
	music::load(SOUND::DECISION, L"./Data/Sounds/�V�X�e��/����/decision.wav");
	music::load(SOUND::SELECTION, L"./Data/Sounds/�V�X�e��/�I��/selection/wav");
}

void audio_init_Player()
{
	//------< �v���C���[�̌��ʉ��̓ǂݍ��� >----------------------------------------------------------
	music::load(SOUND::ACTION, L"./Data/Sounds/�v���C���[/����ւ̍U��/�U���̏u�Ԃ̉�/action.wav");
	music::load(SOUND::CALLING_ACTION, L"./Data/Sounds/�v���C���[/����ւ̍U��/�U���܂ł̉�/calling action.wav");
}

void audio_init_Block()
{
	//------< �u���b�N�̌��ʉ��̓ǂݍ��� >----------------------------------------------------------
	music::load(SOUND::DISAPPER, L"./Data/Sounds/�u���b�N/����/disappear.wav");
	music::load(SOUND::PUT, L"./Data/Sounds/�u���b�N/�u������/put,wav");
	music::load(SOUND::ELECTRIC_CURRENT, L"./Data/Sounds/�u���b�N/�ʓd���Ă���Œ�/the passage of electric current.wav");
}

void audio_init_ModeSelection()
{
	//------< ���[�h�I���̌��ʉ��̓ǂݍ��� >----------------------------------------------------------
	music::load(SOUND::NOTICE, L"./Data/Sounds/���[�h�I��/��ʂ��o����/Notice.wav");
}

void audio_init_Lamp()
{
	//------< �����v�̌��ʉ��̓ǂݍ��� >----------------------------------------------------------
	music::load(SOUND::LUMINESCENCE, L"./Data/Sounds/�����v/�����v��������/luminescence.wav");
	music::load(SOUND::HEAL, L"./Data/Sounds/�����v/��/heal.wav");
	music::load(SOUND::BUFFING, L"./Data/Sounds/�����v/�U����UP/buffing.wav");
	music::load(SOUND::OBTAINING, L"./Data/Sounds/�����v/���e/�A�C�e������/obtaining.wav");
	music::load(SOUND::EXPLOSION, L"./Data/Sounds/�����v/���e/���j/explosion");
}

//--------------------------------------
//  �I�[�f�B�I�̏I������
//--------------------------------------
void audio_deinit()
{
	//���y�����ׂĉ��
	music::clear();
}