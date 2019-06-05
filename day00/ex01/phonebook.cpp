#include "phonebook.hpp"

void userCommand() {
    std::string command;

    std::cout << "Please input command: \n";
    std::cout << "(Available commands are ADD, SEARCH, EXIT) \n";

    std::cin >> command;

    if (command == "ADD")
    {
        /* code */
    }
    if (command == "SEARCH")
    {
        /* code */
    }
    if (command == "EXIT")
    {
        /* code */
    }
    else
    {
        /* code */
    }
    while (command != "EXIT")
    {
        /* code */
    }
    
    
}

void Contact::addContact() {
    std::cout << "Please enter new contact's details. \n";
    std::cout << "Please enter First Name: \n";
    getline(std::cin, firstName);
    std::cout << "Please enter Last Name: \n";
    getline(std::cin, lastName); 
    std::cout << "Please enter Nickname: \n";
    getline(std::cin, nickname);
    std::cout << "Please enter Login: \n";
    getline(std::cin, login);
    std::cout << "Please enter Postal Address: \n";
    getline(std::cin, postalAddress);
    std::cout << "Please enter Email Address: \n";
    getline(std::cin, emailAddress);
    std::cout << "Please enter Phone Number: \n";
    getline(std::cin, phoneNumber);
    std::cout << "Please enter Birthday Date: \n";
    getline(std::cin, birthdayDate);
    std::cout << "Please enter Favourite Meal: \n";
    getline(std::cin, favouriteMeal);
    std::cout << "Please enter Underwear Colour: \n";
    getline(std::cin, underwearColour);
    std::cout << "Please enter Darkest Secret: \n";
    getline(std::cin, darkestSecret);
    
}
