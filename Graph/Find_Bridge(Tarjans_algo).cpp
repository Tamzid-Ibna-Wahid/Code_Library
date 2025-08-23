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


int timer;

void dfs(int node, int parent, vector<int> g[], vector<int>& vis,
    vector<int>& tin, vector<int>& low, vector<pair<int,int>>& bridge){
        
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        for (auto &it : g[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, g, vis, tin, low, bridge);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node]) {
                    bridge.push_back({node, it});  
                }
            } 
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

   



void siuuuuu(){
        
       timer = 0;
       int n, m;
       cin>>n>>m;
       
       vector<int>g[n];
       
       for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
       }
       
       vector<int>vis(n,0), tin(n), low(n);
       vector<pair<int,int>>bridge;
       
       for(int i = 0;i<n;i++){
        if(vis[i])continue;
        dfs(i, -1, g, vis, tin, low, bridge);
       } 
       
       
        cout<<sz(bridge) <<" critical links"<<endl; 

         for(auto &it: bridge){
            cout<<it.fi<<" - "<<it.se<<endl;
        }
        
// Related problem :
// https://lightoj.com/problem/critical-links

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
        
    cout<<"Case "<<i<<": "<<endl;
        
        siuuuuu();          
    }
  
    return 0;
}



