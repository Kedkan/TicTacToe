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
*
*
**********************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Header.h"

int iMove[2];

//Return true if player wins
bool checkWin(char board[][5], char symbol)
{

	//Check the columns and rows
	for (int i = 0; i < 5; i += 2)
	{
		if (board[i][0] == symbol && board[i][2] == symbol && board[i][4] == symbol)
		{
			return true;
			break;
		}
		else if (board[0][i] == symbol && board[2][i] == symbol && board[4][i] == symbol)
		{
			return true;
			break;
		}
	}

	//Check cross
	if (board[0][4] == symbol && board[2][2] == symbol &&  board[4][0] == symbol)
	{
		return true;
	}
	else if (board[0][0] == symbol && board[2][2] == symbol &&  board[4][4] == symbol)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//Return true if nobody wins
bool deadHeat(char board[][5])
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == ' ')
			{
				return true;
				break;
			}
		}	
	}
	return false;
}
//Player round
void round(char board[][5], char &gamer)
{
	int iX=0;
	int	iY=0;

	showGameBoard(board);		//Show game board
	if (gamer == 'O')
	{
		

		cout << "Player\n";
		cout << "Please specify coordinates your move: (x,y)\n";
		cout << "X: ";
		cin >> iX;
		cout << "Y: ";
		cin >> iY;
		
	}
	else
	{
		computerMove(board);
		iX = iMove[0];
		iY = iMove[1];
		
	}
	if (board[iX][iY] = ' ') board[iX][iY] = gamer;
	gamer = (gamer == 'O') ? 'X' : 'O';
	//system("CLS");
}

//MinMax recursion algorithm
int minMax(char board[][5], char gamer)
{
	short int iTemp;			//Temp variable
	short int iMaxScore;		//Maximum player score

	if (checkWin(board, gamer)) return (gamer = 'X') ? 1 : -1;
	if (deadHeat(board)) return 0;

	//Set opponent
	gamer = (gamer == 'X') ? 'O' : 'X';

	iMaxScore = (gamer == 'O') ? 10 : -10;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = gamer;
				iTemp = minMax(board, gamer);
				board[i][j] = ' ';
				if (((gamer == 'O') && (iTemp < iMaxScore)) || ((gamer == 'X') && (iTemp > iMaxScore))) iMaxScore = iTemp;
			}
		}

	}

	return iMaxScore;
}

//Computer best moves
void computerMove(char board[][5])
{
	int iMaxScore, iTemp;
	iMaxScore = -10;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = 'X';
				iTemp = minMax(board, 'X');
				board[i][j] = ' ';
				if (iTemp > iMaxScore)
				{
					iMaxScore = iTemp;
					::iMove[0] = i;
					::iMove[1] = j;
				}
			}
		}
	}
}