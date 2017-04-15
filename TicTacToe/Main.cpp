/**********************************************************************
* Project           : TicTacToe
*
* Program name		: TicTacToe.cpp
*
* Author			: Dawid_Wilk
*
* Date created		: 20170326
*
* Purpose			: Test minmax algorithm.
*
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*
*
**********************************************************************/


#include <iostream>
using namespace std;

#include "Header.h"

char cSymbol;
int *iMove = new int[2];

int main()
{
	char iBoard[5][5];
	

	::cSymbol = 'O';
	drawGameBoard(iBoard);

	while (checkWin(iBoard, cSymbol) == false && deadHeat(iBoard) == true) round(iBoard, cSymbol);

	if (checkWin(iBoard, cSymbol) == true)
	{
		cout << "You win! player: " << cSymbol << ":)\n";
	}
	else if (deadHeat(iBoard) == true)
	{
		cout << "Dead Heat! ;p\n";
	}
	else
	{
		cout << "You lose :(\n";
	}
	
	system("pause");
	return 0;
}
