#pragma once

#include"piece.h"

class Tile : public sf::RectangleShape  //dylan
{
protected:

	Piece* mOcc; // Occupant
	bool mActive;

public:

	Tile(Piece* p = nullptr);
	Tile(const Tile& cpy);
	~Tile();
	Tile& operator=(const Tile& cpy);

	Piece* getocc();
	void setocc(Piece* p);

	bool getActive();
	void setActive(bool nActive);

};