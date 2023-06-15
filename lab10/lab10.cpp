//Elijah Morris
//CMPS 3120 Lab 10
//11-14-21

#include <iostream>
#include <string>

using namespace std;

void stringmatch(string text, string pattern, char table[], int tablenums[]);

int main() {
    string text;
    string pattern;
    char table[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int tablenums[26] = {};
    int patternsize;

    cout << "Program for string matching with space time tradeoff\n";
    cout << "=====================================================\n";
    cout << "ATTENTION: Use '_' for spaces!\n";
    cout << "Enter text to search: ";
    cin >> text;
    cout << "Enter pattern to search for: ";
    cin >> pattern;

    patternsize = pattern.size();
    int dist;
    cout << "\n";

    for(int i = 0; i < 26; i++) {
        dist = patternsize - 1;
        tablenums[i] = patternsize; 
        for(int j = 0; j < (int)pattern.size() - 1; j++) {
            if(pattern[j] == table[i]) {
                tablenums[i] = dist;
            }
            dist--;
        }
    }

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Table: ";
    for(int i = 0; i < 26; i++) {
        cout << table[i] << " ";
    }
    cout << "\n";
    cout << "       ";
    for(int i = 0; i < 26; i++) {
        cout << tablenums[i] << " ";
    }
    cout << "\n";
    stringmatch(text, pattern, table, tablenums);
    return 0;
}

void stringmatch(string text, string pattern, char table[], int tablenums[]) {
    int matches = 0;
    int comparisons = 0;
    int index[100];
    int s = 0;
    int increment = 0;
    int patternIndex = 0;
    int textIndex = 0;
    bool matching;
    while(increment < (int)text.length()) { 
        matching = true;
        int j = pattern.size() - 1;
        while(matching && j > 0) {
            if(pattern[patternIndex] == text[textIndex]) {
                matches++;
                comparisons++;
                index[s] = textIndex;
                s++;
                textIndex++;
                patternIndex++;
                j--;
            }
            else {
                matching = false;
                for(int k = 0; k < 26; k++) {
                    if(pattern[patternIndex] == table[k]) {
                        increment += tablenums[k]; 
                        comparisons++;
                    }
                }
                textIndex += increment;       
            }
        }
        
    }
    cout << "Comparisons: " << comparisons << endl;
    cout << "Matches: " << matches << endl;
    cout << "Matches found at index: ";
    for(int l = 0; l < s; l++) {
        cout << index[l] << " ";
    }
    cout << endl;
}










