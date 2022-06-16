#include<bits/stdc++.h>

using namespace std;

int main(){
	int max, min, n, x;
	vector<int> v;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}

	max = v[0];
	min = v[0];
	for(int i = 1; i < n; i++){
		if(v[i] > max){
			max = v[i];
		}
		
		if(v[i] < min){
			min = v[i];
		}
	}

	cout << max << " "<< min << "\n";
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	return 0;
}