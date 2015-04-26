#include "Utilities.h"
#include "Game.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/*********************************************************************
* Function Prototype: void getMenuInput()
*
* Function Description: Gets user input for the menu and calls the
* appropriate function depending on what the user selects.
*
* Example:
*   getMenuInput();
*
* Preconditions: Should not be called unless through menu() so the
* users can see the options.
*
* Postconditions: Will call the appropriate function for
* what the user wants.
**********************************************************************/
void getMenuInput()
{
    // waits for input
    string input;
    cout << "Select an option: ";
    cin.clear();
    getline(cin, input);

    // runs action according to input
    if (input == "1") {
        Utilities::clearScreen();
        Game(1);
    } else if (input == "2") {
        Utilities::clearScreen();
        Game(2);
    } else if (input == "3") {
        Utilities::printRules();
    } else if (input == "4") {
        cout << endl;
        cout << "Goodbye!" << endl;
        exit(0);
    } else {
        cout << "Not a valid command, try again!" << endl;
        getMenuInput();
    }
}


/*********************************************************************
* Function Prototype: void menu()
*
* Function Description: Prints out the menu and calls getMenuInput()
* to decide what to do with the user's input. Designed to make it easy
* to loop through the game.
*
* Example:
*   menu();
*
* Preconditions: None
* Postconditions: Menu printed to the screen and getMenuInput() called.
**********************************************************************/
void menu()
{
    Utilities::clearScreen();

    cout << "******************************" << endl;
    cout << "  WELCOME TO MANCALA MASTER!  " << endl;
    cout << "******************************" << endl;
    cout << endl;
    cout << "  1. Solo" << endl;
    cout << "  2. Two Player" << endl;
    cout << "  3. How to Play" << endl;
    cout << "  4. Quit" << endl;
    cout << endl;

    getMenuInput();
}


/*********************************************************************
* Function Prototype: int main()
*
* Function Description:
*   This function should never be called, it just starts the program.
*   It will loop through the game until the user quits.
*
* Example:
*   main()
*
* Preconditions: None
* Postconditions: None
**********************************************************************/
int main()
{
    while (true)
        menu();

    return 0;
}
