#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
    setZombieType();
}

ZombieEvent::~ZombieEvent()
{
    std::cout << "Boom. Zombie Event over. \n";
}

void ZombieEvent::setZombieType() 
{
    std::string typesList[5] = {"Human", "Dog", "Dragon", "Elf", "Orc"};
    int index = rand() % 4;
    type = typesList[index];
}

Zombie* ZombieEvent::newZombie(std::string name) 
{
    Zombie *newZombie = new Zombie(name, type);
    return (newZombie);
}

Zombie* ZombieEvent::randomChump()
{
    std::string namesList[6] = {"Kaz", "Nina", "Inej", "Wylan", "Matthias", "Jesper"};
    int index = rand() % 5;
    std::string name = namesList[index];

    Zombie *newZombie = new Zombie(name, type);
    newZombie->announce();
    return(newZombie);
}
