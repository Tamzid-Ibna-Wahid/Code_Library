#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MAXN = 505;   // adjust as needed
const int MAXM = 505;
const int LOGN = 10;    // log2(MAXN)
const int LOGM = 10;    // log2(MAXM)

int st[MAXN][MAXM][LOGN][LOGM];
int lg2N[MAXN+1], lg2M[MAXM+1];

// Precompute logs
void precomputeLogs(int n, int m) {
    lg2N[1] = 0;
    for(int i=2; i<=n; i++) lg2N[i] = lg2N[i/2]+1;
    lg2M[1] = 0;
    for(int j=2; j<=m; j++) lg2M[j] = lg2M[j/2]+1;
}

// Build Sparse Table
void buildST(vector<vector<int>> &a, int n, int m) {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            st[i][j][0][0] = a[i][j];
        }
    }

    for(int kx=0; (1<<kx)<=n; kx++){
        for(int ky=0; (1<<ky)<=m; ky++){
            if(kx==0 && ky==0) continue;

            for(int i=0; i+(1<<kx)-1<n; i++){
                for(int j=0; j+(1<<ky)-1<m; j++){
                    if(kx==0){
                        // extend in y direction
                        st[i][j][kx][ky] = min(
                            st[i][j][kx][ky-1],
                            st[i][j+(1<<(ky-1))][kx][ky-1]
                        );
                    } else if(ky==0){
                        // extend in x direction
                        st[i][j][kx][ky] = min(
                            st[i][j][kx-1][ky],
                            st[i+(1<<(kx-1))][j][kx-1][ky]
                        );
                    } else {
                        // extend in both directions
                        st[i][j][kx][ky] = min(
                            min(st[i][j][kx-1][ky-1], st[i+(1<<(kx-1))][j][kx-1][ky-1]),
                            min(st[i][j+(1<<(ky-1))][kx-1][ky-1], st[i+(1<<(kx-1))][j+(1<<(ky-1))][kx-1][ky-1])
                        );
                    }
                }
            }
        }
    }
}

// Query min in rectangle [x1..x2][y1..y2]
int query(int x1, int y1, int x2, int y2) {
    int kx = lg2N[x2-x1+1];
    int ky = lg2M[y2-y1+1];

    int min1 = min(st[x1][y1][kx][ky],
                   st[x2-(1<<kx)+1][y1][kx][ky]);

    int min2 = min(st[x1][y2-(1<<ky)+1][kx][ky],
                   st[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky]);

    return min(min1, min2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    precomputeLogs(n, m);
    buildST(a, n, m);

    int q;
    cin >> q;
    while(q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2; // 0-based indices
        cout << query(x1,y1,x2,y2) << endl;
    }

    return 0;
}
