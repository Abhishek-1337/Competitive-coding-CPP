#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    int max = 0;
	    for(int i= 0; i < n; i++){
	    	int count = 0;
	    	for(int j = 0; j < n; j++){
	    		if(arr[i] == arr[j]){
	    			count++;
	    		}
	    	}
	    	if(count > max){
	    		max = count;
	    	}
	    }
        cout << n-max <<"\n";
	
	}
	return 0;
}