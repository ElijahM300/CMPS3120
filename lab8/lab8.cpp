//Elijah Morris
//Lab 8
//10-24-21

#include <iostream>
using namespace std;

int dfsTopSort(int v, bool visited[], int topnum[], int graph[][2], int n);

int main() {
    int graph[][2] = {
        {1, 9},
        {2, 3},
        {3, 4},
        {4, 6},
        {5, 6},
        {6, 8},
        {7, 2},
        {7, 8},
        {7, 9},
        {8, 11},
        {11, 10} 
    };
    //Array for keeping track of which nodes have been visited
    bool visited[11] = {0};
    //Array for storing the topological numbers for the nodes
    int topnum[11];
    int n = 10;
    cout << "Program for demonstrating Topological Sort using DFS\n";
    cout << "=====================================================\n";
    cout << "Graph:\n";
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 2; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < 11; i++) {
        if(visited[i] != 1) {
            n = dfsTopSort(i, visited, topnum, graph, n);
        }
    }
    cout << "Topological Sort: ";
    for(int i = 0; i < 11; i++) {
        cout << topnum[i] << " ";
    }
    cout << "\n\n";
    return 0;
}

//Topological Sort method using DFS
int dfsTopSort(int v, bool visited[], int topnum[], int graph[][2], int n) {
    visited[v] = 1;
    cout << "Visiting order: ";
    for(int i = 0; i < 11; i++) {
        cout << visited[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 11; i++) {
        if(visited[graph[i][1]] != 1) {
            n = dfsTopSort(graph[i][1], visited, topnum, graph, n);
        }
    }
    topnum[n] = v;
    return n - 1;   
}
