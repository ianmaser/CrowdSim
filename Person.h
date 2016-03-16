#ifndef PERSON_H
#define PERSON_H
#include <SFML/Graphics.hpp>
#include <vector>

class Person : public sf::Drawable
{
    public:
        Person(int expected_satisfaction_, int current_satisfaction_, int ID_);

        //Desires getDesires();
        int getCurrent_satisfaction();
        void setCurrent_satisfaction(int x);
        int getExpected_satisfaction();
        void setExpected_satisfaction(int x);
        int getID();
        sf::Vector2f& getPosition();
        void setPosition(float x, float y);
        void setPosition (const sf::Vector2f &pos);
        //void draw(sf::RenderWindow* window);
        void setOrientation(float angle);
        float getOrientation();




    private:
        //desires stuff;
        void change_color();
        int current_satisfaction;
        int expected_satisfaction;
        sf::Vector2f position_;
        float orientation;
        sf::CircleShape person_object;
        sf::CircleShape comfort_zone;
        int ID;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;



//        vector<Person> party;//or ints?//work on later


};

#endif // PERSON_H
