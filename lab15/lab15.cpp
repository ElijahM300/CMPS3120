//Elijah Morris
//Lab 15
//12-5-21

#include <iostream>
#include <cmath>
using namespace std;

void coinRow(int arr1[][11], int arr2[][26]);
void printTotals(int arr1[][11], int arr2[][26]);

int main() {
    int arr1[2][11] = {
        {0, 5, 10, 7, 12, 6, 5, 8, 9, 12, 14},
        {0, 5, 0, 0, 0, 0, 0, 0, 0, 0}   
    };
    int arr2[2][26] = {
        {0,15,12,3,7,6,5,9,19,2,21,12,5,9,6,14,20,1,3,7,12,14,7,3,21,15},
        {0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}   
    };

    cout << "Program to Demonstrate the Coin-Row Problem\n";
    cout << "============================================\n";
    cout << "Array #1: "; 
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 11; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
        cout << "          ";
    }
    cout << endl;

    cout << "Array #2: ";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 26; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
        cout << "          ";
    }
    cout << endl;
    coinRow(arr1, arr2);
    cout << endl;

    return 0;
}

void coinRow(int arr1[][11], int arr2[][26]) {
    int max1 = 0;
    int max2 = 0;
    int maxinstance = 0;
    int column1;
    int column2;
    maxinstance = arr1[1][1];
    for(int i = 0; i < 1; i++) {
        for(int j = 2; j < 11; j++) {
            max1 = max(arr1[i][j] + arr1[i][j - 2], arr1[i][j - 1]);
            arr1[i + 1][j] = max1;
            if(maxinstance < arr1[i + 1][j]) {
                maxinstance = arr1[i + 1][j];
                column1 = j - 2;
                column2 = j;
            }
        }
    }
    cout << "Max coins for Instance #1: " << maxinstance << endl;
    cout << "Columns picked to get max coins: " << column1 << " and " << column2 << endl;
    cout << endl;
    maxinstance = 0;

    for(int i = 0; i < 1; i++) {
        for(int j = 2; j < 26; j++) {
            max2 = max(arr2[i][j] + arr2[i][j - 2], arr2[i][j - 1]);
            arr2[i + 1][j] = max2;
            if(maxinstance < arr2[i + 1][j]) {
                maxinstance = arr2[i + 1][j];
                column1 = j - 2;
                column2 = j;
            }
        }
    }
    cout << "Max coins for Instance #2: " << maxinstance << endl;
    cout << "Columns picked to get max coins: " << column1 << " and " << column2 << endl;
    cout << endl;

    printTotals(arr1, arr2);
    cout << endl;
}

void printTotals(int arr1[][11], int arr2[][26]) {
    for(int i = 1; i < 2; i++) {
        cout << "Instance #1 Totals: ";
        for(int j = 0; j < 11; j++) {
            cout << arr1[i][j] << " ";
        }
    }
    cout << endl;
    for(int i = 1; i < 2; i++) {
        cout << "Instance #2 Totals: ";
        for(int j = 0; j < 26; j++) {
            cout << arr2[i][j] << " ";
        }
    }
    cout << endl;
}
