#include "checkersVariables.h"

std::vector<sq::Square> checkers::squares(32, sq::Square(' ',"a1",'1')); //initialized to "a1" and '1' to get through 
	                                                  //constructor's error handling
std::string checkers::selection = " "; //all input by the user is held by this variable
char checkers::turn = ' '; //either 'r' (Red) or 'b' (Black)
char checkers::captureDirection = ' '; //either 'R' (right) or 'L' (left)
char checkers::initialRowParity = ' '; //either 'O' (odd) or 'E' (even)
bool checkers::wasCapture = false; //was there a capture this turn?
				 //used to determine whether to check for consecutive capture
char checkers::loser = ' '; //either 'r' (Red) or 'b' (Black)
		   //who is the loser?
       
//for vector location:
int checkers::selected = 0; //holds vector address of square of selected piece
int checkers::targeted = 0; //holds vector address of square to move a piece to
int checkers::inBetween = 0; //holds vector address of square in between the
			   //selected and targeted squares (in case of capture)

ch::Board checkers::gameBoard = ch::Board(600.0f);