//3Times.h

#pragma once

#include "Mode.h"

class ThreeTimes : public Mode
{
private:

public:
	ThreeTimes();
	ThreeTimes( Sequence* ptr );
	~ThreeTimes() {}

	void update();
	void Uninit();
};