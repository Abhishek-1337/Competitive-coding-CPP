#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the value of n";
    cin >> n;
    int flag = true;
    if(n <= 1) flag = false;
    if(n == 2 || n == 3) flag = true;
    if(n%2 == 0 || n%3 == 0) flag = false;
    for(int i = 5; i*i <= n; i+=6){
        if(n%i == 0 || n%(i+2) == 0) {
            flag = false;
            break;
        }
    }
    if(flag) cout << "True";
    else cout << "False";
    return 0;
}