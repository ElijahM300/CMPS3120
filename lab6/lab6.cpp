//Elijah Morris
//10-10-21
//Lab 6

#include <iostream>
using namespace std;

int count = 0;
void DFS(int graph[][2], int visited[], int startpoint, int nodes[]);
void dfs(int input, int graph[][2], int visited[], int nodes[]);

int main() {
    int graph[][2] = {
        {1,2},
        {1,3},
        {1,4},
        {1,5},
        {1,6}, 
        {1,7}, 
        {1,8}, 
        {1,9}, 
        {1,11}, 
        {1,12}, 
        {1,13},
        {1,14}, 
        {1,18}, 
        {1,20}, 
        {1,22}, 
        {1,32}, 
        {2,1},
        {2,3},
        {2,4},
        {2,8},
        {2,14},
        {2,18},
        {2,20},
        {2,22},
        {2,31},
        {3,1},
        {3,2},
        {3,4},
        {3,8},
        {3,9},
        {3,10},
        {3,14},
        {3,28},
        {3,29},
        {3,33},
        {4,1}, 
        {4,2}, 
        {4,3}, 
        {4,8}, 
        {4,13}, 
        {4,14}, 
        {5,1}, 
        {5,7}, 
        {5,11}, 
        {6,1}, 
        {6,7}, 
        {6,11}, 
        {6,17}, 
        {7,1}, 
        {7,5}, 
        {7,6}, 
        {7,17}, 
        {8,1}, 
        {8,2}, 
        {8,3}, 
        {8,4}, 
        {9,1}, 
        {9,3}, 
        {9,31}, 
        {9,33}, 
        {9,34},
        {10,3}, 
        {11,1}, 
        {11,5}, 
        {11,6},
        {12,1},
        {13,1},
        {13,4}, 
        {14,1}, 
        {14,2}, 
        {14,3}, 
        {14,4}, 
        {14,34}, 
        {15,33}, 
        {15,34}, 
        {16,33}, 
        {16,34}, 
        {17,6}, 
        {17,7}, 
        {18,1}, 
        {18,2}, 
        {19,33}, 
        {19,34}, 
        {20,1}, 
        {20,2}, 
        {20,34}, 
        {21,33}, 
        {21,34}, 
        {22,1}, 
        {22,2}, 
        {23,33}, 
        {23,34}, 
        {24,26}, 
        {24,28}, 
        {24,30}, 
        {24,33}, 
        {24,34}, 
        {25,26}, 
        {25,28}, 
        {26,24}, 
        {26,25}, 
        {26,32}, 
        {27,30}, 
        {27,34}, 
        {28,3}, 
        {28,24}, 
        {28,25}, 
        {28,34}, 
        {29,3}, 
        {29,32}, 
        {29,34}, 
        {30,24}, 
        {30,27}, 
        {30,33}, 
        {30,34}, 
        {31,2}, 
        {31,9}, 
        {31,33}, 
        {31,34}, 
        {32,1}, 
        {32,25}, 
        {32,26}, 
        {32,29}, 
        {32,33}, 
        {32,34}, 
        {33,3}, 
        {33,9}, 
        {33,15}, 
        {33,19}, 
        {33,21}, 
        {33,23}, 
        {33,24}, 
        {33,34}, 
        {33,30}, 
        {33,31}, 
        {33,32}, 
        {33,34}, 
        {34,9}, 
        {34,14}, 
        {34,15}, 
        {34,16}, 
        {34,19}, 
        {34,20}, 
        {34,21}, 
        {34,23}, 
        {34,24}, 
        {34,27}, 
        {34,28}, 
        {34,29}, 
        {34,30}, 
        {34,31}, 
        {34,32}, 
        {34,33} 
    };
    int visited[34] = {0};
    int nodes[34] = {0};
    int startpoint;
    cout << "Program Demonstrating DFS\n";
    cout << "==========================\n";
    cout << "Please enter a node to start from, 1-34: ";
    cin >> startpoint;
    cout << endl;
    cout << "Visiting order: ";
    DFS(graph, visited, startpoint, nodes);
    cout << endl;
    return 0;
}

void DFS(int graph[][2], int visited[34], int startpoint, int nodes[]) {
    visited[startpoint] = 1;
    nodes[0] = startpoint;
    for(int i = 0; i < 34; i++) {
        cout << nodes[i] << " ";
        if(visited[i] == 0) {
            dfs(startpoint, graph, visited, nodes);
        }
    }
}

void dfs(int input, int graph[][2], int visited[], int nodes[]) {
    int next;
    for(int i = 0; i < 34; i++) {
        if((graph[i][0] != 0) && (visited[graph[i][0]] != 1)) {
            visited[graph[i][0]] = 1;
            nodes[i] = graph[i][0];
            next = graph[i][1];
            dfs(next, graph, visited, nodes);
        }
        else if((graph[i][1] != 0) && (visited[graph[i][1]] != 1)) {
            visited[graph[i][1]] = 1;
            nodes[i] = graph[i][1];
            next = graph[i][1];
            dfs(next, graph, visited, nodes);
        }
        else if(graph[i][0] == 0 && graph[i][1] == 0) {

        }
    }
}

