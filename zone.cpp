#include "zone.hpp"

namespace {
	const float TILE_SIZE = 25.f;
}

Zone::Zone(const std::string &ident, const std::vector<sf::Vector2f> &points) : identifier(ident) {
	area.setPointCount(points.size());
	std::size_t index = 0;
	for(auto point : points) {
		area.setPoint(index, point * TILE_SIZE);
		++index;
	}
	// dirty cut corner
	float x = 175.f, y = 15.f;
	if(identifier == "stage") {
		area.setPosition(sf::Vector2f(x,y));
		area.setFillColor(sf::Color(125, 125, 125));
	} else if(identifier == "floor") {
		area.setPosition(sf::Vector2f(x,y));
		area.setFillColor(sf::Color(60, 100, 100));
	} else if(identifier == "lobby") {
		area.setPosition(sf::Vector2f(x,y));
		area.setFillColor(sf::Color(100, 60, 100));
	} else if(identifier == "foyer") {
		area.setPosition(sf::Vector2f(x,y));
		area.setFillColor(sf::Color(100, 100, 60));
	}
}


void Zone::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(area);
}
