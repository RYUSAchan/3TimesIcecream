//Title.h

#pragma once

#include "Mode.h"
#include "Draw.h"

#define MAX_COLUMN 5

#define PROGRAM_TITLE_DRAW title->Draw( _T( "３倍アイスクリーム！！" ), 50, 120 )

class Title : public Mode
{
private:
	DxFont *DrawFps, *title, *column, *column_italic;
	DrawTexture *Cursor;
	
	int x, y;

	int cursorpos;

	int Count, frame;

public:
	Title();
	Title( Sequence* ptr );
	~Title();

	void update();
	void Uninit();
};