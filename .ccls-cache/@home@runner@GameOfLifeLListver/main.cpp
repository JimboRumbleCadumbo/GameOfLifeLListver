#include "GameClasses/GameBoard.h"
#include "menu.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  // ------------------------ Menu Initialization------------------------//

  Menu *newGame = new Menu();
  newGame->setGameOver(false);
  while (!newGame->getGameOver()) {
    newGame->printMainScreenIntro();
  }

  cout << "\n  -- Program has ended --" << endl;

  return 0;
}