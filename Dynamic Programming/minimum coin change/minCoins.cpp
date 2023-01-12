#include<bits/stdc++.h>
using namespace std;

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
    
    cout << minCount(coins, n-1, amount);
    return 0;
}