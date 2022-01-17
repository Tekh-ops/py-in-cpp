#include <iostream>
#include <string>
#include <cs50.h>

int main(int argc, char const *argv[])
{
    std::string str = Get_String("Enter a string: ");
    std::cout << "You entered: " << str << std::endl;
    return 0;
}
