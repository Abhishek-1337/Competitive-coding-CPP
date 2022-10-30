#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number";
    cin >> n;
    int fib[n+1] = {0,1,1};
    for(int i = 3; i <= n; i++){
        fib[i] = fib[i-2] + fib[i-1];
    }
    cout << fib[n];
}