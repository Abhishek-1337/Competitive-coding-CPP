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
	     int n;
	     cin >> n;
	     int size= 2*n;
	     int arr[size];
	     int flag = false;
	     unordered_map<int, int> mp;
	     for(int i = 0; i < size; i++){
	     	cin >> arr[i];
	     	cout << arr[i] << " ";
	     	mp[arr[i]]++;
	     }   
	     for(auto &it: mp){
	     	if(it.second > 2){
	     		flag = true;
	     		break;
	     	}
	     }

	     if(flag) cout << "NO\n";
	     else cout << "YES\n";

	}
	return 0;
}
