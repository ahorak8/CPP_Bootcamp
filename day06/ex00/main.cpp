#include <iostream>
#include <iomanip>

void isDouble(char** argv){
    
    double d = static_cast<double>(atof(argv[1]));
    std::cout << "double: " << d << std::endl;
    if (!d)
        std::cout << "double: impossible" << std::endl;
}

void isFloat(char** argv, int x){
    int z = 0;
    if(!argv[1][x])
        z = 1;
    for (; argv[1][x]; x++){
        if (!isdigit(argv[1][x])){
            if (argv[1][x] == 'f')
                x++;
                if(!argv[1][x])
                    break;
            else
                z = 1;

        }
    }
    if (z == 0)
    {
        float f = static_cast<float>(atof(argv[1]));
        std::cout << "float: " << f << 'f' << std::endl;
    }
    if (z == 1)
        std::cout << "float: impossible" << std::endl;
    isDouble(argv);
}

void isChar(char** argv){
    if (isalpha(argv[1][0]) && !argv[1][1])
    {
        char c = static_cast<char>(argv[1][0]);
        std::cout << "char: " << c << std::endl;
        return;
    }
    else if (atoi(argv[1]) || argv[1][0] == '0')
    {
        int j = atoi(argv[1]);
        char a = static_cast<char>(j);
        if (isprint(j))
            std::cout << "char: " << '\'' << a << '\'' << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
}

void isInt(char** argv){
    int y = 0;
    int x = 0;
    if (argv[1][x] == '-')
        x++;
    for (; argv[1][x]; x++){
        if (!isdigit(argv[1][x])){
            if(argv[1][x] == '.' && argv[1][0] != '.')
            {
                x++;
                if(argv[1][x] != '0')
                {
                    y = 2;
                    isFloat(argv, x);
                    break;
                }
                while(argv[1][x] == '0')
                    x++;
                if(!argv[1][x])
                    break;
                if (argv[1][x] == 'f')
                    x++;
                if(!argv[1][x])
                    break;
                
            }
            y = 1;
            break;
        }

    }
    if (y == 0)
    {
        int i = static_cast<int>(atoi(argv[1]));
        std::cout << "int: " << i << std::endl;
    }
    else if (y == 1 || y == 2)
        std::cout << "int: impossible" << std::endl;
    if (y != 2){
        float f = static_cast<float>(atof(argv[1]));
        std::cout << "float: " << f << 'f' << std::endl;
        double d = static_cast<double>(atof(argv[1]));
        std::cout << "double: " << d << std::endl;
    }

}

int main(int argc, char** argv){
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(1);
    
    if (argc == 2){
        isChar(argv);
        isInt(argv);
    }
    return 0;
}