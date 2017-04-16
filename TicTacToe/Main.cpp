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
	char cTab[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	char *cBoard = cTab;

	::cSymbol = 'O';

	while (checkWin(cBoard,cSymbol) == false && deadHeat(cBoard) == false)
	{
		round(cBoard, cSymbol);
	}

	//to do -> bug wrong symbol
	if (checkWin(cBoard, cSymbol) == true)
	{
		cout << "You win! player: " << cSymbol << ":)\n";
	}
	else if (deadHeat(cBoard) == true)
	{
		cout << "Dead Heat! ;p\n";
	}
	else
	{
		cout << "You lose :(\n";
	}

	//to do -> score array, board opitons, game options
	
	system("pause");
	return 0;
}
