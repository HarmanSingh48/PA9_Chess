#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/Graphics/Text.hpp>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;
using std::vector;

using sf::Vector2i;
using sf::Sprite;
using sf::Event;
using sf::Mouse;
using sf::Texture;

#define SIZE 8

typedef enum color
{
	NUL = -1, BLACK = 0, WHITE = 1
}Col;

typedef enum pa {  // Piece alias

	UNDEF = -1, APAWN = 0, BPAWN = 1, CPAWN = 2, DPAWN = 3, EPAWN = 4, FPAWN = 5, GPAWN = 6, HPAWN = 7,
	KSRK = 8, QSRK = 9, KSB = 10, QSB = 11, KSKN = 12, QSKN = 13, KING = 14, QUEEN = 15
}PA;

class Board;

class Piece
{
public:

	Col mCol;
	vector<int> mPos;
	PA mType;
	Texture mTex;
	Sprite mSpr;

	Piece(Col col = NUL, vector<int> pos = { 0,0 });
	virtual void fvm(Board* gBoard) = 0;
};