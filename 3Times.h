//3Times.h

#pragma once

#include "Mode.h"
#include "Draw.h"
#include "Sound.h"

class ThreeTimes : public Mode
{
private:
	int mode;
	int frame;
	int n;

	BOOL ice;

	Sound *threebai, *Count, *CountDown;
	DxFont* title;

	void Normal();
	void Random();

	BOOL Icecream( int n );

public:
	ThreeTimes();
	ThreeTimes( Sequence* ptr );
	~ThreeTimes() {}

	void update();
	void Uninit();
};