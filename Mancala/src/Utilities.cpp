#include "Utilities.h"
#include <iostream>
#include <fstream>

using namespace std;

/*********************************************************************
* Function Prototype: static void Utilities::clearScreen()
*
* Function Description: Clears the screen using an ANSI escape sequence.
*
* Example:
*   clearScreen();
*
* Preconditions: Probably want something printed on the screen first.
* Postconditions: Blank terminal screen
**********************************************************************/
void Utilities::clearScreen()
{
    cout << "\033[2J\033[;H";
}


/*********************************************************************
* Function Prototype: static void Utilities::printRules()
*
* Function Description: Clears the screen and prints the Mancala rules
* from a .txt file. When the user presses Enter, it will return them
* to the menu.
*
* Example:
*   printRules();
*
* Preconditions: None
**********************************************************************/
void Utilities::printRules()
{
    ifstream rules;
    rules.open("rules.txt");

    // clears screen
    clearScreen();

    // prints rules from .txt file
    if (rules.is_open()) {
        string line;
        while (getline(rules, line)) {
            cout << line << endl;
        }
        rules.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    // waits for user to press Enter
    cout << endl;
    cout << "Press Enter to return to the menu" << endl;
    string input;
    cin.clear();
    getline(cin, input);
}
