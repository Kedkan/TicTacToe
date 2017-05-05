/**********************************************************************
* Project           : TicTacToe
* Program name		: TicTacToe.cpp
* Author			: Dawid_Wilk
* Date created		: 20170326
* Purpose			: Test minmax algorithm
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*20170501	  DW		  1.1	 Version 1.1.
**********************************************************************/


#include <iostream>
using namespace std;

#include "BoardDraw.h"
#include "Game.h"


int main()
{
	char cTab[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };		//Default game board
	char *cBoard = cTab;
	char cChoice;												//Player choice after win/lose game
	char cSymbol = 'O';											//Default game char
	Game Tgame;													//Game one

	do
	{
		cout << "--------------------------------------\n"
			<< "|.....:::::TIC TAC TOE GAME:::::.....|\n"
			<< "--------------------------------------\n";

		BoardDraw::resetGameBoard(cBoard);		//reset game

		while (CheckBoard::checkWin(cBoard, 'X', false) == false && CheckBoard::checkWin(cBoard, 'O', false) == false && CheckBoard::deadHeat(cBoard, false) == false)
		{
			Tgame.round(cBoard, cSymbol);
		};

		cout << "You want to play again? Y? N?\n";
		cin >> cChoice;
	}
	while ((cChoice == 'Y') || (cChoice == 'y'));

	system("pause");
	return 0;
}
