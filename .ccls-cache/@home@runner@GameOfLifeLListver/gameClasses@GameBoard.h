#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "Node.h"

class GameBoard {
  private:
    std::vector<Node*> startingBoard;  // Used to build the board vector
    void connectNodes();               // Used to connect the present linkedlist
    int totaldays;

    Node * presentBoardHeadpt;         // Top left of the lList
    Node * presentBoardTailpt;         // Bottom right of the lList

    // This is needed to stop the present board effecting itself
    std::vector<std::vector<bool>> futureBoard;

    /*
    * This should probs have a way to count the amount of living nodes
    * And push the count into a vector of living nodes
    *
    * - This should also print as it is o(n^2) anyway
    */
    void futureToPresent();            // Connects the futureboard to presentboard

    struct totalLiving 
    {
      int whatDay;
      int livngAmount;
    };

    // This can give the moments that were most to least "active"
    std::vector<totalLiving *> endResults;
    void resultsSorter(std::vector<totalLiving *> vectorToSort);  

    int timeStep(int dayAmount);       // This time step exsists for both board and node

    /*
    * These are the rule sets that can be changed by menu.
    *
    */

    bool wrapMode;       // Does the gameboard wrap, do the boundary nodes point to the     other side

    bool printEachDay;   // Print everyday or only the last day specified
    int  mutationAmount; // Min 0, Max 10
    
  public:
    void startGame();                  // For main to access to play the game
    Node * getHead();
    Node * getTail();
    
}

#endif