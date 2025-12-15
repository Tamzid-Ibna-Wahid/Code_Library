#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

const ll mod = 1e9+7;
const int N = 1e5+10;
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

int inverse[N];
int dp[N];

// o(str_size)
void compute(string str){
    int p = 31;
    int p_power = 1;
    inverse[0] = 1;
    dp[0] = (str[0] - 'a' + 1);

    for(int i=1;i<str.size();i++){
        char ch = str[i];

        p_power = (p_power * p) % mod;
        inverse[i] = inv(p_power);
        dp[i] = (dp[i-1] + (ch - 'a' + 1) * p_power) % mod;
    }
}
int substringHash(int l,int r){
    int result = dp[r];
    if (l > 0) result = (result - dp[l-1] + mod) % mod;
    result = (result * inverse[l]) % mod;
    return result;
}

signed main() {
   
   string str;
   cin>>str;

   compute(str);

    int l,r;
    cin>>l>>r;

    cout<<substringHash(l,r);

    return 0;
}
