#include "GameBoard.h"
using namespace std;

// -------------------------- Initialize Board -------------------------- //

GameBoard::GameBoard() {
  int size = 5;
  startingBoard = vector<vector<Node *>>(size, vector<Node *>(size, nullptr));

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      startingBoard.at(i).at(j) = new Node();
    }
  }

  connectNodes(size);
  printBoard();
}

GameBoard::GameBoard(int size) {
  startingBoard = vector<vector<Node *>>(size, vector<Node *>(size, nullptr));

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      startingBoard.at(i).at(j) = new Node();
    }
  }

  connectNodes(size);
  printBoard();
}

// ------------------------ Connect Nodes Functions ------------------------ //

void GameBoard::connectNodes(int size) {
  setHead(startingBoard.at(0).at(0));

  for (int i = 0; i < size; i++) {
    connectNodesLeft(startingBoard.at(i), size);
    connectNodesRight(startingBoard.at(i), size);
  }

  connectNodesTop(startingBoard, size);
  connectNodesBottom(startingBoard, size);
  connectNodesDiagnols(size);
}

void GameBoard::connectNodesLeft(vector<Node *> &linkNodes, int size) {
  for (int j = 1; j < size; j++) {
    linkNodes.at(j)->setLeft(linkNodes.at(j - 1));
  }
}

void GameBoard::connectNodesRight(vector<Node *> &linkNodes, int size) {
  for (int j = size - 2; j > 0 - 1; j--) {
    linkNodes.at(j)->setRight(linkNodes.at(j + 1));
  }
}

void GameBoard::connectNodesTop(vector<vector<Node *>> &linkNodes, int size) {
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < size; j++) {
      linkNodes.at(i).at(j)->setTop(linkNodes.at(i - 1).at(j));
    }
  }
}

void GameBoard::connectNodesBottom(vector<vector<Node *>> &linkNodes,
                                   int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size; j++) {
      linkNodes.at(i).at(j)->setBottom(linkNodes.at(i + 1).at(j));
    }
  }
}

void GameBoard::connectNodesDiagnols(int size) {
  Node *temp = this->getHead();
  bool func = false;

  while (temp != nullptr) {
    if (temp->getLeft() != nullptr && temp->getBottom() != nullptr) {
      temp->setBottomL(temp->getLeft()->getBottom());
    } else {
      temp->setBottomL(nullptr);
    }

    if (temp->getLeft() != nullptr && temp->getTop() != nullptr) {
      temp->setTopL(temp->getLeft()->getTop());
    } else {
      temp->setTopL(nullptr);
    }

    if (temp->getRight() != nullptr && temp->getBottom() != nullptr) {
      temp->setBottomR(temp->getRight()->getBottom());
    } else {
      temp->setBottomR(nullptr);
    }

    if (temp->getRight() != nullptr && temp->getTop() != nullptr) {
      temp->setTopR(temp->getRight()->getTop());
    } else {
      temp->setTopR(nullptr);
    }

    temp = lListNavagation(temp, func);
  }
}

// ------------------------ Print Board Function ------------------------ //

void GameBoard::printBoard() {
  Node *temp = this->getHead();
  bool changeDirections = false;
  bool downChecker = false;

  while (temp != nullptr) {
    if (!temp->isDead()) {
      printf("%c[%dm", 0x1B, 31); //Color test!
      cout << "\u25A0"
           << " ";
      printf("%c[%dm", 0x1B, 00); //Color test!
    } else {
      cout << "\u25A1"
           << " ";
    }

    temp = lListNavagation(temp, changeDirections);

    if (downChecker != changeDirections) {
      cout << endl;
      downChecker = changeDirections;
    }
  }
}

int GameBoard::timeStep(int dayAmount)
{
  Node * temp = this->getHead();
  bool func = false;
  for(int i = 0; i < dayAmount; i++)
    {
      while(temp != nullptr)
        {
          temp->step();
          temp = lListNavagation(temp, func);
        }
      dayAmount++;
    }
  lateStep();
  return dayAmount;
}

// ------------------------ Linked List Navigation Function------------------------ //

Node *GameBoard::lListNavagation(Node *temp, bool &changeDirections) {
  if (temp->getRight() != nullptr) {
    temp = temp->getRight();
  } else if (temp->getRight() == nullptr) {
    temp = temp->getBottom();
    changeDirections = !changeDirections;

    if (temp != nullptr)
      while (temp->getLeft() != nullptr) {
        temp = temp->getLeft();
      }
  }
  return temp;
}

// ------------------------ Set Living Cell ------------------------ //

void GameBoard::lateStep() 
{
  Node * temp = this->getHead();
  bool func = false;
  while(temp != nullptr)
    {
      //present to future board
      temp = lListNavagation(temp, func);
    }
}

void GameBoard::setLivingCell(int x, int y) {
  Node *temp;
  temp = startingBoard.at(y).at(x);
  temp->flipLiving();
}

// ------------------------ Getters and Setters ------------------------ //

void GameBoard::setHead(Node *temp) { presentBoardHeadpt = temp; }

Node *GameBoard::getHead() { return presentBoardHeadpt; }


// ------------------------ Setters for Rules ------------------------ //

void GameBoard::setWrapMode(bool usrChoice) { wrapMode = usrChoice; }
void GameBoard::setPrintEachDay(bool usrChoice) { printEachDay = usrChoice; }
void GameBoard::setMutationAmount(int usrChoice) { mutationAmount = usrChoice; }