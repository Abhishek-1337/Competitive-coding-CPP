#include<bits/stdc++.h>
using namespace std;


//Naive method using to loop through all values and check which are prime divisors
int isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

void naiveMeth(int n){
    for(int i =2 ;i < sqrt(n); i++){
        if(isPrime(i)){
            int x = i;
            while(n%x == 0) {
                cout << i << " ";
                x *= i;
            }
        }
    }
}

//A little efficient program for finding prime factors
void effPrime(int n){
    for(int i = 2; i*i <= n; i++){
        while(n%i == 0){
            cout << i << " ";
            n /= i;
        }
    }

    if(n > 1) cout << n;
}

//Very efficient algorithm
void moreEffPrime(int n){
    if(n <= 1) {
        cout << false;
        return;q    
    };
    while(n % 2 == 0){
        cout << 2 ;
        n = n/2;
    }
    while(n % 3 == 0){
        cout << 3;
        n = n/3;
    }
    for(int i = 5; i*i <= n; i+=6){
        while(n%i == 0){
            cout << i ;
            n = n/i;
        }
        while(n%(i+2) == 0){
            cout << i+2;
            n = n/(i+2);
        }
    }
    return;
}

int main(){
    int n;
    cout << "Enter the number\n";
    cin >> n;
    // naiveMeth(n);
    // effPrime(n);
    moreEffPrime(n);
    return 0;
}