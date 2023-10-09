#pragma once
#include"board.h"

class Rook : public Piece //tyler
{
public:
	Rook(Col c = NUL, vector<int> p = { -1, -1 });
	Rook(const Rook& copy);
	~Rook();
	Rook& operator = (const Rook& copy);

	void fvm(Board* gBoard);
};

