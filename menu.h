#ifndef MENU_H
#define MENU_H

#include "gameClasses/GameBoard.h"
#include <iostream>
#include <string>

class Menu {
private:
  GameBoard *usrGame;
  void printGameOptions();
  bool GameOver;
public:
  Menu();
  void setGameOver(bool);
  bool getGameOver();
  void printMainScreenIntro();
};

#endif