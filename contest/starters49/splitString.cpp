#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
        cin >> t;
        while(t--){
            long int n, k;
            cin >> n >> k;
            string s{};
            cin >> s;
            int count1 = 0, count0 = 0;
            for(int i  = 0; i < s.size(); i++){
                if(s[i] == '1') count1++;
                else count0++;
            }
            int rem = abs(count1 - count0);
            cout << rem/k << "\n";

        }
                
	return 0;
}
