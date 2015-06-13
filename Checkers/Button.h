/*
  Includes definition of class Button.
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

namespace btn {

class Button {
 public:
  sf::RectangleShape button();

  sf::Text button_text();

 private:
  // "Physical" button that is the part that the user actually sees and clicks
  // on.
  sf::RectangleShape button_;

  // Text that appears on the button.
  sf::Text button_text_;


};

} // namespace btn

#endif