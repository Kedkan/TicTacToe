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
	

	BoardDraw TboardDraw;
	Game Tgame;
	CheckBoard TcheckBoard;
	CheckBoard *checkBoardField = &TcheckBoard;

	do
	{
		cout << "--------------------------------------\n"
			<< "|.....:::::TIC TAC TOE GAME:::::.....|\n"
			<< "--------------------------------------\n";

		TboardDraw.resetGameBoard(cBoard);		//reset game

		while (TcheckBoard.checkWin(cBoard, 'X', false) == false && TcheckBoard.checkWin(cBoard, 'O', false) == false && TcheckBoard.deadHeat(cBoard, false) == false)
		{
			Tgame.round(cBoard, cSymbol, checkBoardField);
		};

		cout << "You want to play again? Y? N?\n";
		cin >> cChoice;
	}
	while ((cChoice == 'Y') || (cChoice == 'y'));

	system("pause");
	return 0;
}
