#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define deb(x)
#endif

using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;  // less ,less_equal , greater, greater_equal, cmp, *a.find_by_order() , order_of_key()
typedef long long ll;
typedef long l;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"

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
const ll mod = 1000000007;


ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
int lcm(int a, int b){ if(a*b==0) return 0; else return a*b/__gcd(a,b);}

std::vector<pair<int,int>>knight ={{-1,2}, {1,2}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {-2,-1}, {-2,1}};

const int N = 1e5+10;

vector<pair<int,int>>g[N];

    vector<int>vis(N,0);
    vector<int>dist(N,INF);
    vector<int>parent(N, -1);


void dijkstra(int source){
    
    set<pair<int,int>>st;  //{wt,node}
    st.insert({0,source});
    dist[source] = 0;

    while(st.size() > 0){
        
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());

        if(vis[v])continue;
        vis[v] = 1;

        for(auto child : g[v]){
            int child_v = child.first;
            int wt = child.second;
            
            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                 parent[child_v] = v;   // Update parent for shortest path
                st.insert({dist[child_v],child_v});
            }
            
        }
    }
}

vector<int> reconstruct_path(int target) {
    vector<int> path;
    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}


void siuuuuu(){
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--; y--;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    
    dijkstra(0);
    
    
    if(dist[n-1]==INF)cout<<-1;
    else{
         vector<int> path = reconstruct_path(n-1);
    
    for(auto &it : path)cout<<it+1<<" ";
        
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

// problem link
// https://codeforces.com/problemset/problem/20/C