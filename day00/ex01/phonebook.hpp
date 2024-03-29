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
    void searchContacts(Contact aContact[], int index) const;
    void getContact(Contact aContact) const;
    std::string display(std::string aString) const;
};

void    userCommand(Contact contacts[], int index);

#endif