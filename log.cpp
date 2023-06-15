//Elijah Morris
//Program to calculate log base 2
//10-26-21

#include <iostream>
#include <math.h>
using namespace std;

double dbh(double n);
double ans = 0;

int main() {
    double n;
    cout << "Program for finding log base 2 for any number\n";
    cout << "==============================================\n";
    cout << "Enter a number to solve for: ";
    cin >> n;
    cout << "\n";
    cout << "Solution: " << dbh(n) << endl;
    return 0;
}

double dbh(double n) {
    if(n <= 1) {
        return 0;
    }
    else {
        ans = dbh(log2(n/2)) + 1;
    }
    return ans;
}
