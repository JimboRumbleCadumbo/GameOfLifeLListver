#include "menu.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Action {
  START_GAME,
  RULES,
  EXIT,
};

Action retriveAction(int usrChoice) {
  if (usrChoice == 1)
    return START_GAME;
  else if (usrChoice == 2)
    return RULES;

  return EXIT;
}

void Menu::printMainScreenIntro() {
  cout << "  *** Welcome to The Game of Life! ***" << endl;
  cout << "\n";
  cout << "  *** Please select an option ***" << endl;
  cout << "  1. Start Game" << endl;
  cout << "  2. Game Rule" << endl;
  cout << "  3. Exit" << endl;

  int usrChoice;
  bool isValid = false;

  Action usrAction;

  while (true) { // Will keep running until EXIT.
    cout << "\n  Enter your choice: ";
    do {
      cin >> usrChoice;
      if (usrChoice < 0 || usrChoice > 3) {
        cout << "  *** Invalid option!  Please select an available option ***"
             << endl;
      } else {
        isValid = true;
      }
    } while (!isValid);

    usrAction = retriveAction(usrChoice);

    switch (usrAction) {
    case START_GAME:
      // Plan to implement gameplay to another file
      cout << "  COMING SOON!" << endl;
      break;
    case RULES:
      // Plan to implement rules to another file
      cout << "  COMING SOON!" << endl;
      break;
    case EXIT:
      cout << "\n  *** Thank you for playing! Bye! ***" << endl;
      return;
    default:
      break;
    }
  }
}
