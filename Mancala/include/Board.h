#ifndef BOARD_H
#define BOARD_H
#include <string>

using std::string;

class Board
{
    public:
        Board();
        virtual ~Board();
        void drawBoard();
        bool gameOver();
        void playerMove(int player, string choice);
        int getP1Store();
        int* getP1Holes();
        int getP2Store();
        int* getp2Holes();
    protected:
    private:
        int p1Store;
        int p2Store;
        int p1Holes[6];
        int p2Holes[6];
};

#endif // BOARD_H
