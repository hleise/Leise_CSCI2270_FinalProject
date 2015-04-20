#include "Board.h"
#include "Game.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// initialize the game's starting values
Board::Board()
{
    // sets stores to 0
    holes[0][1] = 0;
    holes[0][2] = 0;

    // sets every hole to 4
    for (int i = 0; i < 6; i++) {
        holes[1][i] = 4;
        holes[2][i] = 4;
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
    cout << "   | " << holes[2][5] << " | " << holes[2][4] << " | " << holes[2][3] << " | " << holes[2][2] << " | " << holes[2][1] << " | " << holes[2][0] << " |     P2" << endl;

    // prints depending on p2Store value so it lines up correctly
    if (holes[0][2] > 9) {
        cout << holes[0][2];
    } else {
        cout << " " << holes[0][2];
    }

    cout << " ========================= " << holes[0][1] << endl;
    cout << "   | " << holes[1][0] << " | " << holes[1][1] << " | " << holes[1][2] << " | " << holes[1][3] << " | " << holes[1][4] << " | " << holes[1][5] << " |     P1" << endl;
}

// check if a player's side is empty or not
bool Board::gameOver()
{
    if ((holes[1][0] == 0) && (holes[1][1] == 0) && (holes[1][2] == 0) && (holes[1][3] == 0) && (holes[1][4] == 0) && (holes[1][5] == 0)) {
        return true;
    } else {
        if ((holes[2][0] == 0) && (holes[2][1] == 0) && (holes[2][2] == 0) && (holes[2][3] == 0) && (holes[2][4] == 0) && (holes[2][5] == 0)) {
            return true;
        }
    }

    return false;
}

// Most of the game's logic
// by having a 2D array I was able to split the line count in half
bool Board::playerMove(int player, int index)
{
    int pieces, trueCount;
    int j = 1;
    int otherPlayer = getOtherPlayer(player);

    pieces = holes[player][index];
    holes[player][index] = 0;

    // until all but one piece is gone
    for (int i = pieces; i > 1; i--) {
        trueCount = j % 13;
        if ((trueCount + index) == 6) {
            holes[0][player]++;
        } else if ((trueCount + index) > 6) {
            holes[otherPlayer][((trueCount + index) % 6) - 1]++;
        } else if ((trueCount + index) < 6) {
            holes[player][trueCount + index]++;
        } else {
            cout << "Something went wrong" << endl;
            exit(0);
        }
        j++;
    }

    // last piece logic
    trueCount = j % 13;
    if ((trueCount + index) == 6) {
        holes[0][player]++;
        return true;
    } else if ((trueCount + index) < 6) {
        if ((holes[player][(trueCount + index)] == 0) && (holes[otherPlayer][5 - (trueCount + index)] != 0)) {
            holes[0][player] += (holes[otherPlayer][5 - (trueCount + index)] + 1);
            holes[otherPlayer][5 - (trueCount + index)] = 0;
        } else {
            holes[player][trueCount + index]++;
        }
    } else if ((trueCount + index) > 6) {
            holes[otherPlayer][((trueCount + index) % 6) - 1]++;
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
        holes[0][1] += holes[1][i];
        holes[0][2] += holes[2][i];
        holes[1][i] = 0;
        holes[2][i] = 0;
    }
}

int Board::getOtherPlayer(int player)
{
    if (player == 1) {
        return 2;
    } else if (player == 2) {
        return 1;
    } else {
        cout << "Something went wrong" << endl;
        exit(0);
    }
}

int Board::getStore(int id)
{
    return holes[0][id];
}

int* Board::getHoles(int id)
{
    return holes[id];
}
