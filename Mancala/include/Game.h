#ifndef GAME_H
#define GAME_H
#include "Board.h"


class Game
{
    public:
        Game(int numPlayers);
        virtual ~Game();
        void player(int playerID);
    protected:
    private:
        int playerID;
        Board *board;
        int setNextPlayer();
        void solo();
        void twoPlayer();
};

#endif // GAME_H
