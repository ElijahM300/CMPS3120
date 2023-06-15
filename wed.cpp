//Elijah Morris
//9-8-2021


#include <iostream>
using namespace std;

int power1(int b, int n);

int main() {
    int b = 5;
    int n = 5;
    power1(b, n);
    power2(b, n);

    return 0;
}

int power1(int b, int n) {
    int pow = 1;
    int count;
    for(int i = 0; i < n; i++) {
        pow = pow * b;
        count++;
    }
    cout << "Multiplication was done " << count << " times.\n";
    return pow;
}

int power2(int b, int n) {
    if(n == 0) {
        return 1;
    }

}
