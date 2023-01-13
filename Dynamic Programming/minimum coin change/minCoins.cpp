#include<bits/stdc++.h>
using namespace std;


//Tabulation
int minCountTab(int coins[], int amount) {
    int n = coins.size();
    int dp[n][amount+1];
    for(int i = 0; i <= amount; i++){
        if(i % coins[0] == 0){
            dp[0][i] = i/coins[0];
        }
        else{
            dp[0][i] = 1e9;
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= amount; j++){
            int notTake = dp[i-1][j];
            int take = 1e9;
            if(coins[i] <= j){
                take = 1+ dp[i][j-coins[i]];
            }
            dp[i][j] = min(take, notTake);
        }
    }
    int ans = dp[n-1][amount];
    if(ans >= 1e9) return -1;
    return ans;
}

//Memoized
int minCountMemo(int coins[], int idx, int amount, vector<vector<int>> &dp){
    if(idx == 0){
        if(amount % coins[idx] == 0) return amount/coins[idx];
        else return INT_MAX;
    }
    if(dp[idx][amount] != -1){
        return dp[idx][amount];
    }
    int notTake = minCountMemo(coins, idx-1, amount, dp);
    int take = INT_MAX;
    if(coins[idx] <= amount){
        take = 1+minCountMemo(coins, idx, amount-coins[idx], dp);
    }
    return dp[idx][amount] = min(take, notTake);
}


//Recursion
//Infinite supply of value results in multiple use
//either we can not take the value or if that value is less than the amount you can choose it
//then return the minimum result from take or not take.
//INT_MAX is used so as it shouldn't interrupt other result value.
int minCount(int coins[], int idx, int amount){
    if(idx == 0){
        if(amount % coins[idx] == 0) return amount/coins[idx];
        else return INT_MAX;
    }
    int notTake = minCount(coins, idx-1, amount);
    int take = INT_MAX;
    if(coins[idx] <= amount){
        take = 1+minCount(coins, idx, amount-coins[idx]);
    }
    return min(take, notTake);
}


int main(){
    int n, amount;
    cout << "Enter the number of coins in Array: " << endl;
    cin >> n;
    cout << "Enter value for array: " << endl;
    int coins[n];
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    cout << "Enter the total amount" << endl;
    cin >> amount;
    vector<vector<int>> dp(n, vector<int> (amount+1, -1));

    // cout << minCount(coins, n-1, amount);
    cout << minCountMemo(coins, n-1, amount, dp);
    return 0;
}