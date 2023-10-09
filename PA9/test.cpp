#include "test.h"


Test::Test()
{
	
}

void Test::TestActive()
{
	this->c.b.mBrd[0][0].setActive(true);
	if (this->c.b.mBrd[0][0].getActive())
	{
		cout << "Setting to true works!" << endl;
	}
	else cout << "Failed to set to true" << endl;

	this->c.b.mBrd[0][0].setActive(false);
	if (!this->c.b.mBrd[0][0].getActive())
	{
		cout << "Setting to false works!" << endl;
	}
	else cout << "Setting to false failed" << endl;
}

void Test::Testocc()
{
	this->c.b.mBrd[0][0].setocc(new King);
	this->c.b.mBrd[0][0].getocc()->mType = KING;

	if (this->c.b.mBrd[0][0].getocc()->mType == KING)
	{
		cout << "Setting the King worked!" << endl;
	}
	else cout << "Failed to set king" << endl;

	this->c.b.mBrd[0][5].setocc(new Rook);
	this->c.b.mBrd[0][5].getocc()->mType = QSRK;
	if (this->c.b.mBrd[0][5].getocc()->mType == QSRK)
	{
		cout << "Setting the Rook worked!" << endl;
	}
	else cout << "Failed to set rook." << endl;
}

void Test::TestWipe()
{
	this->c.b.mBrd[5][4].setActive(true);
	this->c.b.mBrd[7][7].setActive(true);
	this->c.b.mBrd[1][6].setActive(true);
	this->c.b.mBrd[3][0].setActive(true);
	this->c.wipe();

	if (this->c.b.mBrd[5][4].getActive() == false)
		cout << "Wipe: 1/4 passed" << endl;
	if (this->c.b.mBrd[7][7].getActive() == false)
		cout << "Wipe: 2/4 passed" << endl;
	if (this->c.b.mBrd[1][6].getActive() == false)
		cout << "Wipe: 3/4 passed" << endl;
	if (this->c.b.mBrd[3][0].getActive() == false)
		cout << "Wipe: 4/4 passed" << endl;
}

void Test::TestCheck(){
	if(this->c.b.check(0,1) == WHITE){
		cout << "Check Test for White passed" << endl;
	}
	else cout << "Check Test for White failed" << endl;
	if(this->c.b.check(0,6) == BLACK){
		cout << "Check Test for Black passed" << endl;
	}
	else cout << "Check Test for Black failed" << endl;

}

void Test::Tmove()
{
	this->c.move(this->c.b.mBrd[5][1].getocc(), this->c.b.mBrd[5][3], 5, 3);

	if (this->c.b.mBrd[5][3].getocc() != nullptr)
		cout << "Moved successfully to new space" << endl;
	else cout << "Did not successfully move to new space." << endl;

	if (this->c.b.mBrd[5][1].getocc() == nullptr)
		cout << "Piece no longer in previous position." << endl;
	else cout << "Piece in two positions at once." << endl;
}