#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "GameClasses/GameBoard.h"
#include <iostream>
#include <string>

class GamePlay {
private:
  
public:
  GamePlay();
  void StartGame();
  void mainLoop(GameBoard* &gameBoard);
};

#endif