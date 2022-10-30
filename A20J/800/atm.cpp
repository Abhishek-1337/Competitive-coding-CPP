#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	        int n;
	        cin >> n;
	        int arr[n];
	        
	        for(int i = 0; i < n; i++){
	        	cin >> arr[i];
	        }
	        string s;
	        cin >> s;
	        string test = s;
	        for(int i = 0; i < n; i++){
	        	for(int j = 0; j < n; j++){
	        		if(arr[i] == arr[j]){
	        			test[j] = s[i];
	        		}
	        	}
	        }
	        // cout << test;
            if(test == s) cout << "YES";
            else cout << "NO";
            cout << endl;

	}
	return 0;
}