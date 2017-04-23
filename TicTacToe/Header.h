#pragma once

void drawGameBoard(char *cBoard);						//Prepares game board
bool checkWin(char *cBoard, char cSymbol, bool bTemp);	//return true if player wins
bool deadHeat(char *cBoard, bool bTemp);				//Return true if nobody wins
void round(char *cBoard, char &cSymbol);				//Player round
int minMax(char *cBoard, char cSymbol);					//MinMax recursion algorithm
int computerMove(char *cBoard);							//Computer best move
void resetGameBoard(char *cBoard);						//Reset game board

extern char cSymbol;									//Game symbol 'X' or 'O'
