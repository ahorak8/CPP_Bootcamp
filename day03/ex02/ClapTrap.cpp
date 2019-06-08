#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "(CL4P-TP): Welcome Vault Hunter!\n";
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "(CL4P-TP) " << name << ": Welcome Vault Hunter!\n";

    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_level = 1;
    this->_name = name;

    this->_meleeAttackDamage = 30;
    this->_rangedAttackDamage = 20;

    this->_armorDamageReduction = 5;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Goodbye Vault Hunter!\n";
}

void ClapTrap::setStats(unsigned int hitPoints,
                        unsigned int maxHitPoints,
                        unsigned int energyPoints,
                        unsigned int maxEnergyPoints,
                        unsigned int level,
                        std::string name,
                        unsigned int meleeAttackDamage,
                        unsigned int rangedAttackDamage,
                        unsigned int armorDamageReduction)
{
    this->_hitPoints = hitPoints;
    this->_maxHitPoints = maxHitPoints;
    this->_energyPoints = energyPoints;
    this->_maxEnergyPoints = maxEnergyPoints;
    this->_level = level;
    this->_name = name;

    this->_meleeAttackDamage = meleeAttackDamage;
    this->_rangedAttackDamage = rangedAttackDamage;

    this->_armorDamageReduction = armorDamageReduction;

    return ;
}

ClapTrap &ClapTrap::operator= (ClapTrap const &Clap)
{
	this->_name = Clap._name;
	this->_hitPoints = Clap._hitPoints;
	this->_maxHitPoints = Clap._maxHitPoints;
	this->_energyPoints = Clap._energyPoints;
	this->_maxEnergyPoints = Clap._maxEnergyPoints;
	this->_level = Clap._level;
	this->_meleeAttackDamage = Clap._meleeAttackDamage;
	this->_rangedAttackDamage = Clap._rangedAttackDamage;
	this->_armorDamageReduction = Clap._armorDamageReduction;
    return (*this);
}

std::string ClapTrap::getName()
{
    return this->_name;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    unsigned int damage;
    unsigned int remainingHP;

    damage = amount - this->_armorDamageReduction;
    if (damage > this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << "(Cl4P-TP) " << this->_name << ": Robot down! \n" ;
    }
    else
    {
        remainingHP = this->_hitPoints - damage;
        this->_hitPoints = remainingHP;
        std::cout << "Damage Dealt: " << damage << "/" << amount;
        std::cout << " (Damage Reduction: " << this->_armorDamageReduction << ")\n";
        std::cout << "Health Points: " << this->_hitPoints << "/" << this->_maxHitPoints << "\n";
    }
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    unsigned int newHP = this->_hitPoints + amount;
    unsigned int newMP = this->_energyPoints + amount;
    std::cout << "\n\nBeing repaired...\n";

    if (newHP >= this->_maxHitPoints)
    {
        this->_hitPoints = this->_maxHitPoints;
        std::cout << "Health Points: " << this->_hitPoints << "/" << this->_maxHitPoints << "\n";
    }
    if (newHP < this->_maxHitPoints)
    {
        this->_hitPoints = newHP;
        std::cout << "Health Points: " << this->_hitPoints << "/" << this->_maxHitPoints << "\n";
    }
    if (newMP >= this->_maxEnergyPoints)
    {
        this->_energyPoints = this->_maxEnergyPoints;
        std::cout << "Energy Points: " << this->_energyPoints << "/" << this->_maxEnergyPoints << "\n";

    }
    if (newMP < this->_maxEnergyPoints)
    {
        this->_energyPoints = newMP;
        std::cout << "Energy Points: " << this->_energyPoints << "/" << this->_maxEnergyPoints << "\n";
    }
    std::cout << "(Cl4P-TP) " << this->_name << ": You can't keep a good 'bot down!\n";
    return ;
}

unsigned int ClapTrap::getDamage(std::string attack)
{
    if (attack == "melee")
    {
        return (this->_meleeAttackDamage);
    }
    if (attack == "ranged")
    {
        return (this->_rangedAttackDamage);
    }
    else
    {
        std::cout << "Attack not found";
    }
    
    return (0);
}

void ClapTrap::meleeAttack(std::string const &target) 
{
    std::cout << "(Cl4P-TP) <" << _name << "> slaps <" << target << ">, ";
    std::cout << "causing <" << _meleeAttackDamage << "> points of damage ! \n";
    std::cout << "(Cl4P-TP) " << target << ": Ow you slapped me! \n";
    return ;
}

void ClapTrap::rangedAttack(std::string const &target) 
{
    std::cout << "(Cl4P-TP) <" << _name << "> throws a rock at <" << target << ">, ";
    std::cout << "causing <" << _rangedAttackDamage << "> points of damage ! \n";
    std::cout << "(Cl4P-TP) " << target << ": Did you just throw a rock at me?? \n";
    return ;
}
