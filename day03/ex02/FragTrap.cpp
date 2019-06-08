#include "FragTrap.hpp"


FragTrap::FragTrap()
{
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "(FR4G-TP) " << name << ": F to the R to the 4 to the G to the WHAAT! \n";

    ClapTrap::setStats(100, 100, 100, 100, 1, name, 30, 20, 5);

    this->_iceAttackDamage = 35;
    this->_insultAttackDamage = 5;
    this->_headButtAttackDamage = 10;

}

FragTrap::~FragTrap()
{
    std::cout << "The robot is dead, long live the robot! \n";
}

FragTrap &FragTrap::operator= (FragTrap const &Frag)
{
    this->_hitPoints = Frag._hitPoints;
    this->_maxHitPoints = Frag._maxHitPoints;
    this->_energyPoints = Frag._energyPoints;
    this->_maxEnergyPoints = Frag._maxEnergyPoints;
    this->_level = Frag._level;
    this->_name = Frag._name;

    this->_meleeAttackDamage = Frag._meleeAttackDamage;
    this->_rangedAttackDamage = Frag._rangedAttackDamage;
    this->_iceAttackDamage = Frag._iceAttackDamage;
    this->_insultAttackDamage = Frag._insultAttackDamage;
    this->_headButtAttackDamage = Frag._headButtAttackDamage;
    this->_armorDamageReduction = Frag._vaultHunterDamage;

    this->_armorDamageReduction = Frag._armorDamageReduction;

    return (*this);
}

unsigned int FragTrap::getDamage(std::string attack)
{
    if (attack == "melee")
    {
        return (this->_meleeAttackDamage);
    }
    if (attack == "ranged")
    {
        return (this->_rangedAttackDamage);
    }
     if (attack == "ice")
    {
        return (this->_iceAttackDamage);
    }
    if (attack == "headbutt")
    {
        return (this->_headButtAttackDamage);
    }
    if (attack == "insult")
    {
        return (this->_insultAttackDamage);
    }
    else
    {
        std::cout << "Attack not found";
    }
    
    return (0);
}

void FragTrap::iceAttack(std::string const &target) 
{
    this->_vaultHunterDamage = this->_iceAttackDamage;
    std::cout << "(FR4G-TP) <" << _name << "> attacks <" << target << "> with ice, ";
    std::cout << "causing <" << _iceAttackDamage << "> points of damage ! \n";
    std::cout << "(FR4G-TP) " << target << ": I am a robot popsicle! \n";
    return ;
}

void FragTrap::insultAttack(std::string const &target) 
{
    this->_vaultHunterDamage = this->_insultAttackDamage;
    std::cout << "(FR4G-TP) <" << _name << "> yells at <" << target << "> 'You're just a bucket of bolts!', ";
    std::cout << "causing <" << _insultAttackDamage << "> points of damage ! \n";
    std::cout << "(FR4G-TP) " << target << ": Extra Ouch! \n";
    return ;
}

void FragTrap::headButtAttack(std::string const &target) 
{
    this->_vaultHunterDamage = this->_headButtAttackDamage;
    std::cout << "(FR4G-TP) <" << _name << "> attacks <" << target << "> with a headbutt, ";
    std::cout << "causing <" << _headButtAttackDamage << "> points of damage ! \n";
    std::cout << "(FR4G-TP) " << target << ": Boing! \n";
    return ;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    int attackNumber;
     unsigned int newMP;

    if (this->_energyPoints < 25)
    {
        std::cout << "Out of energy!";
        std::cout << "Energy Points: " << this->_energyPoints << "/" << this->_maxEnergyPoints << "\n";
    }
    else
    {
        newMP = this->_energyPoints - 25;
        this->_energyPoints = newMP;
        srand(time(NULL));
        attackNumber = rand() % 5;
        if (attackNumber == 0)
            FragTrap::meleeAttack(target);
        else if (attackNumber == 1)
            FragTrap::rangedAttack(target);
        else if (attackNumber == 2)
            FragTrap::iceAttack(target);
        else if (attackNumber == 3)
            FragTrap::insultAttack(target);
        else
            FragTrap::headButtAttack(target);
    }
    return ;
}

unsigned int FragTrap::getVaultHunterDamage()
{
    return(this->_vaultHunterDamage);
}