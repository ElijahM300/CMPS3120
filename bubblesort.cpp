//Elijah Morris
//Bubble Sort Program
//10-7-21

#include <iostream>
using namespace std;

void bubblesort(char arr[], int n);

int main() {
    char arr[] = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int n = 7;
    cout << "Bubble Sort Program\n";
    cout << "=======================\n";
    cout << "String to be sorted: EXAMPLE\n";
    bubblesort(arr, n);
}

void bubblesort(char arr[], int n) {
    char tmp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[j] << " ";
        }
        for(int j = 0; j < n - 1 - i; j++) { 
            if(arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        cout << endl;
        for(int j = 0; j < n; j++) 
            cout << arr[j] << " ";
        cout << endl;
    }
}
