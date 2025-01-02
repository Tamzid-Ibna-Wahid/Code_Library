#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int depth[N];
std::vector<int> g[N];

void dfs(int vertex,int parant){

    for(int child : g[vertex]){
        if(child==parant)continue;

        depth[child] = depth[vertex]+1;
        dfs(child,vertex);

  }
}

signed main(){

int n;
cin>>n;

for(int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
}
dfs(1,0);  // 1 ke root dhore sob gular depth ber korsi

int mx_depth=-1;
int max_d_node;

for(int i=1;i<=n;i++){
    if(mx_depth < depth[i]){
        mx_depth = depth[i];
        max_d_node = i;
    }
    /**
     *  0 kore disi
     * karon max_d_node ke root dore abar
     *  dfs call korte hobe
     * */
    depth[i]=0;
}


    dfs(max_d_node,0);
    
    mx_depth=-1;
    for(int i=1;i<=n;i++){
        if(mx_depth < depth[i]){
        mx_depth = depth[i];
        }
    }

    cout<<mx_depth<<endl;   // its the diameter

    return 0;
}