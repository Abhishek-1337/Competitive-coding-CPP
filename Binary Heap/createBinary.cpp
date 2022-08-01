#include<bits/stdc++.h>

using namespace std;

class Heap{
    public:
    void insert(vector<int> &v, int i){
        int n = i;
        int key = v[n];
        while(n > 1 && key > v[n/2]){
           v[n] = v[n / 2];
           n = n / 2;
        }
        v[n] = key;
    }

    int del(vector<int> &v, int len){
        int key = v[1];
        int i = 1;
        v[1] = v[len-1];
        v.pop_back();
        int leftChild = 2, rightChild = 3;
        while((leftChild < len-1) && (rightChild < len-1)){

            int bigOne = v[leftChild] > v[rightChild]?leftChild:rightChild;
            if(v[i] < v[bigOne]){
                swap(v[i], v[bigOne]);
                i = bigOne; 
            }
            else{
                break;
            }

            leftChild = 2*i;
            rightChild = 2*i+1;
        }

        return key;
    }
};

int main(){
    vector<int> v{0,5,6,10,12,15,20,30,40};//30,20,15,5,10,12,6,40
    Heap heap;
    for(int i = 2; i <= 8; i++){
        heap.insert(v, i);
    }
    int len = v.size();
    for(int i = 0; i < len; i++){
        cout << v[i] << "\n";
    }
    int del = heap.del(v,v.size());
    cout <<"This is the deleted item " << del;
    del = heap.del(v,v.size());
    cout <<"This is the deleted item " << del;
    return 0;
}