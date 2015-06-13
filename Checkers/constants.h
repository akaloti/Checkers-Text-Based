#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
	const char Red = 'r';
	const char cRed = 'R'; //crowned red
	const char Black = 'b';
	const char cBlack = 'B'; //crowned black
	const char Both = 'x'; //in case of a tie, char loser = Both
	const char Left = 'L';
	const char Right = 'R';
	const char Odd = 'O';
	const char Even = 'E';
	const int lowVectorRange = 0; //lowest subscript within range of vector
	
	//addresses of squares at ends of board (for detecting promotion):
	const int b8 = 28;
	const int d8 = 29;
	const int f8 = 30;
	const int h8 = 31;
	const int a1 = 0;
	const int c1 = 1;
	const int e1 = 2;
	const int g1 = 3;

	//for capturing (see description at top of mainGame.cpp for explanation):
	const int rOddRightCapJmp = 9; //distance from start to landing square if
								   //piece starts on odd row heading right
								   //red's first capture condition true
	const int rOddRightHafJmp = 4; //distance from start to in-between square if
								   //piece starts on odd row heading right
								   //red's first capture condition true
	//following constants follow same pattern
	const int rEvenRightCapJmp = 9; //red's second capture condition
	const int rEvenRightHafJmp = 5;
	
	const int rOddLeftCapJmp = 7; //red's third capture condition
	const int rOddLeftHafJmp = 3;
	
	const int rEvenLeftCapJmp = 7; //red's fourth capture condition
	const int rEvenLeftHafJmp = 4;

	const int bOddLeftCapJmp = -9; //black's first capture condition
	const int bOddLeftHafJmp = -5;
	
	const int bEvenLeftCapJmp = -9; //black's second capture condition
	const int bEvenLeftHafJmp = -4;
	
	const int bOddRightCapJmp = -7; //black's third capture condition
	const int bOddRightHafJmp = -4;
	
	const int bEvenRightCapJmp = -7; //black's fourth capture condition
	const int bEvenRightHafJmp = -3;
}

using namespace constants;

#endif