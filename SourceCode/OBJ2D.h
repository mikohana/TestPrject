#pragma once
#include "../GameLib/game_lib.h"
#include "../GameLib/obj2d_data.h"
class OBJ2D
{
protected:
    //typedef void (*MOVER)(OBJ2D* obj);

    VECTOR2 position_;
    VECTOR2 scale_;
protected:
    float rotation_;
    VECTOR4 color_;
    GameLib::Blender::BLEND_STATE blendState_;
    int state;
    VECTOR2 velocity;
    int timer_;
    GameLib::AnimeData* animeData_;
    GameLib::Anime anime_;
    GameLib::SpriteData* data_;

    // MOVER mover;    // 移動処理（関数ポインタ）
    //int index;

public:
    bool turn;

    void SetSprData(GameLib::SpriteData* spr) { data_ = spr; }

    GameLib::AnimeData* GetAnimeData() { return animeData_; }
    void SetAnimeData(GameLib::AnimeData *animedata) { animeData_ = animedata; }

    void SetPos(VECTOR2 pos) { position_ = pos; }
    VECTOR2 GetPos() { return position_; }

    void SetScale(VECTOR2 sca) { scale_ = sca; }
    VECTOR2 GetScale() { return scale_; }

    VECTOR4 GetColor() { return color_; }
    void SetColor(VECTOR4 col) { color_ = col; }

    float GetRotation() { return rotation_; }

public:
    OBJ2D(VECTOR2 pos, VECTOR2 scale, float rotation, VECTOR4 color, GameLib::Blender::BLEND_STATE blend) :
        position_(pos), scale_(scale), rotation_(rotation), color_(color),
        blendState_(blend), state(0), velocity({}), timer_(0), animeData_(nullptr),data_(nullptr) {
        anime_ = {}, turn = false;
    }
    OBJ2D() { init(); }

    void init()
    {
        position_ = {};
        scale_ = { 1,1 };
        rotation_ = 0.0f;
        color_ = { 1,1,1,1 };
        blendState_ = GameLib::Blender::BLEND_STATE::BS_ALPHA;
        state = 0;
        velocity = {};
        timer_ = 0;

        //mover = 0;
    }

    void clear() { init(); }

    void draw();

    bool AnimeUpdate(GameLib::AnimeData* animeData);

    bool AnimationUpdate(bool loop);
};

enum CHARA_STATE {
    IDLE,
    ATTACK,
    DAMAGED,
};

class CharacterOBJ :public OBJ2D 
{
public:
    CharacterOBJ(VECTOR2 pos, VECTOR2 scale, float rotation, VECTOR4 color, GameLib::Blender::BLEND_STATE blend) :
        OBJ2D(pos, scale, rotation, color, blend), charaState_(IDLE) {}

public:
    CHARA_STATE GetCharaState()const { return charaState_; }
    void SetCharaState(CHARA_STATE state) { charaState_ = state; }

    float GetHP()const { return hp_; }
    void SetHP(float hp) { hp_ = hp; }


public:
     
    void ReciveDamage(float& ATK);



private:
    CHARA_STATE charaState_;

    float hp_;
};

