// #include <bits/stdc++.h>
// using namespace std;

// #define endl "\n"
// #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long

// void recursion(string s, vector<string> &arr, int i, string output){
// 	if(i == s.size()){
// 		set.insert(arr)
// 	}
//     string curr = output+str[i];
//      if(mp.count(curr)){
     	
//       recursion(s,arr,i+1,curr);
//       arr.push_back(curr);
//       recursion(s, arr , i+1, "  ");
//       arr.pop_back(curr);
//     }
// }

// void ans(){
// 	string s;
// 	cin >> s;
// 	string output = "";
// 	vector<string> arr;
// 	recursion(s,arr,0, output);

// }

// int32_t main(){
// 	IOS;
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		ans();
// 	}
//     return 0;
// }//



// #include <bits/stdc++.h>
// using namespace std;


// long long int func(int index,string&s,vector<int>& dp,map<string,string>& hardcoded,string curr,set<string>& disset,long long int mod){
//     if(index<0){
//         auto it=disset.find(curr);
//         if(it==disset.end()){
//             disset.insert(curr);
//             return 1;
//         }
//         return 0;
//     }
//     if(dp[index]!=-1){
//         return dp[index];
//     }
//     long long int takingone=func(index-1,s,dp,hardcoded,hardcoded[s.substr(index,+1)+curr],disset,mod);
//     long long int takingtwo=0;
//     if(index-1>=0 && hardcoded.find(s.substr(index-1,2))!=hardcoded.end()){
//         takingtwo=func(index-2,s,dp,hardcoded,hardcoded[s.substr(index-1,2)]+curr,disset,mod);
//     }
//     return dp[index]=(takingone+takingtwo)%998244353;
// }


// long long int solve(){
//     string s;
//     cin>>s;
//     long long int n=s.length();
//     vector<int>dp(n,-1);
//     map<string,string>hardcoded{{"a","01"},{"b","10"},{"ab","010"},{"ba","101"}};
//     set<string>disset;
//     cout<<func(n-1,s,dp,hardcoded,"",disset,998244353)<<endl;
//     return 0;
// }



// int main() {
//     long long int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//   return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int func(string s, vector<int> &dp, int i) {
	if(dp[i] != -1){
		return dp[i];
	}
	if(i == s.size() - 2 || i == s.size() - 1)
		return 1;
	if (s[i] == s[i + 1]) {
		dp[i]= (func(s,dp, i + 1))%998244353;
		return dp[i];
	} else {
		dp[i] =(func(s,dp, i + 1) + func(s,dp, i + 2))%998244353;
		return dp[i];
	}

} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt; 
	cin >> tt;
	while (tt--) {

		string s;
		cin >> s;
		int n = s.size();
		vector<int> dp(n,-1);
		if(s.size() == 1)
			cout << "1\n";
		else if (s.size() == 2)
			if(s[0] == s[1])
				cout << "1\n";
			else
				cout << "2\n";
		else
			
			cout << func(s,dp,0) << "\n";
	}
	return 0;
}