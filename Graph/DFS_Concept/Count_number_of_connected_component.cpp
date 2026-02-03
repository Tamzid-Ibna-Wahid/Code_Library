
// connect component count and print korte hobe
#include<bits/stdc++.h>
using namespace std;

int const N =1e5+10;

std::vector<int>g[N];
bool vis[N];

vector<vector<int>>cc;
vector<int>current_cc;

void dfs(int vertex){
    /**Take action on vertex after entering
     * the vertex
     **/
    
    vis[vertex] = true;
    current_cc.push_back(vertex);

    for(int &child : g[vertex]){
        /**Take action on child before
         * entering the child node
         **/
         if(vis[child]) continue;
         
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

    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);

    }

    cout<<cc.size()<<endl;   // Number of connected component

    for(auto &c_cc: cc ){
        for(auto &vertex : c_cc){
            cout<<vertex<<" ";
        }
        cout<<endl;
    }






    return 0;
}