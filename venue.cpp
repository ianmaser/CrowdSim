#include <fstream>
#include <string>

#include "venue.hpp"

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
    
    
}


void Venue::add_occupant(Person person) {
    if(occupants.size() < capacity_limit) {
        occupants.push_back(person);
    }
}


void Venue::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // draw venue
    for(occupant : occupants)
        target.draw(occupant);
}