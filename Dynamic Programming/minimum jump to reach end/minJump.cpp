#include<bits/stdc++.h>
using namespace std;

//Tabulation
int minJumpTab(vector<int>&nums, int n){
    int dp[n];
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = 1e9;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(j+nums[j] >= i){
                if(dp[j] != INT_MAX){  //If index j is reachable from previos elements then only it can be used to reach the end
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
    }
    return dp[n-1];
} 

//Memoized solution
// int minJump(vector<int>&nums, int currIdx, int n, int dp[]){
//     if(n == 1) return 0;
//     int res = INT_MAX;
//     for(int i = 0; i <= n-2; i++){
//         if(i+nums[i] >= n){
//             int sub_res = minJump(nums, i+1);
//             if(sub_res != INT_MAX){
//                 res = min(res, sub_res+1);
//             }
//         }
//     }
//     return res;
// }    

int main(){
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of array" << endl;
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    cout << minJumpTab(arr, n);
    return 0;
}