#ifndef GAMETREE_H
#define GAMETREE_H
#include "Board.h"

class GameTree
{
    public:
        GameTree();
        virtual ~GameTree();
        int expectimax(Board *board, int depth, int playerID);
        int getMove(Board *board);
    protected:
    private:
};

#endif // GAMETREE_H
