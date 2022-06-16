#include<bits/stdc++.h>

using namespace std;

void reverseArray(int start, int end, int arr[]){
    while(start<end){
    	int temp = arr[end];
    	arr[end] = arr[start];
    	arr[start] = temp;
    	start++;
    	end--;
    }

}

int main(){
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(int);
	int d;
	cin >> d;
	reverseArray(0,d-1,arr);
	reverseArray(d,n-1,arr);
	reverseArray(0,n-1,arr);
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
    return 0;
}