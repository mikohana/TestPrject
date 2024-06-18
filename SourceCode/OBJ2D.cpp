#include "OBJ2D.h"
#include "Stage.h"
#include "Stage.h"


bool OBJ2D::AnimeUpdate( GameLib::AnimeData* animeData)
{
    if (animeData == nullptr) assert(!"animeUpdate�֐���AnimeData��nullptr");

    if (anime_.pPrev != animeData)           // �A�j���f�[�^���؂�ւ�����Ƃ�
    {
        anime_.pPrev = animeData;
        anime_.patNum = 0;	                // �擪����Đ�
        anime_.frame = 0;
    }
    animeData += anime_.patNum;
    data_ = animeData->data;                // ���݂̃p�^�[���ԍ��ɊY������摜��ݒ�

    //anime_.frame++;
    //if (anime_.frame >= animeData->frame)   // �ݒ�t���[�����\��������
    //{
    //    anime_.frame = 0;
    //    if (turn) {                         // �ʏ�Đ�

    //        anime_.patNum--;
    //        if (anime_.patNum < 0) {
    //            anime_.patNum = 0;        // �擪�֖߂�
    //            return true;
    //        }
    //    }
    //    else {                       // �t�Đ�
    //        anime_.patNum++;                // ���̃p�^�[����
    //        if ((animeData + 1)->frame < 0) // �I���R�[�h�̂Ƃ�
    //        {
    //            anime_.patNum = 0;          // �擪�֖߂�
    //            return true;
    //        }
    //    }
    //}

    anime_.frame++;
    if (anime_.frame >= animeData->frame)    // �ݒ�t���[�����\��������
    {
        anime_.frame = 0;
        anime_.patNum++;                     // ���̃p�^�[����
        if ((animeData + 1)->frame < 0)     // �I���R�[�h�̂Ƃ�
        {
            anime_.patNum = 0;               // �擪�֖߂�
           return true;
        }
    }

    return false;
}

void OBJ2D::draw()
{
    if (this->data_)                                       // OBJ2D��data�����o�ɃX�v���C�g�f�[�^�������
    {
        data_->draw(position_, scale_, rotation_, color_);  // data��draw���\�b�h�ŃX�v���C�g��`�悷��
    }
}

bool OBJ2D::AnimationUpdate(bool loop)
{
    // �A�j���[�V�����X�V
    if (animeData_)
    {
        // animeData�ɒl�������Ă���΁Aobj->animeUpdate���\�b�h���Ă�
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
