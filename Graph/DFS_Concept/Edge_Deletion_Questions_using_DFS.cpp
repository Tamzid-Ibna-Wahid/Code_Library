
/** tree er ekta edge remove korte hobe jate
 * 2 ta tree toiri hoy and 2 tar sum er gunfol maximum hoy
 * */

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

std::vector<int> g[N];
int subtre_sum[N];
int val[N];

void dfs(int vertex,int p){

    subtre_sum[vertex]+=val[vertex];
    
    for(auto &child : g[vertex]){
        if(child==p)continue;
        dfs(child,vertex);
        subtre_sum[vertex]+=subtre_sum[child];
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

    dfs(1,0);


  int ans=0;

  for(int i=2;i<=n;i++){            //1 holo root tai 2 theke suru korsi
    int part1 = subtre_sum[i];
    int part2 = subtre_sum[1] - subtre_sum[i];
    ans = max(ans,part1*part2);
  }



    return 0;
}