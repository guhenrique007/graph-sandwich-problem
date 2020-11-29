#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Graph
int graph[MAX][MAX];

bool belongsToClique(int n_vertex, int size, int edges[][2]){
    //building graph
    for (int i = 0; i < size; i++){
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }

    //printing graph
    for (int i = 0; i < n_vertex; i++){ 
        cout << i << " ";
        for (int j = 0; j < n_vertex; j++){
            cout << graph[i][j] << " ";
        } 
        cout << endl;
    }

    //check if all vertex are connected
    for (int i = 0; i < n_vertex; i++){ 
        for (int j = 0; j < n_vertex; j++){
            if(i != 0 && j != 0 && i != j){
                if(graph[i][j] != 1){

                    cout << "No" << endl;
                    return false;
                }
            }
        }
    }

    cout << "Sim" << endl;
    return true;
}

int main() {
    // int edges[][2] = {{1,2},
    //                   {1,5},
    //                   {2,3},
    //                   {2,4},
    //                   {3, 1},
    //                   {4, 3},
    //                   {4, 5},
    //                   {5, 3}};

    int e1[][2] = {{1, 2},{2, 3},{3, 1}};

    int e3[][2] = {{2,4}};

    int n_vertex_e3 = 5;
    int n_vertex_e1 = 3;
                      
    int size_e3 = sizeof(e3) / sizeof(e3[0]); 
    int size_e1 = sizeof(e1) / sizeof(e1[0]);


    cout << "[x,y] of E3 in K? " << endl;
    bool condition_e3 = belongsToClique(n_vertex_e3 + 1, size_e3, e3);

    cout << "[x,y] of E1 in K? " << endl;
    bool condition_e1 = belongsToClique(n_vertex_e1 + 1, size_e1, e1);

    if(!condition_e3 && condition_e1) {
        cout << "Passou" << endl;
    } else {
        cout << "Algoritmo Falhou" << endl;
    }

    return 0;
}