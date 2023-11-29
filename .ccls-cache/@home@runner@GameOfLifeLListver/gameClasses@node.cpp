#include<vector>
#include "Node.h"
using namespace std;

//simple getters - const for later assighnment overload (dont know if it will be necessary)
bool Node::isDead() const {return *isAlive;}
int Node::getXPos() const {return *xPos;}
int Node::getYPos() const {return *yPos;}
int Node::getDaysAlive() const {return *daysAlive;}
vector<Node*> Node::getNeighbors() const {return neighbors;}

//Simple setters
void Node::kill() {isAlive = false;}
void Node::revive() {isAlive = true;}
void Node::setPos(int x, int y) {
  //TODO: Out of game bounds check
  *xPos = x;
  *yPos = y;
}
//TODO: Modify this so that the newN is put in the correct empty index of the neigbors vector
/* i.e.
Node -> neigbors {topL = null, top, topR, right = null, botomR, bottom, bottomL = null, left = null}
Node to Insert -> NewN, left
Node -> neigbors {topL = null, top, topR, right = null, botomR, bottom, bottomL = null, left = newN}
*/
void Node::addNeighbor(Node* newN, int location) {
  neighbors.add(newN);
}

//Test function to pring locations of neighbors
void Node::printNeigborsTest(Node* parent) {
  vector::const_iterator itr = parent->neighbors.begin();
  while (itr != parent->neighbors.end()) {
    cout << "Neighbors at X: " << *xPos << ", Y: " << *yPos << endl;
    itr++;
  }
}

//TODO: check conditions from game rules on time step
void 

}