#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    return ;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "(SC4V-TP) " << name << ": Halt, moon citizen! I've been chosen to stand out here...\n";

    ClapTrap::setStats(100, 100, 100, 100, 1, name, 30, 20, 5);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "The robot is floating away into space...\n";
}

ScavTrap &ScavTrap::operator= (ScavTrap const &Scav)
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
std::string ScavTrap::getChallenge()
{
    return (this->_challenge);
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