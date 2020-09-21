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

void showThingUnsafe(Thing* t)
{
    std::cout << "showThingUnsafe " << t->name << " " << t->size << std::endl;
}

std::shared_ptr<Thing> savedThing;

int main()
{
    {
        auto thing = std::make_shared<Thing>("fred", 5);

        showThing(thing);

        savedThing = thing;
        std::cout << "End of scope" << std::endl;
    }
    showThingUnsafe(savedThing.get());

    showThing(savedThing);
    savedThing.reset();

    std::cout << "Leaving main";
}