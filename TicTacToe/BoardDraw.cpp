/**********************************************************************
* Project           : TicTacToe
*
* File name			: BoardDraw.cpp
*
* Author			: Dawid_Wilk
*
* Date created		: 20170326
*
* Purpose			: Game board.
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


//Prepare game board
void drawGameBoard(char board[][5])				 						
{

//Set default values: " ", board background 
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			board[i][j] = ' ';
		}
	}

//Set board frames

	//Perpendicularly
	for (int i = 1; i < 5; i += 2)
	{
		for (int j = 0; j < 5; j += 2)
		{
			board[i][j] = '|';
		}

		for (int j = 1; j < 5; j += 2)
		{
			board[i][j] = '+';
		}
	}

	//Horizontally
	for (int i = 0; i < 5; i += 2)
	{
		for (int j = 1; j < 5; j += 2)
		{
			board[i][j] = '-';
		}
	}

}

//Show game board
void showGameBoard(char board[][5])				
{
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << " " << board[j][i];
			cout << endl;
	}
}