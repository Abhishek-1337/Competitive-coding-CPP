#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const long mod = 1e9+7;
const long int N= 1e5+10;
#define ll long long 


int main() {
	int t;
	cin >> t;
	while(t--){
	     string s;
	     cin >> s;
	     int n = s.size();
	     string str = "Yes";
	     if(n == 1){
	     	int x = s[0];
	     	if(x != 'Y' || x != 'e' || x != 's'){
	     		str = "No";
	     	}
	     }
	     else{
	     	for(int i = 0; i < n; i+=3){
	     		if(s[i] != 'Y' || s[i] != 'e' || s[i] != 's'){
	     			str = "No";
	     		}
	     		if(n-i > 3){
	     			if(s[0] == 'Y' && s[1] == 'e' && s[2] == 's' && s[3] == 's'){
	     				str = "No";
	     			}
	     		}
	     		else if(n-i > 2){
	     			if(s[0] == 'Y' && s[1] == 'E' && s[2] == 'S'){
	     				str = "No";
	     			}
	     		}
	     		else if(n-i > 1){
	     			if(s[0] == 's' && s[1] == 'e'){
	     				str = "No";
	     			}
	     		}
	     	}
	     }

	     cout << str << endl;

	}
	return 0;
}
