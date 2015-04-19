#include "Game.h"
#include "Board.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Game::Game(int numPlayers)
{
    playerID = 1;
    board = new Board();

    if (numPlayers == 1) {
        this->solo();
    } else if (numPlayers == 2) {
        this->twoPlayer();
    } else {
        cout << "Something wen't wrong!" << endl;
        exit(0);
    }
}

Game::~Game()
{
    delete board;
}

void Game::solo()
{

}

void Game::twoPlayer()
{
    while (!board->gameOver()) {
        board->drawBoard();
        player(playerID);
        playerID = setNextPlayer();
    }
}

// set playerID to the next player
int Game::setNextPlayer()
{
    if (playerID == 1) {
        return 2;
    } else if (playerID == 2) {
        return 1;
    }
}

void Game::player(int id)
{
    string choice;

    if (id == 1) {
        cout << "Player 1: " << endl;
    } else if (id == 2) {
        cout << "Player 2: " << endl;
    } else {
        cout << "Something wen't wrong!" << endl;
        exit(0);
    }

    cin.clear();
    getline(cin, choice);
    board->playerMove(id, choice);
}
