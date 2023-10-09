#include "rook.h"

Rook::Rook(Col c, vector<int> p)
{
	this->mCol = c;
	this->mPos = p;
	this->mType = UNDEF;
}

Rook::Rook(const Rook& copy)
{
	*this = copy;
}

Rook::~Rook()
{ }

Rook& Rook::operator = (const Rook& copy)
{
	this->mCol = copy.mCol;
	this->mPos = copy.mPos;

	return *this;
}


void Rook::fvm(Board* gBoard)
{
	int x_i = 0, y_i = 0;
	Col c = this->mCol;
	bool flag = false;

	// checks valid moves above Rook
	for (x_i = this->mPos.at(0), y_i = this->mPos.at(1) + 1; y_i < SIZE && !flag &&
		(gBoard->mBrd[x_i][y_i].getocc() == nullptr || gBoard->mBrd[x_i][y_i].getocc()->mCol != c); ++y_i)
	{
		gBoard->mBrd[x_i][y_i].setActive(true);
		if (gBoard->check(x_i, y_i) != NUL)
			flag = true;
		
	}
	// checks valid moves below Rook
	for (x_i = this->mPos.at(0), y_i = this->mPos.at(1) - 1, flag = false; y_i >= 0 && !flag &&
		(gBoard->mBrd[x_i][y_i].getocc() == nullptr || gBoard->mBrd[x_i][y_i].getocc()->mCol != c); --y_i)
	{
		gBoard->mBrd[x_i][y_i].setActive(true);
		if (gBoard->check(x_i, y_i) != NUL)
			flag = true;
		
	}
	// checks valid moves right of Rook
	for (x_i = this->mPos.at(0) + 1, y_i = this->mPos.at(1), flag = false; x_i < SIZE && !flag &&
		(gBoard->mBrd[x_i][y_i].getocc() == nullptr || gBoard->mBrd[x_i][y_i].getocc()->mCol != c); ++x_i)
	{
		gBoard->mBrd[x_i][y_i].setActive(true);
		if (gBoard->check(x_i, y_i) != NUL)
			flag = true;
	}
	// checks valid moves left of Rook
	for (x_i = this->mPos.at(0) - 1, y_i = this->mPos.at(1), flag = false; x_i >= 0 && !flag &&
		(gBoard->mBrd[x_i][y_i].getocc() == nullptr || gBoard->mBrd[x_i][y_i].getocc()->mCol != c); --x_i)
	{
		gBoard->mBrd[x_i][y_i].setActive(true);
		if (gBoard->check(x_i, y_i) != NUL)
			flag = true;
	}
}