/**********************************************************************
* Project           : TicTacToe
*
* File name			: Game.cpp
*
* Author			: Dawid_Wilk
*
* Date created		: 20170327
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
Function return TRUE if one player wins,
bTemp stop the infinite loop minMax and checkWin.
**********************************************************************/

bool checkWin(char *cBoard, char cSymbol, bool bTemp)
{
	bool bWin = false;		//true if player have three the same char in column, line or cross

	//Check rows in Array, if the same, return TRUE
	for (int i = 0; i < 7; i += 3)
	{
		if ((*cBoard == cSymbol) && (*(cBoard + 2) == cSymbol) && (*(cBoard + 3) == cSymbol))
		{
			bWin = true;
			break;
		}

		//Check columns in Array, if the same, return TRUE
		for (int i = 0; i < 3; i++)
		{
			if ((*cBoard == cSymbol) && (*(cBoard + 3) == cSymbol) && (*(cBoard + 6) == cSymbol))
			{
				bWin = true;
				break;
			}

			//Check cross cTab[0]-cTab[4]-cTab[8]
			if ((*cBoard == cSymbol) && (*(cBoard + 4) == cSymbol) && (*(cBoard + 8) == cSymbol))
			{
				bWin = true;
			}

			//Check cross cTab[6]-cTab[4]-cTab[2]
			if ((*(cBoard + 6) == cSymbol) && (*(cBoard + 4) == cSymbol) && (*(cBoard + 2) == cSymbol))
			{
				bWin =  true;
			}

		}
	}

	if (bWin)			//true if one player win
	{
		if (!bTemp)		//true if bWin is true
		{
			cout << "You win! player: " << cSymbol << ":)\n";
			return true;
		}
	}

	return false;
}

/**********************************************************************
Function return TRUE if Game Board is no free point and
both players doesn't win, otherwise return FALSE,
bTemp stop the infinite loop minMax and checkWin.
**********************************************************************/

bool deadHeat(char *cBoard, bool bTemp)
{
	for (int i = 0; i < 9; i++)
	{
		if (*(cBoard + i) == ' ')
		{
			return false;
		}
	}

	if (!bTemp)
	{
		cout << "Dead heat :( \n";
	}

	return true;
}

/**********************************************************************
MiniMax recursion algorithm.
Algorithm find the best computer move.
'symbol' = actual player
**********************************************************************/

int minMax(char *cBoard, char cSymbol)
{
	int iTemp;					//Temp variable
	int iMaxScore;				//Maximal move score

	//Check that current player win, if yes, return his best score
	if (checkWin(cBoard, cSymbol, true) == true)
	{
		return (cSymbol == 'X') ? 1 : -1;
	}

	//Check that is no Dead Heat, if yes, return 0
	if (deadHeat(cBoard, true) == true)
	{
		return 0;
	}

	//Change current player, to opposite player
	cSymbol = (cSymbol == 'X') ? 'O' : 'X';

	//Algorithm analize player move and move opposite player,
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

int computerMove(char *cBoard)
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

void round(char *cBoard, char &cSymbol)
{
	int iMove = 0;

	drawGameBoard(cBoard);			//Show game board

	//Player move
	if (cSymbol == 'O')
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
		*(cBoard + iMove) = cSymbol;
	}
	//Change player
	cSymbol = (cSymbol == 'O') ? 'X' : 'O';

	//Clean console
	system("cls");
}

