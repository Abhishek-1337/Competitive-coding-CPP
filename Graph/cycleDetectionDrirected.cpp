#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    vector<vector<int>> arr;

    public:
        bool looper();
        bool checkCycleBfs(vector<int> &visited,  int vertex);
        bool checkCycleDfs(vector<int> &visited, int vertex, vector<int> &dfsVisited);
        Graph(int V);
        void addEdge(int u, int v);

        
};

Graph::Graph(int V){
    this->V = V;
    arr.resize(this->V);
}

bool Graph::checkCycleBfs(vector<int> & visited, int vertex){
    queue<pair<int, int>> qp;
    visited[vertex] = 1;
    qp.push({vertex, -1});
    while(!qp.empty()){
        int node = qp.front().first;
        int prev = qp.front().second;
        qp.pop();
        for(auto it: arr[vertex]){
            if(visited[it] == 0){
                visited[it] = 1;
                qp.push({it, node});
            }
            else if(prev != it){
                return true;
            }
        }
    }
    return false;
}

bool Graph::checkCycleDfs(vector<int> &visited, int vertex, vector<int> &dfsVisited){

    if(!visited[vertex]) {
        visited[vertex] = 1;
        dfsVisited[vertex] = 1;
    }
    for(auto &x : arr[vertex]){
        if(!dfsVisited[x]){
            if(checkCycleDfs(visited, x, dfsVisited)) return true;
        }
        else{
            return true;
        }
    }
    dfsVisited[vertex] = 0;
    return false;
}

bool Graph::looper(){

    vector<int> visited(V,0);
    vector<int> dfsVisited(V,0);
    for(int i = 1; i < V; i++){
        if(visited[i] == 0){
            // if(checkCycleBfs(visited, i)) return true;  
            if(checkCycleDfs(visited, i, dfsVisited)) return true;          
        }
    }
    return false;
}
void Graph::addEdge(int u, int v){

    arr[u].push_back(v);
}

int main(){
    Graph g(10);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 6);
    g.addEdge(6, 5);
    g.addEdge(7, 2);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(9, 7);

    // g.BFS();
    bool flag = g.looper();
    cout << flag << endl;
    if(flag)cout << "YES\n";

    return 0;
}