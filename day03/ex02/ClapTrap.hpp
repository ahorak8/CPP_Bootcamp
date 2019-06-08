#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    unsigned int _hitPoints;
    unsigned int _maxHitPoints;
    unsigned int _energyPoints;
    unsigned int _maxEnergyPoints;
    unsigned int _level;
    std::string _name;

    unsigned int _meleeAttackDamage;
    unsigned int _rangedAttackDamage;
    unsigned int _armorDamageReduction;

public:
    ClapTrap();
    ClapTrap(std::string);
    ~ClapTrap();
    ClapTrap  &operator=(ClapTrap const &Clap);

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);

    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);  

    unsigned int getDamage(std::string attack);

    std::string getName();

    void setStats(unsigned int hitPoints,
    unsigned int maxHitPoints,
    unsigned int energyPoints,
    unsigned int maxEnergyPoints,
    unsigned int level,
    std::string name,
    unsigned int meleeAttackDamage,
    unsigned int rangedAttackDamage,
    unsigned int armorDamageReduction);
};

#endif