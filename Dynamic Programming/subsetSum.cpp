#include<iostream>
using namespace std;

int subsetSum2(int arr[], int sum, int n){
	bool dp[n+1][sum+1];
	for(int i = 0; i <= n; i++){
		dp[i][0] = 1;
	}
	for(int i = 1; i <= sum; i++){
		dp[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int  j = 1; j <= sum; j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; 
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
  return dp[n][sum];
}

//memoized code for subset sum
// int dp[2000][2000];

// int subsetSum(int arr[], int sum, int n){
// 	if(sum == 0) return 1;
// 	if(n == 0){
// 		return 0;
// 	}
// 	if(dp[n][sum] != -1){
// 		return dp[n][sum];
// 	}
// 	if(arr[n-1] <= sum ){
// 		dp[n][sum] = subsetSum(arr, sum-arr[n-1], n-1) || subsetSum(arr, sum, n-1);
// 	}
// 	else{
// 		dp[n][sum] =  subsetSum(arr, sum, n-1);
// 	}
// 	return dp[n][sum];
// }

int main(){
	int n, sum;
	cin >> n; 
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cin >> sum;
	// for(int i = 0; i < 2000; i++){
	// 	for(int j = 0; j < 2000; j++){
	// 	 dp[i][j] = -1;
	//     }
	// }
	if(subsetSum2(arr, sum, n)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}