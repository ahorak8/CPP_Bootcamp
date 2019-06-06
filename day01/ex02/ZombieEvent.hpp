#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent
{
private:
    std::string type;
public:
    ZombieEvent();
    ~ZombieEvent();

    void setZombieType();
    Zombie* newZombie(std::string name);
    Zombie* randomChump();
};

void setZombieType();

#endif