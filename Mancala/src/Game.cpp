#include "Game.h"
#include "Board.h"
#include "GameTree.h"
#include "Utilities.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <unistd.h>

using namespace std;

/*********************************************************************
* Function Prototype: Game::Game(int numPlayers)
*
* Function Description: Creates a new Mancala game by creating a new
* board and calling the appropriate gameType (single or two player).
*
* Example:
*   Game(1);
*
* Preconditions: None
* Postconditions: Game started (solo() or twoPlayer() called)
**********************************************************************/
Game::Game(int numPlayers)
{
    // set variables
    playerID = 1;
    toMenu = false;

    // create new board
    board = new Board();

    // what game to run based on numPlayers
    if (numPlayers == 1) {
        this->solo();
    } else if (numPlayers == 2) {
        this->twoPlayer();
    } else {
        cout << "Something went wrong!" << endl;
        exit(0);
    }
}

/*********************************************************************
* Function Prototype: Game::~Game()
*
* Function Description: Destructor that deletes the board instance
* in order to avoid a memory leak.
*
* Example:
*   ~Game();
*
* Preconditions: Game object must exist
* Postconditions: board deleted
**********************************************************************/
Game::~Game()
{
    delete board;
}

/*********************************************************************
* Function Prototype: void Game::solo()
*
* Function Description: Loops through the single player game until
* it's over. Alternates turns between user and AI.
*
* Example:
*   solo();
*
* Preconditions: Board and Game object must exist
* Postconditions: Returns to main menu
**********************************************************************/
void Game::solo()
{
    // alternates between user and AI until game is over
    while (!board->gameOver()) {
        // User
        //Utilities::clearScreen();
        board->drawBoard();
        player(1);

        //  checks if user wants to go to menu
        if (toMenu == true)
            return;

        // AI
        if (!board->gameOver()) {
            //Utilities::clearScreen();
            board->drawBoard();
            AI();
        }
    }

    // collects pieces and prints winner
    board->collect();
    printWinner();
}

/*********************************************************************
* Function Prototype: void Game::twoPlayer()
*
* Function Description: Loops through the two player game until
* it's over. Alternates turns between player one and player two.
*
* Example:
*   twoPlayer();
*
* Preconditions: Board and Game object must exist
* Postconditions: Returns to main menu
**********************************************************************/
void Game::twoPlayer()
{
    // alternates between player one and player two until game is over
    while (!board->gameOver()) {
        Utilities::clearScreen();
        board->drawBoard();
        player(playerID);
        playerID = setNextPlayer();

        // checks if user wants to go to menu
        if (toMenu == true)
            return;
    }

    // collects pieces and prints winner
    board->collect();
    printWinner();
}

/*********************************************************************
* Function Prototype: void Game::printWinner()
*
* Function Description: Calculates the winner and prints the final
* score to the screen. When user presses Enter, it returns to the menu.
*
* Example:
*   printWinner();
*
* Preconditions: Board and Game object must exist
* Postconditions: Returns to main menu
**********************************************************************/
void Game::printWinner()
{
    //Utilities::clearScreen();
    board->drawBoard();
    cout << endl;

    // calculates the winner and prints the final score
    if (board->getStore(1) > board->getStore(2)) {
        cout << "Player 1 Won!!!" << endl;
        cout << "***************" << endl;
        cout << "Player 1: " << board->getStore(1) << endl;
        cout << "Player 2: " << board->getStore(2) << endl;
    } else if (board->getStore(2) > board->getStore(1)) {
        cout << "Player 2 Won!!!" << endl;
        cout << "***************" << endl;
        cout << "Player 1: " << board->getStore(1) << endl;
        cout << "Player 2: " << board->getStore(2) << endl;
    } else {
        cout << "Tie Game!!!" << endl;
        cout << "***************" << endl;
        cout << "Player 1: " << board->getStore(1) << endl;
        cout << "Player 2: " << board->getStore(2) << endl;
    }

    // waits for user to press Enter
    cout << endl;
    cout << "Press Enter to return to the menu" << endl;
    string input;
    cin.clear();
    getline(cin, input);
}

/*********************************************************************
* Function Prototype: void Game::setNextPlayer()
*
* Function Description: Set variable playerID to the next player in
* order to be able to alternate turns between the two.
*
* Example:
*   setNextPlayer();
*
* Preconditions: Board and Game object must exist
* Postconditions: playerID changes to the next player
**********************************************************************/
int Game::setNextPlayer()
{
    if (playerID == 1) {
        return 2;
    } else if (playerID == 2) {
        return 1;
    } else {
        cout << "Something went wrong" << endl;
    }
}

/*********************************************************************
* Function Prototype: void Game::player(int id)
*
* Function Description: Gets user move and calls playerMove() if it's
* a valid choice.
*
* Example:
*   player(1);
*
* Preconditions: Board and Game object must exist
* Postconditions: Calls playerMove()
**********************************************************************/
void Game::player(int id)
{
    string choice;
    bool again;

    // print player name
    cout << endl;
    if (id == 1) {
        cout << "Player 1: " << endl;
    } else if (id == 2) {
        cout << "Player 2: " << endl;
    } else {
        cout << "Something went wrong!" << endl;
        exit(0);
    }

    // get player choice & convert to lower-case
    cin.clear();
    getline(cin, choice);
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    // logic on their choice
    if (choice == "q") {
        cout << "Goodbye!" << endl;
        exit(0);
    } else if (choice == "m") {
        toMenu = true;
        return;
    } else if ((choice == "a") || (choice == "b") || (choice == "c") || (choice == "d") || (choice == "e") || (choice == "f")) {
        if (id == 1) {
            if ((choice == "a") && (board->getHoles(1)[0] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "b") && (board->getHoles(1)[1] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "c") && (board->getHoles(1)[2] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "d") && (board->getHoles(1)[3] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "e") && (board->getHoles(1)[4] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "f") && (board->getHoles(1)[5] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else {
                if (choice == "a") {
                    again = board->playerMove(id, 0);
                } else if (choice == "b") {
                    again = board->playerMove(id, 1);
                } else if (choice == "c") {
                    again = board->playerMove(id, 2);
                } else if (choice == "d") {
                    again = board->playerMove(id, 3);
                } else if (choice == "e") {
                    again = board->playerMove(id, 4);
                } else if (choice == "f") {
                    again = board->playerMove(id, 5);
                } else {
                    cout << "Something went wrong" << endl;
                    exit(0);
                }

                if ((again == true) && (!board->gameOver())) {
                    //Utilities::clearScreen();
                    board->drawBoard();
                    player(id);
                }
            }
        } else if (id == 2) {
            if ((choice == "f") && (board->getHoles(2)[0] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "e") && (board->getHoles(2)[1] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "d") && (board->getHoles(2)[2] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "c") && (board->getHoles(2)[3] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "b") && (board->getHoles(2)[4] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else if ((choice == "a") && (board->getHoles(2)[5] == 0)) {
                cout << "That hole's empty, try again!" << endl;
                player(id);
            } else {
                if (choice == "f") {
                    again = board->playerMove(id, 0);
                } else if (choice == "e") {
                    again = board->playerMove(id, 1);
                } else if (choice == "d") {
                    again = board->playerMove(id, 2);
                } else if (choice == "c") {
                    again = board->playerMove(id, 3);
                } else if (choice == "b") {
                    again = board->playerMove(id, 4);
                } else if (choice == "a") {
                    again = board->playerMove(id, 5);
                } else {
                    cout << "Something went wrong" << endl;
                    exit(0);
                }

                if ((again == true) && (!board->gameOver())) {
                    Utilities::clearScreen();
                    board->drawBoard();
                    player(id);
                }
            }
        } else {
            cout << "Something went wrong" << endl;
            exit(0);
        }
    } else {
        cout << "Choices are A, B, C, D, E, or F, try again!" << endl;
        player(id);
    }
}

void Game::AI()
{
    cout << "Thinking..." << endl;

    // pause for a few seconds so the player can see what the AI does
    sleep(2);

    int choice;
    bool again;

    GameTree *gameTree = new GameTree();
    choice = gameTree->getMove(board);

    again = board->playerMove(2, choice);

    if ((again == true) && (!board->gameOver())) {
        //Utilities::clearScreen();
        board->drawBoard();
        AI();
    }

    delete gameTree;
}
