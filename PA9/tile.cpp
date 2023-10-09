#include "board.h"


Tile::Tile(Piece* p)
{
	this->mOcc = p;
	this->setFillColor(sf::Color::Blue);
	this->setSize(sf::Vector2f(100, 100));
	this->mActive = false;
}

Tile::Tile(const Tile& cpy)
{
	*this = cpy;
}

Tile::~Tile()
{

}

Tile& Tile::operator=(const Tile& cpy)
{
	this->mOcc = cpy.mOcc;

	return *this;
}

Piece* Tile::getocc()
{
	return this->mOcc;
}

void Tile::setocc(Piece* p)
{
	this->mOcc = p;
}

bool Tile::getActive()
{
	return this->mActive;
}

void Tile::setActive(bool nActive)
{
	this->mActive = nActive;
}