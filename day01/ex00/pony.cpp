#include "pony.hpp"

Pony::Pony(std::string aName, std::string aColour, std::string aBreed): 
name(aName), colour(aColour), breed(aBreed){};

Pony::~Pony()
{
    std::cout << "Pony has left the stable. \n";
}

void    ponyOnTheStack() {
    std::cout << "STACK pony: \n";
    Pony aPony("Windstep", "grey", "Spanish Mustang");
    aPony.getPony();
}

void    ponyOnTheHeap() {
    std::cout << "HEAP pony: \n";
    Pony* aPony2 = new Pony("Freya", "black", "Fresian");

    aPony2->getPony();

    delete aPony2;
}

void Pony::getPony() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Colour: " << colour << "\n";
    std::cout << "Breed: " << breed << "\n";
}