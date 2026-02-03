/**
 * Given Q Queries Q <= 1e5
 * in each query given V
 * print subtree sum of V & number of even numbers
 * in subtree of V
 * */
#include<bits/stdc++.h>
using namespace std;


const int N = 1e5;
int subtree_sum[N];
int even_cnt[N];
std::vector<int> g[N];

void dfs(int vertex,int parant){

    subtree_sum[vertex]+=vertex;
    // subtree_sum[vertex]+=val[vertex]; // jodi proti node er jonno value deya thakto

    if(vertex%2==0)even_cnt[vertex]++;

    for(int child : g[vertex]){
        if(child==parant)continue;

        dfs(child,vertex);

      // nicher thika calculate kora lagbe tai dfs call korar pore add korsi
        subtree_sum[vertex]+=subtree_sum[child];
        even_cnt[vertex]+=even_cnt[child];
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

dfs(1,0); // call kora lagbe pre compure er jonno

// int q;
// cin>>q;

// while(q--){
//     int v;
//     cin>>v;
//     cout<<subtree_sum[v]<<" "<<even_cnt[v]<<endl;

// }
for(int i=1;i<=n;i++){
    cout<<subtree_sum[i]<<" "<<even_cnt[i]<<endl;
}


    return 0;
}