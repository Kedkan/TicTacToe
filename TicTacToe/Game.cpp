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

/**********************************************************************
Clean console: Windows, OS X, Linux
**********************************************************************/

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

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
		return (cSymbol == 'X') ? 1 : -1;
	}

	//Check that is no Dead Heat, if yes, return 0
	if (CheckBoard::deadHeat(cBoard, true))
	{
		return 0;
	}

	//Change current player, to opposite player
	cSymbol = (cSymbol == 'X') ? 'O' : 'X';

	//Algorithm analyze player move and move opposite player,
	//for player calculate maximum game score, and for opposite player
	//calculate minimum score:
	//X - calculate max -> iMaxScore = -10
	//O - calculate min -> iMaxScore =  10
	iMaxScore = (cSymbol == 'O') ? 10 : -10;

	//Algorithm looking for free field, and set player symbol, then calculate
	//the best move using recursion

	for (int i = 0; i < 9; i++)
	{
		if (*(cBoard + i) == ' ')
		{
			*(cBoard + i) = cSymbol;
			iTemp = minMax(cBoard, cSymbol);
			*(cBoard + i) = ' ';
			if (((cSymbol == 'O') && (iTemp < iMaxScore)) || ((cSymbol == 'X') && (iTemp > iMaxScore)))
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

	iMaxScore = -10;			//Set score to min value

	for (int i = 0; i < 9; i++)
    {
        if (*(cBoard + i) == ' ')
        {
            *(cBoard + i) = 'X';
            iTemp = minMax(cBoard, 'X');
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
	int iMove = 0;				//Reset player move

	//Show game board
	BoardDraw::drawGameBoard(cBoard);

	//Player move
	if (cSymbol == 'O')
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
	cSymbol = (cSymbol == 'O') ? 'X' : 'O';

	//Clean console
    system(CLEAR);
}






