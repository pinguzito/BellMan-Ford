#include<iostream>
#include<vector>
#include<algorithm>
#define infinito 999999
#define N 5
using namespace std;

class aresta{
    public:
    int v1,v2,peso;
};

class vertice{
    public:
    int valor, dist, pred;
};

class grafo{
    public:
    vector<vertice> vertices;
    vector<aresta> arestas;
};

int matriz[][N]={{0,6,0,0,7},
                 {0,0,5,-4,8},
                 {0,-2,0,0,0},
                 {2,0,7,0,0},
                 {0,0,-3,9,0}};

// int matriz[][N] = {{0,3,7,5},
//                    {0,0,3,1},
//                    {0,0,0,0},
//                    {0,0,1,0}};

grafo criaGrafo(int m[][N]){
    grafo G;    
    aresta A;
    vertice V;
    for(int i = 0; i < N; i++){
        V.valor = i;
        for(int j = 0; j < N; j++){
            if(m[i][j]){
                A.v1 = i;
                A.v2 = j;
                A.peso = m[i][j];
                G.arestas.push_back(A);
            }
        }
        G.vertices.push_back(V);
    }
    return G;
}

void BELLMAN_FORD(grafo G, int s){
    for(int i = 0; i < G.vertices.size(); i++){
        G.vertices.at(i).dist = infinito;
    }
    G.vertices.at(s).dist = 0;
    G.vertices.at(s).pred = infinito;
    for(int i = 1; i < G.vertices.size() - 1; i++){
        for(int j = 0; j < G.arestas.size(); j++){
            if(G.vertices.at(G.arestas.at(j).v1).dist != infinito && (G.vertices.at(G.arestas.at(j).v1).dist + G.arestas.at(j).peso) < G.vertices.at(G.arestas.at(j).v2).dist){
                G.vertices.at(G.arestas.at(j).v2).dist = G.vertices.at(G.arestas.at(j).v1).dist + G.arestas.at(j).peso;
                G.vertices.at(G.arestas.at(j).v2).pred = G.vertices.at(G.arestas.at(j).v1).valor;
            }
        }
    }
    cout << "Bellman-Ford: " << endl;
    cout << "SSSP: (vertice, pred, dist)" << endl;
    cout << "Vertice inicial = " << s << endl;
    for(int i = 0; i < G.vertices.size(); i++){
        if(G.vertices.at(i).pred == infinito){
            G.vertices.at(i).pred = 0;
        }
        if(i == 0){
            cout << "{ ";
        }
        cout << "(" << G.vertices.at(i).valor << ", " << G.vertices.at(i).pred << ", " << G.vertices.at(i).dist << ") ";
        if(i == (G.vertices.size())-1){
            cout << "}" << endl;
        }
    }
}

int main(){

    grafo G = criaGrafo(matriz);
    BELLMAN_FORD(G,0);

    return 0;
}