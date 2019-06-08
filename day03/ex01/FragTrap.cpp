#include "FragTrap.hpp"

FragTrap::FragTrap()
{
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "(FR4G-TP) " << name << ": F to the R to the 4 to the G to the WHAAT! \n";

    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_level = 1;
    this->_name = name;

    this->_meleeAttackDamage = 30;
    this->_rangedAttackDamage = 20;
    this->_iceAttackDamage = 35;
    this->_insultAttackDamage = 5;
    this->_headButtAttackDamage = 10;

    this->_armorDamageReduction = 5;
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

std::string FragTrap::getName()
{
    return this->_name;
}

void FragTrap::takeDamage(unsigned int amount)
{
    unsigned int damage;
    unsigned int remainingHP;

    damage = amount - this->_armorDamageReduction;
    if (damage > this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << "(FR4G-TP) " << this->_name << ": Robot down! \n" ;
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

void FragTrap::beRepaired(unsigned int amount)
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
    std::cout << "(FR4G-TP) " << this->_name << ": You can't keep a good 'bot down!\n";
    return ;
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

void FragTrap::meleeAttack(std::string const &target) 
{
    this->_vaultHunterDamage = this->_meleeAttackDamage;
    std::cout << "(FR4G-TP) <" << _name << "> attacks <" << target << "> with a melee attack, ";
    std::cout << "causing <" << _meleeAttackDamage << "> points of damage ! \n";
    std::cout << target << ": Ow hohoho, that hurts! Yipes! \n";
    return ;
}

void FragTrap::rangedAttack(std::string const &target) 
{
    this->_vaultHunterDamage = this->_rangedAttackDamage;
    std::cout << "(FR4G-TP) <" << _name << "> attacks <" << target << "> at range, ";
    std::cout << "causing <" << _rangedAttackDamage << "> points of damage ! \n";
    std::cout << target << ": Ow hohoho, that hurts! Yipes! \n";
    return ;
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