#include "phonebook.hpp"

void userCommand(Contact contacts[], int index) {
    std::string command;

    std::cout << "Please input command: \n";
    std::cout << "(Available commands are ADD, SEARCH, EXIT) \n";

    std::cin >> command;

    if (command == "ADD")
    {
        if (index == 8)
        {
            std::cout << "Phonebook is full. No more contacts can be added \n";
            std::cout << "Please select another command. \n";
        }
        if (index < 8)
        {
            contacts[index].addContact();
            index++;
        }
           
    }
    if (command == "SEARCH")
    {
        /* code */
    }
    if (command == "EXIT")
    {
        std::cout << "Thank you for using the phonebook";
        std::exit;
    }
    else
    {
        std::cout << "Invalid command. \n";
    }
    while (command != "EXIT")
    {
        userCommand(contacts, index);
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
