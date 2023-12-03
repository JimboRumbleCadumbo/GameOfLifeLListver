#include "GameBoard.h"
using namespace std;

// -------------------------- Initialize Board -------------------------- //

GameBoard::GameBoard() {
  int size = 5;
  startingBoard = vector<vector<Node *>>(size, vector<Node *>(size, nullptr));

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      startingBoard.at(i).at(j) = new Node(false);
    }
  }

  connectNodes(size);
  printBoard();
}

GameBoard::GameBoard(int size) {
  startingBoard = vector<vector<Node *>>(size, vector<Node *>(size, nullptr));

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      startingBoard.at(i).at(j) = new Node(false);
    }
  }

  connectNodes(size);
  printBoard();
}

// ------------------------ Connect Nodes Functions ------------------------ //

void GameBoard::connectNodes(int size) {
  setHead(startingBoard.at(0).at(0));
  this->printDown = this->getHead();

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

  while (this->printDown != nullptr) {
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
  this->printDown = this->getHead();
}

// ------------------------ Print Board Function ------------------------ //

void GameBoard::printBoard() {
  Node *temp = this->getHead();
  bool changeDirections = false;
  bool downChecker = false;

  while (this->printDown != nullptr) {
    if (!temp->isDead()) {
      printf("%c[%dm", 0x1B, 23); // Color test!
      printf("\u25A0 ");
      printf("%c[%dm", 0x1B, 00); // Color test!
    } else {
      printf("\u25A1 ");
    }

    temp = lListNavagation(temp, changeDirections);

    if (downChecker != changeDirections) {
      printf("\n");
      downChecker = changeDirections;
    }
  }
  this->printDown = this->getHead();
}

int GameBoard::timeStep(int dayAmount) {
  Node *temp = this->getHead();
  bool func = false;
  for (int i = 0; i < dayAmount; i++) {
    while (this->printDown != nullptr) {
      temp->step(); // --next things to build
      temp = lListNavagation(temp, func);
    }
    func = false;
    this->printDown = this->getHead();
    temp = this->getHead();
    lateStep();
  }
  return dayAmount;
}

// ------------------------ Linked List Navigation
// Function------------------------ //

Node *GameBoard::lListNavagation(Node *temp, bool &changeDirections) {
  if (temp->getRight() != nullptr) {
    temp = temp->getRight();
  } else if (temp->getRight() == nullptr) {
    this->printDown =  this->printDown->getBottom();
    changeDirections = !changeDirections;

    if (this->printDown != nullptr)
    {
      temp = this->printDown;
    }
  }
  return temp;
}

// ------------------------ Set Living Cell ------------------------ //

void GameBoard::lateStep() {
  Node *temp = this->getHead();
  bool func = false;
  while (this->printDown != nullptr) {
    temp->setLiving();
    // present to future board
    temp = lListNavagation(temp, func);
  }
  this->printDown = this->getHead();
  int needed = 0;
  if ((needed = system("clear")))
    cout << needed << endl;
  printBoard();

  this_thread::sleep_for(chrono::milliseconds(360));
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