#include "person.hpp"
#include <SFML/Graphics.hpp>

Person::Person(int expected_satisfaction_, int current_satisfaction_, int ID_)
{
    person_object.setRadius(5);
    comfort_zone.setRadius(10);
    expected_satisfaction = expected_satisfaction_;
    current_satisfaction = current_satisfaction_;
    ID = ID_;
    change_color();

}

void Person::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    target.draw(person_object);

}


void Person::change_color()
{
    if (current_satisfaction == 5)//very happy
    {
        person_object.setFillColor(sf::Color(0, 255, 0));
        comfort_zone.setFillColor(sf::Color(0,255,0,100));
    }
    else if (current_satisfaction == 4)//happy
    {
        person_object.setFillColor(sf::Color(137, 255, 0));
        comfort_zone.setFillColor(sf::Color(137,255,0,100));
    }
    else if (current_satisfaction == 3)//neutral
    {
        person_object.setFillColor(sf::Color(255, 255, 0));
        comfort_zone.setFillColor(sf::Color(255, 255, 0, 100));
    }
    else if (current_satisfaction == 2) //unhappy
    {
        person_object.setFillColor(sf::Color(255, 128, 0));
        comfort_zone.setFillColor(sf::Color(255, 128, 0, 100));
    }
    else if (current_satisfaction == 1)//very unhappy
    {
        person_object.setFillColor(sf::Color(255, 0 , 0));
        comfort_zone.setFillColor(sf::Color(255, 0, 0, 100));
    }
}

int Person::getID()
{
    return ID;
}

int Person::getCurrent_satisfaction()
{
    return current_satisfaction;
}

void Person::setCurrent_satisfaction(int x)
{
    current_satisfaction = x;
    change_color();
}

int Person::getExpected_satisfaction()
{
    return expected_satisfaction;
}

void Person::setExpected_satisfaction(int x)
{
    x = expected_satisfaction;
}

float Person::getOrientation()
{
    return orientation;
}

void Person::setOrientation(float angle)
{
    orientation = angle;
}

void Person::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void Person::setPosition(const sf::Vector2f& pos)
{
    position = pos;
}

/*void Person::draw(sf::RenderWindow* window)
{
    window->draw(person_object);
}*/

sf::Vector2f& Person::getPosition()
{
    return position;//error
}
