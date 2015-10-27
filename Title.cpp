//Title.cpp

#include "Title.h"

Title::Title()
	:	Mode(), sstate( MOVE_1 )
{}

Title::Title( Sequence* ptr )
	:	sstate( MOVE_1 ), Mode( ptr )
{
	DrawFps = dynamic_cast< DxFont* >( FindObjectBox( "MS_UI_Gothic_16" ) );
	title = dynamic_cast< DxFont* >( FindObjectBox( "MS_MINCHO_52" ) );
	column = dynamic_cast< DxFont* >( FindObjectBox( "MS_UI_Gothic_28" ) );
	column_italic = dynamic_cast< DxFont* >( FindObjectBox( "HGS_GYOSYOTAI_32_Italic" ) );
	Cursor = _NEW DrawTexture( dynamic_cast< Texture* >( FindObjectBox( "Cursor" ) ) );
	Cursor->SetSpriteRect( 0, 0, 24, 24 );
	
	Count = 0;
	frame = 0;
	cursorpos = 0;
}

Title::~Title()
{}

void Title::Uninit()
{
	_DELETE( Cursor );
}

void Title::update()
{
	GetFrame();
	//stringstream ss;
	
	Input_device->GetKeyState();
	if( Input_device->IsKeyDown( DIK_ESCAPE ) )
	{
		obj->SetNextMode( Sequence::MODE_END );
		obj->RemoveModeObject();
	}
	/*if( Input_device->IsKeyDown( DIK_F5 ) )
	{
		ifstream ifs( "cfg.txt" );
		ss.clear();
		char c;
		while( ( c = ifs.get() ) != ',' )
		{
			ss << c;
		}
		ss >> x;
		ss.clear();
		while ( ( c = ifs.get() ) != EOF )
		{
			ss << c;
		}
		ss >> y;
	}*/

	//ss.clear();
	
	column->Draw( _T( "通常アイスクリーム" ), 200, 280 );
	column->Draw( _T( "ランダムアイスクリーム" ), 200, 340 );
	column->Draw( _T( "エグジットアイスクリーム" ), 200, 400 );
	switch( cursorpos ) {
	case 0:
		Cursor->Draw( 180.0f, 293.0f );
		break;
	case 1:
		Cursor->Draw( 180.0f, 353.0f );
		break;
	case 2:
		Cursor->Draw( 180.0f, 413.0f );
		break;	
	}
	PROGRAM_TITLE_DRAW;
	if( Input_device->IsKeyPressed( DIK_Z ) ) {
		if( cursorpos == 0 )
		{
			
			return;
		} else if( cursorpos == 1 )
		{
			return;
		} else if ( cursorpos == 2 )
		{
			obj->SetNextMode( Sequence::MODE_END );
			obj->RemoveModeObject();
			return;
		}
	}
	if( Input_device->IsKeyPressed( DIK_DOWN ) && !Input_device->IsKeyDown( DIK_UP ) ) {
		cursorpos++;
		if( cursorpos > 2 ) { cursorpos = 2; }
	} else if( Input_device->IsKeyPressed( DIK_UP ) && !Input_device->IsKeyDown( DIK_DOWN ) ) {
		cursorpos--;
		if( cursorpos < 0 ) { cursorpos = 0; }
	}


	SleepFrame();
}

void Title::NextStage( int pos )
{
	obj->RemoveModeObject();
}