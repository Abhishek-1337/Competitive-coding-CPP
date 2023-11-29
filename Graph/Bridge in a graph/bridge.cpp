#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    vector<vector<int>> arr;

    public:

        Graph(int V);
        void addEdge(int u, int v);
        int checkBipartite(int vertex, int color[]);
        int getWee();      
        void dfsBridge(vector<int> adj[], vector<int> &visited, int low[], int disc[], int parent, int u, vector<vector<int>> &bridges)  
};

int Graph::getWee(){
    return V;
}

void Graph::dfsBridge(vector<int> adj[], vector<int> &visited, int low[], int disc[], int parent, int u, vector<vector<int>> &bridges){
        visited[u] = 1;
        low[u] = disc[u] = timer;
        timer++;
        for(int v: adj[u]){
            if(parent == v) continue;
            if(!visited[v]){
                dfs(adj, visited, low, disc, u, v, bridges);
                low[u] = min(low[v], low[u]);
                if(low[v] > disc[u]){
                    bridges.push_back({v, u});
                }
            }
            else{
                low[u] = min(low[v], low[u]);
            }
        }
    }

int Graph::checkBipartite(int vertex, int color[]){
    queue<int> qu;
    qu.push(vertex);
    color[vertex] = 1;
    while(!qu.empty()){
        int node = qu.front();
        qu.pop();
        for(auto &it: arr[node]){
            if(color[it] == -1){
                qu.push(it);
                color[it] = 1-color[node];
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}

Graph::Graph(int V){
    this->V = V;
    arr.resize(this->V);
}

void Graph::addEdge(int u, int v){

    arr[u].push_back(v);
    arr[v].push_back(u);
}

int main(){
    
}