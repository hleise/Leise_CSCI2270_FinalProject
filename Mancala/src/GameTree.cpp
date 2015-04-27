#include "GameTree.h"
#include "Board.h"
#include "Utilities.h"
#include <iostream>
#include <stdlib.h>
#include <climits>

using namespace std;

GameTree::GameTree()
{
}

GameTree::~GameTree()
{
    //dtor
}

int GameTree::expectimax(Board *gameState, int depth, int playerID)
{
    int utility = 0;
    int possibleMoves = 6;

    if (gameState->gameOver() || depth >= 3) {
        return gameState->getUtility();
    } else {
        for (int i = 5; i >= 0; i--) {
            if (gameState->getHoles(playerID)[i] != 0) {
                Board *board = new Board(gameState);
                bool again = board->playerMove(playerID, i);

                if (again) {
                    utility += expectimax(board, depth, playerID);
                    if (playerID == 1) {
                        utility -= 2;
                    } else {
                        utility += 2;
                    }
                } else {
                    utility += expectimax(board, depth++, Utilities::getOtherPlayer(playerID));
                }
                utility += board->getUtility();
                delete board;
            } else {
                possibleMoves--;
            }
        }
        return (utility / possibleMoves);
    }
}

int GameTree::getMove(Board *currentState)
{
    int maxUtility = INT_MIN;
    int maxIndex;

    for (int i = 5; i >= 0; i--) {
        if (currentState->getHoles(2)[i] != 0) {
            int utility;
            Board *board = new Board(currentState);
            bool again = board->playerMove(2, i);

            if (again) {
                utility = expectimax(board, 1, 2);
                utility += 2;
            } else {
                utility = expectimax(board, 2, 1);
            }

            if (utility > maxUtility) {
                maxUtility = utility;
                maxIndex = i;
            }
            delete board;
        }
    }

    return maxIndex;
}
