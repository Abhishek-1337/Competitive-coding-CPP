#include<bits/stdc++.h>
using namespace std;


vector<long long int> check(vector<long long int> sub1, vector< long long int> sub2){
        if(sub1[0] < sub2[0]){
            sub1.insert(sub1.end(), sub2.begin(), sub2.end());
            return sub1;
        }
        else{
            sub2.insert(sub2.end(), sub1.begin(), sub1.end());
            return sub2;
        }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long int n;
        cin >> n;
        long long int arr[n];
        for(int i =0 ; i < n ; i++){
            cin >> arr[i];
        }
        vector<long long int> sub1, sub2;
        int o = 0, p = 0;
        long long int min = arr[0];
        sub1.push_back(arr[0]);
        for(int i = 1; i < n; i++){
            // cout << o << " "<< p <<" "<<i <<"\n";
            long long temp = arr[i];
            if(temp > sub1[p]){
                // cout << temp << "temp\n";
                sub1.push_back(temp);
                o=p;
                p++;
            }
            else{
                if(arr[i] < min){
                    sub2.push_back(arr[i]);
                }
                else if(arr[i] < sub1[p] && arr[i]> sub1[o]){
                    sub2.push_back(sub1[p]);
                    sub1.pop_back();
                    sub1.push_back(arr[i]);
                }
                else{
                    cout << "NO\n";
                    return 0;
                }
            }       
        }
        // for(int i = 0 ; i < sub1.size(); i++){
        //     cout << sub1[i] << "\n";
            
        // }
        // cout << "end" << endl;
        // for(int i = 0 ; i < sub2.size(); i++){
        //     cout << sub2[i] << "\n";
           
        // }
        //  cout << "end2" << endl;
   
        vector<long long int> temp = check(sub1, sub2);
        for(int i = 0; i < n-1 ; i++){
            if(temp[i] > temp[i+1]){
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";

       
    }
    return 0;
}