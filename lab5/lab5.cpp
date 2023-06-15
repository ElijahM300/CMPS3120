//Elijah Morris
//10-3-21
//Lab 5

#include <iostream>
#include <string>
using namespace std;

int stringmatch(string txt, string pat);

int main() {
    string txt;
    string pat;
    cout << "Program to demonstrate the String Match Brute-Force Algorithm\n";
    cout << "==============================================================\n"; 
    cout << "Enter text: ";
    cin >> txt;
    cout << "Enter a pattern: ";
    cin >> pat;
    int comp = stringmatch(txt, pat);  
    if(comp == 0)
      cout << "No match was found.\n";  
    cout << "Total # of comparisons: " << comp << endl;
    cout << "\n";
    return 0;
}

int stringmatch(string txt, string pat) {
    int n = txt.size();
    int m = pat.size();
    int count = 0;
    for(int i = 0; i < n - m; i++) {
        int j = 0;
        while(j < m && pat[j] == txt[i + j]) {
            j = j + 1;
            count++;
        }
        if(j == m) {
            cout << "Match found at index: " << i << endl;
        }
        else if(i == (n - m) - 1)
            return count;
    }
    return -1;
}
