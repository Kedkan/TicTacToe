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
*20170603     DW          1.1    Change IDE to CLion
**********************************************************************/


#include <iostream>
using namespace std;

#include "BoardDraw.h"
#include "Game.h"

void scoreTable(char cSymbol, int &iScorePlayer, int &iScoreComputer);

int main()
{
	char cTab[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };		//Default game board
	char *cBoard = cTab;
	char cChoice;												//Player choice after win/lose game
	char cSymbol = 'O';											//Default game char
    int  iScorePlayer = 0;                                      //Player game score
    int  iScoreComputer = 0;                                    //Computer game score
	Game Tgame;													//Game one

	do
	{
		cout << "--------------------------------------\n"
			<< "|.....:::::TIC TAC TOE GAME:::::.....|\n"
			<< "--------------------------------------\n";

		BoardDraw::resetGameBoard(cBoard);		//reset game

		while ((!CheckBoard::checkWin(cBoard, 'X', false)) && (!CheckBoard::checkWin(cBoard, 'O', false)) && (!CheckBoard::deadHeat(cBoard, false)))
		{
			Tgame.round(cBoard, cSymbol);
		};

        scoreTable(cSymbol,iScorePlayer,iScoreComputer);
		cout << "You want to play again? Y? N?\n";
        cout << cSymbol;
        cout << iScoreComputer; //to do X
		cin >> cChoice;
	}
	while ((cChoice == 'Y') || (cChoice == 'y'));


	return 0;
}

void scoreTable(char cSymbol, int & iScorePlayer, int & iScoreComputer)
{
    if (cSymbol == 'O')
    {
        iScorePlayer++;
    }
    if (cSymbol == 'X')
    {
        iScoreComputer++;
    }
}
