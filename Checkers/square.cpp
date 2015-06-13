#include "square.h"

bool isSquare(std::string square);

namespace sq {

// This mutex is needed because both threads access Square::c (see
// Square::changeColor).
sf::Mutex squaresMutex;

void Square::changeColor(char newColor) {
  // The main thread checkers Square::c to decide what to display, so while
  // this function changes Square::c, squaresMutex prevents any conflicts
  // between the two threads by preventing both threads from accessing
  // Square::c at the same time.
  squaresMutex.lock();
	if (c != newColor) c = newColor;
  squaresMutex.unlock();
	return;
}

Square::Square() {
	c = ' ';
	s = "a1";
	r = '1';
	frtAdjSqs = setFrtAdjSqs(s);
	bacAdjSqs = setBacAdjSqs(s);
	frtJmpSqs = setFrtJmpSqs(s);
	bacJmpSqs = setBacJmpSqs(s);
	crowned = false;
	captured = false;
	return;
}

Square::Square(char c_, std::string s_, char r_) 
:c(c_), s(s_), r(r_)
{ 
	//the 5 vector members (frtAdjSqs, bacAdjSqs, etc.) are
	//not in the arguments because they are dependent on std::string s_

	//check for constructor errors:
	if(c_ != Red && c_ != cRed && c_ != Black && c_ != cBlack && c_ != ' ') 
		error("Exception: constructor use without correct color ('r','R','b','B',' ')"); 
	if(!isSquare(s_)) 
		error("Exception: constructor use without correct square");
	switch(r_) {  
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8':
			break;
		default:
			error("Exception: constructor use without correct row");
	}

	//initialize 7 other members
	frtAdjSqs = setFrtAdjSqs(s);
	bacAdjSqs = setBacAdjSqs(s);
	frtJmpSqs = setFrtJmpSqs(s);
	bacJmpSqs = setBacJmpSqs(s);
	if(c_ == cRed || c_ == cBlack) 
		crowned = true; //'R' and 'B' indicate the piece is crowned
	else 
		crowned = false;  //'r' and 'b' (and ' ') indicate the piece is uncrowned
	captured = false;
	return;
}

std::vector<std::string> Square::setFrtAdjSqs(std::string sq) {
	//sets std::vector<std::string> frtAdjSqs

	std::vector<std::string> sqs(2," "); //holds the squares to give to frtAdjSqs

	if(sq == "a1") {sqs[0] = "b2"; return sqs;}
	if(sq == "a3") {sqs[0] = "b4"; return sqs;}
	if(sq == "a5") {sqs[0] = "b6"; return sqs;}
	if(sq == "a7") {sqs[0] = "b8"; return sqs;}

	if(sq == "b2") {sqs[0] = "a3"; sqs[1] = "c3"; return sqs;}
	if(sq == "b4") {sqs[0] = "a5"; sqs[1] = "c5"; return sqs;}
	if(sq == "b6") {sqs[0] = "a7"; sqs[1] = "c7"; return sqs;}
	if(sq == "b8") return sqs;	//a piece on b8 cannot move forward

	if(sq == "c1") {sqs[0] = "b2"; sqs[1] = "d2"; return sqs;}
	if(sq == "c3") {sqs[0] = "b4"; sqs[1] = "d4"; return sqs;}
	if(sq == "c5") {sqs[0] = "b6"; sqs[1] = "d6"; return sqs;}
	if(sq == "c7") {sqs[0] = "b8"; sqs[1] = "d8"; return sqs;}

	if(sq == "d2") {sqs[0] = "c3"; sqs[1] = "e3"; return sqs;}
	if(sq == "d4") {sqs[0] = "c5"; sqs[1] = "e5"; return sqs;}
	if(sq == "d6") {sqs[0] = "c7"; sqs[1] = "e7"; return sqs;}
	if(sq == "d8") return sqs;	//a piece on d8 cannot move forward

	if(sq == "e1") {sqs[0] = "d2"; sqs[1] = "f2"; return sqs;}
	if(sq == "e3") {sqs[0] = "d4"; sqs[1] = "f4"; return sqs;}
	if(sq == "e5") {sqs[0] = "d6"; sqs[1] = "f6"; return sqs;}
	if(sq == "e7") {sqs[0] = "d8"; sqs[1] = "f8"; return sqs;}

	if(sq == "f2") {sqs[0] = "e3"; sqs[1] = "g3"; return sqs;}
	if(sq == "f4") {sqs[0] = "e5"; sqs[1] = "g5"; return sqs;}
	if(sq == "f6") {sqs[0] = "e7"; sqs[1] = "g7"; return sqs;}
	if(sq == "f8") return sqs;	//a piece on f8 cannot move forward

	if(sq == "g1") {sqs[0] = "f2"; sqs[1] = "h2"; return sqs;}
	if(sq == "g3") {sqs[0] = "f4"; sqs[1] = "h4"; return sqs;}
	if(sq == "g5") {sqs[0] = "f6"; sqs[1] = "h6"; return sqs;}
	if(sq == "g7") {sqs[0] = "f8"; sqs[1] = "h8"; return sqs;}

	if(sq == "h2") {sqs[0] = "g3"; return sqs;}
	if(sq == "h4") {sqs[0] = "g5"; return sqs;}
	if(sq == "h6") {sqs[0] = "g7"; return sqs;}
	if(sq == "h8") return sqs;	//a piece on h8 cannot move forward

	error("Exception: constructor use without an accessible square");
}

std::vector<std::string> Square::setBacAdjSqs(std::string sq) {
	//sets std::vector<std::string> bacAdjSqs

	std::vector<std::string> sqs(2," "); //holds the squares to give to bacAdjSqs

	if(sq == "a1") return sqs;	//a piece on a1 cannot move backward
	if(sq == "a3") {sqs[0] = "b2"; return sqs;}
	if(sq == "a5") {sqs[0] = "b4"; return sqs;}
	if(sq == "a7") {sqs[0] = "b6"; return sqs;}

	if(sq == "b2") {sqs[0] = "a1"; sqs[1] = "c1"; return sqs;}
	if(sq == "b4") {sqs[0] = "a3"; sqs[1] = "c3"; return sqs;}
	if(sq == "b6") {sqs[0] = "a5"; sqs[1] = "c5"; return sqs;}
	if(sq == "b8") {sqs[0] = "a7"; sqs[1] = "c7"; return sqs;}

	if(sq == "c1") return sqs;	//a piece on c1 cannot move backward
	if(sq == "c3") {sqs[0] = "b2"; sqs[1] = "d2"; return sqs;}
	if(sq == "c5") {sqs[0] = "b4"; sqs[1] = "d4"; return sqs;}
	if(sq == "c7") {sqs[0] = "b6"; sqs[1] = "d6"; return sqs;}

	if(sq == "d2") {sqs[0] = "c1"; sqs[1] = "e1"; return sqs;}
	if(sq == "d4") {sqs[0] = "c3"; sqs[1] = "e3"; return sqs;}
	if(sq == "d6") {sqs[0] = "c5"; sqs[1] = "e5"; return sqs;}
	if(sq == "d8") {sqs[0] = "c7"; sqs[1] = "e7"; return sqs;}

	if(sq == "e1") return sqs;	//a piece on e1 cannot move backward
	if(sq == "e3") {sqs[0] = "d2"; sqs[1] = "f2"; return sqs;}
	if(sq == "e5") {sqs[0] = "d4"; sqs[1] = "f4"; return sqs;}
	if(sq == "e7") {sqs[0] = "d6"; sqs[1] = "f6"; return sqs;}

	if(sq == "f2") {sqs[0] = "e1"; sqs[1] = "g1"; return sqs;}
	if(sq == "f4") {sqs[0] = "e3"; sqs[1] = "g3"; return sqs;}
	if(sq == "f6") {sqs[0] = "e5"; sqs[1] = "g5"; return sqs;}
	if(sq == "f8") {sqs[0] = "e7"; sqs[1] = "g7"; return sqs;}

	if(sq == "g1") return sqs;	//a piece on g1 cannot move backward
	if(sq == "g3") {sqs[0] = "f2"; sqs[1] = "h2"; return sqs;}
	if(sq == "g5") {sqs[0] = "f4"; sqs[1] = "h4"; return sqs;}
	if(sq == "g7") {sqs[0] = "f6"; sqs[1] = "h6"; return sqs;}

	if(sq == "h2") {sqs[0] = "g1"; return sqs;}
	if(sq == "h4") {sqs[0] = "g3"; return sqs;}
	if(sq == "h6") {sqs[0] = "g5"; return sqs;}
	if(sq == "h8") {sqs[0] = "g7"; return sqs;}

	error("Exception: constructor use without an accessible square");
}

std::vector<std::string> Square::setFrtJmpSqs(std::string sq) {
	//sets std::vector<std::string> frtJmpSqs

	std::vector<std::string> sqs(2," "); //holds the squares to give to frtJmpSqs
	
	if(sq == "a1") {sqs[0] = "c3"; return sqs;}
	if(sq == "a3") {sqs[0] = "c5"; return sqs;}
	if(sq == "a5") {sqs[0] = "c7"; return sqs;}
	if(sq == "a7") return sqs;	//a piece on a7 cannot jump forward

	if(sq == "b2") {sqs[0] = "d4"; return sqs;}
	if(sq == "b4") {sqs[0] = "d6"; return sqs;}
	if(sq == "b6") {sqs[0] = "d8"; return sqs;}
	if(sq == "b8") return sqs;	//a piece on b8 cannot jump forward

	if(sq == "c1") {sqs[0] = "a3"; sqs[1] = "e3"; return sqs;}
	if(sq == "c3") {sqs[0] = "a5"; sqs[1] = "e5"; return sqs;}
	if(sq == "c5") {sqs[0] = "a7"; sqs[1] = "e7"; return sqs;}
	if(sq == "c7") return sqs;	//a piece on c7 cannot jump forward

	if(sq == "d2") {sqs[0] = "b4"; sqs[1] = "f4"; return sqs;}
	if(sq == "d4") {sqs[0] = "b6"; sqs[1] = "f6"; return sqs;}
	if(sq == "d6") {sqs[0] = "b8"; sqs[1] = "f8"; return sqs;}
	if(sq == "d8") return sqs;	//a piece on d8 cannot jump forward

	if(sq == "e1") {sqs[0] = "c3"; sqs[1] = "g3"; return sqs;}
	if(sq == "e3") {sqs[0] = "c5"; sqs[1] = "g5"; return sqs;}
	if(sq == "e5") {sqs[0] = "c7"; sqs[1] = "g7"; return sqs;}
	if(sq == "e7") return sqs;	//a piece on e7 cannot jump forward

	if(sq == "f2") {sqs[0] = "d4"; sqs[1] = "h4"; return sqs;}
	if(sq == "f4") {sqs[0] = "d6"; sqs[1] = "h6"; return sqs;}
	if(sq == "f6") {sqs[0] = "d8"; sqs[1] = "h8"; return sqs;}
	if(sq == "f8") return sqs;	//a piece on f8 cannot jump forward

	if(sq == "g1") {sqs[0] = "e3"; return sqs;}
	if(sq == "g3") {sqs[0] = "e5"; return sqs;}
	if(sq == "g5") {sqs[0] = "e7"; return sqs;}
	if(sq == "g7") return sqs;	//a piece on g7 cannot jump forward

	if(sq == "h2") {sqs[0] = "f4"; return sqs;}
	if(sq == "h4") {sqs[0] = "f6"; return sqs;}
	if(sq == "h6") {sqs[0] = "f8"; return sqs;}
	if(sq == "h8") return sqs;	//a piece on h8 cannot jump forward

	error("Exception: constructor use without an accessible square");
}

std::vector<std::string> Square::setBacJmpSqs(std::string sq) {
	//sets std::vector<std::string> bacJmpSqs

	std::vector<std::string> sqs(2," "); //holds the squares to give to bacJumpSqs
	
	if(sq == "a1") return sqs;	//a crowned piece on a1 cannot jump backward
	if(sq == "a3") {sqs[0] = "c1"; return sqs;}
	if(sq == "a5") {sqs[0] = "c3"; return sqs;}
	if(sq == "a7") {sqs[0] = "c5"; return sqs;}

	if(sq == "b2") return sqs;	//a crowned piece on b2 cannot jump backward
	if(sq == "b4") {sqs[0] = "d2"; return sqs;}
	if(sq == "b6") {sqs[0] = "d4"; return sqs;}
	if(sq == "b8") {sqs[0] = "d6"; return sqs;}

	if(sq == "c1") return sqs;	//a crowned piece on c1 cannot jump backward
	if(sq == "c3") {sqs[0] = "a1"; sqs[1] = "e1"; return sqs;}
	if(sq == "c5") {sqs[0] = "a3"; sqs[1] = "e3"; return sqs;}
	if(sq == "c7") {sqs[0] = "a5"; sqs[1] = "e5"; return sqs;}

	if(sq == "d2") return sqs;	//a crowned piece on d2 cannot jump backward
	if(sq == "d4") {sqs[0] = "b2"; sqs[1] = "f2"; return sqs;}
	if(sq == "d6") {sqs[0] = "b4"; sqs[1] = "f4"; return sqs;}
	if(sq == "d8") {sqs[0] = "b6"; sqs[1] = "f6"; return sqs;}

	if(sq == "e1") return sqs;	//a crowned piece on e1 cannot jump backward
	if(sq == "e3") {sqs[0] = "c1"; sqs[1] = "g1"; return sqs;}
	if(sq == "e5") {sqs[0] = "c3"; sqs[1] = "g3"; return sqs;}
	if(sq == "e7") {sqs[0] = "c5"; sqs[1] = "g5"; return sqs;}

	if(sq == "f2") return sqs;	//a crowned piece on f2 cannot jump backward
	if(sq == "f4") {sqs[0] = "d2"; sqs[1] = "h2"; return sqs;}
	if(sq == "f6") {sqs[0] = "d4"; sqs[1] = "h4"; return sqs;}
	if(sq == "f8") {sqs[0] = "d6"; sqs[1] = "h6"; return sqs;}

	if(sq == "g1") return sqs;	//a crowned piece on g1 cannot jump backward
	if(sq == "g3") {sqs[0] = "e1"; return sqs;}
	if(sq == "g5") {sqs[0] = "e3"; return sqs;}
	if(sq == "g7") {sqs[0] = "e5"; return sqs;}

	if(sq == "h2") return sqs;	//a crowned piece on h2 cannot jump backward
	if(sq == "h4") {sqs[0] = "f2"; return sqs;}
	if(sq == "h6") {sqs[0] = "f4"; return sqs;}
	if(sq == "h8") {sqs[0] = "f6"; return sqs;}
	
	error("Exception: constructor use without an accessible square");
}

} // namespace sq