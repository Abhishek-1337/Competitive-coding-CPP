#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	int arr[tc];
	for(int i = 0; i < tc; i++){
		cin >> arr[i];
	}
	for(int i = tc-1; i >=0; i--){
		cout << arr[i] <<" ";
	}
	return 0;
	
}