//Longest common sequence
#include<iostream>
using namespace std;

#define endl "\n"



//memoized solution
int lcs(string s1, string s2, int x, int y){
	if(dp[x][y] != -1) return dp[x][y];
	if(x == 0 || y == 0) return 0;
	if(s1[x-1] == s2[y-1]){
		dp[x][y] =  1+lcs(s1, s2, x-1, y-1);
	}
	else{
		dp[x][y] = max(lcs(s1, s2, x-1, y), lcs(s1, s2, x, y-1));
	}
	return dp[x][y];
}


//Only recursion
int lcs(string s1, string s2, int x, int y){
	if(x == 0 || y == 0) return 0;
	if(s1[x-1] == s2[y-1]){
		return 1+lcs(s1, s2, x-1, y-1);
	}
	else{
		return max(lcs(s1, s2, x-1, y), lcs(s1, s2, x, y-1));
	}
}

int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int dp[x+1][y+1];
	for(int i = 0; i <= x; i++){
		for(int j = 0; j <= y; j++){
			dp[i][j] = -1;
		}
	}
	lcs(str1, str2, str1.size(), str2.size());
	return 0;
}