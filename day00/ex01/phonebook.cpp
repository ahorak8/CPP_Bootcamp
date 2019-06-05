#include "phonebook.hpp"

void    Contact::addContact() {
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

void    Contact::searchContacts(Contact aContact[], int index) const{
    int i = 0;

    std::cout << "     index|";
    std::cout << "first name|";
    std::cout << " last name|";
    std::cout << "  nickname|";
    std::cout << "\n";

    while (i < index)
    {
        std::cout << "         " << i << "|";
        std::cout <<  << "|";
        std::cout <<  << "|";
        std::cout <<  << "|";
        std::cout << "\n";
        i++;
    }
    if (index != 0)
    {
        std::cout << "Please enter Contact Index to view them: ";
        std::cin >> i;
        if (i < index)
        {
            getContact(aContact[i]);
        }
        else
        {
            std::cout << "Index not valid. \n";
        }
        
    }
    
}

void Contact::getContact(Contact aContact) const{
    std::cout << aContact.firstName << "\n";
    std::cout << aContact.lastName << "\n";
    std::cout << aContact.nickname << "\n";
    std::cout << aContact.login << "\n";
    std::cout << aContact.postalAddress << "\n";
    std::cout << aContact.emailAddress << "\n";
    std::cout << aContact.phoneNumber << "\n";
    std::cout << aContact.birthdayDate << "\n";
    std::cout << aContact.favouriteMeal  << "\n";
    std::cout << aContact.underwearColour << "\n";
    std::cout << aContact.darkestSecret << "\n";
}

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
        contacts[8].searchContacts[contacts, index];
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
