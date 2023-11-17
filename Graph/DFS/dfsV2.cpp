#include<bits/stdc++.h>
#include<iostream>

using namespace std;

//For disconnected components
void dfs(vector<int> adj[], int s, vector<int> &visited){
    cout << s <<endl;
    visited[s] = 1;
    for(int i: adj[s]){
        if(!visited[i]){
            dfs(adj, adj[s][i], visited);
        }
    }
}

void addNode(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[]){
	for(int i = 0; i < 7; i++){
		for(auto x: adj[i]){
			cout << x << " ";
		}
		cout << endl;
	}
}

int main(){
	vector<int> adj[7];
	addNode(adj, 0, 1);
	addNode(adj, 1, 2);
	addNode(adj, 1, 3);
	addNode(adj, 0, 4);
	addNode(adj, 4, 5);
	addNode(adj, 4, 6);
	addNode(adj, 5, 6);
	printGraph(adj);

    vector<int> visited(7, 0);
	for(int i = 0; i < 7; i++){
        if(!visited[i]){
            dfs(adj, 0, visited);
        }
    }
	return 0;
}