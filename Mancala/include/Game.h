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
        Board *board;
        int playerID;
        int setNextPlayer();
        bool toMenu;
        void solo();
        void twoPlayer();
        void printWinner();
};

#endif // GAME_H
