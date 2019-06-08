#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
private:
    unsigned int _hitPoints;
    unsigned int _maxHitPoints;
    unsigned int _energyPoints;
    unsigned int _maxEnergyPoints;
    unsigned int _level;
    std::string _name;

    unsigned int _meleeAttackDamage;
    unsigned int _rangedAttackDamage;

    unsigned int _armorDamageReduction;

    std::string   _challenge;

public:
    ScavTrap();
    ScavTrap(std::string);
    ~ScavTrap();
    ScavTrap &operator=(ScavTrap const &Scav);

    std::string getName();

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);

    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    unsigned int getDamage(std::string attack);
    std::string getChallenge();

    void challengeNewcomer(std::string const &target);

};

#endif