#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class Graph{
    int V;
    vector<vector<int>> arr;

    public:

        Graph(int V);
        void addEdge(int u, int v);
        int checkBipartiteBFS(int vertex, int color[]);
        int checkBipartiteDFS(int vertex, int color[]);
        int getWee();        
};

int Graph::getWee(){
    return V;
}

int Graph::checkBipartiteBFS(int vertex, int color[]){
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

int Graph::checkBipartiteDFS(int vertex, int color[]){
     if(color[vertex] == -1){
        color[vertex] = 1;
     }
     for(auto &x: arr[vertex]){
        if(color[x] == -1){
            color[x] = 1-color[vertex];
            if(!checkBipartiteDFS(x, color))return false;
        }
        else if(color[vertex] == color[x]){
            return false;
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
    Graph g(9);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 7);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(7, 6);
    g.addEdge(6, 5);
    g.addEdge(5, 8);
    int n = g.getWee();
    int color[n];
    for(int i = 0; i <n; i++){
        color[i] = -1;
    }
    for(int i = 1; i < n; i++){
        if(color[i] == -1){
            if(!g.checkBipartiteBFS(i,color)){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}