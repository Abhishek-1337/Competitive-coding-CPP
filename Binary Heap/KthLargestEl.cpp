#include<bits/stdc++.h>

using namespace std;

void maxHeap(vector<int> &v, int n){
    int i = n;
    int key = v[i];
    while(i > 1 && key > v[i/2]){
        v[i] = v[i/2];
        i = i/2;
    }
    v[i] = key;
    
}

int del(vector<int> &v, int n){
    int key = v[1];
    int keyIndex = 1;
    v[1] = v[n-1];
    v.pop_back();
    int leftChild = 2, rightChild = 3;

    while((leftChild < n-1) && (rightChild < n-1)){
        int bigOne = v[leftChild] > v[rightChild]? leftChild:rightChild;
        if(v[keyIndex] < v[bigOne]){
            swap(v[keyIndex], v[bigOne]);
            keyIndex = bigOne;   
        }
        else break;
        leftChild = 2*keyIndex;
        rightChild = 2*keyIndex+1;
    }
   return key;
}

int main(){
    vector<int> v{0, 1, 23, 12, 9, 30, 2, 50};
    int k = 3;

    for(int i = 2; i < v.size(); i++){
        maxHeap(v, i);
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
    for(int i = 0; i < 3; i++){
        cout << "Deleted element: "<< del(v, v.size()) << "\n";
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
    return 0;
}