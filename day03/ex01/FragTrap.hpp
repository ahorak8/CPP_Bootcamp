#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap
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
    unsigned int _iceAttackDamage;
    unsigned int _insultAttackDamage;
    unsigned int _headButtAttackDamage;
    unsigned int _vaultHunterDamage;

    unsigned int _armorDamageReduction;

public:
    FragTrap();
    FragTrap(std::string);
    ~FragTrap();
    FragTrap &operator=(FragTrap const &Frag);

    std::string getName();

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    void iceAttack(std::string const &target);
    void insultAttack(std::string const &target);
    void headButtAttack(std::string const &target);

    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void vaulthunter_dot_exe(std::string const &target);

    unsigned int getDamage(std::string attack);
    unsigned int getVaultHunterDamage();
};

#endif