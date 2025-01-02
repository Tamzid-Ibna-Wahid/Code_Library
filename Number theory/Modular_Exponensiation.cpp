#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
// a ^ n % M  =  ((a % M) ^ n) % M
 // calculate a^n % M
int modExp(int a, int n, int M) {
    int res = 1;
     a %= M;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        n >>= 1;
    }
    return res;
}

int main(){
    
    cout<<(2,3,mod);

    return 0;
}