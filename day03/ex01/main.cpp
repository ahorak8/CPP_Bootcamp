#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap player1("Bob");
    ScavTrap player2("Turret");

    std::cout << "\n\n 1: \n";
    player1.meleeAttack(player2.getName());
    player2.takeDamage(player1.getDamage("melee"));

    std::cout << "\n\n 2: \n";
    player2.rangedAttack(player1.getName());
    player1.takeDamage(player2.getDamage("ranged"));

    std::cout << "\n\n 3:\n";
    player2.challengeNewcomer(player1.getName());
    
    std::cout << "\n\nBattle over: \n";
    return (0);
}