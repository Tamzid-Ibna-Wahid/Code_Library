#include <bits/stdc++.h>
using namespace std;
#define int long long

string T, P;
int length_P, length_T;

bool match(int l, int r) {
    for (int i = 0; i < length_P; i++) {
        if (T[l + i] != P[i]) return false; // Fix index here to l+i instead of l+1
    }
    return true;
}

signed main() {
    int t;
    cin >> t;
    cin.ignore(); // To consume the newline character left in the buffer

    while (t--) {
        getline(cin, T);
        getline(cin, P);
        length_P = P.size();
        length_T = T.size();

        // Check for matches
        for (int l = 0, r = length_P - 1; r < length_T; l++, r++) {
            if (match(l, r)) {
                cout << l << " "; // If match the substring, print first index
            }
        }
        cout << endl; // Add newline for each test case
    }

    return 0;
}
