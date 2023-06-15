//Elijah Morris
//Selection Sort Program
//10-7-21

#include <iostream>
using namespace std;

void selectionsort(char arr[], int n);

int main() {
    char arr[] = {'I', 'L', 'O', 'V', 'E', 'C', 'S', 'U', 'B'};
    int n = 9;
    cout << "Selection Sort Program\n";
    cout << "=======================\n";
    cout << "String to be sorted: ILOVECSUB\n";
    selectionsort(arr, n);
}

void selectionsort(char arr[], int n) {
    int min;
    char tmp;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min] )
                min = j;
        }
        for(int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
        tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;

    }
}
