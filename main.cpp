#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

void flushScreen() {
    system("CLS");
}

void fillBoard(string gameBoard[][15], int pX, int pY) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            gameBoard[i][j] = "_";
        }
    }
    gameBoard[pX][pY] = "7";
}

void printGameBoard(string gameBoard[][15]) {
    cout << "after move: " << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            cout << gameBoard[i][j];
        }
        cout << endl;
    }
}

void updatePlayerPos(char input, int& currPlayerX, int& currPlayerY) {
        if (input == 'w') {
            currPlayerX -= 1;
        }
        else if (input == 's') {
            currPlayerX += 1;
        }
        else if (input == 'a') {
            currPlayerY -= 1;
        }
        else if (input == 'd') {
            currPlayerY += 1;
        }
}

void checkPlayerPos(int& currPlayerX, int& currPlayerY) {
    if (currPlayerX > 9) {
        currPlayerX = 9;
    }
    if (currPlayerX < 0) {
        currPlayerX = 0;
    }
    if (currPlayerY > 14) {
        currPlayerY = 14;
    }
    if (currPlayerY < 0) {
        currPlayerY = 0;
    } 
}

void fillEnemies(string gameBoard[][15], int enemyPos[][2]) {
    int tempX;
    int tempY;
    for (int i = 0; i < 5; i++) {
        tempX = enemyPos[i][0];
        tempY = enemyPos[i][1];
        //cout << tempX << " : " << tempY;
        gameBoard[tempX][tempY] = "9";
    }
}


int main() {

    srand(time(0));
    string gameBox[10][15];
    int playerX = 5;
    int playerY = 5;
    int enemyCount = 5;
    int enemyPos[enemyCount][2];
    for (int i = 0; i < enemyCount; i++) {
        int enemyX;
        int enemyY;
        for (int j = 0; j < 2; j++) {
            if (j % 2 == 0) {
                enemyPos[i][j] = rand() % 10;
            }
            else {
                enemyPos[i][j] = rand() % 15;
            }
        }
    }

    for (int i = 0; i < enemyCount; i++) {
        for (int j = 0; j < 2; j++) {
            cout << enemyPos[i][j] << " ";
        }
    }
    cout << endl;
    // on game start run the following code
    fillBoard(gameBox, playerX, playerY);
    fillEnemies(gameBox, enemyPos);
    printGameBoard(gameBox);

    char ch;

    do {
        ch = _getch();
        //cout << ch << ":pressed" << endl;
        if (ch == 'x') {
            cout << "quit game." << endl;
        }
        else if (ch == 'w' || ch == 's' || ch == 'a' || ch =='d') {
        updatePlayerPos(ch, playerX, playerY);
        checkPlayerPos(playerX, playerY);
        flushScreen();
        fillBoard(gameBox, playerX, playerY);
        fillEnemies(gameBox, enemyPos);
        printGameBoard(gameBox);
        }
        else {
            cout << "Invalid movement input!" << endl << "Please use WASD keys for movement" << endl;
        }

    } while (ch != 'x');

    return 0;
}