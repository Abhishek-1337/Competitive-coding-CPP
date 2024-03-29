#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> arr;

    public:
        bool looper();
        bool checkCycleDfs(vector<int> &visited,  int vertex, pair<int, int> &p);
        Graph(int V);
        void addEdge(int u, int v);

        
};

Graph::Graph(int V){
    this->V = V;
    arr.resize(this->V);
}

bool Graph::checkCycleDfs(vector<int> &visited, int vertex, pair<int, int> &p){
 
    visited[vertex] = 1;
    for(auto x:arr[vertex]){
        if(!visited[x]){
            visited[x] = 1;
            p.first = x;
            p.second = vertex;
            if(checkCycleDfs(visited, x, p)) return true;
        }
        else if(x != p.second){
            return true;
        }
    }
    return false;
}

bool Graph::looper(){
    vector<int> visited(V,0);
    pair<int, int> p(1, -1);
    for(int i = 1; i < V; i++){
        if(visited[i] == 0){
            // if(checkCycleBfs(visited, i)) return true;  
            if(checkCycleDfs(visited, i, p)) return true;          
        }
    }
}
void Graph::addEdge(int u, int v){

    arr[u].push_back(v);
    arr[v].push_back(u);
}

int main(){
    Graph g(12);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 10);
    g.addEdge(5, 6);
    g.addEdge(10, 9);
    g.addEdge(6, 7);
    g.addEdge(9, 8);
    g.addEdge(7, 8);
    g.addEdge(8, 11);

    // g.BFS();
    bool flag = g.looper();
    if(flag)cout << "YES\n";

    return 0;
}