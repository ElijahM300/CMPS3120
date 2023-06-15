//Elijah Morris
//9-17-21
//Lab 3

#include <iostream>
using namespace std;

int main() {
    int n;
    int j, key;
    int counter = 0;

    cout << "Insertion Sort Program\n";
    cout << "=======================\n";
    cout << "How many numbers to sort?: ";
    cin >> n;

    int arr[n];
    cout << "\nEnter numbers to sort: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }    
    
    cout << "\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    //Insertion sort algorithm
    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            counter++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        for(int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    cout << "Number of comparisons: " << counter << endl;
    cout << "\n";

    return 0;
}
