#include <fstream>
#include <sstream>
//#include <string>

#include "venue.hpp"

/* temp */
#include <iostream>

#define LINE_SIZE 256

void Venue::load_from_file(std::string filename) {
    std::vector<std::string> lines;
    std::ifstream file;
    file.open(filename.c_str());
    if(file.good()) {
        while(!file.eof()) {
            char line[LINE_SIZE];
            file.getline(line, LINE_SIZE);
            lines.emplace_back(static_cast<std::string>(line));
        }
    }
    file.close();
    
    construct_from(lines);
}


void Venue::add_occupant(Person &&person) {
    if(occupants.size() < capacity) {
        occupants.push_back(person);
    }
}


void Venue::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // draw venue
	for(const auto zone : zones)
		target.draw(zone);
    for(const auto occupant : occupants)
        target.draw(occupant);
}


void Venue::construct_from(const std::vector<std::string> &lines) {
	auto iter = lines.begin();
	std::stringstream sstream(*iter);
	sstream >> name >> capacity;
	++iter;
	for(; iter != lines.end(); ++iter) {
		sstream.str(*iter);
		sstream.seekg(std::ios_base::beg);
		std::string ident;
		sstream >> ident;
		if(ident != "en") {
			std::vector<sf::Vector2f> points;
			sf::Vector2f point;
			char delimiter = ',';
			do {
				sstream >> point.x >> point.y >> delimiter;
				points.push_back(point);
			} while(delimiter != ';');
			zones.emplace_back(Zone(ident, points));
		} else {
			/* handle entrance */
		}
	}
}