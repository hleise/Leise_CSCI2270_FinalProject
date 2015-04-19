#include "Utilities.h"
#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

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

void Utilities::quitGame()
{
    clearScreen();
    menu();
}

// displays the menu
void Utilities::menu()
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

// gets user input for the menu
void Utilities::getMenuInput()
{
    // waits for input
    string input;
    cout << "Select an option: ";
    cin.clear();
    getline(cin, input);

    // runs action according to input
    if (input == "1") {
        clearScreen();
        Game(1);
    } else if (input == "2") {
        clearScreen();
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

// prints the rules
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

    // clears screen
    clearScreen();

    // return to menu
    menu();
}
