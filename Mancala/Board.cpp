#include "Board.h"
#include "Game.h"
#include "Utilities.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/*********************************************************************
 * Function Prototype: Board::Board();
 *
 * Function Description: Initializes the game's starting values.
 * (Empty stores with 4 pieces in each hole)
 *
 * Example:
 *   Board *board = new Board();
 *
 * Preconditions: None
 * Postconditions: New board created with starting game values.
 **********************************************************************/
Board::Board()
{
    // makes holes a 2D-array
    holes[0] = new int[3];
    holes[1] = new int[6];
    holes[2] = new int[6];
    
    // sets stores to 0
    holes[0][1] = 0;
    holes[0][2] = 0;
    
    // sets every hole to 4
    for (int i = 0; i < 6; i++) {
        holes[1][i] = 4;
        holes[2][i] = 4;
    }
}

/*********************************************************************
 * Function Prototype: Board::Board(Board *board);
 *
 * Function Description: Creates a new Board object with the same
 * values as the passed Board object.
 *
 * Example:
 *   Board *board = new Board(oldBoard);
 *
 * Preconditions: Must have created another board object that you pass in.
 * Postconditions: New board created with the same values as the passed
 * Board object.
 **********************************************************************/
Board::Board(Board *board)
{
    // makes holes a 2D-array
    holes[0] = new int[3];
    holes[1] = new int[6];
    holes[2] = new int[6];
    
    // sets stores to board stores
    holes[0][1] = board->getStore(1);
    holes[0][2] = board->getStore(2);
    
    // sets holes to board holes
    for (int i = 0; i < 6; i++) {
        holes[1][i] = board->getHoles(1)[i];
        holes[2][i] = board->getHoles(2)[i];
    }
}

/*********************************************************************
 * Function Prototype: Board::~Board();
 *
 * Function Description: Destructor for Board that does nothing.
 *
 * Example:
 *   delete board;
 *
 * Preconditions: Board object must exist.
 * Postconditions: Board object deleted.
 **********************************************************************/
Board::~Board()
{
    //dtor
}

/*********************************************************************
 * Function Prototype: void Board::drawBoard();
 *
 * Function Description: Prints the board with the current game values.
 *
 * Example:
 *   board->drawBoard();
 *
 * Preconditions: Game values must be defined (holes[][])
 * Postconditions: Board printed to the screen.
 **********************************************************************/
void Board::drawBoard()
{
    cout << "     A   B   C   D   E   F" << endl;
    cout << endl << "  ";
    for(int i=5;i>=0;i--){
        if(holes[2][i]<=9){
            cout << " | " << holes[2][i];
        }else{
            cout << " |" << holes[2][i];
        }
    }
    cout << " |     P2" << endl;
    // prints depending on p2Store value so it lines up correctly
    if (holes[0][2] > 9) {
        cout << holes[0][2];
    } else {
        cout << " " << holes[0][2];
    }
    
    cout << " =========================== " << holes[0][1] << endl << "  ";
    for(int i=0;i<6;i++){
        if(holes[1][i]<=9){
            cout << " | " << holes[1][i];
        }else{
            cout << " |" << holes[1][i];
        }
    }
    cout << " |     P1" << endl;
}

/*********************************************************************
 * Function Prototype: bool Board::gameOver();
 *
 * Function Description: Returns true if a player has no pieces left
 * on their side.
 *
 * Example:
 *   while (!board->gameOver())
 *         or
 *   bool gameOver = board->gameOver();
 *
 * Preconditions: Game values must be defined (holes[][])
 * Postconditions: Returns boolean of whether the game is over or not
 **********************************************************************/
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

/*********************************************************************
 * Function Prototype: bool Board::playerMove(int player, int index);
 *
 * Function Description: Responsible for most of the game's logic.
 * Updates values of the board based on the user's move. By making
 * holes a 2D-array, I was able to cut the logic in half.
 *
 * Example:
 *   bool again = board->playerMove(1, 4);
 *        or
 *   board->playerMove(2, 3);
 *
 * Preconditions: player must be 1 or 2, and index must be 0-5
 * Postconditions: Returns boolean of whether the user gets another turn.
 **********************************************************************/
bool Board::playerMove(int player, int index)
{
    // set up variables
    int pieces, trueCount, totalCount;
    int j = 1;
    int otherPlayer = Utilities::getOtherPlayer(player);
    pieces = holes[player][index];
    holes[player][index] = 0;
    
    // until all but one piece is gone
    for (int i = pieces; i > 1; i--) {
        trueCount = j % 13;
        totalCount = (trueCount + index) % 13;
        if (totalCount == 6) {
            holes[0][player]++;
        } else if (totalCount > 6) {
            holes[otherPlayer][totalCount % 7]++;
        } else if (totalCount < 6) {
            holes[player][totalCount]++;
        } else {
            cout << "Something went wrong" << endl;
            exit(0);
        }
        j++;
    }
    
    // last piece logic
    trueCount = j % 13;
    totalCount = (trueCount + index) % 13;
    if (totalCount == 6) {
        holes[0][player]++;
        return true;
    } else if (totalCount < 6) {
        if ((holes[player][totalCount] == 0) && (holes[otherPlayer][5 - totalCount] != 0)) {
            holes[0][player] += (holes[otherPlayer][5 - totalCount] + 1);
            holes[otherPlayer][5 - totalCount] = 0;
        } else {
            holes[player][totalCount]++;
        }
    } else if (totalCount > 6) {
        holes[otherPlayer][totalCount % 7]++;
    } else {
        cout << "Something went wrong" << endl;
        exit(0);
    }
    
    return false;
}

/*********************************************************************
 * Function Prototype: void Board::collect();
 *
 * Function Description: Collects pieces from both sides of the board
 * and puts them in the correct store.
 *
 * Example:
 *   board->collect();
 *
 * Preconditions: Should be called when the game is over
 * Postconditions: Holes are empty and store values updated
 **********************************************************************/
void Board::collect()
{
    for (int i = 0; i < 6; i++) {
        holes[0][1] += holes[1][i];
        holes[0][2] += holes[2][i];
        holes[1][i] = 0;
        holes[2][i] = 0;
    }
}

/*********************************************************************
 * Function Prototype: int Board::getStore(int id);
 *
 * Function Description: Returns the queried player's store total.
 *
 * Example:
 *   int totalScore = board->getStore(1);
 *
 * Preconditions: Store value should be defined and id should be 1 or 2.
 * Postconditions: Returns the queried player's store total.
 **********************************************************************/
int Board::getStore(int id)
{
    return holes[0][id];
}

/*********************************************************************
 * Function Prototype: int Board::getHoles(int id);
 *
 * Function Description: Returns queried player's hole array
 *
 * Example:
 *   int holes[6] = board->getHoles(1);
 *
 * Preconditions: id should be 1 or 2
 * Postconditions: Returns queried player's hole array
 **********************************************************************/
int* Board::getHoles(int id)
{
    return holes[id];
}

/*********************************************************************
 * Function Prototype: int Board::getUtility();
 *
 * Function Description: Returns a move's utility for the AI (Player 2)
 * by subtracting player one's store from player two's and dividing that
 * by two. By dividing by two, it makes the utility a less dominating
 * factor in deciding moves and allows things like a second turn to
 * have more influence.
 *
 * Example:
 *   int utility = board->getUtility();
 *
 * Preconditions: None
 * Postconditions: New board created with starting game values.
 **********************************************************************/
int Board::getUtility()
{
    return (holes[0][2] - holes[0][1]) / 2;
}
