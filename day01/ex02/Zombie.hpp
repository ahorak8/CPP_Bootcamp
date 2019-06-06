#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string name;
    std::string type;
public:
    Zombie(std::string aName);
    Zombie(std::string aName, std::string aType);
    ~Zombie();
    void announce();
};
 
#endif