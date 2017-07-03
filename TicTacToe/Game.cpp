/**********************************************************************
* Project           : TicTacToe
* File name			: Game.cpp
* Author			: Dawid_Wilk
* Date created		: 20170327
* Purpose			: Game algorithm
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*20170416	  DW		  1.0	 Use in minMax One-Dimensional Array.
*20170416	  DW		  1.0	 Use in computerMove One-Dimensional Array.
*20170416	  DW		  1.0	 Use in round One-Dimensional Array.
*20170501	  DW		  1.1	 Version 1.1.
**********************************************************************/

#include <iostream>

using namespace std;

#include "Game.h"
#include "Define.h"

/**********************************************************************
MiniMax recursion algorithm.
Algorithm find the best computer move.
'symbol' = actual player
**********************************************************************/
int Game::minMax(char *cBoard, char cSymbol)
{
	int iTemp;					//Temp variable
	int iMaxScore;				//Maximal move score
	
	//Check that current player win, if yes, return his best score
	if (CheckBoard::checkWin(cBoard, cSymbol, true))
	{
		return (cSymbol == CHAR_X) ? ONE : MONE;
	}

	//Check that is no Dead Heat, if yes, return 0
	if (CheckBoard::deadHeat(cBoard, true))
	{
		return 0;
	}

	//Change current player, to opposite player
	cSymbol = (cSymbol == CHAR_X) ? CHAR_O : CHAR_X;

	//Algorithm analyze player move and move opposite player,
	//for player calculate maximum game score, and for opposite player
	//calculate minimum score:
	//X - calculate max -> iMaxScore = -10
	//O - calculate min -> iMaxScore =  10
	iMaxScore = (cSymbol == CHAR_O) ? TEN : MTEN;

	//Algorithm looking for free field, and set player symbol, then calculate
	//the best move using recursion

	for (int i = 0; i < 9; i++)
	{
		if (*(cBoard + i) == ' ')
		{
			*(cBoard + i) = cSymbol;
			iTemp = minMax(cBoard, cSymbol);
			*(cBoard + i) = ' ';
			if (((cSymbol == CHAR_O) && (iTemp < iMaxScore)) || ((cSymbol == CHAR_X) && (iTemp > iMaxScore)))
			{
				iMaxScore = iTemp;
			}
		}
	}

	return iMaxScore;
}

/**********************************************************************
Function return computer move.
**********************************************************************/
int Game::computerMove(char *cBoard)
{
	int iMaxScore;				//Maximal move score
	int iTemp;					//Temp variable
	int iMove;					//Computer and player move

	iMaxScore = MTEN;			//Set score to min value

	for (int i = 0; i < 9; i++)
    {
        if (*(cBoard + i) == ' ')
        {
            *(cBoard + i) = CHAR_X;
            iTemp = minMax(cBoard, CHAR_X);
            *(cBoard + i) = ' ';
            if (iTemp > iMaxScore)
            {
                iMaxScore = iTemp;
                iMove = i;
            }
        }
    }

	return iMove;				//Return computer move
}

/**********************************************************************
Function return player move.
**********************************************************************/
void Game::round(char *cBoard, char &cSymbol)
{
	int iMove = ZERO;				//Reset player move

	//Show game board
	BoardDraw::drawGameBoard(cBoard);

	//Player move
	if (cSymbol == CHAR_O)
	{
		bool correct;

		do
		{
			cout << "Player\n";
			cout << "Please specify coordinates your move: \n";
			cin >> iMove;

			//Check player move
			correct = CheckBoard::checkBoardField(iMove, cBoard);
	
		} while (!correct);

		*(cBoard + iMove) = cSymbol;
	}
	//Computer move
	else
	{
		iMove = computerMove(cBoard);

		//Check computer move
		if ((iMove >= 0) && (iMove <= 8) && (*(cBoard + iMove) == ' '))
		{
			*(cBoard + iMove) = cSymbol;
		}
	}
	//Change player
	cSymbol = (cSymbol == CHAR_O) ? CHAR_X : CHAR_O;

	//Clean console
    system(CLEAR);
}






