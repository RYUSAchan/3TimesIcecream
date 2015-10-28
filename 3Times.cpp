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
	title = dynamic_cast< DxFont* >( FindObjectBox( "MS_MINCHO_52" ) );
	
	mode = mode | 2;
	frame = 30;
	n = 0;
	ice = FALSE;
	srand( timeGetTime() );
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

	if( mode & 2 )
	{
		if( mode & 4 )
		{
			RECT rc = { 320, 120, 320, 120 };
			title->Draw( _T( "Count Down" ), -1, &rc, DT_NOCLIP | DT_CENTER, 0xFFFFFFFF ); 
			if( frame == 75 )
			{
				CountDown->Play();
				frame--;
			} else if( frame == 0 )
			{
				frame = 0;
				mode &= ~( 2 | 4 );
			} else {
				frame--;
			}
		} else {
			if( frame == 0 )
			{
				frame = 75;
				mode |= 4;
			} else {
				frame--;
			}
		}
	} else {
		if( !( mode & 1 ) )
		{
			Normal();
		} else {
			Random();
		}
	}

	SleepFrame();
}

void ThreeTimes::Normal()
{
	if( frame == 0 )
	{
		n++;
		if( ice = Icecream( n ) )
		{
			threebai->Play();
			frame = 120;
		} else {
			Count->Play();
			frame = 60;
		}
	}
	
	RECT rc = { 320, 200, 320, 200 };	
	if( ice )
	{
		title->Draw( _T( "３倍アイスクリーム！！" ), -1, &rc, DT_NOCLIP | DT_CENTER, 0xFFFFFFFF );
	} else {
		TCHAR text[ 32 ];
		wsprintf( text, _T( "%d" ), n );
		title->Draw( text, -1, &rc, DT_NOCLIP | DT_CENTER, 0xFFFFFFFF );
	}
	frame--;
}

void ThreeTimes::Random()
{
	if( frame == 0 )
	{
		n++;
		if( ice = ( ( rand() % 4 ) == 0 ) )
		{
			threebai->Play();
			frame = 120;
		} else {
			Count->Play();
			frame = 60;
		}
	}
	
	RECT rc = { 320, 200, 320, 200 };	
	if( ice )
	{
		title->Draw( _T( "３倍アイスクリーム！！" ), -1, &rc, DT_NOCLIP | DT_CENTER, 0xFFFFFFFF );
	} else {
		TCHAR text[ 32 ];
		wsprintf( text, _T( "%d" ), n );
		title->Draw( text, -1, &rc, DT_NOCLIP | DT_CENTER, 0xFFFFFFFF );
	}
	frame--;
}

BOOL ThreeTimes::Icecream( int n )
{
	return ( ( ( n % 3 ) == 0 ) || strchr( to_string( n ).c_str(), '3' ) );
}