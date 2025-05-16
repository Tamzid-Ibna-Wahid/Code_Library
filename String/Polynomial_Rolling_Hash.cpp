#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

const ll mod = 1e9+7;


int getHash(string &str){
    int value = 0;
    int p = 31;    // power should be greater then the charecter set and need to be prime
    int p_power = 1;

    for(auto &ch : str){
        value = (value + (ch - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }
    return value;
}

/*
This is needed for Rabin_karp
*/



signed main() {
   
   string str;
   cin>>str;

   cout<<"string : "<<str<<endl;
   cout<<"Hash Value : "<<getHash(str)<<endl;

    return 0;
}
