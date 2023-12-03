#include <vector>
#include <string>
#include <random>
#include <stdexcept>
#include <iostream>
#include "GameBoard.h"
#ifndef NODE_H
#define NODE_H

//Throws runtime error when you pass vector into Node(vector) constructor
#define CHECK_EMPTY_VECTOR(vector) \
if (vector.empty()) { \
  throw std::runtime_error("Vector passed to Node constructor is empty"); \
}

//inheriting from gameboard
class Node {
  private:
    bool futureLiving;
    bool isAlive;
    int daysAlive;
    std::string nodeType = "base";
 
//-------------------------------------------PRIVATE UTILITY--------------------------------------
    void mutate();
    void convertNode();  
  protected:
    //All neighbors
    Node* top;
    Node* topR;
    Node* right;
    Node* bottomR;
    Node* bottom;
    Node* bottomL;
    Node* left;
    Node* topL;
    std::vector<Node*> neighbors; //clockwise 0-top, (size - 1) - top left

//-------------------------------------------PROTECTED NODE GETTERS--------------------------------------
    std::vector<Node*> getNeighbors();
    int getNumberOfNeighbors();
//-------------------------------------------PROTECTED NODE SETTERS--------------------------------------
    void setByIndex(int index, Node* toSet);
    void setNeighbor(Node* newN, int location); //Location represents 0 to 8 where 0 is top moving clockwise and 8 - top left
    
  public:
//-------------------------------------------NODE GETTERS--------------------------------------
    bool isDead();
    void flipLiving();
    void flipFutureLiving();
    void setLiving();
    int getDaysAlive();

    Node* getTop();
    Node* getTopR();
    Node* getRight();
    Node* getBottomR();
    Node* getBottom();
    Node* getBottomL();
    Node* getLeft();
    Node* getTopL();

    std::string getType();

//-------------------------------------------NODE SETTERS--------------------------------------
    void setTop(Node* newN);
    void setTopR(Node* newN);
    void setRight(Node* newN);
    void setBottomR(Node* newN);
    void setBottom(Node* newN);
    void setBottomL(Node* newN);
    void setLeft(Node* newN);
    void setTopL(Node* newN);


    //Constructor
    explicit Node(bool alive,
         Node* top = nullptr,
         Node* topR = nullptr,
         Node* right = nullptr,
         Node* bottomR = nullptr,
         Node* bottom = nullptr,
         Node* bottomL = nullptr,
         Node* left = nullptr,
         Node* topL = nullptr) {
      
      // Setting all nodes to given nodes
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
      
      //testcounter++; -For testing 
      this->isAlive = alive;
      this->daysAlive = 0;
      }

    explicit Node(std::vector<Node*> &neighbors, bool alive = false) { 
      //Throws system error if we send an empty list here
      CHECK_EMPTY_VECTOR(neighbors);
      this->neighbors = neighbors;
      resetVector();

      this->isAlive = alive;
      this->daysAlive = 0;
    }
    
    virtual ~Node();
//-------------------------------------------PUBLIC UTILITY--------------------------------------
/* Function to make removing and adding mutated nodes easier. all old neighbors go to new nodes neighbors and returns a dead node with the
   same neighbors and delete oldN
*/
//For easy type conversions for mutation and dead -> living type node conversions
template<typename T> 
T convert(Node* target); 

void inheritNeighbors(Node* oldN, bool alive);
void resetVector();

virtual void step();
virtual bool livingEligibility();


//-------------------------------------------OVERLOADED OPERATORS--------------------------------------

};

#endif