#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int r,c;
	    cin >> r >> c;
	    if(r == 1 || c == 1){
	    	int temp = r>c?r:c;
	        cout <<  temp<< "\n";
	    }
	    else if(r%2 != 0 && c%2 != 0){
	    	cout << r+c-1 << "\n";
	    }
	    else if(r%2 == 0 && c%2 == 0)cout << 0 << "\n";
	    else if(r%2 != 0){
	    	cout << c << "\n";
	    }
	    else if(c%2 != 0){
	    	cout << r << "\n";
	    }
	}
	return 0;
}