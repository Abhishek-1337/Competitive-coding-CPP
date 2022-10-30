// Pratiyush Mishra
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
 
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
 
void prime_factorization(ll n, vector<pair<ll, ll>> &v)
{
    for (int i = 2; (i * i) <= n; i++)
    {
        if (n % i != 0)
            continue;
        ll cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            ++cnt;
        }
        v.push_back({i, cnt});
    }
    if (n != 1)
        v.push_back({n, 1});
    sort(v.begin(), v.end());
}
 
void mainSolve()
{
    ll a, b;
    cin >> a >> b;
    vector<pair<ll, ll>> prime_fac_a, prime_fac_b;
    prime_factorization(a, prime_fac_a);
    prime_factorization(b, prime_fac_b);
    if (prime_fac_a.size() != prime_fac_b.size() || prime_fac_a[0].first != prime_fac_b[0].first)
    {
        cout << "NO \n";
        return;
    }
    ll g = gcd(prime_fac_a[0].second, prime_fac_b[0].second);
    ll c1 = prime_fac_a[0].second / g;
    ll c2 = prime_fac_b[0].second / g;
    int n = prime_fac_b.size();
    for (int i = 1; i < n; i++)
    {
        if (prime_fac_a[i].first != prime_fac_b[i].first)
        {
            cout << "NO \n";
            return;
        }
        ll curr_g = gcd(prime_fac_a[i].second, prime_fac_b[i].second);
        ll curr_c1 = prime_fac_a[i].second / curr_g;
        ll curr_c2 = prime_fac_b[i].second / curr_g;
        if (curr_c1 != c1 || curr_c2 != c2)
        {
            cout << "NO \n";
            return;
        }
    }
    cout << "YES \n";
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        mainSolve();
    }
    return 0;
}

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back               
#define mp make_pair        
#define nline "\n"                         
#define f first                                          
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()   
#define vl vector<ll>         
#define vvl vector<vector<ll>>    
#define vvvl vector<vector<vector<ll>>>          
#ifndef ONLINE_JUDGE    
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<nline;
#else
#define debug(x);  
#endif     
void _print(ll x){cerr<<x;} 
void _print(char x){cerr<<x;} 
void _print(string x){cerr<<x;}     
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";} 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const ll MOD=1e9+7;          
const ll MAX=1000100; 
vector<ll> track(MAX,MOD);
void solve(){
    ll a,b; cin>>a>>b;
    if(track[a]==track[b]){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return;
}                
int main()                                                                                 
{                        
    ios_base::sync_with_stdio(false);                            
    cin.tie(NULL);                            
    #ifndef ONLINE_JUDGE                 
    freopen("input.txt", "r", stdin);                                           
    freopen("output.txt", "w", stdout);  
    freopen("error.txt", "w", stderr);                        
    #endif    
    ll test_cases=1;                   
    cin>>test_cases;
    for(ll i=2;i<MAX;i++){
        ll cur=i;
        while(cur<MAX){
            track[cur]=min(track[cur],i);
            cur*=i;
        }
    }
    while(test_cases--){
        solve();     
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"; 
} 