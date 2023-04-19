#include <iostream>

#include <utils/index.h>

utils::ErrorCode checkError(bool b)
{
    if (b == true)
    {
        return utils::ErrorCode::NO_ERROR;
    }
    else
    {
        return utils::ErrorCode::ERROR;
    }
}

int main()
{
    utils::ErrorCode er1 = checkError(true);
    utils::ErrorCode er2 = checkError(false);
    
    if (er1 == utils::ErrorCode::NO_ERROR)
    {
        std::cout << "No error\n";
    }
    else
    {
        std::cout << "Error\n";
    }

    if (er2 == utils::ErrorCode::NO_ERROR)
    {
        std::cout << "No error\n";
    }
    else
    {
        std::cout << "Error\n";
    }
    return 0;
}