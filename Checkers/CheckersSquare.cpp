#include "CheckersSquare.h"

namespace ch {

//Public functions:

// Creates and initializes sf::RectangleShape square, the only member
// variable.
Square::Square(const float length,
					     const sf::Color &color, 
					     const sf::Vector2f &position)
	: square(sf::RectangleShape(sf::Vector2f(length, length)))
{
	square.setPosition(position);
	square.setFillColor(color);
}


// Calls renderWindow's draw() method.
void Square::draw(sf::RenderWindow &renderWindow) {
	renderWindow.draw(square);
}

// Compares int square, which should be an enum Name, to the other members
// of enum Name to determine which square positioning function to call.
// squareLength is needed to determine exact coordinates (see comments in
// CheckersSquare.h from line 28-41).
sf::Vector2f Square::set_sq_position(int square, const float &squareLength) {
	switch (square) {
	case a1: 
		return set_a1_position(squareLength);
	case a3:
		return set_a3_position(squareLength);
	case a5:
		return set_a5_position(squareLength);
	case a7:
		return set_a7_position(squareLength);
	case b2:
		return set_b2_position(squareLength);
	case b4:
		return set_b4_position(squareLength);
	case b6:
		return set_b6_position(squareLength);
	case b8:
		return set_b8_position(squareLength);
	case c1:
		return set_c1_position(squareLength);
	case c3:
		return set_c3_position(squareLength);
	case c5:
		return set_c5_position(squareLength);
	case c7:
		return set_c7_position(squareLength);
	case d2:
		return set_d2_position(squareLength);
	case d4:
		return set_d4_position(squareLength);
	case d6:
		return set_d6_position(squareLength);
	case d8:
		return set_d8_position(squareLength);
	case e1:
		return set_e1_position(squareLength);
	case e3:
		return set_e3_position(squareLength);
	case e5:
		return set_e5_position(squareLength);
	case e7:
		return set_e7_position(squareLength);
	case f2:
		return set_f2_position(squareLength);
	case f4:
		return set_f4_position(squareLength);
	case f6:
		return set_f6_position(squareLength);
	case f8:
		return set_f8_position(squareLength);
	case g1:
		return set_g1_position(squareLength);
	case g3:
		return set_g3_position(squareLength);
	case g5:
		return set_g5_position(squareLength);
	case g7:
		return set_g7_position(squareLength);
	case h2:
		return set_h2_position(squareLength);
	case h4:
		return set_h4_position(squareLength);
	case h6:
		return set_h6_position(squareLength);
	case h8:
		return set_h8_position(squareLength);
	default:
		return sf::Vector2f(0, 0);
	}
}

// The following 32 functions are all used by Square::set_sq_position(), which
// is called by Board::positionAccessibleSquares to position the 32 accessible
// squares on ch::Board.
// See the comments on lines 28-41 of CheckersSquare.h for an in-depth
// explanation.
sf::Vector2f Square::set_a1_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_a_positional_multiplier, 
                      squareLength * kRow_1_positional_multiplier);
}

sf::Vector2f Square::set_a3_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_a_positional_multiplier, 
                      squareLength * kRow_3_positional_multiplier);
}

sf::Vector2f Square::set_a5_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_a_positional_multiplier, 
                      squareLength * kRow_5_positional_multiplier);
}

sf::Vector2f Square::set_a7_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_a_positional_multiplier, 
                      squareLength * kRow_7_positional_multiplier);
}

sf::Vector2f Square::set_b2_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_b_positional_multiplier, 
                      squareLength * kRow_2_positional_multiplier);
}

sf::Vector2f Square::set_b4_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_b_positional_multiplier, 
                      squareLength * kRow_4_positional_multiplier);
}

sf::Vector2f Square::set_b6_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_b_positional_multiplier, 
                      squareLength * kRow_6_positional_multiplier);
}

sf::Vector2f Square::set_b8_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_b_positional_multiplier, 
                      squareLength * kRow_8_positional_multiplier);
}

sf::Vector2f Square::set_c1_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_c_positional_multiplier, 
                      squareLength * kRow_1_positional_multiplier);
}

sf::Vector2f Square::set_c3_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_c_positional_multiplier, 
                      squareLength * kRow_3_positional_multiplier);
}

sf::Vector2f Square::set_c5_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_c_positional_multiplier, 
                      squareLength * kRow_5_positional_multiplier);
}

sf::Vector2f Square::set_c7_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_c_positional_multiplier, 
                      squareLength * kRow_7_positional_multiplier);
}

sf::Vector2f Square::set_d2_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_d_positional_multiplier, 
                      squareLength * kRow_2_positional_multiplier);
}

sf::Vector2f Square::set_d4_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_d_positional_multiplier, 
                      squareLength * kRow_4_positional_multiplier);
}

sf::Vector2f Square::set_d6_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_d_positional_multiplier, 
                      squareLength * kRow_6_positional_multiplier);
}

sf::Vector2f Square::set_d8_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_d_positional_multiplier, 
                      squareLength * kRow_8_positional_multiplier);
}

sf::Vector2f Square::set_e1_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_e_positional_multiplier, 
                      squareLength * kRow_1_positional_multiplier);
}

sf::Vector2f Square::set_e3_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_e_positional_multiplier, 
                      squareLength * kRow_3_positional_multiplier);
}

sf::Vector2f Square::set_e5_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_e_positional_multiplier, 
                      squareLength * kRow_5_positional_multiplier);
}

sf::Vector2f Square::set_e7_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_e_positional_multiplier, 
                      squareLength * kRow_7_positional_multiplier);
}

sf::Vector2f Square::set_f2_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_f_positional_multiplier, 
                      squareLength * kRow_2_positional_multiplier);
}

sf::Vector2f Square::set_f4_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_f_positional_multiplier, 
                      squareLength * kRow_4_positional_multiplier);
}

sf::Vector2f Square::set_f6_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_f_positional_multiplier, 
                      squareLength * kRow_6_positional_multiplier);
}

sf::Vector2f Square::set_f8_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_f_positional_multiplier, 
                      squareLength * kRow_8_positional_multiplier);
}

sf::Vector2f Square::set_g1_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_g_positional_multiplier, 
                      squareLength * kRow_1_positional_multiplier);
}

sf::Vector2f Square::set_g3_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_g_positional_multiplier, 
                      squareLength * kRow_3_positional_multiplier);
}

sf::Vector2f Square::set_g5_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_g_positional_multiplier, 
                      squareLength * kRow_5_positional_multiplier);
}

sf::Vector2f Square::set_g7_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_g_positional_multiplier, 
                      squareLength * kRow_7_positional_multiplier);
}

sf::Vector2f Square::set_h2_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_h_positional_multiplier, 
                      squareLength * kRow_2_positional_multiplier);
}

sf::Vector2f Square::set_h4_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_h_positional_multiplier, 
                      squareLength * kRow_4_positional_multiplier);
}

sf::Vector2f Square::set_h6_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_h_positional_multiplier, 
                      squareLength * kRow_6_positional_multiplier);
}

sf::Vector2f Square::set_h8_position(const float &squareLength) {
	return sf::Vector2f(squareLength * kColumn_h_positional_multiplier, 
                      squareLength * kRow_8_positional_multiplier);
}


sf::Vector2f Square::getSize() const { return square.getSize(); }

sf::Vector2f Square::getPosition() const { return square.getPosition(); }

sf::Color Square::getColor() const { return square.getFillColor(); }

void Square::setSize(const sf::Vector2f &newSize) { square.setSize(newSize); }

void Square::setPosition(const sf::Vector2f &newPosition) { 
  square.setPosition(newPosition); 
}

void Square::setColor(const sf::Color &newColor) { 
  square.setFillColor(newColor); 
}


// To find the coordinates on a square to place piece_to_place's member
// sf::CircleShape circle, a little math is needed. Piece
// piece_to_place's positional coordinates are not on the sf::Circle circle
// itself, but on the invisible square that both makes up the circle's global
// bounds and circumscribes the circle. The position of this invisible square 
// equals the position of sf::Circle circle. The position is equal to the 
// Square's center minus the radius of piece_to_place. 
sf::Vector2f Square::getCoordinatesToPlacePiece(Piece &piece_to_place) {
  
  sf::Vector2f result = (getCenterCoordinates() - 
          sf::Vector2f(piece_to_place.getCircle().getRadius(),
          piece_to_place.getCircle().getRadius()));

  return result;
}



// To find the center of the square, first find the square's local coordinates.
// The square's center's local coordinates' are (half of the square's
// length, half of the square's length). For example, a 4 by 4 square has
// local center coordinates (2, 2). After, those local coordinates
// are added to the square's global positional coordinates, creating the
// square's global center coordinates of the square. For example, a 4 by 4
// square at position (400, 400) has global center coordinates (402, 402) on
// its window.
sf::Vector2f Square::getCenterCoordinates() {
  const int number_of_radii_in_diameter = 2;
  return sf::Vector2f((getSize().x / number_of_radii_in_diameter) + getPosition().x, 
                      (getSize().y / number_of_radii_in_diameter) + getPosition().y);
}

} // namespace ch