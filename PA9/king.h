#pragma once
#include"board.h"

class King : public Piece //harman
{
	public:
	King(Col c = NUL, vector<int> p = { -1,-1 });
	King(const King& copy);
	~King();
	King& operator=(const King& copy);

	void fvm(Board* gBoard);
};


