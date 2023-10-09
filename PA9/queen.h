#pragma once
#include"board.h"



class Queen : public Piece //harman
{
public:
	Queen(Col c = NUL, vector<int> p = { -1,-1 });
	Queen(const Queen& copy);
	~Queen();
	Queen& operator=(const Queen& copy);


	void fvm(Board* gBoard);
};
