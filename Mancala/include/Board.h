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
        void collect();
        bool gameOver();
        bool playerMove(int player, int index);
        int getOtherPlayer(int player);
        int getStore(int id);
        int* getHoles(int id);
    protected:
    private:
        // 2D array holding holes and stores
        int holes[3][6];
};

#endif // BOARD_H
