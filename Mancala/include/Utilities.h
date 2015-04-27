#ifndef UTILITIES_H
#define UTILITIES_H


class Utilities
{
    public:
        Utilities();
        virtual ~Utilities();
        static void clearScreen();
        static void printRules();
        static int getOtherPlayer(int player);
    protected:
    private:
};

#endif // UTILITIES_H
