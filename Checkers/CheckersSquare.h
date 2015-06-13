#ifndef CHECKERSSQUARE_H
#define CHECKERSSQUARE_H

#include <SFML/Graphics.hpp>
#include "CheckersPiece.h"

namespace ch {

// Represents an individual square of a checkers board.
class Square {
 public:
  
  // A constant for each accessible square in a checkers board.
  // Last is to allow iteration through all of these constants
  // (see Board::positionAccessibleSquares() for an example).
	/*enum Name {
		a1, a3, a5, a7,
		b2, b4, b6, b8,
		c1, c3, c5, c7,
		d2, d4, d6, d8,
		e1, e3, e5, e7,
		f2, f4, f6, f8,
		g1, g3, g5, g7,
		h2, h4, h6, h8,
		last
	};*/

  enum Name {
    a1, c1, e1, g1,
    b2, d2, f2, h2,
    a3, c3, e3, g3,
    b4, d4, f4, h4,
    a5, c5, e5, g5,
    b6, d6, f6, h6,
    a7, c7, e7, g7,
    b8, d8, f8, h8,
    last
  };

  // The following 16 constants are used to position each square.
  // For example, on a ch::Board with dimensions 800 by 800, each square
  // should be 100 by 100. The squareLength is 100. 
  // Assuming the board is positioned at (0,0), each square can be position 
  // with coordinates
  // (squareLength * kColumn_X_positional_multiplier,
  //  squareLength * kRow_X_positional_multiplier).
  // 
  // Example usage: square a1 should be set with setPosition() to 
  // (squareLength * kColumn_a_positional_multiplier,
  //  squareLength * kRow_a_positional_multiplier).
  // This would set square a1 to
  // (100 * 0, 100 * 7), or (0, 700), which correctly positions square a1 at
  // the bottom left of a 800 by 800 checkers board positioned at (0, 0).
  // 
  // Columns for use on X coordinates:
	static const int kColumn_a_positional_multiplier = 0;
	static const int kColumn_b_positional_multiplier = 1;
	static const int kColumn_c_positional_multiplier = 2;
	static const int kColumn_d_positional_multiplier = 3;
	static const int kColumn_e_positional_multiplier = 4;
	static const int kColumn_f_positional_multiplier = 5;
	static const int kColumn_g_positional_multiplier = 6;
	static const int kColumn_h_positional_multiplier = 7;
  // Rows for use on Y coordinates:
	static const int kRow_1_positional_multiplier = 7;
	static const int kRow_2_positional_multiplier = 6;
	static const int kRow_3_positional_multiplier = 5;
	static const int kRow_4_positional_multiplier = 4;
	static const int kRow_5_positional_multiplier = 3;
	static const int kRow_6_positional_multiplier = 2;
	static const int kRow_7_positional_multiplier = 1;
	static const int kRow_8_positional_multiplier = 0;

	
	Square(const float length, 
         const sf::Color &color = sf::Color::Black, 
				 const sf::Vector2f &position = sf::Vector2f(0,0));

  // Draws the square to the renderWindow.
	void draw(sf::RenderWindow &renderWindow);


  // Returns the position for square.
  // int square should be a member of enum Name, otherwise coordinates (0, 0)
  // will be returned.
	static sf::Vector2f set_sq_position(int square, const float &squareLength);
	
  // Each of these are called by set_sq_position() to determine an individual
  // square's position.
	static sf::Vector2f set_a1_position(const float &squareLength);
	static sf::Vector2f set_a3_position(const float &squareLength);
	static sf::Vector2f set_a5_position(const float &squareLength);
	static sf::Vector2f set_a7_position(const float &squareLength);
	static sf::Vector2f set_b2_position(const float &squareLength);
	static sf::Vector2f set_b4_position(const float &squareLength);
	static sf::Vector2f set_b6_position(const float &squareLength);
	static sf::Vector2f set_b8_position(const float &squareLength);
	static sf::Vector2f set_c1_position(const float &squareLength);
	static sf::Vector2f set_c3_position(const float &squareLength);
	static sf::Vector2f set_c5_position(const float &squareLength);
	static sf::Vector2f set_c7_position(const float &squareLength);
	static sf::Vector2f set_d2_position(const float &squareLength);
	static sf::Vector2f set_d4_position(const float &squareLength);
	static sf::Vector2f set_d6_position(const float &squareLength);
	static sf::Vector2f set_d8_position(const float &squareLength);
	static sf::Vector2f set_e1_position(const float &squareLength);
	static sf::Vector2f set_e3_position(const float &squareLength);
	static sf::Vector2f set_e5_position(const float &squareLength);
	static sf::Vector2f set_e7_position(const float &squareLength);
	static sf::Vector2f set_f2_position(const float &squareLength);
	static sf::Vector2f set_f4_position(const float &squareLength);
	static sf::Vector2f set_f6_position(const float &squareLength);
	static sf::Vector2f set_f8_position(const float &squareLength);
	static sf::Vector2f set_g1_position(const float &squareLength);
	static sf::Vector2f set_g3_position(const float &squareLength);
	static sf::Vector2f set_g5_position(const float &squareLength);
	static sf::Vector2f set_g7_position(const float &squareLength);
	static sf::Vector2f set_h2_position(const float &squareLength);
	static sf::Vector2f set_h4_position(const float &squareLength);
	static sf::Vector2f set_h6_position(const float &squareLength);
	static sf::Vector2f set_h8_position(const float &squareLength);

	
  sf::Vector2f getSize() const;
	
  sf::Vector2f getPosition() const;
	
  sf::Color getColor() const;

	void setSize(const sf::Vector2f &newSize);

	void setPosition(const sf::Vector2f &newPosition);

	void setColor(const sf::Color &newColor);

  // Returns a set of coordinates that, if used to position Piece
  // piece_to_place.circle, will center the piece_to_place on this Square.
  sf::Vector2f getCoordinatesToPlacePiece(Piece &piece_to_place);

 private:
  // Makes up the square. Is drawn in Square::draw().
	sf::RectangleShape square;

  // Is private because is only used in sf::Vector2f
  // getCoordinatesToPlacePiece() and has no other purpose.
  // Returns coordinates of the center of the square.
  sf::Vector2f getCenterCoordinates();
};

} // namespace ch

#endif