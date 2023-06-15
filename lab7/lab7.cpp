//Elijah Morris
//10-16-21
//Lab 7

#include <iostream>
#include <algorithm>
using namespace std;

int treeHeight(int tree[][3], int rows);

int main() {
    char input;
    int height;
    int tree1[][3] = {
        {1,2,0},
        {2,3,0},
        {3,0,4},
        {4,5,0},
        {5,0,0}
    };
    int tree2[][3] = {
        {1,2,3},
        {2,4,5},
        {4,0,6},
        {6,0,7},
        {7,8,9},
        {8,0,10},
        {10,0,11},
        {11,12,0},
        {12,13,0},
        {14,0,0},
        {9,15,16},
        {15,0,0},
        {16,0,0},
        {5,17,18},
        {17,19,0},
        {19,0,20},
        {20,0,0},
        {18,0,0},
        {3,0,0}

    };
    int tree3[][3] = {
        {1,2,3},
        {2,0,4},
        {4,5,6},
        {5,7,8},
        {7,9,10},
        {9,11,0},
        {11,0,0},
        {10,0,11},
        {10,12,0},
        {12,13,0},
        {13,0,14},
        {14,0,15},
        {15,0,16},
        {16,0,0},
        {8,17,0},
        {17,18,0},
        {18,0,0},
        {6,0,0},
        {3,0,19},
        {20,0,21},
        {21,22,23},
        {22,0,24},
        {24,25,26},
        {25,0,27},
        {27,0,0},
        {26,0,0},
        {23,0,0}
    };
    int rows;
    
    do{
        cout << "Program for Finding the Height of a Binary Tree\n";
        cout << "================================================\n";
        cout << "a. Tree1\n";
        cout << "b. Tree2\n";
        cout << "c. Tree3\n";
        cout << "d. Tree4\n";
        cout << "e. Tree5\n";
        cout << "q. Quit Program\n";
        cout << "================================================\n";
        cout << "Enter an option: ";
        cin >> input;
        switch(input) {
            case 'a':
                cout << "\nTree:\n";
                for(int i = 0; i < 5; i++) {
                    for(int j = 0; j < 3; j++) {
                        cout << tree1[i][j] << " ";
                    }
                    cout << endl;
                }
                rows = sizeof(tree1)/sizeof(tree1[0]);
                height = treeHeight(tree1, rows) - 1;
                if(height == 0) {
                    cout << "Tree has no height, there is no root node.\n";
                }
                else {
                    cout << "The height of this tree is: " << height << endl;
                }
                cout << "\n";
                break;
            case 'b':
                cout << "\nTree:\n";
                for(int i = 0; i < 18; i++) {
                    for(int j = 0; j < 3; j++) {
                        cout << tree2[i][j] << " ";
                    }
                    cout << endl;
                } 
                rows = sizeof(tree2)/sizeof(tree2[0]);
                height = treeHeight(tree2, rows) - 1;
                if(height == 0) {
                    cout << "Tree has no height, there is no root node.\n";
                }
                else {
                    cout << "The height of this tree is: " << height << endl;
                }
                cout << "\n";
                break;
            case 'c':
                cout << "\nTree:\n";
                for(int i = 0; i < 26; i++) {
                    for(int j = 0; j < 3; j++) {
                        cout << tree3[i][j] << " ";
                    }
                    cout << endl;
                } 
                rows = sizeof(tree3)/sizeof(tree3[0]);
                height = treeHeight(tree3, rows) - 1;
                if(height == 0) {
                    cout << "Tree has no height, there is no root node.\n";
                }
                else {
                    cout << "The height of this tree is: " << height << endl;
                }
                cout << "\n";
        } 
    } while(input != 'q'); 
    cout << "\n";
    return 0;
}

int treeHeight(int tree[][3], int rows) {
    static int i = 0;
    int leftSide = 0;
    int rightSide = 0;

    if(tree[0][1] != 0 && tree[0][2] != 0) {
        while(tree[i][0] != tree[0][2]) {
            i++;
            leftSide = leftSide + treeHeight(tree, rows);
        }
        while(i < rows) {
            cout << i << " ";
            i++;
            rightSide = rightSide + treeHeight(tree, rows);
        }
    }
    else {
        while(i < rows) {
            i++;
            leftSide = leftSide + treeHeight(tree, rows);
        }
    }
   
    cout << endl;
    //cout << leftSide << " " << rightSide << endl;
    return max(leftSide, rightSide) + 1;
}







