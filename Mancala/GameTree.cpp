#include "GameTree.h"
#include "Board.h"
#include "Utilities.h"
#include <iostream>
#include <stdlib.h>
#include <climits>

using namespace std;

/*********************************************************************
* Function Prototype: GameTree::GameTree();
*
* Function Description: Constructor that does nothing.
*
* Example:
*   GameTree *gameTree = new GameTree();
*
* Preconditions: None
* Postconditions: New GameTree created.
**********************************************************************/
GameTree::GameTree()
{
}

/*********************************************************************
* Function Prototype: GameTree::~GameTree();
*
* Function Description: Destructor that does nothing.
*
* Example:
*   delete gameTree();
*
* Preconditions: GameTree object must exist
* Postconditions: GameTree object deleted
**********************************************************************/
GameTree::~GameTree()
{
    //dtor
}

/*********************************************************************
* Function Prototype: int GameTree::expectimax(Board *gameState, int depth, int playerID);
*
* Function Description: Runs expectimax to determine a node's value.
* Implicitly creates a search tree, so this is my data structure
* for the project.
*
* Example:
*   int nodeValue = gameTree->expectimax(board, 1, 1);
*
* Preconditions: GameTree and Board object must exist. Depth should
* be greater than 0 and playerID should be 1 or 2.
* Postconditions: Returns the value of a node/move.
**********************************************************************/
int GameTree::expectimax(Board *gameState, int depth, int playerID)
{
    // set up variables
    int utility = 0;
    int possibleMoves = 6;

    // if game is over or max depth reached, return utility
    if (gameState->gameOver() || depth >= 3) {
        return gameState->getUtility();
    } else {
        // Until the max depth is reached, just keep branching for each possible move
        for (int i = 5; i >= 0; i--) {
            if (gameState->getHoles(playerID)[i] != 0) {
                Board *board = new Board(gameState);
                bool again = board->playerMove(playerID, i);

                if (again) {
                    utility += expectimax(board, depth, playerID);

                    if (playerID == 1) {
                        // bad if the other player gets another turn
                        utility -= 2;
                    } else {
                        // good if you get another turn
                        utility += 2;
                    }
                } else {
                    utility += expectimax(board, depth++, Utilities::getOtherPlayer(playerID));
                }

                // add the utility of this state
                utility += board->getUtility();

                // delete board to avoid a memory leak
                delete board;
            } else {
                possibleMoves--;
            }
        }
        // average the utility across possible moves
        return (utility / possibleMoves);
    }
}

/*********************************************************************
* Function Prototype: int GameTree::getMove(Board *currentState);
*
* Function Description: Calculates the best move by calling expectimax
* and returns the move index.
*
* Example:
*   int move = gameTree->getMove(board);
*
* Preconditions: GameTree object must exist
* Postconditions: Returns move index for AI
**********************************************************************/
int GameTree::getMove(Board *currentState)
{
    // set up variables
    int maxUtility = INT_MIN;
    int maxIndex;

    // calculate the best move
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
            // delete board to avoid a memory leak
            delete board;
        }
    }

    // return the move index
    return maxIndex;
}
