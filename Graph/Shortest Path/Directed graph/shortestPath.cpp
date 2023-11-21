#include<bits/stdc++.h>
using namespace std;

class adj{
    int v, weight;
    public: 
        adj(int _v, int _weight){
            v = _v;
            weight = _weight;
        }
        int getWeight(){
            return weight;
        };
        int getV(){
            return v;
        }
};

class Graph{
    int V;
    vector<vector<adj>> arr;
    stack<int> sort;
    queue<int> node;
    vector<int> topoSort;

    public:
        bool looper();
        void topologicalSort();
        Graph(int V);
        void addEdge(int u, int v, int weight);
        void shortestPath(int source);
        
};

Graph::Graph(int V){
    this->V = V;
    arr.resize(this->V);
}

void Graph::topologicalSort(){
    // cout << "HELLO0"<< endl;
    vector<int> indegree(V,0);
    
    for(int i = 0; i < V; i++){
        for(auto x: arr[i]){
            indegree[x.getV()]++;
        }
    }
    for(int i = 0; i< V; i++){
        if(indegree[i] == 0){
            node.push(i);
        }
    }
    while(!node.empty()){
        int vertex = node.front();
        topoSort.push_back(vertex);
        node.pop();
        for(auto &x: arr[vertex]){
            int val = x.getV();
            indegree[val]--;
            if(indegree[val] == 0){
                node.push(val);
            }
        }
    }

}

void Graph::shortestPath(int source){
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    topologicalSort();
    for(int u: topoSort){
        for(auto &v: arr[u]){
            int distV = dist[v.getV()];
            int distV2 = dist[u] + v.getWeight();
            if(distV > distV2){
                dist[v.getV()] = distV2;
            }
        }
    }

    for(auto i: dist){
        cout << i << endl;
    }
}

void Graph::addEdge(int u, int v, int weight){
    adj nod(v, weight);
    arr[u].push_back(nod);
}

int main(){
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
 
    g.shortestPath(0);
    // g.looper();
    // g.sortBfs();

    return 0;
}