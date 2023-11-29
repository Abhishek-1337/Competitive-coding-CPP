#include<bits/stdc++.h>
using namespace std;

int adjMatrix[20][20];

class Graph{

    int V;
    public:

        Graph(int V);
        void addWeight(int u, int v, int weight);
        int prims();
        // void adjListTraverse(){
        //     for(int i = 1; i < V; i++){
        //         for(auto j:arr[i]){
        //             cout << j << "\n";
        //         }
        //         cout << "***" << "\n";
        //     }
        // }
        
};

Graph::Graph(int V){
    this->V = V;
}

int Graph::prims(){
    vector<int> mst(V, false);
    vector<int> key(V, INT_MAX);
    int res = 0;
    key[0] = 0;
    for(int i = 0; i < V; i++){
        int u = -1;
        for(int j = 0; j < V; j++){
            if(!mst[j] && ( u == -1 || key[j] < key[u])){
                u = j;
            }
        }
        res += key[u];
        mst[u] = true;
        for(int j = 0; j < V; j++){
            if(adjMatrix[u][j] && !mst[j]){
                key[j] = min(key[j], adjMatrix[u][j]);
            }
        }
    }
    return res;
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

    cout << g.prims() << endl;
    return 0;
}