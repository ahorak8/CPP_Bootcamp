#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
private:
    unsigned int _iceAttackDamage;
    unsigned int _insultAttackDamage;
    unsigned int _headButtAttackDamage;
    unsigned int _vaultHunterDamage;

public:
    FragTrap();
    FragTrap(std::string);
    ~FragTrap();
    FragTrap &operator=(FragTrap const &Frag);

    void iceAttack(std::string const &target);
    void insultAttack(std::string const &target);
    void headButtAttack(std::string const &target);

    void vaulthunter_dot_exe(std::string const &target);

    unsigned int getVaultHunterDamage();

    unsigned int getDamage(std::string attack);
};

#endif