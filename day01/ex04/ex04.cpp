#include <iostream>

int main() {
    std::string aString = "HI THIS IS BRAIN";
    std::string *pointer = &aString;
    std::string &reference = aString;

    std::cout << *pointer << "\n";
    std::cout << reference << "\n";

    return 0;
}