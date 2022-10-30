#include<iostream>
using namespace std;

int fib(int n , int ans[]){
    if(n <= 1){
        return n;
    }
    if(ans[n] != -1){
        return ans[n];
    }
    ans[n] = fib(n-1, ans)+fib(n-2, ans);
    return ans[n];
}

int main(){
    int n;
    cout << "Enter the value for n";
    cin >> n;
    int ans[n+1];
    for(int i = 0; i <= n; i++){
        ans[i] = -1;
    }
    cout << fib(n, ans) << endl;
    return 0;
}