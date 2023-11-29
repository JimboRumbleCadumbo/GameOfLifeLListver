


#include<vector>
#include "GameBoard.h"
#ifndef NODE_H
#define NODE_H

//inheriting from gameboard
class Node : GameBoard {
  private:
    bool isAlive;
    int* xPos;
    int* yPos;
    int* daysAlive();
    std::vector<Node*> neighbors;

    //TODO: Add clust obj representing the group of nodes that this node is part of

  public:
    //getters
    bool isDead() const;
    int getXPos() const;
    int getYPos() const;
    int getDaysAlive() const;
    std::vector<Node*> getNeighbors();

    //setters
    void kill();
    void revive();
    void setPos(int x, int y);
    void addNeighbor(Node* newN);

    //Test functions
    void printNeigborsTest();

    //Constructor
    Node(bool alive = false, std::vector<Node*> neighbors) {
      this->isAlive = alive;
      this->neighbors = neighbors;
    }
};

#endif