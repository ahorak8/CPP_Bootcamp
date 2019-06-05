#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string login;
    std::string postalAddress;
    std::string emailAddress;
    std::string phoneNumber;
    std::string birthdayDate;
    std::string favouriteMeal;
    std::string underwearColour;
    std::string darkestSecret;
public:
    void addContact();
    ~Contact();
};

#endif