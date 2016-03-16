#ifndef ZONE_HPP
#define ZONE_HPP

#include <SFML/Graphics.hpp>

class Zone : public sf::Drawable {
  public:
	Zone(const std::string &ident, const std::vector<sf::Vector2f> &points);
	//std::string get_name() const { return name; }
  private:
	std::string identifier;
	sf::ConvexShape area;
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif