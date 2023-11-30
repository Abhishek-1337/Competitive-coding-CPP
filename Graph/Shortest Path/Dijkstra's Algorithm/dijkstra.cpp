#include<bits/stdc++.h>
using namespace std;

int adjMatrix[20][20];

class Graph{

    int V;
    public:

        Graph(int V);
        void addWeight(int u, int v, int weight);
        vector<int> dijkstra();
        
};

Graph::Graph(int V){
    this->V = V;
}

vector<int> Graph::dijkstra(){
    vector<int> finalized(V, false);
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    for(int i = 0; i < V; i++){
        int u = -1;
        for(int j = 0; j < V; j++){
            if(!finalized[j] && ( u == -1 || dist[j] < dist[u])){
                u = j;
            }
        }
        finalized[u] = true;
        for(int j = 0; j < V; j++){
            if(adjMatrix[u][j] && !finalized[j]){
                dist[j] = min(dist[j], dist[u]+adjMatrix[u][j]);
            }
        }
    }
    return dist;
}

void Graph::addWeight(int u, int v, int weight){
    adjMatrix[u][v] = adjMatrix[v][u] = weight;
}


int main(){
    Graph g(4);
    g.addWeight(0, 1, 5);
    g.addWeight(0, 2, 8);
    g.addWeight(1, 2, 10);
    g.addWeight(1, 3, 15);
    g.addWeight(2, 3, 20);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> dist = g.dijkstra();
    for(int i = 0; i < 4; i++){
        cout << dist[i] << endl;
    }
    return 0;
}