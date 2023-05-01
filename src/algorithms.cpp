#include <iostream>

#include "algorithms/sha256/index.h"

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        std::cout << "Please check the input count\n";
        return 1;
    }

    std::string hash = algorithms::hashComputation(algorithms::toBinary(argv[1]));

    if (hash == argv[2])
    {
        std::cout << "test passed\n";
    }
    else
    {
        std::cout << "test failed\n";
    }

    return 0;
}