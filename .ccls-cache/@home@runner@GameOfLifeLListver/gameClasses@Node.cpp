#include "Node.h"
#include "NodeTypes/RedNode.h"
using namespace std;

template <typename T>
T Node::convert(Node* target) {
  return dynamic_cast<T>(target);
}

void Node::mutate() {
  //Get a random integer to determine the type that a node can mutate into
  //1 - base, 2 - red, 3 - yellow, 4 - red, 5 - green
  int output = 1 + (rand() % static_cast<int>(5 - 1 + 1));

  if (daysAlive < 5) {output = 1;}
  
  switch(output) {
    case 1:
      return;
    case 2:
      inheritNeighbors(this, convert<RedNode*>(this));
      delete this;
    case 3:
      // return convert<BlueNode*>(this);
      break;
    case 4:
      // return convert<YellowNode*>(this);
      break;
    case 5:
      // return convert<GreenNode*>(this);
      break;
  }
}

//-------------------------------------------NODE GETTERS--------------------------------------
//simple getters - const for later assighnment overload (dont know if it will be necessary)
bool Node::isDead() {return !isAlive;}
int Node::getDaysAlive() {return daysAlive;}

void Node::flipLiving() {isAlive = !isAlive;}
void Node::flipFutureLiving() {futureLiving = !futureLiving;}
void Node::setLiving() {isAlive = futureLiving;}

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

string Node::getType() {return nodeType;}

//Returns number of living neighbors to be used in process
int Node::getNumberOfNeighbors() {
  int counter = 0;
  for (int i = 0; i < neighbors.size(); i++) {
    if (neighbors.at(i)->isDead() == false) {counter++;}
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


//-------------------------------------------UTILITY--------------------------------------
//Call this after changing node neighbors in vector
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
void Node::inheritNeighbors(Node* old, bool alive) {
  //New Node will point to it's neighbors
  vector<Node*> tempNeighbors = old->getNeighbors();
  Node* newN = new Node(tempNeighbors, alive);
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

/* 
Function to return the type that the node should be converted to based on the nodes neighbors
- Using counters sum up the number of neighbors using different counters to differentiate the types
- Then using a long else if chain we can determine what type the resulting node
- Yellow is the special case that can take other node types as yellow ONLY when there is at least one yellow EXCLUDES BASE TYPE
- Priority Order: RED BLUE GREEN YELLOW BASE

- will 
*/
void Node::convertNode() {
  if (this->isDead()) {return;} //If node is already alive just return and do nothing
  //Count up all the nodes of different types
  int yCounter = 0;
  int gCounter = 0;
  int bCounter = 0;
  int rCounter = 0;
  int baseCounter = 0;

  for (int i = 0; i < neighbors.size(); i++) {
    string type = neighbors.at(i)->nodeType;
    if (type.compare("yellow") != 0) {
      yCounter++;
    } else if (type.compare("red") != 0) {
      rCounter++;
      if (yCounter > 1) {yCounter++;}
    } else if (type.compare("blue") != 0) {
      bCounter++;
      if (yCounter > 1) {yCounter++;}
    } else if (type.compare("green") != 0) {
      gCounter++;
      if (yCounter > 1) {yCounter++;}
    } else {
      baseCounter++;
    }
  }

  //Now we make deicision based on neighbor counts about the type of conversion
  if (baseCounter > max(max(yCounter, bCounter), max(gCounter, yCounter))) {
    //Convert to a living node by fliping the switch to living
    isAlive = false;
  } else if (rCounter >= 3) {
    //Will replace current deadnode with new RedNode then delete itself
    inheritNeighbors(this, convert<RedNode*>(this));
    delete this;
  } else  if (yCounter >= 3) {
    // inheritNeighbors(this, convert<YellowNode*>(this));
    // delete this;
  } else if (bCounter >=3) {
    // inheritNeighbors(this, convert<BlueNode*>(this));
    // delete this
  } else {
    // inheritNeighbors(this, convert<GreenNode*>(this));
    // delete this;
  }
}

void Node::step() {
  //Dead or alive
  if (isAlive) {
    //When alive we want to check if this Node should die
    if (!livingEligibility()) {
      //In the case that this node should die
      futureLiving = false;
      return;
    } else {
      //In the case the node is alive perform the mutation after incrementing days alive
      daysAlive++;
      mutate();
    }
  } else {
    //If the node is dead we want to check the conversion
    convertNode();
  }
}


bool Node::livingEligibility() {
  int temp = getNumberOfNeighbors();
  if (temp < 2 || temp > 3) {return false;}
  return true;
}



