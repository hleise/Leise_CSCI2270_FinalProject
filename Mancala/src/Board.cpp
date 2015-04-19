#include "Board.h"
#include <iostream>

using namespace std;

// initialize the game's starting values
Board::Board()
{
    p1Store = 0;
    p2Store = 0;

    for (int i = 0; i < 6; i++) {
        p1Holes[i] = 4;
        p2Holes[i] = 4;
    }
}

Board::~Board()
{
    //dtor
}

// draws the board with the current store and hole values
void Board::drawBoard()
{
    cout << "     A   B   C   D   E   F" << endl;
    cout << endl;
    cout << "   | " << p2Holes[0] << " | " << p2Holes[1] << " | " << p2Holes[2] << " | " << p2Holes[3] << " | " << p2Holes[4] << " | " << p2Holes[5] << " |" << endl;

    // prints depending on p2Store value so it lines up correctly
    if (p2Store > 9) {
        cout << p2Store;
    } else {
        cout << " " << p2Store;
    }

    cout << " ========================= " << p1Store << endl;
    cout << "   | " << p1Holes[0] << " | " << p1Holes[1] << " | " << p1Holes[2] << " | " << p1Holes[3] << " | " << p1Holes[4] << " | " << p1Holes[5] << " |" << endl;
}

// check if a player's side is empty or not
bool Board::gameOver()
{
    if ((p1Holes[0] == 0) && (p1Holes[1] == 0) && (p1Holes[2] == 0) && (p1Holes[3] == 0) && (p1Holes[4] == 0) && (p1Holes[5] == 0)) {
        return true;
    } else {
        if ((p2Holes[0] == 0) && (p2Holes[1] == 0) && (p2Holes[2] == 0) && (p2Holes[3] == 0) && (p2Holes[4] == 0) && (p2Holes[5] == 0)) {
            return true;
        }
    }

    return false;
}

void Board::playerMove(int player, string Choice)
{

}

int Board::getP1Store()
{
    return p1Store;
}

int* Board::getP1Holes()
{
    return p1Holes;
}

int Board::getP2Store()
{
    return p2Store;
}

int* Board::getp2Holes()
{
    return p2Holes;
}
