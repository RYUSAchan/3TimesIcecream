//Load.cpp

#include "Load.h"
#include "Draw.h"
#include "Sound.h"
#include <process.h>

BOOL Load::complete = FALSE;

Load::Load( Sequence* ptr )
{
	SetGameObject( ptr );

	tex = _NEW Texture( _T( "data/nowloading.png" ) );
	drawtex = new DrawTexture( tex );
	drawtex->SetSpriteSize( 240, 48 );

	complete = FALSE;

	_beginthread( this->LoadThread, 0, NULL );

}

Load::~Load()
{}

void Load::update()
{
	GetFrame();
	if( !complete )
	{
		brightness = ( ( brightness + 253 ) % 255 );

		drawtex->SetCenterPosition( CP_LEFT | CP_TOP );

		drawtex->Draw( 427.0f, 444.0f, brightness );
	} else {
		obj->SetNextMode( obj->MODE_TITLE );
		obj->RemoveModeObject();
	}
	SleepFrame();
}

void Load::Uninit()
{
	_DELETE( drawtex );
	_DELETE( tex );
}

void Load::LoadThread( void *data )
{
	AppendObjectBox( "MS_UI_Gothic_16", _NEW DxFont( 16 ) );
	AppendObjectBox( "MS_UI_Gothic_28", _NEW DxFont( 28 ) );
	AppendObjectBox( "HGS_GYOSYOTAI_32_Italic", _NEW DxFont( 32, _T( "HGS_çsèëëÃ" ), TRUE ) );  
	AppendObjectBox( "MS_MINCHO_52", _NEW DxFont( 52, _T( "ÇlÇr ñæí©" ), FALSE ) );

	AppendObjectBox( "Cursor", _NEW Texture( _T( "data/cursor.png" ) ) );
	AppendObjectBox( "3bai", _NEW Sound( _T( "data/3.wav" ) ) );
	AppendObjectBox( "Count", _NEW Sound( _T( "data/Count.wav" ) ) );
	AppendObjectBox( "CountDown", _NEW Sound( _T( "data/CountDown.wav" ) ) );

	complete = TRUE;
}