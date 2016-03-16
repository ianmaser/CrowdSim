#include <SFML/Graphics.hpp>
#include <vector>
#include "person.h"

void setBehaviors(std::vector<Person> p){
    for(auto i = p.begin(); i != p.end(); i++)
    {
        if (i->getCurrent_satisfaction()==5)
        {
            //
        }
        else if (i->getCurrent_satisfaction()==4)
        {

        }
        else if (i->getCurrent_satisfaction()==3)
        {

        }
        else if (i->getCurrent_satisfaction()==2)
        {

        }
        else if (i->getCurrent_satisfaction()==1)
        {

        }
    }
}
