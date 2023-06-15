//Elijah Morris
//Lab 13
//11-30-21

#include <iostream>
using namespace std;

int prim(char nodes[], int edges[], char connected[]);
int kruskal(char nodes[], int edges[], char connected[]);
int search(char connected[], char node);

int main() {
    char nodes[] = {'a','e','b','e','c','e','c','d','a','b','d','e','b','d','a','c'};
    int edges[] = {2, 3, 4, 4, 5, 5, 6, 7}; 
    char connected[5];
    int weight;
    cout << "Program for Finding the Minimum Spanning Tree Using Prim's and Kruskal's Algorithms\n";
    cout << "====================================================================================\n";
    cout << "Prim\n";
    cout << "-----\n";
    weight = prim(nodes, edges, connected);
    cout << "Total weight: " << weight << endl;
    cout << endl;
    cout << "Kruskal\n";
    cout << "--------\n";
    weight = kruskal(nodes, edges, connected);
    cout << "Total weight: " << weight << endl;
    return 0;
}

int prim(char nodes[], int edges[], char connected[]) {
    int n = 0;
    int weight = 0;
    int visited;
    for(int i = 0; i < 8; i++) {
        visited = 0;
        for(int j = 0; j < 2; j++) {
            visited = search(connected, nodes[n]);
            if(n%2 == 0) {
                connected[n] = nodes[n]; 
                if(visited == 1) {
                    cout << "Node already visited\n";
                } 
                else {
                    weight = weight + edges[i];
                }
            }
            n++;
        }
    }
    return weight;
}

int kruskal(char nodes[], int edges[], char connected[]) {
    int weight = 0;
    int n = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 2; j++) {
            if(n < 5) {
                connected[n] = nodes[n];
            }
            if(n%2 == 0) {
                if(nodes[n] == connected[0]) {
                    cout << "Avoiding edge\n";
                }
                else {
                    weight = weight + edges[i];
                }
            }   
            n++;
        }
    }
    return weight;
}

int search(char connected[], char node) {
    int visited = 0;
    for(int i = 0; i < 5; i++) {
        if(connected[i] == node) {
            visited = 1;
            return visited;
        }
    }
    return 0;
}
