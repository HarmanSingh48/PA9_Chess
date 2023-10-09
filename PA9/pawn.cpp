#include "pawn.h"

Pawn::Pawn(Col c, vector<int> p)
{
	this->mCol = c;
	this->mPos = p;
	this->mType = UNDEF;
}

Pawn::Pawn(const Pawn& cpy)
{
	*this = cpy;
}

Pawn::~Pawn()
{

}

Pawn& Pawn::operator=(const Pawn& cpy)
{
	this->mCol = cpy.mCol;
	this->mPos = cpy.mPos;

	return *this;
}

void Pawn::fvm(Board* gBoard)
{
	int x_i = this->mPos.at(0), y_i = this->mPos.at(1);
	if (this->mCol == WHITE)
	{
		if (y_i + 1 < SIZE)
		{
			if (gBoard->check(x_i, y_i + 1) == NUL) {
				gBoard->mBrd[x_i][y_i + 1].setActive(true);
			}
		}

		if (y_i == 1)
		{
			if (gBoard->check(x_i, y_i + 2) == NUL) {
				gBoard->mBrd[x_i][y_i + 2].setActive(true);
			}
		}

		if (x_i + 1 < SIZE && y_i + 1 < SIZE)
		{
			if (gBoard->check(x_i + 1, y_i + 1) != NUL && gBoard->check(x_i + 1, y_i + 1) != this->mCol)
				gBoard->mBrd[x_i + 1][y_i + 1].setActive(true);
		}
		if (x_i - 1 > -1 && y_i + 1 < SIZE)
		{
			if (gBoard->check(x_i - 1, y_i + 1) != NUL && gBoard->check(x_i - 1, y_i + 1) != this->mCol)
				gBoard->mBrd[x_i - 1][y_i + 1].setActive(true);
		}

	}
	else
	{
		if (y_i - 1 > -1)
		{
			if (gBoard->check(x_i, y_i - 1) == NUL) {
				gBoard->mBrd[x_i][y_i - 1].setActive(true);
			}
		}

		if (y_i == 6)
		{
			if (gBoard->check(x_i, y_i - 2) == NUL) {
				gBoard->mBrd[x_i][y_i - 2].setActive(true);
			}
		}

		if (x_i + 1 < SIZE && y_i - 1 > -1)
		{
			if (gBoard->check(x_i + 1, y_i - 1) != NUL && gBoard->check(x_i + 1, y_i - 1) != this->mCol)
				gBoard->mBrd[x_i + 1][y_i - 1].setActive(true);
		}
		if (x_i - 1 > -1 && y_i - 1 > -1)
		{
			if (gBoard->check(x_i - 1, y_i - 1) != NUL && gBoard->check(x_i - 1, y_i - 1) != this->mCol)
				gBoard->mBrd[x_i - 1][y_i - 1].setActive(true);
		}
	}

}