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

vector<int>g[N];
bool cycle = false;
map<int, int>state;  // 1 - > not visited   2 -> processing    3-> process done
vector<int>parent(N);


void reconstract_path(int cycle_start, int cycle_end){
     vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) cycle.push_back(v);
    cycle.push_back(cycle_start);

        cout <<sz(cycle)<<endl;
        reverse(all(cycle));
        for (int v : cycle) cout << v << " ";   
}



void find_cycle(int vertex){
  
     state[vertex] = 2;

    for(auto &child : g[vertex]){
     
        if(state[child] == 2){
            cycle = true;
            reconstract_path(child, vertex);
            return;
        }
        else if(state[child] == 3)continue;
        parent[child] = vertex;
        find_cycle(child);
        if(cycle)return;
    }
    
     state[vertex] = 3;
  
}



void siuuuuu(){
        
        
       int n, m;
       cin>>n>>m;
       
       for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
       }
       
       for(int i = 1;i<=n;i++){
        if(state[i]>0)continue;
           find_cycle(i);
         if(cycle)return;
       }
       
       if(!cycle){
        cout<<"IMPOSSIBLE";
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
    // cin>>tt;  

   for(int i=1;i<=tt;i++){
        
    //cout<<"Case "<<i<<": ";
        
        siuuuuu();          
    }
  
    return 0;
}