#include <iostream>

template <typename T>
void print_array(T &data)
{
	std::cout << data << std::endl;
}

template <typename T>
void iter(T *address, size_t length, void(*function)(T &))
{
    size_t i;

    i = 0;
    while (i < length)
    {
        (*function)(address[i]);
		 i++;
    }
    
} 

int main() {
    std::string	string_test[] = {"ABC", "BCD", "CDE", "EFG", "GHI"};
	char		char_test[] = {'a', 'b', 'c', 'd', 'e'};
	int			int_test[] = {1, 20, 300, 4000, 50000};
	double		double_test[] = {1.00, 2.00, 3.00, 4.00, 5.00};

	std::cout << "test1: string array iter" << std::endl;
	iter(string_test, 5, print_array);
	std::cout << "test2: char array iter" << std::endl;
	iter(char_test, 5, print_array);
	std::cout << "test3: int array iter" << std::endl;
	iter(int_test, 5, print_array);
	std::cout << "test4: double array iter" << std::endl;
	iter(double_test, 5, print_array);
	return 0;
}