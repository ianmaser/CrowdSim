#ifndef VENUE_HPP
#define VENUE_HPP

#include <SFML/Graphics.hpp>
#include "person.hpp"

class Venue : public sf::Drawable {
  public:
    
    void load_from_file(std::string filename);
    void add_occupant(Person person);

  private:
    std::string name;
    std::size_t capacity;
    std::vector<Person> occupants;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif