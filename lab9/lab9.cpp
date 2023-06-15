//Elijah Morris
//Lab 9
//11-7-21

#include <iostream>
using namespace std;
void heapbottomup(int arr[], int n);
void insert(int h[], int arr[], int input, int n);
void heapsort(int h[], int n);

int main() {
    int arr[] = {1, 5, 4, 3, 10, 2, 6, 7, 9, 8, 11};
    int n = 11;
    int h[n + 1];
    int input;
    cout << "Program to construct a heap\n";
    cout << "============================\n";
    cout << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    cout << "Heap: ";
    heapbottomup(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    cout << "Enter a number to insert into the heap: ";
    cin >> input;
    cout << "\n";
    insert(h, arr, input, n);
    cout << "Heap with inserted value: ";
    for(int i = 0; i < n; i++)
        cout << h[i] << " ";
    cout << "\n\n";
    cout << "Sorted heap: ";
    heapsort(h, n);
    for(int i = 0; i < n; i++)
        cout << h[i] << " ";
    cout << "\n\n";
    return 0;
}

void heapbottomup(int arr[], int n) {
    int k;
    int v;
    int j;
    bool heap;
    for(int i = n/2 ; i > 0; i--) {
        k = i - 1;
        v = arr[k];
        heap = false;
        while(!heap && 2*k <= n) {
            j = (2*k+1);
            if(j < n) {
                if(arr[j] < arr[j + 1])
                    j = j + 1;
            }
            if(v >= arr[j]) {
                heap = true;
            }
            else {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }
}

void insert(int h[], int arr[], int input, int n) {
    for(int i = 0; i < n; i++) 
        h[i] = arr[i];
    h[11] = input;
    n += 1;
    heapbottomup(h, n); 
}

void heapsort(int h[], int n) {
    int tmp;
    for(int i = 0; i < n; i++) {
        tmp = h[i];
        h[i] = h[n - 1];
        h[n - 1] = tmp; 
        n -= 1;
        heapbottomup(h, n);
    }
}


