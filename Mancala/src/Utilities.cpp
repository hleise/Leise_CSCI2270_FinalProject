#include "Utilities.h"
#include <iostream>

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
* Function Description: Clears the screen and prints the Mancala rules.
* When the user presses Enter, it will return them to the menu.
* Originally printed from a .txt file, but that had issues when creating
* an executable so I just hard-coded the rules in.
*
* Example:
*   printRules();
*
* Preconditions: None
* Postconditions: None
**********************************************************************/
void Utilities::printRules()
{
    // clears screen
    clearScreen();

    // prints rules
    cout << "How to Play:" << endl;
    cout << endl;
    cout << "1. The Mancala board is made up of two rows of six holes each." << endl;
    cout << "2. Player one's row is on the bottom, and player two's is on the top." << endl;
    cout << "3. Player one's store is on the right, and player two's is on the left." << endl;
    cout << "4. To begin, 4 pieces are placed into each hole." << endl;
    cout << "5. Player one begins by picking up all pieces in any hole on their side." << endl;
    cout << "6. Moving counter-clockwise, deposit one piece in each hole until pieces run out" << endl;
    cout << "7. If you run into your own store, deposit one piece in it." << endl;
    cout << "8. If you run into your opponent's store, skip it." << endl;
    cout << "9. If the last piece you drop is in your own store, you get an extra turn." <<  endl;
    cout << "10. If the last piece you drop is in an empty hole on your side, you capture that piece and any pieces in the hole directly opposite." << endl;
    cout << "11. Always place all captured pieces in your store." << endl;
    cout << "12. The game ends when all six holes on one side of the board are empty." << endl;
    cout << "13. The player who still has pieces on their side of the board when the game ends captures all of those pieces." << endl;
    cout << "14. The winner is the player with the most pieces in their store." << endl;
    cout << "15. Press 'm' during your turn to return to the menu." << endl;
    cout << "16. Press 'q' during your turn to quit the application." << endl;

    // waits for user to press Enter
    cout << endl;
    cout << "Press Enter to return to the menu" << endl;
    string input;
    cin.clear();
    getline(cin, input);
}
