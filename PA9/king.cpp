#include "king.h"

King::King(Col c, vector<int> p)
{
	this->mCol = c;
	this->mPos = p;
	this->mType = KING;
}

King::King(const King& copy)
{
	*this = copy;
}

King::~King()
{
}

King& King::operator=(const King& copy)
{
	this->mCol = copy.mCol;
	this->mPos = copy.mPos;

	return *this;
}

void King::fvm(Board* gBoard)
{
	int x_i = this->mPos[0], y_i = this->mPos[1];//set x and y to piece positions

	//Checking above
	if (y_i + 1 < 8) {
		if (gBoard->check(x_i, y_i + 1) == NUL || gBoard->check(x_i, y_i + 1) != this->mCol) {
			gBoard->mBrd[x_i][y_i + 1].setActive(true);
		}
	}

	//Checking below
	if (y_i - 1 >= 0) {
		if (gBoard->check(x_i, y_i - 1) == NUL || gBoard->check(x_i, y_i - 1) != this->mCol) {
			gBoard->mBrd[x_i][y_i - 1].setActive(true);
		}
	}

	//Checking right
	if (x_i + 1 < 8) {
		if (gBoard->check(x_i + 1, y_i) == NUL || gBoard->check(x_i + 1, y_i) != this->mCol) {
			gBoard->mBrd[x_i + 1][y_i].setActive(true);
		}
	}
	//Checking left
	if (x_i - 1 >= 0) {
		if (gBoard->check(x_i - 1, y_i) == NUL || gBoard->check(x_i - 1, y_i) != this->mCol) {
			gBoard->mBrd[x_i - 1][y_i].setActive(true);
		}
	}

	//Checking top-right
	if (y_i + 1 < 8 && x_i + 1 < 8) {
		if (gBoard->check(x_i + 1, y_i + 1) == NUL || gBoard->check(x_i + 1, y_i + 1) != this->mCol) {
			gBoard->mBrd[x_i + 1][y_i + 1].setActive(true);
		}
	}

	//Checking top-left
	if ((y_i + 1 < 8) && (x_i - 1 >= 0)) {
		if (gBoard->check(x_i - 1, y_i + 1) == NUL || gBoard->check(x_i - 1, y_i + 1) != this->mCol) {
			gBoard->mBrd[x_i - 1][y_i + 1].setActive(true);
		}
	}

	//Checking bottom-right
	if ((y_i - 1 >= 0) && (x_i + 1 < 8)) {
		if (gBoard->check(x_i + 1, y_i - 1) == NUL || gBoard->check(x_i + 1, y_i - 1) != this->mCol) {
			gBoard->mBrd[x_i + 1][y_i - 1].setActive(true);
		}
	}

	//Checking bottom-left
	if ((y_i - 1 >= 0) && (x_i - 1 >= 0)) {
		if (gBoard->check(x_i - 1, y_i - 1) == NUL || gBoard->check(x_i - 1, y_i - 1) != this->mCol) {
			gBoard->mBrd[x_i - 1][y_i - 1].setActive(true);
		}
	}

	
}
