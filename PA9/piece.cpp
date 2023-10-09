#include"board.h"

Piece::Piece(Col col, vector<int> pos)
{
	this->mCol = col;
	this->mPos = pos;
	this->mType = UNDEF;
}