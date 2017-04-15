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
	char board[5][5];

	::cSymbol = 'O';
	drawGameBoard(board);

	while (checkWin(board, cSymbol) == false && deadHeat(board) == true) round(board, cSymbol);

	if (checkWin(board, cSymbol) == true)
	{
		cout << "You win! player: " << cSymbol << ":)\n";
	}
	else if (deadHeat(board) == true)
	{
		cout << "Dead Heat! ;p\n";
	}
	else
	{
		cout << "You lose :(\n";
	}
	
	system("pause");
	return 0;
}
