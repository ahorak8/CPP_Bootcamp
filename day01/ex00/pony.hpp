#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony
{
private:
    std::string name;
    std::string colour;
    std::string breed;
public:
    Pony(std::string aName, std::string aColour, std::string aBreed);
    ~Pony();
    void getPony() const;
};

void ponyOnTheStack();
void ponyOnTheHeap();


#endif