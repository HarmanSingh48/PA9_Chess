#include "knight.h"

Knight::Knight(Col c, vector<int> p)
{
	this->mCol = c;
	this->mPos = p;
	this->mType = UNDEF;
}

Knight::Knight(const Knight& copy)
{
	*this = copy;
}

Knight::~Knight()
{ }

Knight& Knight::operator = (const Knight& copy)
{
	this->mCol = copy.mCol;
	this->mPos = copy.mPos;

	return *this;
}

void Knight::fvm(Board* gBoard)
{
	int x_i = this->mPos.at(0), y_i = this->mPos.at(1);
	// checks valid move 2U + L of knight
	if ((x_i + 2 < SIZE) && (y_i - 1 >= 0))
	{
		if (gBoard->check(x_i + 2, y_i - 1) == NUL || gBoard->check(x_i + 2, y_i - 1) != this->mCol) {
			gBoard->mBrd[x_i + 2][y_i - 1].setActive(true);
		}
	}
	// checks valid move 2U + R of knight
	if ((x_i + 2 < SIZE) && (y_i + 1 < SIZE))
	{
		if (gBoard->check(x_i + 2, y_i + 1) == NUL || gBoard->check(x_i + 2, y_i + 1) != this->mCol) {
			gBoard->mBrd[x_i + 2][y_i + 1].setActive(true);
		}
	}
	// checks valid move U + 2R of knight
	if ((x_i + 1 < SIZE) && (y_i + 2 < SIZE))
	{
		if (gBoard->check(x_i + 1, y_i + 2) == NUL || gBoard->check(x_i + 1, y_i + 2) != this->mCol) {
			gBoard->mBrd[x_i + 1][y_i + 2].setActive(true);
		}
	}
	// checks valid move D + 2R of knight
	if ((x_i - 1 >= 0) && (y_i + 2 <= SIZE))
	{
		if (gBoard->check(x_i - 1, y_i + 2) == NUL || gBoard->check(x_i - 1, y_i + 2) != this->mCol) {
			gBoard->mBrd[x_i - 1][y_i + 2].setActive(true);
		}
	}
	// checks valid move 2D + R of knight
	if ((x_i - 2 >= 0) && (y_i + 1 < SIZE))
	{
		if (gBoard->check(x_i - 2, y_i + 1) == NUL || gBoard->check(x_i - 2, y_i + 1) != this->mCol) {
			gBoard->mBrd[x_i - 2][y_i + 1].setActive(true);
		}
	}
	// checks valid move 2D + L of knight
	if ((x_i - 2 >= 0) && (y_i - 1 >= 0))
	{
		if (gBoard->check(x_i - 2, y_i - 1) == NUL || gBoard->check(x_i - 2, y_i - 1) != this->mCol) {
			gBoard->mBrd[x_i - 2][y_i - 1].setActive(true);
		}
	}
	// checks valid move D + 2L of knight
	if ((x_i - 1 >= 0) && (y_i - 2 >= 0))
	{
		if (gBoard->check(x_i - 1, y_i - 2) == NUL || gBoard->check(x_i - 1, y_i - 2) != this->mCol) {
			gBoard->mBrd[x_i - 1][y_i - 2].setActive(true);
		}
	}
	// checks valid move U + 2L of knight
	if ((x_i + 1 < SIZE) && (y_i - 2 >= 0))
	{
		if (gBoard->check(x_i + 1, y_i - 2) == NUL || gBoard->check(x_i + 1, y_i - 2) != this->mCol) {
			gBoard->mBrd[x_i + 1][y_i - 2].setActive(true);
		}
	}
}