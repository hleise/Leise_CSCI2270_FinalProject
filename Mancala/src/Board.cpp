#include "Board.h"
#include "Game.h"
#include <iostream>
#include <stdlib.h>

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
    cout << "   | " << p2Holes[5] << " | " << p2Holes[4] << " | " << p2Holes[3] << " | " << p2Holes[2] << " | " << p2Holes[1] << " | " << p2Holes[0] << " |     P2" << endl;

    // prints depending on p2Store value so it lines up correctly
    if (p2Store > 9) {
        cout << p2Store;
    } else {
        cout << " " << p2Store;
    }

    cout << " ========================= " << p1Store << endl;
    cout << "   | " << p1Holes[0] << " | " << p1Holes[1] << " | " << p1Holes[2] << " | " << p1Holes[3] << " | " << p1Holes[4] << " | " << p1Holes[5] << " |     P1" << endl;
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

// Most of the game's logic
bool Board::playerMove(int player, int index)
{
    int pieces = 0;
    int j = 1;

    if (player == 1) {
        pieces = p1Holes[index];
        p1Holes[index] = 0;
        for (int i = pieces; i > 1; i--) {
            if ((index + j) % 12 == 6) {
                p1Store++;
            } else if ((index + j) % 12 > 6) {
                p2Holes[((index + j) % 7) + ((index + j) / 12)]++;
            } else if ((index + j) % 12 < 6) {
                p1Holes[((index + j) % 6) - ((index + j) / 12)]++;
            } else {
                cout << "Something went wrong" << endl;
                exit(0);
            }
            j++;
        }
        if ((index + j) % 12 == 6) {
            p1Store++;
            return true;
        } else if ((index + j) % 12 < 6) {
            if (p1Holes[((index + j) % 6) - ((index + j) / 12)] == 0) {
                p1Store += (p2Holes[5 - (((index + j) % 6) - ((index + j) / 12))] + 1);
                p2Holes[5 - (((index + j) % 6) - ((index + j) / 12))] = 0;
            } else {
                p1Holes[((index + j) % 6) - ((index + j) / 12)]++;
            }
        } else if ((index + j) % 12 > 6) {
                p2Holes[((index + j) % 7) + ((index + j) / 12)]++;
        } else {
            cout << "Something went wrong" << endl;
            exit(0);
        }

        return false;
    } else if (player == 2) {
        pieces = p2Holes[index];
        p2Holes[index] = 0;
        for (int i = pieces; i > 1; i--) {
            if ((index + j) % 12 == 6) {
                p2Store++;
            } else if ((index + j) % 12 > 6) {
                p1Holes[((index + j) % 7) + ((index + j) / 12)]++;
            } else if ((index + j) % 12 < 6) {
                p2Holes[((index + j) % 6) - ((index + j) / 12)]++;
            } else {
                cout << "Something went wrong" << endl;
                exit(0);
            }
            j++;
        }
        if ((index + j) % 12 == 6) {
            p2Store++;
            return true;
        } else if ((index + j) % 12 < 6) {
            if (p2Holes[((index + j) % 6) - ((index + j) / 12)] == 0) {
                p2Store += (p1Holes[5 - (((index + j) % 6) - ((index + j) / 12))] + 1);
                p1Holes[5 - (((index + j) % 6) - ((index + j) / 12))] = 0;
            } else {
                p2Holes[((index + j) % 6) - ((index + j) / 12)]++;
            }
        } else if ((index + j) % 12 > 6) {
                p1Holes[((index + j) % 7) + ((index + j) / 12)]++;
        } else {
            cout << "Something went wrong" << endl;
            exit(0);
        }

        return false;
    } else {
        cout << "Something went wrong" << endl;
        exit(0);
    }

    return false;
}

// collects pieces from both sides and puts in stores
void Board::collect()
{
    for (int i = 0; i < 6; i++) {
        p1Store += p1Holes[i];
        p2Store += p2Holes[i];
    }
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

int* Board::getP2Holes()
{
    return p2Holes;
}
