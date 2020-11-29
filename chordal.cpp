#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int MAX = 100;

// Graph
int graph[MAX][MAX];

bool isComplete(int n_vertex, int size, int edges[][2]) {
    //building graph
    for (int i = 0; i < size; i++){
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }

    //printing graph
    for (int i = 0; i < n_vertex; i++){ 
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

                    // cout << "No" << endl;
                    return false;
                }
            }
        }
    }

    // cout << "Sim" << endl;
    return true;
}

bool isSimplicial(int v, int n_vertex) {
    std::vector<int> neighbors;

    //ver os adjacentes de v no graph
    for (int i = 0; i < n_vertex; i++) { 
        for (int j = 0; j < n_vertex; j++) {
            if(i == v && graph[i][j] == 1) {
                // cout << "vizinhos do v " << j<< endl;
                neighbors.push_back(j);
            }
        }
    }

    // cout << neighbors.size() << endl;
    for (int i = 0; i < neighbors.size(); i++) { 
        for (int j = 0; j < neighbors.size(); j++) { 
            // cout << i << " " << j << " " << graph[neighbors[i]][neighbors[j]] << endl;
            if(i != j && graph[neighbors[i]][neighbors[j]] != 1) {
                return false;
            }
        }
    }

    return true;
}

bool isChordal(int n_vertices, int size, int edges[][2]) {
    std::vector<int> simplicial_list;

    //G is k ? check if all v is simplicial : check if there is a pair simplicial not adjacent
    if(isComplete(n_vertices, size, edges)) {
        //list all simplicial vertices
        for (int i = 1; i < n_vertices; i++) {
            if(isSimplicial(i, n_vertices)) {
                cout << i << " eh simplicial" << endl;
                simplicial_list.push_back(i);
            }
        }

        //check if all v is simplicial
        if(simplicial_list.size() != n_vertices-1) {
            cout << "No Chordal" << endl;
        } else {
            cout << "Chordal" << endl;
        }
    } else {
        cout << "not complete " << endl;

        //list all simplicial vertices
        for (int i = 1; i < n_vertices; i++) {
            if(isSimplicial(i, n_vertices)) {
                cout << i << " eh simplicial" << endl;
                simplicial_list.push_back(i);
            }
        }
        
        //check if there is a pair simplicial not adjacent
        //simplicial_list tem q ter pelo menos 2 elementos
        if(simplicial_list.size() > 1){
            for (int i = 0; i < simplicial_list.size(); i++) {
                for (int j = 0; j < simplicial_list.size(); j++) {
                    if(i != j && graph[simplicial_list[i]][simplicial_list[j]] == 0) {
                        cout << simplicial_list[i] << " e " << simplicial_list[j] << " Sao simpliciais n adj" << endl;
                        cout << "Chordal" << endl;
                        return true;
                    }
                }
                cout << "Not Chordal" << endl;
            }
        } else {
            cout << "Not Chordal" << endl;
        }
    }

    return true;
}

int main() {
    //complete-chordal-graph example
    //int e1[][2] = {{1, 2},{2, 3},{3, 1}};
    //not-complete-chordal-graph example
    //int e1[][2] = {{1, 2},{2, 3},{3, 1},{1,4},{4,3}};
    //not-complete-not-chordal-graph example
    int e1[][2] = {{1, 2},{2, 3},{1,4},{4,3}};
    //another not-complete-not-chordal-graph with c4 example 
    //int e1[][2] = {{1, 2},{2, 3},{2,4},{3,4},{4,6},{5,6},{5,3}};
    //another not-complete-chordal-graph example
    //int e1[][2] = {{1, 2},{2, 3},{2,4},{3,4},{4,6},{5,6},{5,3},{6,3}};
    int n_vertex_e1 = 4; //lembrar de mudar sempre isso aqui qndo for trocar o grafo
                      
    int size_e1 = sizeof(e1) / sizeof(e1[0]);

    isChordal(n_vertex_e1 + 1, size_e1, e1);
    // cout << "E1 is chrodal? " << endl;
    // bool condition_e1 = isComplete(n_vertex_e1 + 1, size_e1, e1);

    return 0;
}