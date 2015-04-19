#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Utilities.h"
#include "Game.h"

using namespace std;

void menu();

// prints the rules
void printRules()
{
    ifstream rules;
    rules.open("rules.txt");

    // clears screen
    Utilities::clearScreen();

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

    // clears screen
    Utilities::clearScreen();

    // return to menu
    menu();
}

// gets user input for the menu
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
        printRules();
    } else if (input == "4") {
        exit(0);
    } else {
        cout << "Not a valid command, try again!" << endl;
        getMenuInput();
    }
}

// displays the menu
void menu()
{
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

// starts the program
int main()
{
    menu();

    return 0;
}
