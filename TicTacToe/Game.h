/**********************************************************************
* Project           : TicTacToe
* File name			: Game.h
* Author			: Dawid_Wilk
* Date created		: 20170501
* Purpose			: Game algorithm Class
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*20170501	  DW		  1.1	 Version 1.1.
**********************************************************************/


#include "CheckBoard.h"
#include "BoardDraw.h"

#ifndef _GAME_H_
#define _GAME_H_

class Game
{
private:
	friend BoardDraw;
	friend CheckBoard;
	int minMax(char *cBoard, char cSymbol);									//MinMax recursion algorithm
	int computerMove(char *cBoard);											//Computer best move
public:
	void round(char *cBoard, char &cSymbol);								//Player round
};
#endif // _GAME_H_