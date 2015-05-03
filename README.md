# Leise_CSCI2270_FinalProject

## Project Summary: 
My project is a game of Mancala that allows the user to play solo or against a friend. If the user selects solo, they play an AI that uses expectimax to select optimal moves. Overall it should be pretty self-explanatory. If you don't know how to play Mancala, don't worry, I included a "How to Play" option in the main menu.

## How to Run: 
There are two ways you can run my code. One, you can just open the files in your favorite IDE (like CodeBlocks or Geany) and run it with no command line arguments, or two, you can create an executable. To create an executable open terminal and cd to the Mancala file that you should have downloaded from my repo. Once there, run this line:

```
    g++ main.cpp Board.cpp Game.cpp GameTree.cpp Utilities.cpp Utilities.h Board.h Game.h GameTree.h
```

This creates an executable called a.out in the Mancala folder. To run this, simply type:

```
    ./a.out
```

From there you are free to play Mancala! Just remember, if you make any changes to the code, you need to delete the executable and repeat this process.

## Dependencies: 
None

## System Requirements: 
None in particular that I know about. Add an issue on GitHub if you find any.

## Group Members: 
Hunter Leise

## Contributors: 
None yet

## Open issues/bugs: 
No bugs that I know of. Aesthetically, if someone could make it format better when a hole has over 10 pieces in it that would be great. Even better yet, someone could implement actual graphics if they want!
