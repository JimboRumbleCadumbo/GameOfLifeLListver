#include "Node.h"
#include <string>
#include <vector>
#ifndef REDNODE_H
#define REDNODE_H

class RedNode : Node {
private:
  std::string nodeType = "red"; // agressive

public:
  bool livingEligibility() override;
  void step() override;

  //Should use the explicit typed constructor in Node
  using Node::Node;

  //Destructor of super class will be called when an instance of RedNode is deleted from heap or stack 
};

#endif