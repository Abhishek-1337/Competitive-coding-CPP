#include<bits/stdc++.h>
using namespace std;

int findMinTab(int n){
    if(n <= 1){
        return 0;
    }
    int dp[n+1] = {0};
    dp[0] = -1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i< n+1; i++){
        int one = dp[n-1];
        int two = INT_MAX, three = INT_MAX;
        if(i % 2 == 0){

            two = dp[i/2];
        }
        if(i % 3 == 0){
            three = dp[i/3];
        }
        int output = min(one, min(two, three))+1;
        dp[i] = output;
    }
    return dp[n];
}

int findMin(int n, int arr[]){
    if(n <= 1){
        return 0;
    }
    //Check if output already exists
    if(arr[n] != -1){
        return arr[n];
    }
    int x = findMin(n-1, arr);
    int y = INT_MAX, z = INT_MAX;
    if(n % 3 == 0){
        y = findMin(n/3, arr);
    }
    if(n % 2 == 0){
        z = findMin(n/2, arr);
    }
    int output =  min(x,min(y,z))+1;
    //Save output for futur+e use
    arr[n] = output;
    return arr[n];
}

int main(){
    int n;
    cout << "Enter the value for n";
    cin >> n;
    int arr[n+1];
    for(int i = 0; i <= n; i++){
        arr[i] = -1;
    }
    cout << findMinTab(n);
    return 0;
}


