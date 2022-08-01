#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    cin >> num;
    int count = 0;
    string var = to_string(num);
    int len = var.size();
    for(int i = 0; i < len; i++){
        if(var[i] == '4' || var[i] == '7'){
            count++;
        }
    }
    if(count == len) cout << "YES\n";
    else if(num % 4 == 0 || num%7 == 0)cout << "YES\n";
    else cout << "NO\n";
    return 0;
}