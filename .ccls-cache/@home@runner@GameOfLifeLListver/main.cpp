#include <iostream>
#include <vector>
#include <string>
#include "menu.h"

using namespace std;

int main() {
  Menu* newGame = new Menu();
  newGame->printMainScreenIntro();
  
  cout << "  -- Program has ended --" << endl;

  return 0;
}