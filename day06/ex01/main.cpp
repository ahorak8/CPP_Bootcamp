#include <iostream>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

void *serialize(void) {
    Data *data = new Data;
    data->n = 0;

    static const char alphanumericArray[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
 
    for (int i=0; i<8; i++)
    {
        data->s1 += alphanumericArray[rand() % 63];
        data->s2 += alphanumericArray[rand() % 63];
    }
    data->n += rand() % INT_MAX;

    std::cout << "Serialized: \n";
    std::cout << "s1: " << data->s1 << "\n";
    std::cout << "s2: " << data->s2 << "\n";
    std::cout << "n:  " << data->n << "\n";

    return (reinterpret_cast<void *>(data));
}

Data *deserialize(void *raw) {
    return reinterpret_cast<Data *>(raw);
}

int main() 
{
    srand(time(0));

    void *ptr;
    Data *myData;

    ptr = serialize();

    std::cout << "\n\n";
    std::cout << "Memory address: " << ptr << "\n";

    myData = deserialize(ptr);

    std::cout << "\n\n";
    std::cout << "Deserialized stuff: \n";
    std::cout << "s1: " << myData->s1 << "\n";
    std::cout << "s2: " << myData->s2 << "\n";
    std::cout << "n:  " << myData->n << "\n";
    
    return 1;
}