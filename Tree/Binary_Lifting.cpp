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

// node1 - - - 2 ^ (x-1) - - - node2 - - - 2 ^ (x-1) - - - node3
// node1 - - - 2 ^ x - - - node3
  
vector<vector<int>> dp(N, vector<int>(21));

vector<int>g[N];

void dfs(int vertex, int parent){
  
     dp[vertex][0] = parent;
     
    for (int i = 1; i < 21; i++) {
        dp[vertex][i] = dp[dp[vertex][i-1]][i-1];
    }

    for(int &child : g[vertex]){
         if(child == parent)continue;
         
        dfs(child, vertex);
    }
  
}
int k_th_ancestor(int node, int k){
     for(int i = 20 ; i>=0;i--){
            if((k>>i) & 1){
                node = dp[node][i];
            }
        }
       return node;
}





void siuuuuu(){
      
          int n;
      cin>>n;
      
      for(int i = 0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
      }  
      
      
      dfs(1, 0);
      
      int q;
      cin>>q;
      
      while(q--){
        int node, k;
        cin>>node>>k;
        
        cout<<k_th_ancestor(node, k)<<endl;;
       
        
      }
        
       
       







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
    cin>>tt;  

   for(int i=1;i<=tt;i++){
        
    //cout<<"Case "<<i<<": ";
        
        siuuuuu();          
    }
  
    return 0;
}