#pragma once
#include"tile.h"

class Board : public sf::RectangleShape
{
public:
	Tile mBrd[8][8];
	Texture mTex;

	Board();
	Board(const Board& cpy);
	~Board();
	Board& operator=(const Board& cpy);

	//returns color of occupant; NUL for unoccupied
	Col check(int x, int y);
	// checks for check
	bool c4c(int x, int y, Col color); 
};

