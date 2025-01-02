#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;

int const N =1e5+10;

std::vector<int>g[N];
bool vis[N];

void dfs(int vertex){
    /**Take action on vertex after entering
     * the vertex
     **/
    
    vis[vertex] = true;

    for(int &child : g[vertex]){
        /**Take action on child before
         * entering the child node
         **/
         if(vis[child])continue;
         
        dfs(child);
        /**Take action on child
         * after exiting child node
         **/
    }
    /** Take action on vertex before
     * exiting the vertex
     **/
}



signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }
    return 0;
}