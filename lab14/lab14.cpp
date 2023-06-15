//Elijah Morris
//Lab 14
//12-5-21

#include <iostream>
#include <cmath>
using namespace std;

void minCoins(int coinValues[], int total[], int n, int amount);
void totalCoins(int total[], int coinValues[], int amount);

int main() {
    int coinValues[] = {11, 5, 1};
    int n = 3;
    int amount;

    cout << "Program to Demonstrate Dynamic Programming for Change-Making\n";
    cout << "==============================================================\n";
    cout << "Coin values: 11c, 5c, 1c\n";
    cout << "Enter an amount (in cents) to solve for: ";
    cin >> amount;
    cout << endl;
    int total[amount];
    total[0] = 0;
    cout << "Coins used to solve: ";
    minCoins(coinValues, total, n, amount);
    cout << "\n\n";

    return 0;
}

void minCoins(int coinValues[], int total[], int n, int amount) {
    int min1;
    int min2;
    int orgamount = amount;
    for(int i = amount; i > 0; i--) {
        min1 = min((i - 1), abs(i - 5));
        min2 = min(min1, abs(i - 11)) + 1;
        total[i - 1] = min2;
    }
    cout << "\n";
    for(int i = 0; i < n; i++) {
        while(amount >= coinValues[i]) {
            amount = amount - coinValues[i];
            printf("%ic ", coinValues[i]);     
        }  
    }
    cout << "\n\n";
    cout << "Table: ";
    for(int i = 0; i < orgamount; i++) {
        cout << total[i] << " ";
        if(i > 0 && i % 30 == 0) {
            cout << endl;
        }
    }
}





