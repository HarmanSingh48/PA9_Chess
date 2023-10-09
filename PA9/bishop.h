#pragma once
#include"board.h"

class Bishop : public Piece //dylan
{

public:

	Bishop(Col c = NUL, vector<int> p = { -1, -1 });
	Bishop(const Bishop& cpy);
	~Bishop();
	Bishop& operator=(const Bishop& cpy);

	void fvm(Board* gBoard);

};
