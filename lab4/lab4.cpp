//Elijah Morris
//CMPS 3120
//Lab 4

#include <iostream>
#include <string>
using namespace std;

int hanoiMoves(int n, int rod1, int rodB, int rodC);

int main() {
    int n;
    int count;
    int rod1 = 1;
    int rod2 = 2;
    int rod3 = 3;
    cout << "Program for counting the number of moves for the Tower of Hanoi\n";
    cout << "================================================================\n";
    cout << "Enter the number of disks to move: ";
    cin >> n;
    cout << "\n";
    count = hanoiMoves(n, rod1, rod2, rod3);
    cout << "\n";
    cout << "The nubmber of moves it took to solve the puzzle was: " << count << endl;
    cout << "\n"; 
    return 0;
}

int hanoiMoves(int n, int rod1, int rod2, int rod3) {
    int count = 1;
    if(n == 0) {
        return 0;
    }  
    count += hanoiMoves(n - 1, rod1, rod3, rod2);
    cout << "Move disk " << n << " from rod " << rod1 << " to rod " << rod3 << endl;
    count += hanoiMoves(n - 1, rod2, rod1, rod3);
    return count;
}
