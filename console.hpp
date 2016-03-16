#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <SFML/Graphics.hpp>

namespace f32 {


class Console : public sf::Drawable {
  public:
    Console();
  
    bool is_visible() const { return visible; }
    void toggle() { visible = !visible; }
    
    void process_input(sf::Event event);

  private:
    bool visible;
    sf::Font font;
    sf::Text prompt;
    sf::String input;
    std::vector<sf::String> messages;
    sf::RectangleShape pane;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}; // namespace f32
#endif