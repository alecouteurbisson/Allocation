// Allocation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>      // memory management

class Thing
{
public:
    Thing(std::string name, int size)
    {
        this->name = name;
        this->size = size;
        std::cout << "I made a thing!" << std::endl;
    }

    std::string name;
    int size;

    ~Thing()
    {
        std::cout << "It's a thing of the past" << std::endl;
    }
};

void showThing(std::shared_ptr<Thing> t)
{
    std::cout << "showThing " << t->name << " " << t->size << std::endl;
}

void showThingWeak(std::weak_ptr<Thing> t)
{
    if (auto tt = t.lock())
    {
        std::cout << "showThingWeak " << tt->name << " " << tt->size << std::endl;
    }
    else
    {
        std::cout << "no Thing " << std::endl;
    }
}

std::shared_ptr<Thing> savedThing;

int main()
{
    std::weak_ptr<Thing> weakThing;
    {
        auto thing = std::make_shared<Thing>("fred", 5);

        showThing(thing);

        savedThing = thing;
        weakThing = thing;
        std::cout << "End of scope" << std::endl;
    }

    showThing(savedThing);
    showThingWeak(weakThing);

    savedThing.reset();

    showThingWeak(weakThing);

    std::cout << "Leaving main";
}