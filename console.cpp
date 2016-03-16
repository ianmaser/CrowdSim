#include "console.hpp"

f32::Console::Console() : visible(false) {
    font.loadFromFile("lucon.ttf");
    prompt.setFont(font);
    prompt.setString("> ");
    prompt.setCharacterSize(13);
    prompt.setColor(sf::Color::Green);    
    pane.setSize(sf::Vector2f(640, 480));
    pane.setFillColor(sf::Color(82, 94, 84, 123));
}

void f32::Console::process_input(sf::Event event) {
    if(event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Return) {
        prompt.setString("> ");
        sf::String message(input);
        messages.emplace_back(message);
        if(messages.size() > 32) {
            messages.erase(messages.begin());
        }
        input.clear();
    } else if(event.type == sf::Event::TextEntered) {
        auto unicode_char = event.text.unicode;
        auto line = prompt.getString();
        auto size = line.getSize();
        if(unicode_char != '`' and unicode_char > 31) {
            line += sf::String(unicode_char);
        } else if(unicode_char == 8 and size > 2) {
            line.erase(size - 1);
        }
        prompt.setString(line);
        line.erase(0, 2);
        input = line;
    }
}


void f32::Console::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(visible) {
        target.draw(pane, states);
        target.draw(prompt, states);
        auto height = 15.f;
        auto iterator = messages.rbegin();
        for(auto i = 1; i * height < 480; ++i) {
            if(iterator == messages.rend())
                return;
            sf::Text message(*iterator, font, 13);
            message.setPosition(0.f, i * height);
            target.draw(message, states);
            ++iterator;
        }
    }
}