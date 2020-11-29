#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

// Graph
int graph[MAX][MAX];

bool isComplete(int n_vertex, int size, vector<vector<int>> edges) {
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

bool isChordal(int n_vertices, int size, vector<vector<int>> edges) {
    std::vector<int> simplicial_list;

    //G is k ? check if all v is simplicial : check if there is a pair simplicial not adjacent
    if(isComplete(n_vertices, size, edges)) {
        //list all simplicial vertices
        for (int i = 1; i < n_vertices; i++) {
            if(isSimplicial(i, n_vertices)) {
                // cout << i << " eh simplicial" << endl;
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
        //list all simplicial vertices
        for (int i = 1; i < n_vertices; i++) {
            if(isSimplicial(i, n_vertices)) {
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
                return false;
            }
        } else {
            cout << "Not Chordal" << endl;
            return false;
        }
    }

    return true;
}

bool checkElementExists(vector<int> v, int element){
    for (int i = 0; i < v.size(); i++){
        if(v[i] == element){
            return true;
        }
    }
    return false;
}

int calcDiffNumVertices(vector<vector<int>> e1, vector<vector<int>> e2) {
    vector<int> common_vertices;
    common_vertices.push_back(0);
    
    for (int i = 0; i < e1.size(); i++){
        if(!checkElementExists(common_vertices, e1[i][0])) {
            common_vertices.push_back(e1[i][0]);   
        }  
        if(!checkElementExists(common_vertices, e1[i][1])) {
            common_vertices.push_back(e1[i][1]);  
        }
    }

    for (int i = 0; i < e2.size(); i++){
        if(!checkElementExists(common_vertices, e2[i][0])) {
            common_vertices.push_back(e2[i][0]);   
        }  
        if(!checkElementExists(common_vertices, e2[i][1])) {
            common_vertices.push_back(e2[i][1]);  
        }
    }

    return common_vertices.size();
}

vector<vector<int>> mergeGraphs(vector<vector<int>> e1, vector<vector<int>> e2) {
    vector<vector<int>> e;
    e.insert( e.end(), e1.begin(), e1.end() );
    e.insert( e.end(), e2.begin(), e2.end() );

    // for (int i = 0; i < e2.size(); i++) {
    //     cout << e2[i][0] << "," << e2[i][1] << " ";
    // }

    cout << "sanduiche" <<endl;
    for (int i = 0; i < e.size(); i++){
       cout << e[i][0] << "," << e[i][1] << endl;
    }
    cout << endl;

    return e;
}

void subsetsUtil(vector<vector<int> >& A, vector<vector<vector<int> >>& res, vector<vector<int> >& subset, int index) { 
    res.push_back(subset); 
    for (int i = index; i < A.size(); i++) { 
        for (int j = index; j < A.size(); j++) { 
            // include the A[i] in subset. 
            subset.push_back({A[i][0], A[i][1]}); 

            // move onto the next element. 
            subsetsUtil(A, res, subset, i + 1); 
    
            // exclude the A[i] from subset and triggers 
            // backtracking. 
            subset.pop_back(); 
        }
    } 
  
    return; 
} 
 
vector<vector<vector<int> >> subsets(vector<vector<int> >& A) { 
    vector<vector<int> > subset; 
    vector<vector<vector<int> >> res; 
  
    // keeps track of current element in vector A; 
    int i = 0; 
    int j = 0;
    subsetsUtil(A, res, subset, i); 
  
    return res; 
} 

bool existsEdge(vector<int> edge, vector<vector<int> > edges) {
    for (int i = 0; i < edge.size(); i++) { 
        for (int j = 0; j < edges.size(); j++) { 
            if((edges[j][0] == edge[0] && edges[j][1] == edge[1]) || (edges[j][1] == edge[0] && edges[j][0] == edge[1])){
                return true;
            }
        }
    }

    return false;
}

vector<vector<int> > arrumarArray(vector<vector<int> > v){
    vector<vector<int> > aux;

    for (int i = 0; i < v.size(); i++) {
        if(!existsEdge({v[i][0], v[i][1]}, aux)){
            aux.push_back({v[i][0], v[i][1]});
        }
    }

    return aux;
}

bool findSandwich(vector<vector<int>> e1, vector<vector<int>> e0) {
    //1 - get a e0 subset
    //2 - merge subset de e0 + e1
    //3 - isChordal?

    vector<vector<vector<int> >> res = subsets(e0); 
    vector<vector<int> > current_e0;

    // Print result 
    for (int i = 0; i < res.size(); i++) { 
        for (int j = 0; j < res[i].size(); j++) {
            vector<vector<int> > aux;
            for (int k = 0; k < res[i].size(); k++) { 
                if(k%2==0){
                    aux.push_back({res[i][j][0], res[i][j][1]});
                    //cout << res[i][j][0] << "," << res[i][j][1] << " ";
                }
            }

            //isso aqui só serve pra resolver um problema de duplicação da linha
            vector<vector<int> > arrayLimpo = arrumarArray(aux);

            for (int i = 0; i < arrayLimpo.size(); i++) {
                //cout << arrayLimpo[i][0] << "," << arrayLimpo[i][1] << " size:" << arrayLimpo.size();
                current_e0.push_back({arrayLimpo[i][0], arrayLimpo[i][1]});
            }
        }

        //2 - merge subset of e0 + e1
        vector<vector<int>> e = mergeGraphs(e1, current_e0);

        //3 - isChordal?
        int n_vertices = calcDiffNumVertices(e1, current_e0);

        if(isChordal(n_vertices, e.size(), e)){
            cout << "Graph" << endl;
            for (int i = 0; i < e.size(); i++) {
                cout << e[i][0] << "," << e[i][1] << " ";
            }
            cout << "Is SP-Chordal" << endl;
            return true;
        }


        cout << endl;

        current_e0 = {};
    } 

    cout << "No SP-Chordal" << endl;
    return false;
}

int main() {
    /*inputs sp chordal:*/
    //vector<vector<int>> e1 = {{1, 2},{2, 3},{2,4},{3,4},{4,6},{5,6},{5,3},{6,3}};
    //vector<vector<int>> e_optionals = {{7, 1}, {7,2}, {7,8}};

    /*inputs not sp-chordal*/
    vector<vector<int>> e1 = {{1, 2},{2, 3},{1,4},{4,3}};
    vector<vector<int>> e_optionals = {{5,1}};

    findSandwich(e1, e_optionals);

    return 0;
}