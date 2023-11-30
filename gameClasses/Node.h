#include<vector>
#include<string>
#include<stdexcept>

#include "GameBoard.h"
#ifndef NODE_H
#define NODE_H

//Throws runtime error when you pass vector into Node(vector) constructor
#define CHECK_EMPTY_VECTOR(vector) \
if (!vector.empty()) { \
  throw std::runtime_error("Vector passed to Node constructor is empty"); \
}


//inheriting from gameboard
class Node {
  private:
    bool isAlive;
    int* xPos;
    int* yPos;
    int* daysAlive;
    std::vector<Node*> neighbors; //clockwise 0-top, (size - 1) - top left

    //All neighbors
    Node* top;
    Node* topR;
    Node* right;
    Node* bottomR;
    Node* bottom;
    Node* bottomL;
    Node* left;
    Node* topL;

    //TODO: Add clust obj representing the group of nodes that this node is part of

  public:
//-------------------------------------------NODE Getters--------------------------------------
    bool isDead() const;
    int getXPos() const;
    int getYPos() const;
    int getDaysAlive();
    std::vector<Node*> getNeighbors();
    void setNeighbor(Node* newN, int location); //Location represents 0 to 8 where 0 is top moving clockwise and 8 - top left
    int getNumberOfNeighbors();

    //Node getters
    Node* getTop();
    Node* getTopR();
    Node* getRight();
    Node* getBottomR();
    Node* getBottom();
    Node* getBottomL();
    Node* getLeft();
    Node* getTopL();

    //-------------------------------------------NODE SETTERS--------------------------------------
    void kill();
    void revive();
    void setPos(int x, int y);

    void setTop(Node* newN);
    void setTopR(Node* newN);
    void setRight(Node* newN);
    void setBottomR(Node* newN);
    void setBottom(Node* newN);
    void setBottomL(Node* newN);
    void setLeft(Node* newN);
    void setTopL(Node* newN);

    void setByIndex(int index, Node* toSet);

    //Constructor
    Node(Node* top = nullptr,
         Node* topR = nullptr,
         Node* right = nullptr,
         Node* bottomR = nullptr,
         Node* bottom = nullptr,
         Node* bottomL = nullptr,
         Node* left = nullptr,
         Node* topL = nullptr, bool alive = false,) {
      
      //Setting all nodes to given nodes
      this->top = top;
      this->neighbors.push_back(this->top);
      this->topR = topR;
      this->neighbors.push_back(this->topR);
      this->right = right;
      this->neighbors.push_back(this->right);
      this->bottomR = bottomR;
      this->neighbors.push_back(this->bottomR);
      this->bottom = bottom;
      this->neighbors.push_back(this->bottom);
      this->bottomL = bottomL;
      this->neighbors.push_back(this->bottomL);
      this->left = left;
      this->neighbors.push_back(this->left);
      this->topL = topL;
      this->neighbors.push_back(this->topL);

      this->isAlive = false;
      *(this->daysAlive) = 0;
      }

    Node(bool alive, std::vector<Node*> neighbors) {
      //Throws system error if we send an empty list here
      CHECK_EMPTY_VECTOR(neighbors);
      this->top = neighbors.at(0);
      this->topR = neighbors.at(1);
      this->right = neighbors.at(2);
      this->bottomR = neighbors.at(3);
      this->bottom = neighbors.at(4);
      this->bottomL = neighbors.at(5);
      this->left = neighbors.at(6);
      this->topL = neighbors.at(7);

      this->isAlive = alive;
      *(this->daysAlive) = 0;
    }

//-------------------------------------------UTILITY--------------------------------------
/* Function to make removing and adding mutated nodes easier. all old neighbors go to new nodes neighbors and returns a dead node with the
   same neighbors and delete oldN
*/
Node* inheritNeighbors(Node* oldN);
void resetVector();
//-------------------------------------------OVERLOADED OPERATORS--------------------------------------

};

#endif