#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

    std::string   _challenge;

public:
    ScavTrap();
    ScavTrap(std::string);
    ~ScavTrap();
    ScavTrap &operator=(ScavTrap const &Scav);

    std::string getChallenge();

    void challengeNewcomer(std::string const &target);

};

#endif