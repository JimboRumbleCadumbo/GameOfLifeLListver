#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Node.h"
#include <vector>
#include <cstdio>

class GameBoard {
private:
    // ---------------------------Building the board-------------------------------//
    std::vector<std::vector<Node *>> startingBoard; // Used to build the board vector

    void connectNodes(int size); // Used to connect the present linkedlist
    void connectNodesLeft(std::vector<Node *> &linkNodes, int size);
    void connectNodesRight(std::vector<Node *> &linkNodes, int size);
    void connectNodesTop(std::vector<std::vector<Node *>> &linkNodes, int size);
    void connectNodesBottom(std::vector<std::vector<Node *>> &linkNodes, int size);

    void connectNodesDiagnols(int size); // using new connections

    Node *lListNavagation(Node *temp, bool &changeDirections);
    int totaldays;

    Node *presentBoardHeadpt; // Top left of the lList

    // --------------------------Building Future Board-----------------------------//
    // This is needed to stop the present board effecting itself

    void futureToPresent(); // Connects the future board to the present board

    // ---------------------------------Post Game--------------------------------//
    struct totalLiving {
        int whatDay;
        int livngAmount;
    };

    // This can give the moments that were most to least "active"
    std::vector<totalLiving *> endResults;
    void resultsSorter(std::vector<totalLiving *> vectorToSort);

    // -------------------------Time Step and functionality------------------------//
    int timeStep(int dayAmount); // This time step exists for both board and node
    void lateStep();
    /*
    * These are the rule sets that can be changed by menu.
    *
    */
    bool wrapMode;      // Does the game board wrap, do the boundary nodes point to the
                        // other side
    bool mutationAmount;
    bool printEachDay; // Print every day or only the last day specified

    // ---------------------Private getters and setters--------------------------//
    void setHead(Node *temp);

public:
    // testing purposes only
    void printBoard();

    void startGame(); // For main to access to play the game
    Node *getHead();
    Node *getTail();

    // --------------Rules--------------//
    void setWrapMode(bool);
    void setPrintEachDay(bool);
    void setMutationAmount(int);

    // -------------------Node--------------------//
    void setLivingCell(int x, int y);

    // --------------constructors----------------//
    GameBoard();
    GameBoard(int size);
};

#endif