#include<bits/stdc++.h>
using namespace std;

int tabMin(){
    int dp[n+1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    int mini = INT_MAX;
    for(int i = 4; i < n+1; i++){
        int val = dp[n-i];
        mini = min(val, mini);
        dp[i] = mini;
    }

    return dp[n];

}

//Memoized solution
int memoMin(int n, int ans[]){
    if(sqrt(n)- floor(sqrt(n)) == 0) return 1;
    if(n <= 3) return n;

    if(ans[n] != 0){
        return ans[n];
    }
    int mini = INT_MAX;
    for(int i = 1; i < sqrt(n); i++){
        int val = memoMin(n-i*i, ans)+1;
        mini = min(mini, val);
    }
    ans[n] = mini;
    return mini;
}

//Bruteforce solution
int findMinCount(int n){
    if(sqrt(n)- floor(sqrt(n)) == 0) return 1;
    if(n <= 3) return n;
    int mini = INT_MAX;
    for(int i = 1; i < sqrt(n); i++){
        int val = findMinCount(n-i*i)+1;
        mini = min(mini, val);
    }
    return mini;
}

int main(){
    int n;
    cout << "Enter the value of n";
    cin >> n;
    int ans[n+1] = {0};
    cout << memoMin(n, ans);
    return 0;
}