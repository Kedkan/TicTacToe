/**********************************************************************
* Project           : TicTacToe
* File name			: BoardDraw.h
* Author			: Dawid_Wilk
* Date created		: 20170501
* Purpose			: Game board Class
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*20170501	  DW		  1.1	 Version 1.1.
**********************************************************************/

#ifndef _BOARDDRAW_H_
#define _BOARDDRAW_H_

class BoardDraw
{
public:
	static void drawGameBoard(char *cBoard);			//Prepares game board
	static void resetGameBoard(char *cBoard);			//Reset game board
};
#endif // _BOARDDRAW_h_

