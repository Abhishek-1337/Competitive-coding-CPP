#include<bits/stdc++.h>
using namespace std;

int maxi(int one, int two, int three){
    return max(one, max(two, three));
}

int maximumCuts(int l, int a, int b, int c){
    if(l == 0) return 0;
    if(l < 0) return -1;
    int res = maxi(maximumCuts(l-a, a, b, c),
                  maximumCuts(l-b, a, b, c),
                  maximumCuts(l-c, a, b, c)
                );
    if(res != -1){
        return (res+1);
    }
    else return -1;
}

int main(){
    int l, a, b, c;
    cin >> l >> a >> b >> c;
    cout << "Hello";
    cout << maximumCuts(l, a, b, c);
}