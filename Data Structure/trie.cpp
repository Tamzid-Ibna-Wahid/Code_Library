#ifndef ONLINE_JUDGE
#include "Siuuu.h"
#else
#define deb(x)

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;  // less ,less_equal , greater, greater_equal, cmp, *a.find_by_order() , order_of_key()
typedef long long ll;
typedef long l;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;
#define endl "\n"
#define vint vector<int>
#define vpr vector<pr>
#define vvint vector<vector<int>>
#define pr pair<int, int>
#define REPn(i,n) for(ll i = 0; i < n; i++) 
#define REPsn(i,s,n) for(ll i = s; i <= n; i++)
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define int long long
#define em emplace_back
#define mp make_pair 
#define pb push_back 
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size()) 
#define INF 2000000000000000000
#endif

const ll mod = 1e9 + 7;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
int lcm(int a, int b){ if(a*b==0) return 0; else return a*b/__gcd(a,b);}

std::vector<pair<int,int>>knight ={{-1,2}, {1,2}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {-2,-1}, {-2,1}};

const int N = 5e5 + 10;

struct trieNode{
    ll value;
    trieNode *arr[2];
};

trieNode *newNode(){
    trieNode *temp = new trieNode;
    temp->value = 0;
    temp->arr[0] = NULL;
    temp->arr[1] = NULL;
    return temp;
}

void insert(trieNode *root, ll pre_xor, ll max_bits){
    trieNode *temp = root;
 
    bool val;
    for (ll i=max_bits; i>=0; i--){
        val = pre_xor & (1ll<<i);
 
        if (temp->arr[val] == NULL) temp->arr[val] = newNode();
        temp = temp->arr[val];
    }
 
    temp->value = pre_xor;
}

ll query(trieNode *root, ll pre_xor, ll max_bits){
    trieNode *temp = root;
    
    bool val;
    for (ll i= max_bits; i>=0; i--){
        val = pre_xor & (1ll<<i);
 
        if (temp->arr[!val] != NULL) temp = temp->arr[!val];
        else if (temp->arr[val] != NULL) temp = temp->arr[val];
    }
    
    return pre_xor^(temp->value);
}

ll maxSubarrayXOR(vector<ll>& arr){
    int  n = arr.size();
    int max_val = *max_element(arr.begin(), arr.end());
    
    // int  max_bits = 64 - __builtin_clzll(max_val | 1);
    int max_bits = 32;
    
    
    trieNode *root = newNode();
    insert(root, 0, max_bits);
    ll result = 0, pre_xor =0;
 
    for (ll i=0; i<n; i++){
        pre_xor = pre_xor^arr[i];
        insert(root, pre_xor, max_bits);
        result = max(result, query(root, pre_xor, max_bits));
    }
    
    return result;
}

// https://codeforces.com/blog/entry/123404
// https://www.geeksforgeeks.org/dsa/find-the-maximum-subarray-xor-in-a-given-array/
// https://cses.fi/problemset/task/1655



void siuuuuu(){
        
        // Maximum xor subarray
        
        int n;
        cin>>n;
       
       vint v(n);
       REPn(i,n){
         cin>>v[i];
       }
       
       cout<<maxSubarrayXOR(v)<<endl;

}




signed main(){

 #ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
 #endif


     fast_cin();
     cout << fixed;
     cout << setprecision(10);

    int tt;
                tt=1;
    // cin>>tt;  

   for(int i=1;i<=tt;i++){
        
    //cout<<"Case "<<i<<": ";
        
        siuuuuu();          
    }
  
    return 0;
}