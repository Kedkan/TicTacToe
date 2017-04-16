/**********************************************************************
* Project           		: TicTacToe
*
* File name			: Game.cpp
*
* Author			: Dawid_Wilk
*
* Date created			: 20170327
*
* Purpose			: Game algorithm.
*
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*20170416	  DW		  1.0	 Use in checkWin One-Dimensional Array.
*20170416	  DW		  1.0	 Use in deadHeat One-Dimensional Array.
*20170416	  DW		  1.0	 Use in minMax One-Dimensional Array.
*20170416	  DW		  1.0	 Use in computerMove One-Dimensional Array.
*20170416	  DW		  1.0	 Use in round One-Dimensional Array.
**********************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Header.h"


/**********************************************************************
Function return TRUE if one player wins.
**********************************************************************/

bool checkWin(char *cBoard, char symbol)
{

	//Check rows in Array, if the same, return TRUE
	for (int i = 0; i < 7; i += 3)
	{
		if ((*cBoard == symbol) && (*(cBoard + 2) == symbol) && (*(cBoard + 3) == symbol))
		{
			return true;
			break;
		}

		//Check columns in Array, if the same, return TRUE
		for (int i = 0; i < 3; i++)
		{
			if ((*cBoard == symbol) && (*(cBoard + 3) == symbol) && (*(cBoard + 6) == symbol))
			{
				return true;
				break;
			}

			//Check cross cTab[0]-cTab[4]-cTab[8]
			if ((*cBoard == symbol) && (*(cBoard + 4) == symbol) && (*(cBoard + 8) == symbol))
			{
				return true;
			}

			//Check cross cTab[6]-cTab[4]-cTab[2]
			if ((*(cBoard + 6) == symbol) && (*(cBoard + 4) == symbol) && (*(cBoard + 2) == symbol))
			{
				return true;
			}

		}
	}

	return false;
}

/**********************************************************************
Function return TRUE if Game Board is no free point and
both players doesn't win, otherwise return FALSE.
**********************************************************************/

bool deadHeat(char *cBoard)
{
	for (int i = 0; i < 9; i++)
	{
		if (*(cBoard + i) == ' ')
		{
			return false;
		}
	}

	return true;
}

/**********************************************************************
MiniMax recursion algorithm.
Algorithm find the best computer move.
'symbol' = actual player
**********************************************************************/

int minMax(char *cBoard, char symbol)
{
	int iTemp;				//Temp variable
	int iMaxScore;				//Maximal move score

	//Check that current player win, if yes, return his best score
	if (checkWin(cBoard, symbol) == true)
	{
		return (symbol == 'X') ? 1 : -1;
	}

	//Check that is no Dead Heat, if yes, return 0
	if (deadHeat(cBoard) == true)
	{
		return 0;
	}

	//Change current player, to opposite player
	symbol = (symbol == 'X') ? 'O' : 'X';

	//Algorithm analize player move and move opposite player,
	//for player calculate maximum game score, and for opposite player
	//calculate minimum score:
	//X - calculate max -> iMaxScore = -10
	//O - calculate min -> iMaxScore =  10
	iMaxScore = (symbol == 'O') ? 10 : -10;

	//Algorithm looking for free field, and set player symbol, then calculate
	//the best move using recursion

	for (int i = 0; i < 9; i++)
	{
		if (*(cBoard + i) == ' ')
		{
			*(cBoard + i) = symbol;
			iTemp = minMax(cBoard, symbol);
			*(cBoard + i) = ' ';
			if (((symbol == 'O') && (iTemp < iMaxScore)) || ((symbol == 'X') && (iTemp > iMaxScore)))
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

int computerMove(char *cBoard)
{
	int iMaxScore;				//Maximal move score
	int iTemp;				//Temp variable
	int iMove;				//Computer and player move

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

void round(char *cBoard, char &symbol)
{
	int iMove = 0;

	drawGameBoard(cBoard);			//Show game board

	//Player move
	if (symbol == 'O')
	{
		cout << "Player\n";
		cout << "Please specify coordinates your move: \n";
		cin >> iMove;
	}
	//Computer move
	else
	{
		iMove = computerMove(cBoard);
	}
	//Check condition >=0 and <=8 and == ' '
	if ((iMove >= 0) && (iMove <= 8) && (*(cBoard + iMove) == ' '))
	{
		*(cBoard + iMove) = symbol;
	}
	//Change player
	symbol = (symbol == 'O') ? 'X' : 'O';

	//Clean console
	system("cls");
}
