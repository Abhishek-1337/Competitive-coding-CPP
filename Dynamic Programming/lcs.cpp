//Longest common sequence
#include<iostream>
using namespace std;

#define endl "\n"

//Space optimized
 int longestCommonSubsequence(string text1, string text2) {
        //memoized
        int m = text1.size();
        int n = text2.size();
        // vector<vector<int>> dp(m+1, vector(n+1,-1));
        // return longestCommonSubsequence(text1, text2, m , n, dp);

        //Tabulation
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int i = 0; i <= n; i++){
            prev[i] = 0;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1+prev[j-1];
                }
                else{
                    curr[j] = max(curr[j-1], prev[j]);
                }
                
            }
            prev = curr;

        }
        return prev[n];
    }


//tabulation
int longestCommonSubsequence(string text1, string text2) {
        //memoized
        int m = text1.size();
        int n = text2.size();
        // vector<vector<int>> dp(m+1, vector(n+1,-1));
        // return longestCommonSubsequence(text1, text2, m , n, dp);

        //Tabulation
        int dp[m+1][n+1];
        for(int i = 0; i <= m; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
}

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