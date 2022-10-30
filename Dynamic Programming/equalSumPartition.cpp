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

int partitionSum(int sum1, int arr[], int sum2, int n){
	cout << sum1 << " " << sum2 << endl;
	if(sum1 == sum2){
		return 1;
	}

	if(n == 0) return 0;
	return partitionSum(sum1+arr[n-1], arr, sum2, n-1) || partitionSum(sum1, arr , sum2+arr[n-1], n-1);
}

int main(){
	int n, sum1 = 0, sum2 = 0;
	cin >> n; 
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	// cin >> sum;
	// for(int i = 0; i < 2000; i++){
	// 	for(int j = 0; j < 2000; j++){
	// 	 dp[i][j] = -1;
	//     }
	// }
	if(partitionSum(sum1+arr[n-1], arr, sum2, n-1) || partitionSum(sum1, arr, sum2+arr[n-1], n-1)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}