
/**********************************************************************
* Project           : TicTacToe
* File name			: CheckBoard.cpp
* Author			: Dawid_Wilk
* Date created		: 20170501
* Purpose			: Check Board
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*20170501	  DW		  1.1	 Version 1.1.
**********************************************************************/

#include <iostream>
using namespace std;

#include "CheckBoard.h"

/**********************************************************************
Check condition >=0 and <=8 and == ' '.
**********************************************************************/
bool CheckBoard::checkBoardField(short int iAnswer, char *cBoard)
{
	if ((iAnswer >= 0) && (iAnswer <= 8) && (*(cBoard + iAnswer) == ' '))
	{
		return true;
	}
	else
	{
		cout << "Bad address!\n";
		return false;
	}
}

/**********************************************************************
Function return TRUE if one player wins,
bTemp stop the infinite loop minMax and checkWin.
**********************************************************************/
bool CheckBoard::checkWin(char *cBoard, char cSymbol, bool bTemp)
{
	bool bWin = false;		//true if player have three the same char in column, line or cross

	//Check rows in Array, if the same, return TRUE
	for (int i = 0; i < 7; i += 3)
	{
		if ((*(cBoard + i) == cSymbol) && (*(cBoard + i + 1) == cSymbol) && (*(cBoard + i + 2) == cSymbol))
		{
			bWin = true;

			break;
		}
	}

	//Check columns in Array, if the same, return TRUE
	for (int i = 0; i < 3; i++)
	{
		if ((*(cBoard + i) == cSymbol) && (*(cBoard + i + 3) == cSymbol) && (*(cBoard + i + 6) == cSymbol))
		{
			bWin = true;
			break;
		}
	}

	//Check cross cTab[0]-cTab[4]-cTab[8]
	if ((*cBoard == cSymbol) && (*(cBoard + 4) == cSymbol) && (*(cBoard + 8) == cSymbol))
	{
		bWin = true;
	}

	//Check cross cTab[6]-cTab[4]-cTab[2]
	if ((*(cBoard + 6) == cSymbol) && (*(cBoard + 4) == cSymbol) && (*(cBoard + 2) == cSymbol))
	{
		bWin = true;
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
bool CheckBoard::deadHeat(char *cBoard, bool bTemp)
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