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

int main()
{
	char cTab[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };		//game board
	char *cBoard = cTab;
	char cChoice;

	::cSymbol = 'O';

	do
	{
		cout << "--------------------------------------\n"
			<< "|.....:::::TIC TAC TOE GAME:::::.....|\n"
			<< "--------------------------------------\n";

		resetGameBoard(cBoard);		//reset game

		while (checkWin(cBoard, 'X', false) == false && checkWin(cBoard, 'O', false) == false && deadHeat(cBoard, false) == false)
		{
			round(cBoard, cSymbol);
		};

		cout << "You want to play again? Y? N?\n";
		cin >> cChoice;
	}
	while ((cChoice == 'Y') || (cChoice == 'y'));

	system("pause");
	return 0;
}
