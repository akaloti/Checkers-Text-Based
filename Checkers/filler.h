/*	Chart of vector addresses:
	
	       | 28|   | 29|   | 30|   | 31
	8   ___|___|___|___|___|___|___|___
	     24|   | 25|   | 26|   | 27|
	7   ___|___|___|___|___|___|___|___
	       | 20|   | 21|   | 22|   | 23
	6   ___|___|___|___|___|___|___|___
	     16|   | 17|   | 18|   | 19|
	5   ___|___|___|___|___|___|___|___
	       | 12|   | 13|   | 14|   | 15
	4   ___|___|___|___|___|___|___|___
	      8|   |  9|   | 10|   | 11|
	3   ___|___|___|___|___|___|___|___
	       |  4|   |  5|   |  6|   |  7
	2   ___|___|___|___|___|___|___|___
	      0|   |  1|   |  2|   |  3|
	1   ___|___|___|___|___|___|___|___
	     a   b   c   d   e   f   g   h

	See either function void checkers::prepare_game() or void checkers::display_board() for the coding of these vector addresses.

	How capture is detected:
	There are eight kinds of relationships that indicate a capture (four for red, four for black).
	The directional words (right/left) describe the direction of the movement of the selected piece.

		Red:
			1) start odd-numbered row, going right:
				3         sq
						 /
				2      sq
					  /
				1  sq
					a  b  c
				-In the above example, the piece on a1 is jumping to c3, capturing the piece on b2.
				-The vector address of a1 is 0, of b2 is 4, and of c3 is 9.
				-Notice that from a1, the initial square, to b2, the captured square, the jump in address is 4 (0 to 4).
				-Notice that from b2 to c3, the landing square, the jump in address is 5 (4 to 9).
				-The jump in addresses remain the same in any red piece's jump from a square on an odd-numbered row 
				 (to another odd-numbered row), so long as the direction of capture is right (as opposed to left).
				-For example:
				7         sq
						 /
				6      sq
					  /
				5  sq
					e  f  g
				-The vector address of e5 is 18, of f6 is 22, and of g7 is 27.
				-Notice that from e5 to f6, the jump in address is 4 (18 to 22).
				-Notice that from f6 to g7, the jump in address is 5 (22 to 27).
			
			2) start even-numbered row, going right:
				6         sq
						 /
				5      sq
					  /
				4  sq
					d  e  f
				-In the above example, the piece on d4 is jumping to f6, capturing the piece on e5.
				-The vector address of d4 is 13, of e5 is 18, and of f6 is 22.
				-Notice that from d4, the initial square, to e5, the captured square, the jump in address is 5 (13 to 18).
				-Notice that from e5 to f6, the landing square, the jump in address is 4 (18 to 22).
				-The jump in addresses remain the same in any red piece's jump from a square on an even-numbered row 
				 (to another even-numbered row), so long as the direction of capture is right (as opposed to left).
			
			3) start odd-numbered row, going left:
				5  sq
					  \
				4      sq
					     \
				3         sq
					c  d  e
				-In the above example, the piece on e3 is jumping to c5, capturing the piece on d4.
				-The vector address of e3 is 10, of d4 is 13, and of c5 is 17.
				-Notice that from e3, the initial square, to d4, the captured square, the jump in address is 3 (10 to 13).
				-Notice that from d4 to c5, the landing square, the jump in address is 4 (13 to 17).
				-The jump in addresses remain the same in any red piece's jump from a square on an odd-numbered row 
				 (to another odd-numbered row), so long as the direction of capture is left.
				
			4) start even-numbered row, going left
				4  sq
					  \
				3      sq
					     \
				2         sq
					f  g  h
				-In the above example, the piece on h2 is jumping to f4, capturing the piece on g3.
				-The vector address of h2 is 7, of g3 is 11, and of f4 is 14.
				-Notice that from h2, the initial square, to g3, the captured square, the jump in address is 4 (7 to 11).
				-Notice that from g3 to f4, the landing square, the jump in address is 3 (11 to 14).
				-The jump in addresses remain the same in any red piece's jump from a square on an even-numbered row
				 (to another even-numbered row), so long as the direction of movement is left.

		Black:
			1) start odd-numbered row, going left (from our view):
				3         sq
						 /
				2      sq
					  /
				1  sq
					a  b  c
				-In the above example, the piece on c3 is jumping to a1, capturing the piece on b2.
				-The vector address of c3 is 9, of b2 is 4, and of a1 is 0.
				-Notice that from c3, the initial square, to b2, the captured square, the drop in address is 5 (9 to 4).
				-Notice that from b2 to a1, the landing square, the drop in address is 4 (4 to 0).

			2) start even-numbered row, going left:
				6         sq
						 /
				5      sq
					  /
				4  sq
					d  e  f
				-In the above example, the piece on f6 is jumping to d4, capturing the piece on e5.
				-The vector address of f6 is 22, of e5 is 18, and of d4 is 13.
				-Notice that from f6, the initial square, to e5, the captured square, the drop in address is 4 (22 to 18).
				-Notice that from e5 to d4, the landing square, the drop in address is 5 (18 to 13).

			3) start odd-numbered row, going right:
				5  sq
					  \
				4      sq
					     \
				3         sq
					c  d  e
				-The vector address of c5 is 17, of d4 is 13, and of e3 is 10.
				-From c5 to d4, the drop in address is 4 (17 to 13).
				-From d4 to e3, the drop in address is 3 (13 to 10).

			4) start even-numbered row, going right:
				4  sq
					  \
				3      sq
					     \
				2         sq
					f  g  h
				-The vector address of f4 is 14, of g3 is 11, and of h2 is 7.
				-From f4 to g3, the drop in address is 3 (14 to 11).
				-From g3 to h2, the drop in address is 4 (11 to 7).*/