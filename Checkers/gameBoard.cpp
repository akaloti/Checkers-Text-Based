#include "gameBoard.h"

void displayBoard(const std::vector<sq::Square> &sqVect, int widthInUnderscores) {
	//decides which board to display depending on desired width
	if (widthInUnderscores == 1) compactBoard(sqVect);
	if (widthInUnderscores == 2) defaultBoard(sqVect);
	return;
}

void compactBoard(const std::vector<sq::Square> &sqVect) {
	std::cout<<'\n'
		<<"   |"<<sqVect[28].color()<<"| |"<<sqVect[29].color()<<"| |"<<sqVect[30].color()<<"| |"<<sqVect[31].color()<<'\n'
		<<"8 _|_|_|_|_|_|_|_\n"
		<<"  "<<sqVect[24].color()<<"| |"<<sqVect[25].color()<<"| |"<<sqVect[26].color()<<"| |"<<sqVect[27].color()<<"|\n"
		<<"7 _|_|_|_|_|_|_|_\n"
		<<"   |"<<sqVect[20].color()<<"| |"<<sqVect[21].color()<<"| |"<<sqVect[22].color()<<"| |"<<sqVect[23].color()<<'\n'
		<<"6 _|_|_|_|_|_|_|_\n"
		<<"  "<<sqVect[16].color()<<"| |"<<sqVect[17].color()<<"| |"<<sqVect[18].color()<<"| |"<<sqVect[19].color()<<"|\n"
		<<"5 _|_|_|_|_|_|_|_\n"
		<<"   |"<<sqVect[12].color()<<"| |"<<sqVect[13].color()<<"| |"<<sqVect[14].color()<<"| |"<<sqVect[15].color()<<'\n'
		<<"4 _|_|_|_|_|_|_|_\n"
		<<"  "<<sqVect[8].color()<<"| |"<<sqVect[9].color()<<"| |"<<sqVect[10].color()<<"| |"<<sqVect[11].color()<<"|\n"
		<<"3 _|_|_|_|_|_|_|_\n"
		<<"   |"<<sqVect[4].color()<<"| |"<<sqVect[5].color()<<"| |"<<sqVect[6].color()<<"| |"<<sqVect[7].color()<<'\n'
		<<"2 _|_|_|_|_|_|_|_\n"
		<<"  "<<sqVect[0].color()<<"| |"<<sqVect[1].color()<<"| |"<<sqVect[2].color()<<"| |"<<sqVect[3].color()<<"|\n"
		<<"1 _|_|_|_|_|_|_|_\n"
		<<"  a b c d e f g h \n"
		<<'\n';
	return;
}

void defaultBoard(const std::vector<sq::Square> &sqVect) {
//void wideBoard() {
	std::cout<<'\n'
	<<"     | "<<sqVect[28].color()<<" |   | "<<sqVect[29].color()<<" |   | "<<sqVect[30].color()<<" |   | "<<sqVect[31].color()<<'\n'
	<<"8 ___|___|___|___|___|___|___|___\n"
	<<"   "<<sqVect[24].color()<<" |   | "<<sqVect[25].color()<<" |   | "<<sqVect[26].color()<<" |   | "<<sqVect[27].color()<<" |\n"
	<<"7 ___|___|___|___|___|___|___|___\n"
	<<"     | "<<sqVect[20].color()<<" |   | "<<sqVect[21].color()<<" |   | "<<sqVect[22].color()<<" |   | "<<sqVect[23].color()<<'\n'
	<<"6 ___|___|___|___|___|___|___|___\n"
	<<"   "<<sqVect[16].color()<<" |   | "<<sqVect[17].color()<<" |   | "<<sqVect[18].color()<<" |   | "<<sqVect[19].color()<<" |\n"
	<<"5 ___|___|___|___|___|___|___|___\n"
	<<"     | "<<sqVect[12].color()<<" |   | "<<sqVect[13].color()<<" |   | "<<sqVect[14].color()<<" |   | "<<sqVect[15].color()<<'\n'
	<<"4 ___|___|___|___|___|___|___|___\n"
	<<"   "<<sqVect[8].color()<<" |   | "<<sqVect[9].color()<<" |   | "<<sqVect[10].color()<<" |   | "<<sqVect[11].color()<<" |\n"
	<<"3 ___|___|___|___|___|___|___|___\n"
	<<"     | "<<sqVect[4].color()<<" |   | "<<sqVect[5].color()<<" |   | "<<sqVect[6].color()<<" |   | "<<sqVect[7].color()<<'\n'
	<<"2 ___|___|___|___|___|___|___|___\n"
	<<"   "<<sqVect[0].color()<<" |   | "<<sqVect[1].color()<<" |   | "<<sqVect[2].color()<<" |   | "<<sqVect[3].color()<<" |\n"
	<<"1 ___|___|___|___|___|___|___|___\n"
	<<"   a   b   c   d   e   f   g   h \n"
	<<'\n';
	return;
}