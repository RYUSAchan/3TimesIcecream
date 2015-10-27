//3Times.cpp

#include "3Times.h"

ThreeTimes::ThreeTimes()
	:	Mode()
{}

ThreeTimes::ThreeTimes( Sequence* ptr )
	:	Mode( ptr )
{

}

void ThreeTimes::Uninit()
{
}

void ThreeTimes::update()
{
	GetFrame();
	Input_device->GetKeyState();
	if( Input_device->IsKeyDown( DIK_ESCAPE ) )
	{
		obj->SetNextMode( Sequence::MODE_END );
		obj->RemoveModeObject();
	}

	SleepFrame();
}