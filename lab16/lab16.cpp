//Elijah Morris
//Lab 16
//12-7-21

#include <iostream>
#include <cmath>

using namespace std;

void robot(int board[][10], int n, int m);

int main() {
    int board[][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,2,0,0,0,0,0,2,0},
        {0,0,0,3,0,0,0,0,0,0},
        {0,0,3,1,0,2,1,0,3,0},
        {0,2,1,2,0,3,0,0,0,0},
        {0,3,0,0,0,1,0,0,0,0},
        {0,0,2,0,0,0,2,0,0,0},
        {0,0,0,0,3,2,0,2,1,0},
        {0,0,0,0,0,0,3,3,0,0},
        {0,1,0,0,1,3,1,1,2,0}
    };
    int n = 9;
    int m = 9;

    cout << "Program for Demonstrating the Robot Coin-Collecting Problem\n";
    cout << "============================================================\n";
    cout << "Board: ";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
        cout << "       ";
    }
    cout << endl;
    robot(board, n, m);
    cout << endl;
    return 0;
}

void robot(int board[][10], int n, int m) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1) {
                if(j > 1) {
                    board[i][j] = board[i][j - 1] + board[i][j];
                }
            }
            else {
                if(j == 1) {
                    board[i][j] = board[i - 1][j] + board[i][j];
                }
                else {
                    board[i][j] = max(board[i - 1][j], board[i][j - 1]) + board[i][j];
                }
            }
            
        }
    }
    
    cout << "Collection paths: ";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
        cout << "                  ";
    }
    cout << endl;
    cout << "Total coins possible: " << board[n][m] << endl;
}






