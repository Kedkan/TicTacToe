/**********************************************************************
* Project           : TicTacToe
* File name			: Define.h
* Author			: Dawid_Wilk
* Date created		: 20170703
* Purpose			: Definitions
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*20170703	  DW		  1.1	 Version 1.1.
**********************************************************************/

#ifndef TICTACTOE_DEFINE_H
#define TICTACTOE_DEFINE_H

/**********************************************************************
Clean console: Windows, OS X, Linux
**********************************************************************/

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

/**********************************************************************
Char definitions
**********************************************************************/

#define CHAR_O 'O' //O game char
#define CHAR_X 'X' //O game char
#define CHAR_Y 'Y'
#define CHAR_y 'y'

/**********************************************************************
Int definitions
**********************************************************************/

#define ZERO 0
#define ONE 1
#define MONE -1
#define TEN 10
#define MTEN -10

#endif //TICTACTOE_DEFINE_H
