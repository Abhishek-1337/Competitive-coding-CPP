#include<bits/stdc++.h>

using namespace std;

//time complexity :n*squarerootof(n)
void basicMethod(int n){
    bool flag;
    for(int i = 2; i <= n; i++){
        flag = true;
        for(int j = 2; j*j <= i; j++){
            if(i%j == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i << endl; 
        }
        
    }
}

//more efficient method sieve of eratosthenes >> time complexity = log(log(squarerootof(n)))
void soe(int n){
    vector<bool> arr(n+1, true);
    for(int i = 2; i <= n; i++){
        if(arr[i]) cout << i << endl;
        for(int j = 2*i; j<=n; j=j+i){
            arr[j] = false;
        }
    }
    
}

int main(){
    int n;
    cin >> n;
    // basicMethod(n);
    soe(n);
    return 0;
}