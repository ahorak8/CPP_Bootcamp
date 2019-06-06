#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main() 
{    
    srand(time(0));
    ZombieEvent Zombie1;

    std::cout << "STACK: \n";
    Zombie stackZombie1("Darkling");
    stackZombie1.announce();
    Zombie stackZombie2("Nicolai", "Cat");
    stackZombie2.announce();

    std::cout << "HEAP: \n";
    Zombie *heapZombie1 = Zombie1.randomChump();
    Zombie *heapZombie2 = Zombie1.newZombie("Alina");
    heapZombie2->announce();
    Zombie *heapZombie3 = new Zombie("Zombie", "Zombie");
    heapZombie3->announce();

    std::cout << "Clearing the zombie horde: \n";
    delete heapZombie1;
    delete heapZombie2;
    delete heapZombie3;
}