#pragma once

void drawGameBoard(char *cBoard);						//Prepares game board
bool checkWin(char *cBoard, char symbol);				//return true if player wins
bool deadHeat(char *cBoard);							//Return true if nobody wins
void round(char *cBoard, char &symbol);					//Player round
int minMax(char *cBoard, char symbol);					//MinMax recursion algorithm
int computerMove(char *cBoard);							//Computer best move

extern char cSymbol;									//Game symbol 'X' or 'O'