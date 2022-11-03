#include<iostream>
using namespace std;

// int subsetSum2(int arr[], int sum, int n){
// 	bool dp[n+1][sum+1];
// 	for(int i = 0; i <= n; i++){
// 		dp[i][0] = 1;
// 	}
// 	for(int i = 1; i <= sum; i++){
// 		dp[0][i] = 0;
// 	}
// 	for(int i = 1; i <= n; i++){
// 		for(int  j = 1; j <= sum; j++){
// 			if(arr[i-1] <= j){
// 				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; 
// 			}
// 			else{
// 				dp[i][j] = dp[i-1][j];
// 			}
// 		}
// 	}
// 	for(int i = 0; i <= n; i++){
// 		for(int j = 0; j <= sum; j++){
// 			cout << dp[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
//   return dp[n][sum];
// }

//memoized code for subset sum
// int dp[2000][2000];

int partitionSum(int sum, int arr[], int n){
	cout << sum << endl;
	if(sum == 0){
		return 1;
	}

	if(n == 0) return 0;
	return partitionSum(sum-arr[n-1], arr, n-1) || partitionSum(sum, arr, n-1);
}

int main(){
	int n, sum = 0;
	cin >> n; 
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	if(sum % 2 != 0){
		cout << "NO\n";
		return 0;
	}
	if(partitionSum(sum/2, arr, n)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}