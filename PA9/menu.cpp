#include "menu.h"


int Menu::displaymenu()
{
	int choice = 0;


	cout << "Welcome to Chess!" << endl << "Main Menu:" << endl << "1. Play" << endl << "2. Instructions" << endl << "3. Exit" << endl;
	cin >> choice;

	this->validate(choice, 1, 3);

	return choice;
}

int Menu::validate(int val, int lb, int ub)
{
	while (!cin.good() || (val < lb || val > ub)) 
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input, please try again." << endl;
		cin >> val;
	}
	return val;
}

void Menu::wrap()
{
	bool exit = false;

	while (!exit)
	{
		switch (this->displaymenu())
		{
		case 1://Play
			this->runitback();
			break;
		case 2://Instructions
			cout << "Instructions:" << endl << "1. This is a 2-Player game. The two sides available are: black and white. White player goes first" << endl << "2. Once a color makes a move, the turn switches to the other player." << endl;
			cout << "3. When it is your turn, click on a piece. All possible places that the piece can move to will turn blue" << endl << "4. This is not a chess lesson. That costs extra." << endl;
			break;
		case 3://exit
			exit = true;
			break;

		}
	}
}

void Menu::runitback()
{
	Chess c;
	c.play();
}