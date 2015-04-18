#include "Utilities.h"
#include <iostream>

using namespace std;

Utilities::Utilities()
{
    //ctor
}

Utilities::~Utilities()
{
    //dtor
}

// clears the terminal screen using an ANSI escape sequence
void Utilities::clearScreen()
{
    cout << "\033[2J\033[;H";
}
