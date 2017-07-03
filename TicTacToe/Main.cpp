/**********************************************************************
* Project           : TicTacToe
* Program name		: TicTacToe.cpp
* Author			: Dawid_Wilk
* Date created		: 20170326
* Purpose			: Test minmax algorithm
* Revision History :
*
* Date        Author      Ref    Revision(Date in YYYYMMDD format)
*20170501	  DW		  1.1	 Version 1.1.
*20170603     DW          1.1    Change IDE to CLion
**********************************************************************/


#include <iostream>
using namespace std;

#include "BoardDraw.h"
#include "Game.h"
#include "Define.h"

void scoreTable(char *cBoard, int & iScorePlayer, int & iScoreComputer);
void showMenu();

/**********************************************************************/

int main()
{
	char cTab[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };		//Default game board
	char *cBoard = cTab;
	char cChoice;												//Player choice after win/lose game
	char cSymbol = CHAR_O;									    //Default game char
    int  iAnswer;                                               //Player menu choice
    int  iScorePlayerOne = ZERO;                                //Player game score
    int  iScorePlayerTwo = ZERO;                                //Computer game score
	Game Tgame;													//Game one 9x9

        showMenu();

        do
        {
            cin >> iAnswer;     //Player menu choice

            switch (iAnswer)
            {
                case 1:
                    do
                    {
                        BoardDraw::resetGameBoard(cBoard);		//reset game

                            while  ((!CheckBoard::checkWin(cBoard, CHAR_X, false))
                                   && (!CheckBoard::checkWin(cBoard, CHAR_O, false))
                                   && (!CheckBoard::deadHeat(cBoard, false)))
                            {
                                Tgame.round(cBoard, cSymbol);
                            };

                        scoreTable(cBoard,iScorePlayerOne,iScorePlayerTwo);     //score counting
                        cout << "You want to play again? Y? N?\n";
                        cin >> cChoice;
                    } while ((cChoice == CHAR_Y) || (cChoice == CHAR_y));
                    break;

                case 2:
                    cout << "Test\n";
                    break;

                case 3:
                {
                    cout << "Player One: " << iScorePlayerOne << endl;
                    cout << "Player Two: " << iScorePlayerTwo << endl;
                }
                    break;

                case 4:
                    cout << "to do";
                    break;

                default:
                    cout << "BB.\n";
            }
        } while (iAnswer != 5);

	return 0;
}

/**********************************************************************/


/**********************************************************************
Function increment iScorePlayerOne if Player O win the game,
or increment IScorePlayerTwo if Player X win the game, if deadhead,
no one score the point.
**********************************************************************/

void scoreTable(char *cBoard, int & iScorePlayerOne, int & iScorePlayerTwo)
{
    if (CheckBoard::checkWin(cBoard, CHAR_O, false))
    {
        iScorePlayerOne++;
    }
    if (CheckBoard::checkWin(cBoard, CHAR_X, false))
    {
        iScorePlayerTwo++;
    }
}

/**********************************************************************
Function show menu.
**********************************************************************/

void showMenu()
{
    cout  << "\n"
          << "                  TIC TAC TOE                 \n"
          << "\n"
          << "\n"
          << "\n"
          << "        Select the option of your choice: \n"
          << "\n"
          << "          (1) New Game One Player\n"
          << "          (2) New Game Two Players\n"
          << "          (3) Show Score Table\n"
          << "          (4) Game Options\n"
          << "\n"
          << "        Select 5 to Exit\n";

}
