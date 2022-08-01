#include<bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;
    map<char, int> m;
    string result;
    for(int i = 0; i < str.length(); i++){
        char a = str[i];
        if(m[a] >= 1){
           if(a != 'l'){
             continue;
           }
           else if(a == 'l' && m[a] > 2){
            continue;
           }
        }
        m[a]++;
        if((a == 'h' || a == 'e' || a == 'l' || a == 'o') && m[a] <= 2 ){
            result.push_back(a);
        }
    }

    if(result == "hello"){
       cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }    
   return 0;
}