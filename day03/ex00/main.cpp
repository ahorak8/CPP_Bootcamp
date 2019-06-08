#include "FragTrap.hpp"

int main()
{
    FragTrap player1("Bob");
    FragTrap player2("Turret");

    std::cout << "\n\n 1: \n";
    player1.meleeAttack(player2.getName());
    player2.takeDamage(player1.getDamage("melee"));

    std::cout << "\n\n 2: \n";
    player2.iceAttack(player1.getName());
    player1.takeDamage(player2.getDamage("ice"));
    player2.beRepaired(20);

    std::cout << "\n\n 3: \n";
    player1.vaulthunter_dot_exe(player2.getName());
    player2.takeDamage(player1.getVaultHunterDamage());

    std::cout << "\n\nBattle over: \n";
    return (0);
}