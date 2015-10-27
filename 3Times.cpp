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
	count = 0;
}

void ThreeTimes::Uninit()
{
	_DELETE( threebai );
}

void ThreeTimes::update()
{
	GetFrame();
	Input_device->GetKeyState();
	if( Input_device->IsKeyDown( DIK_ESCAPE ) || mode == 1 )
	{
		obj->SetNextMode( Sequence::MODE_END );
		obj->RemoveModeObject();
	}
	if( count == 0) { threebai->Play(); }

	count = ( count + 1 ) % 120;

	SleepFrame();
}