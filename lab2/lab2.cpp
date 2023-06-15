//Elijah Morris
//Lab 2 
//9-2-2021

#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
long fib1(long n);
int fib2(long n);

long add_count1 = 0;
long add_count2 = 0;

int main() {
    long n = 0;
    cout << "Program for finding an nth fibonacci number\n";
    cout << "============================================\n";
    cout << "Please enter a fibonacci number to see: ";
    cin >> n;
    cout << "\n";
    cout << "Recursive function\n";
    cout << "===================\n";
    for(int i = 0; i < n; i++) {
        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);
        cout << fib1(i) << " ";
        auto end = chrono::high_resolution_clock::now();
        double total_time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        total_time *= 1e-9;
        cout << "Steps of addition used: " << add_count1 << endl;
        cout << "Time taken to calculate this number: " << fixed << total_time << setprecision(8) << "\n\n"; 
    }
    cout << "\n";
    cout << "Array function\n";
    cout << "===============\n";
    fib2(n);
    cout << "\n";
    return 0;
}

long fib1(long n) {
    if(n <= 1) {
        return n;
    }
    else {
        add_count1++;
        return fib1(n - 1) + fib1(n - 2);
    }

}

int fib2(long n) {
    double total_time = 0;
    long f[n];
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    cout << f[0] << " The time taken to calculate this number is 0.00000000\n\n";
    cout << f[1] << " The time taken to calculate this number is 0.00000000\n\n";
    cout << f[2] << " The time taken to calculate this number is 0.00000000\n\n";
    for(int i = 3; i < n; i++) {
        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);
        add_count2++;
        f[i] = f[i - 1] + f[i - 2];
        auto end = chrono::high_resolution_clock::now();
        double time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time *= 1e-9;
        total_time += time;
        cout << f[i] << " ";
        cout << "Steps of addition used: " << add_count2 << endl;
        cout << "Time taken to calculate this number: " << fixed << total_time << setprecision(8) << "\n\n";
    }

    return f[n];
}



