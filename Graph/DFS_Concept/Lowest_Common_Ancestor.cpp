#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

std::vector<int> g[N];
int par[N];

void dfs(int vertex,int p){
    par[vertex]=p;
    for(auto &child : g[vertex]){
        if(child==p)continue;
        dfs(child,vertex);
    }
}

vector<int> path(int v){
    vector<int>ans;
    while(v!=-1){
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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

    dfs(1,-1);


  // ei 2 tar lca find kora lagbe
  int x,y;
  cin>>x>>y;

  vector<int> path_x = path(x);
  vector<int> path_y = path(y);

  int mn_ln = min(path_x.size(),path_y.size());

  int lca = -1;

  for(int i=0;i<mn_ln;i++){
    if(path_x[i]==path_y[i]){
        lca = path_x[i];
    }
    else break;
  }
  cout<<lca<<endl;
  
  
  // for more optimization learn binary uplifting


    return 0;
}