/**********************************************************************
* Project           : TicTacToe
* File name			: BoardDraw.cpp
* Author			: Dawid_Wilk
* Date created		: 20170326
* Purpose			: Game board
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*20170416	  DW		  1.0	 Delete showGameBoard function.		
*20170416	  DW		  1.0	 Use in drawGameBoard One-Dimensional Array.
*20170501	  DW		  1.1	 Version 1.1.
**********************************************************************/

#include <iostream>
using namespace std;

#include "BoardDraw.h"

/**********************************************************************
Function draw a Game Board, using One-Dimensional Array.
Items of Game Board ('O' and 'X') are stored in Array:
cTab[0] cTab[1] cTab[2]
cTab[3] cTab[4] cTab[5]
cTab[6] cTab[7] cTab[8]
**********************************************************************/
void BoardDraw::drawGameBoard(char *cBoard)
{
	for (int i = 1; i < 10; i++)
	{
		cout << " " << *cBoard << " ";

		if (i % 3)							//After 1,2,4,5,7,8 -> write "|"
		{
			cout << "|";
		}
		else if (i != 9)					//After 3 and 6 -> write separation
		{
			cout << "\n---+---+---\n";
		}
		else								//After 9 -> end line
		{
			cout << endl;
		}

		cBoard++;							//Go to the next table element
	}

}

/**********************************************************************
Function reset a Game Board, set all field to the default value ' '.
**********************************************************************/
void BoardDraw::resetGameBoard(char *cBoard)
{
	for (int i = 0; i < 9; i++)
	{
		*(cBoard + i) = ' ';
	}
}