#include<bits/stdc++.h>

using namespace std;


int check(char temp){
     if(temp == 'A' || temp == 'a' || temp == 'E' || temp == 'e' || temp == 'I' || temp == 'i' || temp == 'o' || temp == 'O' || temp =='u' || temp== 'U' ||temp == 'Y' || temp == 'y'){
        return 1;
     }
     else{
        if(temp <= 97){
            return 2;
        }
        return -1;
     }
}
int main(){
    string str;
    cin >> str;
    string result;
    for(int i = 0; i < str.size(); i++){
        char j = str[i];
        if(check(j) == -1){
            result.push_back('.');
            result.push_back(j);
        }
        else if(check(j)==2){


            char temp = j+32;
            result.push_back('.');
            result.push_back(temp); 
        }
    }
    cout << result << "\n";
    return 0;
}