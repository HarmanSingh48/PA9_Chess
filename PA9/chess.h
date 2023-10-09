#pragma once
#include"bishop.h"
#include"king.h"
#include"knight.h"
#include"pawn.h"
#include"queen.h"
#include"rook.h"


/*
Harman:
Tyler:
Dylan:
*/




class Chess
{
	friend class Test;
private:
	Board b;
	Piece** p1Arr;
	Piece** p2Arr;
public:
	Chess();
	~Chess();
	//int** fvm(Piece* temp);
	void play();
	void hilight(sf::RenderWindow& window);
	void wipe();
	void move(Piece* moving, Tile& moveto, int tx, int ty);
	void Run();
	int menu();
};
