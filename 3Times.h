//3Times.h

#pragma once

#include "Mode.h"
#include "Sound.h"

class ThreeTimes : public Mode
{
private:
	int mode;
	int frame;

	Sound *threebai, *Count, *CountDown;

	void Normal();
	void Random();

public:
	ThreeTimes();
	ThreeTimes( Sequence* ptr );
	~ThreeTimes() {}

	void update();
	void Uninit();
};