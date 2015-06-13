#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <vector>
#include <string>
#include "square.h"

void displayBoard(const std::vector<sq::Square> &sqVect, int widthInUnderscores);
void compactBoard(const std::vector<sq::Square> &sqVect);
void defaultBoard(const std::vector<sq::Square> &sqVect);
void wideBoard(const std::vector<sq::Square> &sqVect);

#endif