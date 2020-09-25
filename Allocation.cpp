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

void showThing(Thing t)
{
    std::cout << "showThing " << t.name << " " << t.size << std::endl;
   
}

void showRefThing(Thing &t)
{
    std::cout << "showRefThing " << t.name << " " << t.size << std::endl;
    t.size += 10;
    std::cout << "showThing " << t.name << " " << t.size << std::endl;
}

std::shared_ptr<Thing> savedThing;

int main()
{
    Thing t("fred", 5);
    showThing(t);
    showRefThing(t);
    showThing(t);
    showRefThing(t);
    std::cout << "ending";
}