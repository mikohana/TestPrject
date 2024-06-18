#include "EasingOBJ.h"

bool EasingOBJ::TimeUpdate()
{
	currentTime_++;
	if (currentTime_ > endTime_) {
		currentTime_ = endTime_;
		return true;
	}
	return false;
}
