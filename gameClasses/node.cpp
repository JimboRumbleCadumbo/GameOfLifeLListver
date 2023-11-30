#include<vector>
#include "Node.h"
using namespace std;

//-------------------------------------------NODE GETTERS--------------------------------------
//simple getters - const for later assighnment overload (dont know if it will be necessary)
bool Node::isDead() const {return isAlive;}
int Node::getXPos() const {return *xPos;}
int Node::getYPos() const {return *yPos;}
int Node::getDaysAlive() {return *daysAlive;}
vector<Node*> Node::getNeighbors() {return neighbors;}

//Getters for nodes
Node* Node::getTop() {return this->top;}
Node* Node::getTopR() {return this->topR;}
Node* Node::getRight() {return this->right;}
Node* Node::getBottomR() {return this->bottomR;}
Node* Node::getBottom() {return this->bottom;}
Node* Node::getBottomL() {return this->bottomL;}
Node* Node::getLeft() {return this->left;}
Node* Node::getTopL() {return this->topL;}

//Returns number of living neighbors to be used in process
int Node::getNumberOfNeighbors() {
  int counter;
  for (int i = 0; i < neighbors.size(); i++) {
    if (neighbors.at(i)->isDead() == false) {counter++;};
  }
  return counter;
}

//-------------------------------------------NODE SETTERS--------------------------------------
void Node::setTop(Node* newN) {this->top = newN;}
void Node::setTopR(Node* newN) {this->topR = newN;}
void Node::setRight(Node* newN) {this->right = newN;}
void Node::setBottomR(Node* newN) {this->bottomR = newN;}
void Node::setBottom(Node* newN) {this->bottom = newN;}
void Node::setBottomL(Node* newN) {this->bottomL = newN;}
void Node::setLeft(Node* newN) {this->left = newN;}
void Node::setTopL(Node* newN) {this->topL = newN;}

void Node::setByIndex(int index, Node* toSet) {
  this->neighbors.at(index) = toSet;
}

void Node::kill() {isAlive = false;}
void Node::revive() {isAlive = true;}
void Node::setPos(int x, int y) {
  *xPos = x;
  *yPos = y;
}

//-------------------------------------------UTILITY--------------------------------------
void Node::resetVector() {
  this->top = neighbors.at(0);
  this->topR = neighbors.at(1);
  this->right = neighbors.at(2);
  this->bottomR = neighbors.at(3);
  this->bottom = neighbors.at(4);
  this->bottomL = neighbors.at(5);
  this->left = neighbors.at(6);
  this->topL = neighbors.at(7);
}

//Will inherit a target nodes links allowing for easier node insertion and deletion
Node* Node::inheritNeighbors(Node* old) {
  //New Node will point to it's neighbors
  Node* newN = new Node(false, old->getNeighbors());

  //Now to set node neighbors to point to newN instead of oldN
  for (int i = 0; i < 8; i++) {
    //Search through all 8 neighbors
    for (int j = 0; j < 8; j++) {
      Node* temp = newN->getNeighbors().at(i)->getNeighbors().at(j);
      //Search through adjacent neighbors neighbors to find the pointer pointing to old
      if (&temp == &old) {
        //make correct change in neighbors vectors
        temp->getNeighbors().at(j) = newN;
        //force reset vector to change target node
        temp->resetVector();
      }
    }
  }
  
}