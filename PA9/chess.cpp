#include "chess.h"


Chess::Chess()
{
	// Player 1 pieces

	this->p1Arr = new Piece * [16];
	int i = 0;
	for (; i < 8; ++i)
	{
		this->p1Arr[i] = new Pawn();
		this->p1Arr[i]->mType = static_cast<PA>(i);
		this->p1Arr[i]->mTex.loadFromFile("w_pawn.png");
		this->p1Arr[i]->mSpr.setTexture(this->p1Arr[i]->mTex);
		this->p1Arr[i]->mCol = WHITE;
	}
	while (i < 10)
	{
		this->p1Arr[i] = new Rook();
		this->p1Arr[i]->mType = static_cast<PA>(i);
		this->p1Arr[i]->mTex.loadFromFile("w_rook.png");
		this->p1Arr[i]->mSpr.setTexture(this->p1Arr[i]->mTex);
		this->p1Arr[i]->mCol = WHITE;
		++i;
	}
	while (i < 12)
	{
		this->p1Arr[i] = new Bishop();
		this->p1Arr[i]->mType = static_cast<PA>(i);
		this->p1Arr[i]->mTex.loadFromFile("w_bishop.png");
		this->p1Arr[i]->mSpr.setTexture(this->p1Arr[i]->mTex);
		this->p1Arr[i]->mCol = WHITE;
		++i;
	}
	while (i < 14)
	{
		this->p1Arr[i] = new Knight();
		this->p1Arr[i]->mType = static_cast<PA>(i);
		this->p1Arr[i]->mTex.loadFromFile("w_knight.png");
		this->p1Arr[i]->mSpr.setTexture(this->p1Arr[i]->mTex);
		this->p1Arr[i]->mCol = WHITE;
		++i;
	}
	this->p1Arr[i] = new King();
	this->p1Arr[i]->mType = KING;
	this->p1Arr[i]->mTex.loadFromFile("w_king.png");
	this->p1Arr[i]->mSpr.setTexture(this->p1Arr[i]->mTex);
	this->p1Arr[i]->mCol = WHITE;
	++i;
	this->p1Arr[i] = new Queen();
	this->p1Arr[i]->mType = QUEEN;
	this->p1Arr[i]->mTex.loadFromFile("w_queen.png");
	this->p1Arr[i]->mSpr.setTexture(this->p1Arr[i]->mTex);
	this->p1Arr[i]->mCol = WHITE;

	// Player 2 pieces

	this->p2Arr = new Piece * [16];
	i = 0;
	for (; i < 8; ++i)
	{
		this->p2Arr[i] = new Pawn();
		this->p2Arr[i]->mType = static_cast<PA>(i);
		this->p2Arr[i]->mTex.loadFromFile("b_pawn.png");
		this->p2Arr[i]->mSpr.setTexture(this->p2Arr[i]->mTex);
		this->p2Arr[i]->mCol = BLACK;
	}
	while (i < 10)
	{
		this->p2Arr[i] = new Rook();
		this->p2Arr[i]->mType = static_cast<PA>(i);
		this->p2Arr[i]->mTex.loadFromFile("b_rook.png");
		this->p2Arr[i]->mSpr.setTexture(this->p2Arr[i]->mTex);
		this->p2Arr[i]->mCol = BLACK;
		++i;
	}
	while (i < 12)
	{
		this->p2Arr[i] = new Bishop();
		this->p2Arr[i]->mType = static_cast<PA>(i);
		this->p2Arr[i]->mTex.loadFromFile("b_bishop.png");
		this->p2Arr[i]->mSpr.setTexture(this->p2Arr[i]->mTex);
		this->p2Arr[i]->mCol = BLACK;
		++i;
	}
	while (i < 14)
	{
		this->p2Arr[i] = new Knight();
		this->p2Arr[i]->mType = static_cast<PA>(i);
		this->p2Arr[i]->mTex.loadFromFile("b_knight.png");
		this->p2Arr[i]->mSpr.setTexture(this->p2Arr[i]->mTex);
		this->p2Arr[i]->mCol = BLACK;
		++i;
	}
	this->p2Arr[i] = new King();
	this->p2Arr[i]->mType = KING;
	this->p2Arr[i]->mTex.loadFromFile("b_king.png");
	this->p2Arr[i]->mSpr.setTexture(this->p2Arr[i]->mTex);
	this->p2Arr[i]->mCol = BLACK;
	++i;
	this->p2Arr[i] = new Queen();
	this->p2Arr[i]->mType = QUEEN;
	this->p2Arr[i]->mTex.loadFromFile("b_queen.png");
	this->p2Arr[i]->mSpr.setTexture(this->p2Arr[i]->mTex);
	this->p2Arr[i]->mCol = BLACK;


	Board b;
	this->b = b;

	//White

	for (i = 0; i < SIZE; ++i)
	{
		this->b.mBrd[i][1].setocc(p1Arr[i]);
		p1Arr[i]->mPos = { i, 1 };
		p1Arr[i]->mSpr.setPosition(sf::Vector2f((i * 100) + 8, 700 - 100));
	}

	this->b.mBrd[0][0].setocc(p1Arr[KSRK]); // rook
	p1Arr[8]->mPos = { 0, 0 };
	p1Arr[8]->mSpr.setPosition(sf::Vector2f(0 + 5, 700 - 0));

	this->b.mBrd[7][0].setocc(p1Arr[QSRK]);
	p1Arr[9]->mPos = { 7, 0 };
	p1Arr[9]->mSpr.setPosition(sf::Vector2f(700 + 5, 700 - 0));

	this->b.mBrd[1][0].setocc(p1Arr[KSKN]); // knight
	p1Arr[10]->mPos = { 2, 0 };
	p1Arr[10]->mSpr.setPosition(sf::Vector2f(200, 700 - 0));

	this->b.mBrd[6][0].setocc(p1Arr[QSKN]);
	p1Arr[11]->mPos = { 5, 0 };
	p1Arr[11]->mSpr.setPosition(sf::Vector2f(500, 700 - 0));

	this->b.mBrd[2][0].setocc(p1Arr[KSB]); // bishop
	p1Arr[12]->mPos = { 1, 0 };
	p1Arr[12]->mSpr.setPosition(sf::Vector2f(100, 700 - 0));

	this->b.mBrd[5][0].setocc(p1Arr[QSB]);
	p1Arr[13]->mPos = { 6, 0 };
	p1Arr[13]->mSpr.setPosition(sf::Vector2f(600, 700 - 0));

	this->b.mBrd[3][0].setocc(p1Arr[QUEEN]);
	p1Arr[15]->mPos = { 3, 0 };
	p1Arr[15]->mSpr.setPosition(sf::Vector2f(300, 700 - 0 + 8));

	this->b.mBrd[4][0].setocc(p1Arr[KING]);
	p1Arr[14]->mPos = { 4, 0 };
	p1Arr[14]->mSpr.setPosition(sf::Vector2f(400, 700 - 0));

	// Black

	for (i = 0; i < SIZE; ++i)
	{
		this->b.mBrd[i][6].setocc(p2Arr[i]);
		p2Arr[i]->mPos = { i, 6 };
		p2Arr[i]->mSpr.setPosition(sf::Vector2f((i * 100) + 8, 700 - 600));
	}

	this->b.mBrd[0][7].setocc(p2Arr[KSRK]);
	p2Arr[8]->mPos = { 0, 7 };
	p2Arr[8]->mSpr.setPosition(sf::Vector2f(0 + 5, 700 - 700));

	this->b.mBrd[7][7].setocc(p2Arr[QSRK]);
	p2Arr[9]->mPos = { 7, 7 };
	p2Arr[9]->mSpr.setPosition(sf::Vector2f(700 + 5, 700 - 700));

	this->b.mBrd[2][7].setocc(p2Arr[KSB]);
	p2Arr[10]->mPos = { 2, 7 };
	p2Arr[10]->mSpr.setPosition(sf::Vector2f(200, 700 - 700));

	this->b.mBrd[5][7].setocc(p2Arr[QSB]);
	p2Arr[11]->mPos = { 5, 7 };
	p2Arr[11]->mSpr.setPosition(sf::Vector2f(500, 700 - 700));

	this->b.mBrd[1][7].setocc(p2Arr[KSKN]);
	p2Arr[12]->mPos = { 1, 7 };
	p2Arr[12]->mSpr.setPosition(sf::Vector2f(100, 700 - 700));

	this->b.mBrd[6][7].setocc(p2Arr[QSKN]);
	p2Arr[13]->mPos = { 6, 7 };
	p2Arr[13]->mSpr.setPosition(sf::Vector2f(600, 700 - 700));

	this->b.mBrd[3][7].setocc(p2Arr[QUEEN]);
	p2Arr[15]->mPos = { 3, 7 };
	p2Arr[15]->mSpr.setPosition(sf::Vector2f(300, 700 - 700 + 8));

	this->b.mBrd[4][7].setocc(p2Arr[KING]);
	p2Arr[14]->mPos = { 4, 7 };
	p2Arr[14]->mSpr.setPosition(sf::Vector2f(400, 700 - 700));

}

Chess::~Chess()
{
	for (int i = 0; i < 16; ++i)
	{
		delete p1Arr[i];
		delete p2Arr[i];
	}
	delete[]p1Arr;
	delete[]p2Arr;
}

void Chess::play()
{
	int size = 100;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game");
	sf::Image winIcon;
	winIcon.loadFromFile("chessicon.png");

	window.setIcon(winIcon.getSize().x, winIcon.getSize().y, winIcon.getPixelsPtr());
	int i = 0;

	int mx = 0, my = 0;
	int tx = 0, ty = 0;
	Piece* tmpPiece = nullptr;
	Col turn = WHITE;
	bool checkmate = false;

	while (window.isOpen())
	{
		sf::Vector2i pos = Mouse::getPosition(window);
		Event e;
		sf::RectangleShape checksq;
		checksq.setSize(sf::Vector2f(100, 100));
		checksq.setFillColor(sf::Color::Red);
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			window.clear();
			if ((this->p1Arr[KING]->mPos.at(0) == -1) || (this->p2Arr[KING]->mPos.at(0) == -1))
			{
				sf::RectangleShape message;
				Texture txt;
				txt.loadFromFile("Game Over Message.png");
				message.setTexture(&txt);
				message.setSize(sf::Vector2f(600, 400));
				message.setPosition(sf::Vector2f(100, 200));
				window.draw(message);
				window.display();
				checkmate = true;
				if (e.type == sf::Event::KeyPressed)
					window.close();

			}
		}

		if(this->p1Arr[KING]->mPos[0] != -1 && this->p2Arr[KING]->mPos[0] != -1)
		{
			
			window.draw(this->b);
			if (this->b.c4c(this->p1Arr[KING]->mPos[0], this->p1Arr[KING]->mPos[1], WHITE))
			{
				checksq.setPosition(sf::Vector2f(this->p1Arr[KING]->mPos.at(0) * 100, 700 - this->p1Arr[KING]->mPos.at(1) * 100));
				window.draw(checksq);
			}
			else if (this->b.c4c(this->p2Arr[KING]->mPos[0], this->p2Arr[KING]->mPos[1], BLACK))
			{
				checksq.setPosition(sf::Vector2f(this->p2Arr[KING]->mPos.at(0) * 100, 700 - this->p2Arr[KING]->mPos.at(1) * 100));
				window.draw(checksq);
			}
			if (e.type == sf::Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == sf::Mouse::Left)
				{
					mx = e.mouseButton.x;
					my = e.mouseButton.y;
					tx = mx / size;
					ty = 7 - my / size;

					if (this->b.mBrd[tx][ty].getActive() == true)
					{
						wipe();
						move(tmpPiece, this->b.mBrd[tx][ty], tx, ty);
						(turn == WHITE) ? turn = BLACK : turn = WHITE;
					}
					else
					{
						if (this->b.mBrd[tx][ty].getocc() != nullptr)
						{
							if (this->b.mBrd[tx][ty].getocc()->mCol == turn)
							{
								tmpPiece = this->b.mBrd[tx][ty].getocc();
								wipe();
								(*tmpPiece).fvm(&this->b);
							}
							else
							{
								tmpPiece = nullptr;
								wipe();
							}
						}
						else
						{
							tmpPiece = nullptr;
							wipe();
						}
					}
				}
			}
			this->hilight(window);
			for (i = 0; i < 16; ++i)
			{
				window.draw(this->p1Arr[i]->mSpr);
			}
			for (i = 0; i < 16; ++i)
			{
				window.draw(this->p2Arr[i]->mSpr);
			}
			window.display();
		}
	}
}


void Chess::hilight(sf::RenderWindow& window)
{

	for (int i = 0, j = 0; i < SIZE; ++i)
	{
		for (j = 0; j < SIZE; ++j)
		{
			if(this->b.mBrd[i][j].getActive())
				window.draw(this->b.mBrd[i][j]);
		}
	}
}

void Chess::wipe()
{
	for (int i = 0, j = 0; i < SIZE; ++i)
	{
		for (j = 0; j < SIZE; ++j)
		{
			this->b.mBrd[i][j].setActive(false);
		}
	}
}

void Chess::move(Piece* moving, Tile& moveto, int tx, int ty)
{
	int tmpX = moving->mPos.at(0), tmpY = moving->mPos.at(1);
	if (moveto.getocc() != nullptr)
	{
		Piece* temp = moveto.getocc();
		temp->mPos = { -1, -1 };
		temp->mSpr.setPosition(sf::Vector2f(-100, -100));
	}

	moveto.setocc(moving);
	moveto.getocc()->mPos = { tx, ty };
	if (moving->mType == APAWN || moving->mType == BPAWN || moving->mType == CPAWN || moving->mType == DPAWN || 
		moving->mType == EPAWN || moving->mType == FPAWN || moving->mType == GPAWN || moving->mType == HPAWN)
	{
		moveto.getocc()->mSpr.setPosition(static_cast<float>(tx * 100+ 8), static_cast<float>(700 - ty * 100));
	}
	else if (moving->mType == QSRK || moving->mType == KSRK)
	{
		moveto.getocc()->mSpr.setPosition(static_cast<float>(tx * 100 + 8), static_cast<float>(700 - ty * 100));
	}
	else if (moving->mType == QUEEN)
	{
		moveto.getocc()->mSpr.setPosition(static_cast<float>(tx * 100 + 8), static_cast<float>(700 - ty * 100));
	}
	else
	{
		moveto.getocc()->mSpr.setPosition(static_cast<float>(tx * 100), static_cast<float>(700 - ty * 100));
	}
	this->b.mBrd[tmpX][tmpY].setocc(nullptr);
}