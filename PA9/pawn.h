#pragma once
#include"board.h"

class Pawn : public Piece //dylan
{

public:

	Pawn(Col c = NUL, vector<int> p = { -1, -1 });
	Pawn(const Pawn& cpy);
	~Pawn();
	Pawn& operator=(const Pawn& cpy);

	void fvm(Board* gBoard);

};
