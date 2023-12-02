#include "GamePlay.h"
#include "GameClasses/GameBoard.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

GamePlay::GamePlay() {}

void GamePlay::StartGame() {
  int livingXpos = 0;
  int livingYpos = 0;
  int size = 5;

  while (true) {
    do {
      cout << "What dimensions do you want the gameboard to be" << endl;
      cin >> size;
      if (size < 1)
        cout << "oh, that is too small for a board" << endl;
    } while (size < 1);

    // ------------------------ Game Initialization ------------------------//
    GameBoard *gameBoard = new GameBoard(size);

    // ------------------------ Welcome Message ------------------------//

    cout << "--------------------------------------------------------------"
         << endl;
    cout << "\n\n";
    cout << "Here we are going to have you decide what the coordinates of the "
            "living cells are going to be."
         << endl;
    cout << "As an example a coordinate can be written like this: 1 1 or like "
            "this: "
            "\n1\n1\n"
         << endl;
    cout << "When finished, press: \n-1\n-1" << endl;
    cout << "--------------------------------------------------------------"
         << endl;

    // ------------------------ User Input for Living Cells
    // ------------------------//

    cout << "x,y\n" << endl;
    cin >> livingXpos;
    cin >> livingYpos;

    while (livingXpos > -1 && livingYpos > -1) {
      gameBoard->setLivingCell(livingXpos, livingYpos);
      gameBoard->printBoard();
      cout << "--------------------------------------------------------------"
           << endl;
      cout << "x,y\n" << endl;
      cin >> livingXpos;
      cin >> livingYpos;

      if (livingXpos < 0 || livingYpos < 0) {
        char confirm;
        cout << "Just confirming this is all you want for this game. (y/n)"
             << endl;
        cout << endl;
        cin >> confirm;
        if (confirm == 'y') {
          continue;
        } else {
          cout << "What else would you like to add?\n" << endl;
          cout << "------------------------------------------------------------"
                  "--"
               << endl;
          cout << "x,y\n" << endl;
          cin >> livingXpos;
          cin >> livingYpos;
        }
      }
    }

    // ------------------------ Game Start ------------------------//

    mainLoop(gameBoard);

    // repeat if yes
    cout << "Do you want to start another game? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm == 'n')
      return;
  }
}

void GamePlay::mainLoop(GameBoard * &gameBoard)
{
  int days = 0;
  cout << "Enter the number of days you want to run the game for! " << endl;
  cout << "Enter -1 if you wish to quit this game: ";
  cin >> days;
  while(days > 0)
    {
  cout << endl;
  cout << "--------------------------------------------------------------\n\n"<< endl;
  gameBoard->timeStep(days);
  cout << "Enter more days or -1 to quit: ";
  cin >> days;
    }
}