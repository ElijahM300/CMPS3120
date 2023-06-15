//Elijah Morris
//Lab 12
//11-28-21

#include <iostream>
using namespace std;

void minCoins(int coinValues[], int n, int amount);

int main() {
    int coinValues[] = {25, 10, 5, 1};
    int n = 4;
    int amount;

    cout << "Program to Demonstrate the Greedy Algorithm for Change-Making\n";
    cout << "==============================================================\n";
    cout << "Coin values: 25c, 10c, 5c, 1c\n";
    cout << "Enter an amount (in cents) to solve for: ";
    cin >> amount;
    cout << endl;
    cout << "Coins used to solve: ";
    minCoins(coinValues, n, amount);
    cout << "\n\n";

    return 0;
}

void minCoins(int coinValues[], int n, int amount) {
    for(int i = 0; i < n; i++) {
        while(amount >= coinValues[i]) {
            amount = amount - coinValues[i];
            printf("%ic ", coinValues[i]);
        }
    }
    
}
