#include <iostream>
#include <iomanip>

// void charConversion(char **argv)
// {
//     if (argv[1] && !argv[1][1])
//     {
//         if (isalpha(argv[1][0]))
//         {
//             int c = argv[1][0];
//             std::cout << "char: ";
//             std::cout << static_cast<char>(c);
//             std::cout << "\n";
//         }
//         else
//         {
//             std::cout << "char: ";
//             std::cout << "Not displayable \n";
//         }
//     }
//     else
//     {
//         std::cout << "char: ";
//         std::cout << "Not possible \n";
//     }
// }

// void intConversion(char **argv)
// {
//     if (argv[1] || argv[1])
//     {
//         if (isnumber(*argv[1]))
//         {
//             int c = *argv[1];
//             std::cout << "int: ";
//             std::cout << static_cast<int>(c - 48);
//             std::cout << "\n";
//         }
//         else
//         {
//             std::cout << "int: ";
//             std::cout << "Not possible \n";
//         }
//     }
//     else
//     {
//         std::cout << "int: ";
//         std::cout << "Not possible** \n";
//     }
// }

// int main(int argc, char **argv) {

//     if (argc > 1)
//     {
//         charConversion(argv);
//         intConversion(argv);
//     }
//     else 
//     {
//         std::cout << "Please input a parameter \n";
//     }
//     return (0);
// }

int main(int argc, char const *argv[])
{
	if (argc != 2){
		std::cout << "Please input ONE paramater \n";
		return (0);
	}
	std::string input = argv[1];
	std::cout << std::fixed << std::setprecision(1);
	// CHAR
	try{
		int i = std::stoi(input);
		char c = i;
		if (std::isprint(c)){
			std::cout << "char: " << c <<std::endl;
		} else {
			std::cout << "char: " << "non displayble" <<std::endl;
		}
	} catch (std::exception &e)
	{
		std::cout << "char: " << "impossible" <<std::endl;
	}

	//INT
	try{
		int a = std::stoi(input);
		std::cout << "int: " << a <<std::endl;
	} catch (std::exception &e)
	{
		std::cout << "int: " << "impossible" <<std::endl;
	}

	//FLOAT
	try{
		float f = std::stof(input);
		std::cout << "float: " << f << "f" <<std::endl;
	} catch (std::exception &e)
	{
		std::cout << "float: " << "impossible" <<std::endl;
	}

	// DOUBLE
	try {
		double d = std::stod(input);
		std::cout << "double: " << d <<std::endl;

	} catch (std::exception &e)
	{
		std::cout << "double: " << "impossible" <<std::endl;
	}
	return 0;
}