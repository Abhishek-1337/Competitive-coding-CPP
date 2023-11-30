#include<bits/stdc++.h>

void bfs(vector<int> adj[], int s){
	
	queue<int> q;
	q.push(s);
	int visited[5]={0};
	while(!q.empty()){
		int curr = q.front();
		cout << curr << endl;
		q.pop();
		for(int i = 0; i < adj[curr].size(); i++){
			if(visited[i]){
				continue;
			}
			q.push(adj[curr][i]);
			visited[i] = 1;
		}
	}
}

void addNode(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[]){
	for(int i = 0; i < 5; i++){
		for(auto x: adj[i]){
			cout << x << " ";
		}
		cout << endl;
	}
}

int main(){
	vector<int> adj[5];
	addNode(adj, 0, 1);
	addNode(adj, 0, 2);
	addNode(adj, 1, 2);
	addNode(adj, 1, 3);
	addNode(adj, 2, 3);
	printGraph(adj);
	bfs(adj, 0);
	return 0;
}