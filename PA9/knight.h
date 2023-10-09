#pragma once
#include"board.h"

class Knight : public Piece //tyler
{
public:
	Knight(Col c = NUL, vector<int> p = { -1, -1 });
	Knight(const Knight& copy);
	~Knight();
	Knight& operator = (const Knight& copy);

	void fvm(Board* gBoard);
};
