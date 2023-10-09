#include "bishop.h"


Bishop::Bishop(Col col, vector<int> p)
{
	this->mCol = col;
	this->mPos = p;
	this->mType = UNDEF;

}


Bishop::Bishop(const Bishop& cpy)
{
	*this = cpy;
}

Bishop::~Bishop()
{

}

Bishop& Bishop::operator=(const Bishop& cpy)
{
	this->mCol = cpy.mCol;
	this->mPos = cpy.mPos;

	return *this;
}

void Bishop::fvm(Board* gBoard)
{
	int x_i = 0, y_i = 0;
	bool flag = false;
	Col c = this->mCol;

	

	//diagonal: up-right
	for (x_i = this->mPos.at(0) + 1, y_i = this->mPos.at(1) + 1; x_i < SIZE && y_i < SIZE && !flag
		&& (gBoard->mBrd[x_i][y_i].getocc() == nullptr || gBoard->mBrd[x_i][y_i].getocc()->mCol != c); ++x_i, ++y_i)
	{
		gBoard->mBrd[x_i][y_i].setActive(true);
		if (gBoard->check(x_i, y_i) != NUL)
			flag = true;

	}

	//diagonal: down-right
	for (x_i = this->mPos.at(0) + 1, y_i = this->mPos.at(1) - 1, flag = false; x_i < SIZE && y_i >= 0 && !flag &&
		(gBoard->mBrd[x_i][y_i].getocc() == nullptr || gBoard->mBrd[x_i][y_i].getocc()->mCol != c); ++x_i, --y_i)
	{

		gBoard->mBrd[x_i][y_i].setActive(true);
		if (gBoard->check(x_i, y_i) != NUL)
			flag = true;
	}
	//diagonal: up-left
	for (x_i = this->mPos.at(0) - 1, y_i = this->mPos.at(1) + 1, flag = false; x_i >= 0 && y_i < SIZE && !flag &&
		(gBoard->mBrd[x_i][y_i].getocc() == nullptr || gBoard->mBrd[x_i][y_i].getocc()->mCol != c); --x_i, ++y_i)
	{
		gBoard->mBrd[x_i][y_i].setActive(true);
		if (gBoard->check(x_i, y_i) != NUL)
			flag = true;
	}

	//diagonal: down-left
	for (x_i = this->mPos.at(0) - 1, y_i = this->mPos.at(1) - 1, flag = false; x_i >= 0 && y_i >= 0 && !flag &&
		(gBoard->mBrd[x_i][y_i].getocc() == nullptr || gBoard->mBrd[x_i][y_i].getocc()->mCol != c); --x_i, --y_i)
	{
		gBoard->mBrd[x_i][y_i].setActive(true);
		if (gBoard->check(x_i, y_i) != NUL)
			flag = true;
	}

}
