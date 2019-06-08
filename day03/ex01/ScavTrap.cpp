#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    return ;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "(SC4V-TP) " << name << ": Halt, moon citizen! I've been chosen to stand out here...\n";

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

ScavTrap::~ScavTrap(void)
{
    std::cout << "The robot is floating away into space...\n";
}

ScavTrap
&ScavTrap::operator= (ScavTrap const &Scav)
{
	this->_name = Scav._name;
	this->_hitPoints = Scav._hitPoints;
	this->_maxHitPoints = Scav._maxHitPoints;
	this->_energyPoints = Scav._energyPoints;
	this->_maxEnergyPoints = Scav._maxEnergyPoints;
	this->_level = Scav._level;
	this->_meleeAttackDamage = Scav._meleeAttackDamage;
	this->_rangedAttackDamage = Scav._rangedAttackDamage;
	this->_armorDamageReduction = Scav._armorDamageReduction;
    return (*this);
}

std::string ScavTrap::getName()
{
    return this->_name;
}

std::string ScavTrap::getChallenge()
{
    return (this->_challenge);
}

void ScavTrap::takeDamage(unsigned int amount)
{
    unsigned int damage;
    unsigned int remainingHP;

    damage = amount - this->_armorDamageReduction;
    if (damage > this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << "(SC4V-TP) " << this->_name << ": Robot down! \n" ;
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

void ScavTrap::beRepaired(unsigned int amount)
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
    std::cout << "(SC4V-TP) " << this->_name << ": You can't keep a good 'bot down!\n";
    return ;
}

unsigned int ScavTrap::getDamage(std::string attack)
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

void ScavTrap::meleeAttack(std::string const &target) 
{
    std::cout << "(SC4V-TP) <" << _name << "> slaps <" << target << ">, ";
    std::cout << "causing <" << _meleeAttackDamage << "> points of damage ! \n";
    std::cout << "(SC4V-TP) " << target << ": Ow you slapped me! \n";
    return ;
}

void ScavTrap::rangedAttack(std::string const &target) 
{
    std::cout << "(SC4V-TP) <" << _name << "> throws a rock at <" << target << ">, ";
    std::cout << "causing <" << _rangedAttackDamage << "> points of damage ! \n";
    std::cout << "(SC4V-TP) " << target << ": Did you just throw a rock at me?? \n";
    return ;
}

void ScavTrap::challengeNewcomer(std::string const &target)
{
    int challengeNumber;

    std::string challenge[] =
    {
        "eat a tablespoon of cinnamon!",
        "eat an entire raw onion!",
        "the chubby bunny challenge!",
        "run around like a chicken!",
        "to the ice bucket challenge!",
        "to draw something blindfolded"
    };

    srand(time(NULL));
    challengeNumber = rand() % 6;
    this->_challenge = challenge[challengeNumber];
    std::cout << "(SC4V-TP) " << this->_name << ": I challenge you, " << target <<", to " << this->_challenge << "\n";

    return ;
}