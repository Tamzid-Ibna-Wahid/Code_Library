#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
 // binomial coefficient O(r)
int nCr(int n, int r) {
    int sum = 1;
    for (int i = 1; i <= r; i++) {
        sum = sum * (n - r + i);
        sum /= i;
    }
    return sum;
}

int main(){


    
    return 0;
}