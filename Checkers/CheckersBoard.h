#ifndef CHECKERSBOARD_H
#define CHECKERSBOARD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "square.h"
#include "CheckersSquare.h"
#include "CheckersPiece.h"

namespace ch {

// Represents the entire checkers board and all its squares as class
// Square.
class Board {
 public:

  Board(const float boardLength = 0.0,
        const sf::Color &color1 = sf::Color::Red,
        const sf::Color &color2 = sf::Color::Black,
        const sf::Color &borderColor = sf::Color::Blue);


  // Draws the class object's members: sf::RectangleSquare board and the
  // contents of std::vector<ch::Square> squaresVect to the renderWindow.
  void draw(sf::RenderWindow &renderWindow, std::vector<sq::Square> &squares_list);

  sf::RenderWindow* getWindow() const;

  sf::Vector2f getSize() const;

  float getBorderThickness() const;

  sf::Color getBorderColor() const;

  sf::Vector2f getPosition() const;

  sf::Color getSquareColor1() const;

  sf::Color getSquareColor2() const;

  void setWindow(sf::RenderWindow &newWindow);

  void setSize(const sf::Vector2f &newSize);

  void setBorderThickness(const float &newBorderThickness);

  void setBorderColor(const sf::Color &newBorderColor);

  // Changes the position of both sf::RectangleSquare board and the members
  // of std::vector<ch::Square> squaresVect.
  void setPosition(const sf::Vector2f &newPosition);

  void setSquareColor1(const sf::Color &newColor);

  void setSquareColor2(const sf::Color &newColor);
  
  void drawPieces(sf::RenderWindow &window,
                 std::vector<sq::Square> &updates);

  std::string interpretClick(sf::Event &what, std::vector<sq::Square> &squares);

 private:
  
  // The window that the board will be drawn to.
  sf::RenderWindow* window;

  // Makes up the large square that the board is, but without the individual
  // 64 squares. Is drawn in Board::draw().
  sf::RectangleShape board;

  
  // Holds the minor squares of the checkers board. Those squares are
  // each represent by type ch::Square and stored in this vector. Only
  // contains 32 ch::Squares because it only holds the accessible squares.
  // Contents are drawn in Board::draw(). By drawing its 32 squares, the
  // board appears to have all 64 squares, making memory usage on 32
  // additional squares unnecessary.
  std::vector<Square> squaresVect;
  

  // Color of the accessible squares, such as a1 and h8.
  sf::Color squareColor1;


  // Color of the inaccessible squares, such as a2 and h7.
  sf::Color squareColor2;


  // Length of each of the 64 individual squares that make up the board,
  // NOT the length of the board itself.
  float squareLength;


  // Used in the contructor to intialize the squareLength by dividing the
  // boardLength by this constant, as a checkers board is 8 squares by 8
  // squares.
  static const int boardLengthInSquares = 8;


  // Constructs and positions the 32 ch::Square objects and stores them
  // all in std::vector<ch::Square> squaresVect.
  void setAccessibleSquares(const sf::Color &color,
                            const float &squareLength);


  // Called by setAccessibleSquares() to construct the 32 ch::Square objects
  // and place them in std::vector<ch::Square> squaresVect.
  void constructAccessibleSquares(const sf::Color &color);


  // Called by setAccessibleSquares() to position each of the 32 ch::Square
  // objects in std::vector<ch::Square> squaresVect.
  void positionAccessibleSquares(const float &squareLength);

  
  // Called by draw() to draw the 32 ch::Square objects in
  // std::vector<ch::Square> squaresVect to the renderWindow.
  void drawSquares(sf::RenderWindow &renderWindow);


  // Called by setPosition() to adjust the positions of each of the 32
  // ch::Square objects in std::vector<ch::Square> squaresVect.
  void adjustSquaresPositions(const sf::Vector2f &positionalChange);

};

} // namespace ch

#endif