#include<bits/stdc++.h>
using namespace std;

int const N =1e5+10;

std::vector<int>g[N];

int depth[N],hight[N];

void dfs(int vertex,int parants){
    /**Take action on vertex after entering
     * the vertex
     **/

    for(int &child : g[vertex]){
        /**Take action on child before
         * entering the child node
         **/
    if(child==parants)continue;

        depth[child] = depth[vertex]+1;

        dfs(child,vertex);
        
        /**Take action on child
         * after exiting child node
         **/
        hight[vertex] = max(hight[vertex],hight[child]+1);
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
    dfs(1,0);

    return 0;
}