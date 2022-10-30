#include<bits/stdc++.h>
using namespace std;

int dp[47] = {0};

int tabWays(int s,int n){ //Tabulation or Bottom-up
    if(dp[s] != 0){
        return dp[s];
    }
    if(s == n){
        return 1;
    }
    if(s > n){
        return 0;
    }
    dp[s] = tabWays(s+1, n) + tabWays(s+2, n) + tabWays(s+3, n);
    return dp[s];
}

int memoWays(int n, int ans[]){ //Top-down or memoized
    
    if(n == 0) {
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(ans[n] != 0){
        return ans[n];
    }
    ans[n] =  memoWays(n-1, ans)+memoWays(n-2, ans)+memoWays(n-3, ans);  
    return ans[n];
}

int countWays(int n){ //Bruteforce
    if(n == 0) {
        // countg++;
        return 1;
    }
    if(n < 0){
        return 0;
    }
    return countWays(n-1)+countWays(n-2)+countWays(n-3);  
}

int main(){
    int n;
    cout << "Enter the n \n";
    cin >> n;
    int ans[n+1] = {0};
    // cout << countWays(n) << endl;
    // cout << tabWays(0,n) << endl;
    cout << memoWays(n, ans) << endl;
    return 0;
}