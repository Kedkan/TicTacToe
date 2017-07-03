/**********************************************************************
* Project           : TicTacToe
* File name			: CheckBoard.h
* Author			: Dawid_Wilk
* Date created		: 20170501
* Purpose			: Check Board Class
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*20170501	  DW		  1.1	 Version 1.1.
**********************************************************************/

#ifndef TICTACTOE_CHECKBOARD_H_
#define TICTACTOE_CHECKBOARD_H_
class CheckBoard
{
public:
	static bool checkBoardField(int iAnswer, char *cBoard);		        //Check condition >=0 and <=8 and == ' '
	static bool checkWin(char *cBoard, char cSymbol, bool bTemp);		//return true if player wins
	static bool deadHeat(char *cBoard, bool bTemp);						//Return true if nobody wins
};
#endif // TICTACTOE_CHECKBOARD_H_
