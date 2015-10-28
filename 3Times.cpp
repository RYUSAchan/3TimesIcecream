//3Times.cpp

#include "3Times.h"

ThreeTimes::ThreeTimes()
	:	Mode()
{}

ThreeTimes::ThreeTimes( Sequence* ptr )
	:	Mode( ptr )
{
	mode = ( int )obj->GetUserData();
	threebai = _NEW Sound( *dynamic_cast< Sound* >( FindObjectBox( "3bai" ) ) );
	Count = _NEW Sound( *dynamic_cast< Sound* >( FindObjectBox( "Count" ) ) );
	CountDown = _NEW Sound( *dynamic_cast< Sound* >( FindObjectBox( "CountDown" ) ) );
	frame = 0;
}

void ThreeTimes::Uninit()
{
	_DELETE( threebai );
	_DELETE( Count );
	_DELETE( CountDown );
}

void ThreeTimes::update()
{
	GetFrame();
	Input_device->GetKeyState();
	if( Input_device->IsKeyDown( DIK_ESCAPE )  )
	{
		obj->SetNextMode( Sequence::MODE_END );
		obj->RemoveModeObject();
	}

	if( mode == 0 )
	{
		Normal();
	} else {
		Random();
	}

	SleepFrame();
}

void ThreeTimes::Normal()
{}

void ThreeTimes::Random()
{}