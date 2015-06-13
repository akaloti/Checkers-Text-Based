/*
  Definitions of class Button member functions.
*/

#include "Button.h"

namespace btn {

sf::RectangleShape Button::button() {
  return button_;
}

sf::Text Button::button_text() {
  return button_text_;
}

} // namespace btn