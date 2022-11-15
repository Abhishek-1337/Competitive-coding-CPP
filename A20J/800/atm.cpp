#include <iostream>
using namespace std;

#define ull unsigned long long
const long mod = 1e9+7;
const long int N= 1e5+10;
#define ll long long 

// ull factorial(int num)
// {
 
//     // Initialize result
//     ull f = 1; // Or BigInt 1
 
//     // Multiply f with 2, 3, ...N
//     for (ull i = 2; i <= num; i++)
//         {
//         	f  = (f*i)%mod;
//         }
 
//     return f;
// }

int main() {
	// your code goes here
	ull fact[N];
	fact[0] = 1;
	for(int i = 1; i < N; i++){
		// if(i == 100000) break;
	        fact[i] = (fact[i-1]*i)%mod;
	}
	for(int i = 0; i < 5; i++){
	        cout << fact[i] << " ";
	}
	return 0;
}
