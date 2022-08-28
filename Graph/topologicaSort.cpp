#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> arr;
    stack<int> sort;
    queue<int> node;

    public:
        bool looper();
        void sortBfs();
        bool sortDfs(vector<int> &visited, int vertex);
        Graph(int V);
        void addEdge(int u, int v);
        void display();

        
};

Graph::Graph(int V){
    this->V = V;
    arr.resize(this->V);
}

void Graph::sortBfs(){
    // cout << "HELLO0"<< endl;
    vector<int> indegree(V,0);
    
    for(int i = 0; i < V; i++){
        for(auto &x: arr[i]){
            indegree[x]++;
        }
    }
    for(int i = 0; i< V; i++){
        if(indegree[i] == 0){
            node.push(i);
        }
    }
    while(!node.empty()){
        int vertex = node.front();
        node.pop();
        for(auto &x: arr[vertex]){
            indegree[x]--;
            if(indegree[x] == 0){
                node.push(x);
            }
        }
        cout << vertex << endl;
    }

}

bool Graph::sortDfs(vector<int> &visited, int vertex){
 
    visited[vertex] = 1;
    for(auto x:arr[vertex]){
        if(!visited[x]){
            sortDfs(visited, x);
        }
    }
    sort.push(vertex);
}

bool Graph::looper(){
    // vector<int> visited(V,0);
    
    // for(int i = 0; i < V; i++){
    //     // if(visited[i] == 0){
    //         // sortDfs(visited, i);     
    //         sortBfs();
    //     // }
    // }
    // Graph::display();
}


void Graph::display(){
    while(!sort.empty()){
        cout << sort.top() << endl;
        sort.pop();
    }
}


void Graph::addEdge(int u, int v){

    arr[u].push_back(v);
}

int main(){
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(5, 2);
    g.addEdge(3, 1);
 

    // g.looper();
    g.sortBfs();

    return 0;
}