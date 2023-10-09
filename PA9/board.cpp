#include "board.h"

Board::Board()
{

	this->setSize(sf::Vector2f(800, 800));
	this->setPosition(00, 00);
	this->mTex.loadFromFile("chessboard.png");
	this->setTexture(&this->mTex);

	Tile t;

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			this->mBrd[i][j] = t;
			this->mBrd[i][j].setPosition(sf::Vector2f(i * 100, 700 - j * 100));
		}
	}

}

Board::Board(const Board& cpy)
{
	*this = cpy;
}

Board::~Board()
{

}

Board& Board::operator=(const Board& cpy)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			this->mBrd[i][j] = cpy.mBrd[i][j];
		}
	}

	return *this;
}

Col Board::check(int x, int y)
{
	Col c = NUL;
	if (this->mBrd[x][y].getocc() != nullptr)
		c = this->mBrd[x][y].getocc()->mCol;

	return c;
}

bool Board::c4c(int x, int y, Col color)
{
	int xi = 0, yi = 0;
	bool check = false;
	

	// right
	for (xi = x + 1, yi = y; !check && xi < SIZE && this->check(xi, yi) == NUL; ++xi);
	if (xi < SIZE && this->check(xi, yi) != color && this->check(xi, yi) != NUL)
	{
		if (xi == x + 1 && this->mBrd[xi][yi].getocc()->mType == KING)
			check = true;
		else if (this->mBrd[xi][yi].getocc()->mType == QSRK || this->mBrd[xi][yi].getocc()->mType == KSRK || this->mBrd[xi][yi].getocc()->mType == QUEEN)
			check = true;
	}

	//left
	for (xi = x - 1, yi = y; !check && xi > -1 && this->check(xi, yi) == NUL; --xi);
	if (xi > -1 && this->check(xi, yi) != color && this->check(xi, yi) != NUL)
	{
		if (xi == x - 1 && this->mBrd[xi][yi].getocc()->mType == KING)
			check = true;
		else if (this->mBrd[xi][yi].getocc()->mType == QSRK || this->mBrd[xi][yi].getocc()->mType == KSRK || this->mBrd[xi][yi].getocc()->mType == QUEEN)
			check = true;
	}

	// up
	for (xi = x, yi = y + 1; !check && yi < SIZE && this->check(xi, yi) == NUL; ++yi);
	if (yi < SIZE && this->check(xi, yi) != color && this->check(xi, yi) != NUL)
	{
		if (yi == y + 1 && this->mBrd[xi][yi].getocc()->mType == KING)
			check = true;
		else if (this->mBrd[xi][yi].getocc()->mType == QSRK || this->mBrd[xi][yi].getocc()->mType == KSRK || this->mBrd[xi][yi].getocc()->mType == QUEEN)
			check = true;
	}

	//down
	for (xi = x, yi = y - 1; !check && yi > -1 && this->check(xi, yi) == NUL; --yi);
	if (yi > -1 && this->check(xi, yi) != color && this->check(xi, yi) != NUL)
	{
		if (yi == y - 1 && this->mBrd[xi][yi].getocc()->mType == KING)
			check = true;
		else if (this->mBrd[xi][yi].getocc()->mType == QSRK || this->mBrd[xi][yi].getocc()->mType == KSRK || this->mBrd[xi][yi].getocc()->mType == QUEEN)
			check = true;
	}


	//up and right
	for (xi = x + 1, yi = y + 1; !check && xi < SIZE && yi < SIZE && this->check(xi, yi) == NUL; ++xi, ++yi);
	if (xi < SIZE && yi < SIZE && this->check(xi, yi) != color && this->check(xi, yi) != NUL)
	{
		if (xi == x + 1 && yi == y + 1 && (this->mBrd[xi][yi].getocc()->mType == KING || (color == WHITE && (this->mBrd[xi][yi].getocc()->mType == APAWN || this->mBrd[xi][yi].getocc()->mType == BPAWN || this->mBrd[xi][yi].getocc()->mType == CPAWN || this->mBrd[xi][yi].getocc()->mType == DPAWN || this->mBrd[xi][yi].getocc()->mType == EPAWN || this->mBrd[xi][yi].getocc()->mType == FPAWN || this->mBrd[xi][yi].getocc()->mType == GPAWN || this->mBrd[xi][yi].getocc()->mType == HPAWN))))
			check = true;
		else if (this->mBrd[xi][yi].getocc()->mType == QSB || this->mBrd[xi][yi].getocc()->mType == KSB || this->mBrd[xi][yi].getocc()->mType == QUEEN)
			check = true;
	}

	//down and right
	for (xi = x + 1, yi = y - 1; !check && xi < SIZE && yi > -1 && this->check(xi, yi) == NUL; ++xi, --yi);
	if (xi < SIZE && yi > -1 && this->check(xi, yi) != color && this->check(xi, yi) != NUL)
	{
		if (xi == x + 1 && yi == y - 1 && (this->mBrd[xi][yi].getocc()->mType == KING || (color == BLACK && (this->mBrd[xi][yi].getocc()->mType == APAWN || this->mBrd[xi][yi].getocc()->mType == BPAWN || this->mBrd[xi][yi].getocc()->mType == CPAWN || this->mBrd[xi][yi].getocc()->mType == DPAWN || this->mBrd[xi][yi].getocc()->mType == EPAWN || this->mBrd[xi][yi].getocc()->mType == FPAWN || this->mBrd[xi][yi].getocc()->mType == GPAWN || this->mBrd[xi][yi].getocc()->mType == HPAWN))))
			check = true;
		else if (this->mBrd[xi][yi].getocc()->mType == QSB || this->mBrd[xi][yi].getocc()->mType == KSB || this->mBrd[xi][yi].getocc()->mType == QUEEN)
			check = true;
	}

	//up and left
	for (xi = x - 1, yi = y + 1; !check && xi > -1 && yi < SIZE && this->check(xi, yi) == NUL; --xi, ++yi);
	if (xi > -1 && yi < SIZE && this->check(xi, yi) != color && this->check(xi, yi) != NUL)
	{
		if (xi == x - 1 && yi == y + 1 && (this->mBrd[xi][yi].getocc()->mType == KING || (color == WHITE && (this->mBrd[xi][yi].getocc()->mType == APAWN || this->mBrd[xi][yi].getocc()->mType == BPAWN || this->mBrd[xi][yi].getocc()->mType == CPAWN || this->mBrd[xi][yi].getocc()->mType == DPAWN || this->mBrd[xi][yi].getocc()->mType == EPAWN || this->mBrd[xi][yi].getocc()->mType == FPAWN || this->mBrd[xi][yi].getocc()->mType == GPAWN || this->mBrd[xi][yi].getocc()->mType == HPAWN))))
			check = true;
		else if (this->mBrd[xi][yi].getocc()->mType == QSB || this->mBrd[xi][yi].getocc()->mType == KSB || this->mBrd[xi][yi].getocc()->mType == QUEEN)
			check = true;
	}

	//down and left
	for (xi = x - 1, yi = y - 1; !check && xi > -1 && yi > -1 && this->check(xi, yi) == NUL; --xi, --yi);
	if (xi > -1 && yi > -1 && this->check(xi, yi) != color && this->check(xi, yi) != NUL)
	{
		if (xi == x - 1 && yi == y - 1 && (this->mBrd[xi][yi].getocc()->mType == KING || (color == BLACK && (this->mBrd[xi][yi].getocc()->mType == APAWN || this->mBrd[xi][yi].getocc()->mType == BPAWN || this->mBrd[xi][yi].getocc()->mType == CPAWN || this->mBrd[xi][yi].getocc()->mType == DPAWN || this->mBrd[xi][yi].getocc()->mType == EPAWN || this->mBrd[xi][yi].getocc()->mType == FPAWN || this->mBrd[xi][yi].getocc()->mType == GPAWN || this->mBrd[xi][yi].getocc()->mType == HPAWN))))
			check = true;
		else if (this->mBrd[xi][yi].getocc()->mType == QSB || this->mBrd[xi][yi].getocc()->mType == KSB || this->mBrd[xi][yi].getocc()->mType == QUEEN)
			check = true;
	}


	//knight 2 r 1 u
	if (x + 2 < SIZE && y + 1 < SIZE && this->check(x + 2, y + 1) != color && this->check(x + 2, y + 1) != NUL)
	{
		if (this->mBrd[x + 2][y + 1].getocc()->mType == QSKN || this->mBrd[x + 2][y + 1].getocc()->mType == KSKN)
			check = true;
	}

	//knight 2 r 1 d
	if (x + 2 < SIZE && y - 1 > -1 && this->check(x + 2, y - 1) != color && this->check(x + 2, y - 1) != NUL)
	{
		if (this->mBrd[x + 2][y - 1].getocc()->mType == QSKN || this->mBrd[x + 2][y - 1].getocc()->mType == KSKN)
			check = true;
	}

	//knight 2 l 1 u
	if (x - 2 > -1 && y + 1 < SIZE && this->check(x - 2, y + 1) != color && this->check(x - 2, y + 1) != NUL)
	{
		if (this->mBrd[x - 2][y + 1].getocc()->mType == QSKN || this->mBrd[x - 2][y + 1].getocc()->mType == KSKN)
			check = true;
	}

	//knight 2 l 2 d
	if (x - 2 > -1 && y - 1 > -1 && this->check(x - 2, y - 1) != color && this->check(x - 2, y - 1) != NUL)
	{
		if (this->mBrd[x - 2][y - 1].getocc()->mType == QSKN || this->mBrd[x - 2][y - 1].getocc()->mType == KSKN)
			check = true;
	}

	//knight 1 r 2 u
	if (x + 1 < SIZE && y + 2 < SIZE && this->check(x + 1, y + 2) != color && this->check(x + 1, y + 2) != NUL)
	{
		if (this->mBrd[x + 1][y + 2].getocc()->mType == QSKN || this->mBrd[x + 1][y + 2].getocc()->mType == KSKN)
			check = true;
	}

	//knight 1 r 2 d
	if (x + 1 < SIZE && y - 2 > -1 && this->check(x + 1, y - 2) != color && this->check(x + 1, y - 2) != NUL)
	{
		if (this->mBrd[x + 1][y - 2].getocc()->mType == QSKN || this->mBrd[x + 1][y - 2].getocc()->mType == KSKN)
			check = true;
	}

	//knight 1 l 2 u
	if (x - 1 > -1 && y + 2 < SIZE && this->check(x - 1, y + 2) != color && this->check(x - 1, y + 2) != NUL)
	{
		if (this->mBrd[x - 1][y + 2].getocc()->mType == QSKN || this->mBrd[x - 1][y + 2].getocc()->mType == KSKN)
			check = true;
	}

	//knight 1 l 2 d
	if (x - 1 > -1 && y - 2 > -1 && this->check(x - 1, y - 2) != color && this->check(x - 1, y - 2) != NUL)
	{
		if (this->mBrd[x - 1][y - 2].getocc()->mType == QSKN || this->mBrd[x - 1][y - 2].getocc()->mType == KSKN)
			check = true;
	}

	return check;
}