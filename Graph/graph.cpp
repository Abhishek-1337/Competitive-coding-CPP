#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> arr;

    public:

        Graph(int V);
        void DfS(vector<int>&stored, vector<int>&visited, int vertex, vector<vector<int>> adj);
        vector<int> dfsLooper();
        void BFS();
        void addEdge(int u, int v);
        void adjListTraverse(){
            for(int i = 1; i < V; i++){
                for(auto j:arr[i]){
                    cout << j << "\n";
                }
                cout << "***" << "\n";
            }
        }
        
};

Graph::Graph(int V){
    this->V = V;
    arr.resize(this->V);
}

void Graph::BFS(){
    vector<int> visited(V);
    queue<int> q;
    for(int i = 1; i < V; i++){
        if(visited[i] == 0){         
            visited[i] = 1;
            q.push(i);
            while(!q.empty()){
                int el = q.front();
                cout <<  el << " ";
                q.pop();
                for(auto j: arr[el]){
                    if(visited[j] == 0){
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
    }
}

void Graph::DfS(vector<int>&stored, vector<int>&visited, int vertex, vector<vector<int>> adj){
    stored.push_back(vertex);
    cout << vertex << " ";
    visited[vertex] = 1;
    for(auto it : adj[vertex]){
        if(visited[it] == 0){
            DfS(stored, visited, it, adj);
        }
    }
}

vector<int> Graph::dfsLooper(){
    vector<int> storedDfs;
    vector<int> visited(V,0);
    for(int i = 1; i < V; i++){
        if(visited[i] == 0){
            DfS(storedDfs, visited, i, arr);         
        }
    }
    return storedDfs;
}

void Graph::addEdge(int u, int v){

    arr[u].push_back(v);
    arr[v].push_back(u);
}

int main(){
    Graph g(8);
    g.addEdge(1, 2);
    g.addEdge(4, 6);
    g.addEdge(6, 7);
    g.addEdge(2, 4);
    g.addEdge(2, 7);
    g.addEdge(3, 5);

    // g.BFS();
    g.dfsLooper();

    return 0;
}