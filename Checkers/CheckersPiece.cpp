#include "CheckersPiece.h"

namespace ch {

Piece::Piece(const float &radius, 
        const sf::Color &color, 
        const float &outlineThickness)
    : circle(radius)
{
  circle.setFillColor(color);
  circle.setOutlineThickness(outlineThickness);
  circle.setOutlineColor(sf::Color::White);
}


// Uses renderWindow's draw method to draw the Piece.
// Draws Piece's member sf::CircleShape circle.
void Piece::draw(sf::RenderWindow &renderWindow) {
  renderWindow.draw(circle);
}


// Repositions the Piece, ignoring the outline thickness (i.e. the x and y
// coordinates start at the actual shape, not the outline).
// Uses member sf::CircleShape circle's setPosition() method.
void Piece::setPosition(const sf::Vector2f &newPosition) {
  circle.setPosition(newPosition);
}

void Piece::setColor(const sf::Color &newColor) {
  circle.setFillColor(newColor);
}

void Piece::setOutlineColor(const sf::Color &newColor) {
  circle.setOutlineColor(newColor);
}

sf::CircleShape Piece::getCircle() {
  return circle;
}

sf::Vector2f Piece::getPosition() {
  return circle.getPosition();
}

} // namespace ch