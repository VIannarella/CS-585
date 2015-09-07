// game.m.cpp
#include <iostream>
#include "add.h"
#include "subtract.h"

int main()
{
    std::cout << "Hello\n";

    StevensDev::Add a;
    StevensDev::Subtract s;

    std::cout << "3 + 5 = " << a.addElements(3,5) << "\n";

    std::cout << "Goodbye\n";

    return 0;
}
