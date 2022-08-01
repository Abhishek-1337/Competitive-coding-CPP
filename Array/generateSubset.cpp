#include<bits/stdc++.h>
using namespace std;


void subset(int ind, vector<int> &ds,vector<int>&sub, int arr[], int n){
    if(ind == n){
        if(ds.size() != 0){
            for(auto x: ds) cout << x << " ";
        int product = accumulate(ds.begin(), ds.end(), 1,multiplies<int>());
        cout << product << endl;
        sub.push_back(product);

        }
        return;
    }
    ds.push_back(arr[ind]);
    subset(ind+1,ds,sub, arr, n);
    ds.pop_back();
    subset(ind+1,ds,sub, arr, n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i< n; i++){
            cin >> arr[i];
        }
        vector<int> ds;
        vector<int> sub;
        subset(0, ds,sub, arr, n);
        // for(auto x:sub) cout << x << endl;
    }
    // int n = sizeof(arr)/sizeof(int);
    
    return 0;
}