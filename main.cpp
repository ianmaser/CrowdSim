#include <SFML/Graphics.hpp>
#include "console.hpp"
#include "human_factory.hpp"
#include "venue.hpp"

int main(int argc, char** argv) {
    
    sf::RenderWindow window(sf::VideoMode(640, 480), "Crowd Simulator");
    f32::Console console;
	
	Venue venue;
	
	venue.add_occupant(generate_human());
    
    while(window.isOpen()) {

        sf::Event event;
        
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(console.is_visible())
                console.process_input(event);
            if(event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Tilde)
                console.toggle();
        }

        window.clear();
        window.draw(console);
		window.draw(venue);
        window.display();
    }
    
    return 0;
}


