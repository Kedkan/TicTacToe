#pragma once

void drawGameBoard(char board[][5]);					//Prepares game board
void showGameBoard(char board[][5]);					//Show game board
bool checkWin(char board[][5], char symbol);			//return true if player wins
bool deadHeat(char board[][5]);							//Return true if nobody wins
void round(char board[][5], char &gamer);				//Player round
int minMax(char board[][5], char gamer);				//MinMax recursion algorithm
void computerMove(char board[][5]);						//Computer best move

extern char cSymbol;									//Game symbol 'X' or 'O'
extern int *iMove;