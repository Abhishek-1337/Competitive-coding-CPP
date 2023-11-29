//Find shortest path in undirected graph with unweighted edges

#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;

    public:
      void shortestPathBfs(int src, int dest);
      void addEdge(int u, int v);
      Graph(int V);
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(this->V); 
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::shortestPathBfs(int src, int dest){
    vector<int> distance(V, INT_MAX);
    
    queue<int> node;
    node.push(src);
    distance[src] = 0;
    while(!node.empty()){
        int currNode = node.front();
        node.pop();
        for(auto &it: adj[currNode]){
            int dist = distance[currNode]+1;
            if(dist < distance[it]){
                distance[it] = dist;
                node.push(it);
            }
        }
    }
    cout << distance[dest] << endl;
}

int main(){
    Graph g(9);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,6);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(6,8);
    g.addEdge(7,8);
    g.shortestPathBfs(0, 6);
    return 0;
}