#ifndef PERSON_HPP
#define PERSON_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Person : public sf::Drawable {
    public:
        Person(int expected_satisfaction_, int current_satisfaction_, int ID_);

        int getCurrent_satisfaction();
        void setCurrent_satisfaction(int x);
        int getExpected_satisfaction();
        void setExpected_satisfaction(int x);
        int getID();
        sf::Vector2f& getPosition();
        void setPosition(float x, float y);
        void setPosition (const sf::Vector2f &pos);
        void setOrientation(float angle);
        float getOrientation();




    private:
        int ID;
        int current_satisfaction;
        int expected_satisfaction;
        sf::Vector2f position;
        float orientation;
        sf::CircleShape person_object;
        sf::CircleShape comfort_zone;
		
        void change_color();
		
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PERSON_HPP