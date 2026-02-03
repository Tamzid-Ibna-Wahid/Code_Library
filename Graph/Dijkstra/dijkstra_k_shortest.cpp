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



const int N = 1e5+10;
 int n, m, k;
 
vector<pair<int,int>> g[N];

void dijkstra_k_shortest(int source) {
    vector<vector<ll>> dist(n + 1, vector<ll>(k, INF));
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

    dist[source][0] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        pair<ll,int> top = pq.top();
        ll d = top.first;
        int u = top.second;
        pq.pop();

        if (dist[u][k - 1] < d) continue;

        for (auto i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            int wt = g[u][i].second;
            ll newDist = d + wt;
            if (newDist < dist[v][k - 1]) {
                dist[v][k - 1] = newDist;
                sort(dist[v].begin(), dist[v].end());
                pq.push({newDist, v});
            }
        }
    }

    // Print 1st to k-th smallest distances to node n
    for (int i = 0; i < k; i++) {
        if (dist[n][i] == INF) cout << -1 << " ";
        else cout << dist[n][i] << " ";
    }
    cout << "\n";
}



void siuuuuu(){
        
        cin>>n>>m>>k;
        
        for(int i = 0;i<m;i++){
            int u, v, w;
            cin>>u>>v>>w;
            g[u].pb({v, w});
        }
        
        dijkstra_k_shortest(1); 
       







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