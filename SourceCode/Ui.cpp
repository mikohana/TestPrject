#include "Ui.h"
#include "../GameLib/game_lib.h"

void UI_Gauge::BarUpdate(float current)
{

	gaugeRatio_ = current / maxValue_;//”ä—¦ŒvŽZ
	barLength_ = changeSize_ * gaugeRatio_;
}


void UI_Gauge::RectDraw(bool XorY)//X‚ª•Ï‰»‚·‚é‚È‚çtrueAY‚ª‚Ö‚ñ‚©‚·‚é‚È‚ç‚È‚çfalse
{
	if (XorY) {
		GameLib::primitive::rect(
			position_.x,position_.y ,
			barLength_,texSize_.y ,
			scale_.x, scale_.y,
			rotation_,
			color_.x, color_.y, color_.z, color_.w
		);
	}
	else{
		GameLib::primitive::rect(
			position_.x, position_.y,
			texSize_.x, barLength_,
			scale_.x, scale_.y,
			rotation_,
			color_.x, color_.y, color_.z, color_.w
		);
	}

}

void UI_Gauge::SprDraw()
{
	GameLib::texture::begin(this->data_->texNo);
	GameLib::texture::draw(this->data_->texNo,
		{ this->position_.x,this->position_.y },
		{ this->scale_.x,this->scale_.y },
		{ 0, 0 },
		{ texSize_.x, barLength_ },
		{ this->data_->centerX, this->data_->centerY },
		rotation_,
		{ color_.x, color_.y, color_.z, color_.w });
	GameLib::texture::end(this->data_->texNo);
}
