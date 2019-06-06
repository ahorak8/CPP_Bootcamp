#include "Zombie.hpp"

Zombie::Zombie(std::string aName): name(aName)
{};

Zombie::Zombie(std::string aName, std::string aType): name(aName), type(aType)
{};

Zombie::~Zombie()
{
    std::cout << "Headshot! You killed the zombie: " << name << "\n";
}

void Zombie::announce() 
{
    if (type == "")
    {
        std::string typesList[5] = {"Human", "Dog", "Dragon", "Elf", "Orc"};
        int index = rand() % 4;
        type = typesList[index];
    }
    
    std::cout << "<" << this->name << " (" << this->type << ")> Braiiiiiiinnnssss... \n";
}
