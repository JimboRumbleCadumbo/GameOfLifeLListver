#include "RedNode.h"
#include <string>
#include <vector>
using namespace std;

bool RedNode::livingEligibility() {
  // needs 4 or more non-red nodes/null around it to continue living
  int counter = 0;
  for (int i = 0; i < neighbors.size(); i++) {
    if (neighbors.at(i) != nullptr && neighbors.at(i)->getType() != "red") {
      if (!(neighbors.at(i)->isDead())) {
        counter++;
      }
    }
  }
  return (counter >= 4);
}

void RedNode::step() {
  //Check living eligibility
  if (livingEligibility()) {
    //In the case it should not live it's converted back to a dead base node
    Node::inheritNeighbors(this, Node::convert<Node*>(this));
    delete this;
  }
}