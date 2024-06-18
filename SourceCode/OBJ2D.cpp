#include "OBJ2D.h"
#include "Stage.h"
#include "Stage.h"


bool OBJ2D::AnimeUpdate( GameLib::AnimeData* animeData)
{
    if (animeData == nullptr) assert(!"animeUpdate関数でAnimeDataがnullptr");

    if (anime_.pPrev != animeData)           // アニメデータが切り替わったとき
    {
        anime_.pPrev = animeData;
        anime_.patNum = 0;	                // 先頭から再生
        anime_.frame = 0;
    }
    animeData += anime_.patNum;
    data_ = animeData->data;                // 現在のパターン番号に該当する画像を設定

    //anime_.frame++;
    //if (anime_.frame >= animeData->frame)   // 設定フレーム数表示したら
    //{
    //    anime_.frame = 0;
    //    if (turn) {                         // 通常再生

    //        anime_.patNum--;
    //        if (anime_.patNum < 0) {
    //            anime_.patNum = 0;        // 先頭へ戻る
    //            return true;
    //        }
    //    }
    //    else {                       // 逆再生
    //        anime_.patNum++;                // 次のパターンへ
    //        if ((animeData + 1)->frame < 0) // 終了コードのとき
    //        {
    //            anime_.patNum = 0;          // 先頭へ戻る
    //            return true;
    //        }
    //    }
    //}

    anime_.frame++;
    if (anime_.frame >= animeData->frame)    // 設定フレーム数表示したら
    {
        anime_.frame = 0;
        anime_.patNum++;                     // 次のパターンへ
        if ((animeData + 1)->frame < 0)     // 終了コードのとき
        {
            anime_.patNum = 0;               // 先頭へ戻る
           return true;
        }
    }

    return false;
}

void OBJ2D::draw()
{
    if (this->data_)                                       // OBJ2Dのdataメンバにスプライトデータがあれば
    {
        data_->draw(position_, scale_, rotation_, color_);  // dataのdrawメソッドでスプライトを描画する
    }
}

bool OBJ2D::AnimationUpdate(bool loop)
{
    // アニメーション更新
    if (animeData_)
    {
        // animeDataに値が入っていれば、obj->animeUpdateメソッドを呼ぶ
        if (this->AnimeUpdate(animeData_)) {
            if (!loop) {
                animeData_ = nullptr;
                return true;
          }
       }

    }
    return false;
}

void CharacterOBJ::ReciveDamage(float& ATK)
{
    hp_ -= ATK;
}
