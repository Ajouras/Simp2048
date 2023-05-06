#include<iostream>
#include<cmath>
#include<unistd.h>
#include<vector>    
#include <iomanip>  

const int BOARD_SIZE = 4;
std::vector<std::vector<int>> board(BOARD_SIZE, std::vector<int>(BOARD_SIZE));


bool GAMEOVER = false;
void renderboard();
void randomseed();
void movetile();
bool GameOverCheck(int i, int j);

int main() {
    while (GAMEOVER == false) {
        randomseed(); 
        if (GAMEOVER == false) {
            renderboard();
            movetile();
        }   
        
        
                 
    }
}

void renderboard() {
    std::cout << "---------------------\n";   
    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << "|";
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                std::cout << "    |";
            } else {
                std::cout << std::setw(4) << board[i][j] << "|";
            }
            
        }
        std::cout << "\n";
        std::cout << "---------------------\n";

    }
}

void randomseed() {
    for (int count = 0; count < 2; count++) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (board[x][y] == 0) {
            board[x][y] = (rand() % 2 + 1) * 2;

        }  else {
            count--;
        }
    } 
    bool Boardisfull = true;
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 2048) {
                    std::cout << "YOU WIN";
                    GAMEOVER = true;
                }
            if (board[i][j] == 0) {
                Boardisfull = false;
                
                break;
            } 
        }
    }
    
    if (Boardisfull == true){
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] != 0) {
                    Boardisfull = GameOverCheck;
                    break;
            } 
        }
    }
            if (Boardisfull == true) {
                    std::cout << "GAME OVER";
                    GAMEOVER = true;
            }

        
    }

    
}

void movetile() {
    char direction;
    std::cout << "Enter w, a, s, d: ";
    std::cin >> direction;

    if (direction == 'a') {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 1; j < BOARD_SIZE; j++) {
                if (board[i][j] != 0) {
                    int boardValue = board[i][j];
                    int newPos = j;

                    for (int n = j - 1; n >= 0; n--) {
                        if (board[i][n] == 0) {
                            newPos = n;
                        } else if (board[i][n] == boardValue) {
                            boardValue *= 2;
                            newPos = n;
                            break;
                        } else {
                            break;
                        }
                    }

                    if (newPos != j) {
                        board[i][newPos] = boardValue;
                        board[i][j] = 0;
                    }
                }
            }
        }
    }

    if (direction == 'w') {
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int i = 1; i < BOARD_SIZE; i++) {
                if (board[i][j] != 0) {
                    int boardValue = board[i][j];
                    int newPos = i;

                    for (int n = i - 1; n >= 0; n--) {
                        if (board[n][j] == 0) {
                            newPos = n;
                        } else if (board[n][j] == boardValue) {
                            boardValue *= 2;
                            newPos = n;
                            break;
                        } else {
                            break;
                        }
                    }

                    if (newPos != i) {
                        board[newPos][j] = boardValue;
                        board[i][j] = 0;
                    }
                }
            }
        }
    }

    if (direction == 's') {
    for (int j = 0; j < BOARD_SIZE; j++) {
        for (int i = BOARD_SIZE - 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int boardValue = board[i][j];
                int newPos = i;

                for (int n = i + 1; n < BOARD_SIZE; n++) {
                    if (board[n][j] == 0) {
                        newPos = n;
                    } else if (board[n][j] == boardValue) {
                        boardValue *= 2;
                        newPos = n;
                        break;
                    } else {
                        break;
                    }
                }

                if (newPos != i) {
                    board[newPos][j] = boardValue;
                    board[i][j] = 0;
                }
            }
        }
    }
}
if (direction == 'd') {
    for (int j = 0; j < BOARD_SIZE; j++) {
        for (int i = BOARD_SIZE - 2; i >= 0; i--) {
            if (board[j][i] != 0) {
                int boardValue = board[j][i];
                int newPos = i;

                for (int n = i + 1; n < BOARD_SIZE; n++) {
                    if (board[j][n] == 0) {
                        newPos = n;
                    } else if (board[j][n] == boardValue) {
                        boardValue *= 2;
                        newPos = n;
                        break;
                    } else {
                        break;
                    }
                }

                if (newPos != i) {
                    board[j][newPos] = boardValue;
                    board[j][i] = 0;
                }
            }
        }
    }
}
}
bool GameOverCheck(int i, int j) {
    if ((i > 0 && board[i][j] == board[i-1][j]) || (i < BOARD_SIZE - 1 && board[i][j] == board[i+1][j]) ||              
        (j > 0 && board[i][j] == board[i][j-1]) ||                         
        (j < BOARD_SIZE - 1 && board[i][j] == board[i][j+1])) {              
        return false;  
    }
    
    return true; 
}