#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "constants.h"
#include "error.h"

namespace sq {

struct Square
{
	char color() const { return c; }
	std::string square() const { return s; }
	char row() const { return r; }
	std::vector<std::string> getFrtAdjSqs() const { return frtAdjSqs; }
	std::vector<std::string> getBacAdjSqs() const { return bacAdjSqs; }
	std::vector<std::string> getFrtJmpSqs() const { return frtJmpSqs; }
	std::vector<std::string> getBacJmpSqs() const { return bacJmpSqs; }
	bool isCrowned() const { return crowned; }
	void switchCrown(bool status) { crowned = status; return; }
	bool isCaptured() const { return captured; }
	void switchCap(bool status) { captured = status; return; }
	
	void changeColor(char newColor);
	
	Square();
	Square(char c_, std::string s_, char r_);

	std::vector<std::string> setFrtAdjSqs(std::string sq); //sets std::vector<std::string> FrtAdjSqs
	std::vector<std::string> setBacAdjSqs(std::string sq); //sets std::vector<std::string> BacAdjSqs
	std::vector<std::string> setFrtJmpSqs(std::string sq); //sets std::vector<std::string> frontJumpSqs
	std::vector<std::string> setBacJmpSqs(std::string sq); //sets std::vector<std::string> backJumpSqs
	
private: 
	//10 members
	char c;  
	//color of piece on it
		//'r' for red
		//'R' for crowned red
		//'b' for black
		//'B' for crowned black
		//' ' for none
	std::string s;  //square name; could be a1, e5, etc.
	char r;  //row; could be 1,2,3,...8
	std::vector<std::string> frtAdjSqs; //holds adjacent squares in front
	std::vector<std::string> bacAdjSqs; //holds adjacent squares in back
	std::vector<std::string> adjSqs; //holds adjacent squares
	std::vector<std::string> frtJmpSqs; //holds squares that are two away in front
								 //used to detect a capture
	std::vector<std::string> bacJmpSqs; //holds squares that are two away in back
	                            //used to detect a capture by crowned pieces
	bool crowned; //is the piece on this square crowned?
				  //if a piece is crowned, it can move backwards in default game mode
	bool captured; //is the piece on this square captured?
};

} // namespace sq

#endif