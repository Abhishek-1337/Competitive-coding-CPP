#include<bits/stdc++.h>
using namespace std;

vector<int> bellFord(int graph[][3], int v, int e){
    vector<int> dist(v, INT_MAX);
    dist[0] = 0;
    for(int i = 0; i < v-1; i++){
        for(int j = 0; j < e; j++){
            if(dist[graph[j][1]] > dist[graph[j][0]] + graph[j][2]){
                dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
            }
        }
    }

    for(int i = 0; i < e; i++){
        if(dist[graph[i][1]] > dist[graph[i][0]] + graph[i][2]){
            cout << "Negative weight cycle detected" << endl;
            break;
        }
    }
    return dist;
}


int main(){
    
    int graph[][3] = {
        {0,1,1},
        {0,2,4},
        {1,2,-3},
        {1,3,2},
        {2,3,3}
    };

    vector<int> dist = bellFord(graph, 4, 5);
    for(int i = 0; i < 4; i++){
        cout << dist[i] << endl;
    }
    return 0;
}