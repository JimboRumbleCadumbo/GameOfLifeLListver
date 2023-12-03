#include <iostream>
#include "GameBoard.h"

using namespace std;

// Test Case 1: 
void testGameBoardInitialization() {
    GameBoard gameBoard(5); 
    assert(gameBoard.getHead() != nullptr);
    bool goingRight = true; // snake through gameBoard starting right
  // go through each node

  if(gameBoard.getHead() == nullptr)
    cout << "fail:\ncan't get head" << endl;


  Node* currentNode = gameBoard.getHead();
  for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
          if(currentNode == nullptr)
              cout << "fail:\ncan't get node position x: " << i << " y: " << j << endl;
          if(goingRight)
            currentNode = currentNode->getRight();  
          else
            currentNode = currentNode->getLeft();
      }
      currentNode = currentNode->getBottom(); 
      goingRight = !goingRight; // swap value
  }
}



// Test Case 2: Printing
void testPrinting() {
    GameBoard gameBoard(5);
    gameBoard.setLivingCell(2, 2);
    gameBoard.setLivingCell(3, 3);
    gameBoard.printBoard();
    cout << "gameboard successfully printed above" << endl;
}


// "still lifes don't change from one generation to the next"
// Test Case 3: "still lifes" stagnant patterns: Block
void testStillLifes1() {
    bool goingRight = true;
    GameBoard gameBoard(5);
    gameBoard.setLivingCell(2, 2);
    gameBoard.setLivingCell(2, 3);
    gameBoard.setLivingCell(3, 2);
    gameBoard.setLivingCell(3, 3);
    gameBoard.timeStep(rand() % 20 + 1);
    // check all living cells are in same position

  Node* currentNode = gameBoard.getHead(); // should probably turn this into a method later
      for (int i = 0; i < 5; ++i) {
          for (int j = 0; j < 5; ++j) {
              if ((i == 2 && (j == 2 || j == 3)) || (i == 3 && (j == 2 || j == 3))) {
                  // cells (2,2), (2,3), (3,2), (3,3) should still be alive
                  if (currentNode == nullptr || currentNode->isDead()) {
                      cout << "testStillLifes1 Failed: living cell is dead" << endl;
                      return;  
                  }
              } else {
                  // all other cells should be dead
                  if (currentNode == nullptr || !currentNode->isDead()) {
                      cout << "testStillLifes1 Failed: Dead cell is alive" << endl;
                      return;  /
                  }
              }
              if(goingRight)
                currentNode = currentNode->getRight();  
              else
                currentNode = currentNode->getLeft();
            }
            currentNode = currentNode->getBottom(); 
            goingRight = !goingRight; // swap value
      }

      cout << "testStillLifes1 Passed" << endl;
 }



// Test Case 3: Testing "still lifes" stagnant patterns: Beehive
void testStillLifes2() {
    bool goingRight = true;
    GameBoard gameBoard(5);
    gameBoard.setLivingCell(2, 2);
    gameBoard.setLivingCell(3, 2);
    gameBoard.setLivingCell(1, 3);
    gameBoard.setLivingCell(4, 3);
    gameBoard.setLivingCell(2, 4);
    gameBoard.setLivingCell(3, 4);
    gameBoard.timeStep(rand() % 20 + 1);

    Node* currentNode = gameBoard.getHead();
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (((i == 2 || i == 3) && (j == 2 || j == 3)) || (i == 1 && j == 3) || (i == 4 && j == 3)) {
                // cells (2,2), (3,2), (1,3), (4,3), (2,4), (3,4) should still be alive
                if (currentNode == nullptr || currentNode->isDead()) {
                    cout << "testStillLifes2 Failed: living cell is dead" << endl;
                    return;  
                }
            } else {
                // all other cells should be dead
                if (currentNode == nullptr || !currentNode->isDead()) {
                    cout << "testStillLifes2 Failed: Dead cell is alive" << endl;
                    return;  
                }
            }
            if(goingRight)
                currentNode = currentNode->getRight();  
            else
                currentNode = currentNode->getLeft();
        }
        currentNode = currentNode->getBottom(); 
        goingRight = !goingRight; // swap value
    }

    cout << "testStillLifes2 Passed" << endl;
}


// Test Case 4: Testing "still lifes" stagnant patterns: Loaf
void testStillLifes3() {
    bool goingRight = true;
    GameBoard gameBoard(6);
    gameBoard.setLivingCell(2, 2);
    gameBoard.setLivingCell(3, 2);
    gameBoard.setLivingCell(1, 3);
    gameBoard.setLivingCell(4, 3);
    gameBoard.setLivingCell(2, 4);
    gameBoard.setLivingCell(4, 4);
    gameBoard.setLivingCell(3, 5);
    gameBoard.timeStep(rand() % 20 + 1);

    Node* currentNode = gameBoard.getHead();
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (((i == 2 || i == 3) && (j == 2 || j == 3)) || (i == 1 && j == 3) || (i == 4 && (j == 3 || j == 4)) || (i == 3 && j == 5)) {
                // cells (2,2), (3,2), (1,3), (4,3), (2,4), (4,4), (3,5) should still be alive
                if (currentNode == nullptr || currentNode->isDead()) {
                    cout << "testStillLifes3 Failed: living cell is dead" << endl;
                    return;  
                }
            } else {
                // all other cells should be dead
                if (currentNode == nullptr || !currentNode->isDead()) {
                    cout << "testStillLifes3 Failed: Dead cell is alive" << endl;
                    return;  
                }
            }
            if(goingRight)
                currentNode = currentNode->getRight();  
            else
                currentNode = currentNode->getLeft();
        }
        currentNode = currentNode->getBottom(); 
        goingRight = !goingRight; // swap value
    }

    cout << "testStillLifes3 Passed" << endl;
}

// Test Case 5: testing "still lifes" stagnant patterns: Boat
void testStillLifes4() {
    bool goingRight = true;
    GameBoard gameBoard(6);
    gameBoard.setLivingCell(1, 2);
    gameBoard.setLivingCell(2, 2);
    gameBoard.setLivingCell(1, 3);
    gameBoard.setLivingCell(3, 3);
    gameBoard.setLivingCell(2, 4);
    gameBoard.timeStep(rand() % 20 + 1);

    Node* currentNode = gameBoard.getHead();
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (((i == 1 || i == 2) && (j == 2 || j == 3)) || (i == 3 && j == 3) || (i == 2 && j == 4)) {
                // cells (1,2), (2,2), (1,3), (3,3), (2,4) should still be alive
                if (currentNode == nullptr || currentNode->isDead()) {
                    cout << "testStillLifes4 Failed: living cell is dead" << endl;
                    return;  
                }
            } else {
                // all other cells should be dead
                if (currentNode == nullptr || !currentNode->isDead()) {
                    cout << "testStillLifes4 Failed: Dead cell is alive" << endl;
                    return;  
                }
            }
            if(goingRight)
                currentNode = currentNode->getRight();  
            else
                currentNode = currentNode->getLeft();
        }
        currentNode = currentNode->getBottom(); 
        goingRight = !goingRight; // swap value
    }

    cout << "testStillLifes4 Passed" << endl;
}

// Test Case 5: testing "still lifes" stagnant patterns: Tub
void testStillLifes5() {
    bool goingRight = true;
    GameBoard gameBoard(6);
    gameBoard.setLivingCell(2, 2);
    gameBoard.setLivingCell(1, 3);
    gameBoard.setLivingCell(3, 3);
    gameBoard.setLivingCell(2, 4);
    gameBoard.timeStep(rand() % 20 + 1);

    Node* currentNode = gameBoard.getHead();
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (((i == 2) && (j == 2 || j == 4)) || (i == 1 && j == 3) || (i == 3 && j == 3)) {
                // cells (2,2), (1,3), (3,3), (2,4) should still be alive
                if (currentNode == nullptr || currentNode->isDead()) {
                    cout << "testStillLifes5 Failed: living cell is dead" << endl;
                    return;  
                }
            } else {
                // all other cells should be dead
                if (currentNode == nullptr || !currentNode->isDead()) {
                    cout << "testStillLifes5 Failed: Dead cell is alive" << endl;
                    return;  
                }
            }
            if(goingRight)
                currentNode = currentNode->getRight();  
            else
                currentNode = currentNode->getLeft();
        }
        currentNode = currentNode->getBottom(); 
        goingRight = !goingRight; // swap value
    }

    cout << "testStillLifes5 Passed" << endl;
}

// will test oscillators next: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life



void testCases() {

  // testGameBoardInitialization();
  // testPrinting();
  // testStillLifes1();
  // testStillLifes2();
  // testStillLifes3();
  // testStillLifes4();
  // testStillLifes5();

  cout << "test cases passed" << endl;


}
