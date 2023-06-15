//Elijah Morris
//Lab 11
//11-24-21

#include <iostream>
using namespace std;

void printTable(int arr[], int size);
int hashFunc(int value);
void linearInsert(int value, int arr[]);
void chainInsert(int value, int arr[]);
int linearProbeSearch(int value, int arr[], int size);
int chainSearch(int value, int arr[], int size);

int main() {
    int linear[21] = {0};
    int chain[210] = {0};
    int values1[] = {7, 22, 44, 27, 38, 53, 40};
    int values2[] = {7, 22, 44, 43, 27, 89, 30, 64, 85};
    char input;
    int comparisons;
    cout << "Program for demonstrating hash tables using linear probing and chained hashing\n";
    cout << "===============================================================================\n";
    cout << "Enter an 'l' to see a linear hash table or 'c' for chained hashing: ";
    cin >> input;
    cout << endl;
    if(input == 'l') { 
        cout << "Table before inserting values: ";
        printTable(linear, 21);
        cout << "First value set being inserted: "; 
        for(int i = 0; i < 7; i++) {
            cout << values1[i] << " ";
            linearInsert(values1[i], linear);
        }
        cout << "\n\n";
        cout << "Table after inserting values: ";
        printTable(linear, 21);

        cout << "Second value set being inserted: ";
        for(int i = 0; i < 9; i++) {
            cout << values2[i] << " ";
            linearInsert(values2[i], linear);
        }
        cout << "\n\n";
        cout << "Table after inserting values: ";
        printTable(linear, 21);

        cout << "Now searching the table for values 27, 40, 85...\n\n";
        comparisons = linearProbeSearch(27, linear, 21);
        cout << "Number of comparisons: " << comparisons << endl;
        cout << endl;
        comparisons = linearProbeSearch(40, linear, 21);
        cout << "Number of comparisons: " << comparisons << endl;
        cout << endl;
        comparisons = linearProbeSearch(85, linear, 21);
        cout << "Number of comparisons: " << comparisons << endl;
        cout << endl;
    }
    else if(input == 'c') {
        cout << "Table before inserting values: ";
        printTable(chain, 210);
        cout << "First value set being inserted: "; 
        for(int i = 0; i < 7; i++) {
            cout << values1[i] << " ";
            chainInsert(values1[i], chain);
        }
        cout << "\n\n";
        cout << "Table after inserting values: ";
        printTable(chain, 210);

        cout << "Second value set being inserted: ";
        for(int i = 0; i < 9; i++) {
            cout << values2[i] << " ";
            chainInsert(values2[i], chain);
        }
        cout << "\n\n";
        cout << "Table after inserting values: ";
        printTable(chain, 210);

        cout << "Now searching the table for values 27, 40, 85...\n\n";
        comparisons = chainSearch(27, chain, 210);
        cout << "Number of comparisons: " << comparisons << endl;
        cout << endl;
        comparisons = chainSearch(40, chain, 210);
        cout << "Number of comparisons: " << comparisons << endl;
        cout << endl;
        comparisons = chainSearch(85, chain, 210);
        cout << "Number of comparisons: " << comparisons << endl;
        cout << endl;
    }

    return 0;
}

void printTable(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

int hashFunc(int value) {
    return (value % 21);
}

void linearInsert(int value, int arr[]) {
    int hash = hashFunc(value);
    if(arr[hash] == 0) {
        arr[hash] = value;
    }
    else {
        //linear probing
        int j = hash + 1;
        for(int i = 0; i < 21; i++) {
            if(arr[j] == 0) {
                arr[j] = value;
                break;
            }
            j = (j + 1) % 21;
        }
    }
}

void chainInsert(int value, int arr[]) {
    int hash = hashFunc(value);
    if(arr[hash] == 0) {
        arr[hash] = value;
    }
    else {
        //chain hashing
        int j = hash + 21;
        for(int i = 0; i < 210; i++) {
            if(arr[j] != 0) {
                j += 21;
            }
            else {
                break;
            } 
        }
        if(arr[j] == 0) {
            arr[j] = value;    
        }
    }
}
int linearProbeSearch(int value, int arr[], int size) {
    int hash = hashFunc(value);
    int j = hash;
    int comp = 0;
    for(int i = 0; i < size; i++) {
        if(arr[j] == value) {
            comp++;
            cout << value << " was found.\n";
            return comp;
        }
        else if(arr[j] != value && arr[j] != 0) {
            comp++;    
        }
        else if(arr[j] == 0) {
            comp++;
            cout << value << " was not found.\n";
            return comp;
        }
        j = (j + 1) % 21;
    }
    return comp;
}

int chainSearch(int value, int arr[], int size) {
    int hash = hashFunc(value);
    int j = hash;
    int comp = 0;
    if(arr[j] != value) { 
        comp++;
        j += 21;
        for(int i = 0; i < size; i++) {
            if(arr[j] != value) {
                comp++;
                j += 21;
            }
            else {
                break;
            }
        }
        if(arr[j] == value) {
            comp++;
            cout << value << " was found.\n";
            return comp;
        }
        else if(arr[j] == 0) {
            comp++;
            cout << value << " was not found.\n";
            return comp;
        }
    }
    else if(arr[j] == value) {
        comp++;
        cout << value << " was found.\n";
        return comp;
    }
    return comp;
}







