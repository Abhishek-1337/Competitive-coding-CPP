#include <iostream>
using namespace std;

int main() {
	int t;
        cin >> t;
        while(t--){
                long long int a,b,n;
                cin >>a>>b>>n;
                if(a % b == 0){
                        cout << -1 << "\n";
                        return 0;
                }
                long long nCopy = n;
                if(n % a != 0){
                    nCopy = n + a - (n%a);
                }

                while(!(nCopy % a == 0 && nCopy % b != 0)){
                    nCopy = nCopy + a;
                }
                cout << nCopy << "\n";
        }
	return 0;
}
