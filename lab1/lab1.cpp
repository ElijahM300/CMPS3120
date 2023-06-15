//Elijah Morris
//CMPS 3120
//Lab 1
//8-26-21

#include <iostream>
using namespace std;
int lcm(int a, int b);

int main(){
    int a = 0;
    int b = 0;
    bool valid = true;
    cout << "Program for finding the least common multiple of two numbers\n\n";
    while(valid) {
        valid = false;
        cout << "Please enter a value for a: ";
        cin >> a;
        if(cin.fail()) {
            cout << "Please enter a valid number...\n\n";
            valid = true;
            cin.clear();
            cin.ignore();
        }
    }

    valid = true;
    while(valid) {
        valid = false;
        cout << "Please enter a value for b: ";
        cin >> b;
        if(cin.fail()) {
            cout << "Please enter a valid number...\n\n";
            valid = true;
            cin.clear();
            cin.ignore();
        }
    }
    cout << "\n";
    cout << "The least common multiple of " << a << " and " << b << " is: " << lcm(a, b) << endl;

    return 0;
}

int lcm(int a, int b){
    //multiply a and b for the lcm formula which is a*b/gcd(a, b)
    int ans = a * b;

    //First find the gcd of a and b
    while(b != 0){
        int c = a % b;
        a = b;
        b = c;
    }    
    //Divide the product of a and b by the gcd to solve for the lcm    
    ans = ans / a;
    return ans;
}

