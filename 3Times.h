//3Times.h

#pragma once

#include "Mode.h"
#include "Sound.h"

class ThreeTimes : public Mode
{
private:
	int mode;
	int count;

	Sound* threebai;

public:
	ThreeTimes();
	ThreeTimes( Sequence* ptr );
	~ThreeTimes() {}

	void update();
	void Uninit();
};