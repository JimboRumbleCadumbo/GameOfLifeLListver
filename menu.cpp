#include "menu.h"
#include "GameClasses/GameBoard.h"
#include "GamePlay.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

Menu::Menu() { usrGame = NULL; }

void Menu::setGameOver(bool usrChoice) { GameOver = usrChoice; }

bool Menu::getGameOver() { return GameOver; }

enum Action {
  START_GAME,
  RULES,
  GAME_SETTING,
  EXIT,
};

Action retriveAction(int usrChoice) {
  if (usrChoice == 1)
    return START_GAME;
  else if (usrChoice == 2)
    return RULES;
  else if (usrChoice == 3)
    return GAME_SETTING;
  else
    return EXIT;
}

void Menu::printGameOptions() {
  while (true) {
    // Get user input
    int usrChoice;
    system("clear");
    cout << "---------------------[Game Settings]---------------------" << endl;
    cout << "  1) Change gameboard wrap."
            "\n     Boundary nodes point to the other side if on."<< endl;
    cout << "  2) Print everyday or only the last day specified."
            "\n     On to print everyday."<< endl;
    cout << "  3) Change mutation amount." << endl;
    cout << "  4) Go back to menu." << endl;

    cout << "  --- Choose options 1 - 4: ";

    while (true) {
      cin >> usrChoice;
      if (usrChoice < 1 || usrChoice > 4)
        cout << "  --- Invalid choice. Choose options 1 - 4: ";
      else
        break;
    }
    if (usrChoice == 4) {
      break;
    } else if (usrChoice == 1) {
      int usrCase;
      while (true) {
        system("clear");
        cout << "---------------------[Set Wrapping]---------------------"
             << endl;
        cout << "  1) Wrap within." << endl;
        cout << "  2) Wrap around." << endl;
        cout << "  3) Go back." << endl;
        cout << "\n  Choose options 1 - 3: ";
        cin >> usrCase;
        if (usrCase < 1 || usrCase > 3)
          cout << "   Invalid choice. Choose options 1 - 3: ";
        else if (usrCase == 1) {
          usrGame->setWrapMode(false);
          cout << "  --- Boundry set Wrap Within. --- " << endl;
          sleep(3);
        } else if (usrCase == 2) {
          usrGame->setWrapMode(true);
          cout << "  --- Boundry set Wrap Around. ---" << endl;
          sleep(3);
        }
        break; // entered 3 or previous statement executed, go back to previous
               // page.
      }
    } else if (usrChoice == 2) {
      int usrCase;

      while (true) {
        system("clear");
        cout << "---------------------[Printing Method]---------------------"
             << endl;
        cout << "  1) Print Everyday." << endl;
        cout << "  2) Print only the Final Day." << endl;
        cout << "  3) Go back." << endl;
        cout << "\n  Choose options 1 - 3: ";
        cin >> usrCase;
        if (usrCase < 1 || usrCase > 3)
          cout << "  Invalid choice. Choose options 1 - 3: ";
        else if (usrCase == 1) {
          usrGame->setPrintEachDay(false);
          cout << "  --- Program now prints EVERYDAY. --- " << endl;
          sleep(3);
        } else if (usrCase == 2) {
          usrGame->setPrintEachDay(true);
          cout << "  --- Program now prints THE FINAL DAY. ---" << endl;
          sleep(3);
        }
        break; // entered 3 or previous statement executed, go back to previous
               // page.
      }

    } else if (usrChoice == 3) {
      system("clear");
      cout << "---------------------[Mutation Number]---------------------"
           << endl;
      cout << "\nPlease enter the new Mutation Amount (1-10) or enter 0 "
              "to go back: ";
      int usrCase;

      while (true) {
        cin >> usrCase;
        if (usrCase < 0 || usrCase > 10)
          cout << "  --- Invalid choice. Please enter the new Mutation "
                  "Amount (1-10) or enter 0 to go back: ";
        if (usrCase != 0) {
          usrGame->setMutationAmount(usrCase);
          cout << "  --- Mutation Amount is now " << usrCase << ". --- "
               << endl;
          sleep(3);
        }
        break; // entered 0 or previous statement executed, go back to previous
               // page.
      }
    }
  }
}

void Menu::printMainScreenIntro() {

  int usrChoice;
  bool isValid = false;

  Action usrAction;

  while (true) { // Will keep running until EXIT.
    system("clear");
    cout << "\n";
    cout << "  *** Welcome to The Game of Life! ***" << endl;
    cout << "\n";
    cout << "  *** Please select an option ***" << endl;
    cout << "  1) Start Game" << endl;
    cout << "  2) Game Rule" << endl;
    cout << "  3) Game Settings" << endl;
    cout << "  4) Exit" << endl;
    cout << "\n  Enter your choice: ";
    do {
      cin >> usrChoice;
      if (usrChoice < 0 || usrChoice > 4)
        cout << "  *** Invalid option!  Please select an available option ***"
             << endl;
      else
        isValid = true;
    } while (!isValid);

    usrAction = retriveAction(usrChoice);

    if (usrAction == EXIT) {
      cout << "\n  *** Thank you for playing !!! *** " << endl;
      setGameOver(true);
      return;
    } else {
      switch (usrAction) {
      case START_GAME: {
        GamePlay *newGameplay = new GamePlay();
        newGameplay->StartGame();
        break;
      }
      case RULES:
        // Plan to implement rules to another file
        cout << "  COMING SOON!" << endl;
        sleep(5);
        break;
      case GAME_SETTING:
        printGameOptions();
        break;
      default:
        break;
      }
    }
  }
}
