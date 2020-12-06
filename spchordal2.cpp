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


cout << "ok " << endl;


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

bool isSimplicial2(int v, int n_vertex, vector<vector<int>> graph) {
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

bool isChordal1(int n_vertices, int size, vector<vector<int>> edges) {
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

int calcNumVertices(vector<vector<int>> e1) {
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

    return common_vertices.size() - 1;
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

vector<int> get_neighbors(vector<vector<int>> e, int vertex) {
    vector<int> neighbors = {};

    for (int i = 0; i < e.size(); i++){
        if(e[i][0] == vertex) {
            neighbors.push_back(e[i][1]);
        } else if (e[i][1] == vertex){
            neighbors.push_back(e[i][0]);
        }
    }

    return neighbors;
}

vector<vector<int>> remove_edge(vector<vector<int>> e_set, int v1, int v2) {
    vector<int> edge = {v1, v2};
    vector<int> edge2 = {v2, v1};

    for (int i = 0; i < e_set.size(); i++){
        if(e_set[i] == edge) {
           e_set.erase(remove(e_set.begin(), e_set.end(), edge), e_set.end());
           break;
        } else if (e_set[i] == edge2) {
           e_set.erase(remove(e_set.begin(), e_set.end(), edge2), e_set.end());
           break;
        }
    }   

    return e_set;
}

vector<vector<int>> remove_vertex(vector<vector<int>> e_set, int v) {
    vector<vector<int>> new_array = {};

    for (int i = 0; i < e_set.size(); i++){
        if(e_set[i][0] != v && e_set[i][1] != v) {
           new_array.push_back({e_set[i][0], e_set[i][1]});
        }
    }   

    return new_array;
}

vector<int> bfs_lex(vector<vector<int>> e1) {
    vector<int> fila = {};
    vector<int> marcados = {};
    vector<int> tabela_rotulos = {};
    vector<vector<int>> arestas_nao_exploradas = e1;

    cout << "**** BFS ****" << endl;

    int N = calcNumVertices(e1);
    cout << "num v " << N << endl;
    int label = N;
    int vertex = 1;
    int i = 0;

    for(int j = 0; j <= N; j++) {
        tabela_rotulos.push_back(0);
        marcados.push_back(0);
    }

    while(fila.size() != N) {
        //arestas_nao_exploradas = remove_edge(e1, 4, 1);
        cout << endl << "Iteracao " << i << endl << " ------------" << endl;
        fila.push_back(vertex);
        marcados[vertex] = 1;


        //pegar os vizinhos
        vector<int> neighbors = get_neighbors(e1, vertex);
        cout << "vertice "<< vertex << " tem " << neighbors.size() << " Vizinhos nao marcados: ";
        for(int j = 0; j < neighbors.size(); j++) {
            //rotula toda vizinhança não marcada de v
            if(marcados[neighbors[j]] == 0){
                int position = neighbors[j];
                tabela_rotulos[position] = (tabela_rotulos[position] * 10) + label; //rotulo errado, pq tem q somar
                cout << position << ", "; 
            }
        }

        cout << endl;

        label--;

        //pega o maior 
        vector<int> tabela_rotulos_n_marcados = {};
        for(int j = 0; j < tabela_rotulos.size(); j++) {
            tabela_rotulos_n_marcados.push_back(0);
        }

        for(int j = 0; j < tabela_rotulos.size(); j++) {
            if(marcados[j] == 0){
                tabela_rotulos_n_marcados[j] = tabela_rotulos[j];
            }
        }

        int vertex_greatest_label = distance(tabela_rotulos_n_marcados.begin(),max_element(tabela_rotulos_n_marcados.begin(), tabela_rotulos_n_marcados.end()));
        cout << "maior label esta no " << vertex_greatest_label << endl;
        arestas_nao_exploradas = remove_edge(e1, vertex, vertex_greatest_label);
       

        //checar se precisa algo da fila (q tiver todas arestas visitadas)
        //é o mesmo que checar se o vértive está em arestas_nao_exploradas



        //colocar o novo v
        vertex = vertex_greatest_label;

        cout<< endl << "Rotulos dessa iteracao: " << endl;
        for(int j = 1; j <= N ; j++) {
            cout << j << " - " << tabela_rotulos[j] << endl;
        }
        
        // if(i == 2)break;
        i++;
    }

    vector<int> fila_ordenada = {};

    for(int j = fila.size() - 1; j >= 0; j--) {
        fila_ordenada.push_back(fila[j]);
    }


    return  fila_ordenada;
}

bool is_eep(vector<int> eep, vector<vector<int>> e) {
    //for in eep
    //checa se v do eep é simplicial 
        //se for, remove ele do grafo, cria um novo subgrafo sem v e  repete o loop
        //senao n é cordal
    int i = 0;
    vector<vector<int>> new_e = e;
    int n_vertex = calcNumVertices(new_e);
    cout << n_vertex <<endl;

    //building graph
    for (int i = 0; i < e.size(); i++){
        graph[e[i][0]][e[i][1]] = 1;
        graph[e[i][1]][e[i][0]] = 1;
    }

    cout << "  0 1 2 3 4 5 6 7" << endl;
    //printing graph
    for (int i = 0; i <= n_vertex; i++){ 
        if(i!=0) cout << i << " ";
        for (int j = 0; j <= n_vertex; j++){
            if(i!=0)
                cout << graph[i][j] << " ";
        } 
        cout << endl;
    }
    cout << endl;

    while(i != eep.size()) {
        n_vertex = calcNumVertices(new_e);

        cout << "----- Iteracao " << i << " -----" << endl;
        for (int i = 0; i < new_e.size(); i++){ 
            cout << new_e[i][0] << ", " << new_e[i][1] << endl ;
        }

        cout << n_vertex <<endl; //PAREI AQUI AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        //O NEW_E N TA SE REDUZINDO

        if(isSimplicial(eep[i], n_vertex)) {
            cout << "Removendo vertice " << eep[i] << endl; 
            new_e = remove_vertex(new_e, eep[i]);
            cout << calcNumVertices(new_e) << endl;
        } else {
            cout << "n eh eep " << i << endl;

            // for (int i = 0; i <= new_e.size(); i++){ 
            //     cout << new_e[i][0] << ", " << new_e[i][1] << endl ;
            // }
            return false;
        }
        i++;
    }

    cout << "eh eep" << endl;
    return true;
}

bool isChordal(int n_vertices, int size, vector<vector<int>> edges) {
    vector<int> fila = bfs_lex(edges);
    if(is_eep(fila, edges)){
        cout << "Is chordal";
    } else {
        cout << "Not Chordal";
        return false;
    }

    return true;
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
    vector<vector<int>> e1 = {{1, 2},{2, 3},{1,4},{4,3}, {5,1}};
    vector<vector<int>> e_optionals = {{2,4}};

    //teste eep livro jaime
    //vector<vector<int>> e1 = {{1, 2},{2, 3},{1,4},{4,2}, {2,5}, {3,5}, {4,5}, {4,6}, {5,6}, {6,7}, {5,7}};


    findSandwich(e1, e_optionals);


    return 0;
}