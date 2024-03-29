#include<vector>
#ifndef NODE_H
#define NODE_H

class Node {
  private:
    bool isAlive;
    std::vector<Node*> neighbors;

    //TODO: Add clust obj representing the group of nodes that this node is part of

  public:
    bool getAlive() const;
    std::vector<Node*> getNeighbors();

    //Constructor
    Node(bool alive = false, std::vector<Node*> neighbors = nullptr) {
      this->isAlive = alive;
      //TODO: Requires overload assighnment to 
      this->neighbors = neighbors;
      
    }

#endif