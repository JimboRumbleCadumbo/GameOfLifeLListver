#ifndef MENU_H
#define MENU_H

#include "GameClasses/GameBoard.h"
#include <iostream>
#include <string>

class Menu {
private:
  GameBoard *usrGame;
  void printGameOptions();
  bool GameOver;
  void cleanMenu();
public:
  Menu();
  void setGameOver(bool);
  bool getGameOver();
  void printMainScreenIntro();
  
};

#endif