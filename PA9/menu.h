#pragma once
#include "chess.h"

class Menu
{
public:
	
	int displaymenu();
	void wrap();
	void runitback();
	int validate(int val, int lb, int ub);
};

