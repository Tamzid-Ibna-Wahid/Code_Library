#ifndef Siuuu
#define Siuuu

// Standard Headers
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;  // less ,less_equal , greater, greater_equal, cmp, *a.find_by_order() , order_of_key()
typedef long long ll;
typedef long l;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;
#define endl "\n"
#define vin vector<int>
#define pr pair<int, int>
#define REPn(i,n) for(ll i = 0; i < n; i++) 
#define REPsn(i,s,n) for(ll i = s; i <= n; i++)
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define int long long
#define em emplace_back
#define mp make_pair 
#define pb push_back 
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size()) 
#define INF 2000000000000000000

// Debugging Macros (Disabled in Online Judge)
#ifndef ONLINE_JUDGE
    #define deb(x) cerr << #x << " = "; _print(x); cerr << endl;

    // void _print(int t) { cerr << t; }
    void _print(long long t) { cerr << t; }
    void _print(unsigned long long t) { cerr << t; }
    void _print(float t) { cerr << t; }
    void _print(double t) { cerr << t; }
    void _print(long double t) { cerr << t; }
    void _print(char t) { cerr << t; }
    void _print(const string& t) { cerr << t; }
    void _print(bool t) { cerr << (t ? "true" : "false"); }

    template <class T, class V>
    void _print(const pair<T, V>& p) {
        cerr << "{";
        _print(p.first);
        cerr << ", ";
        _print(p.second);
        cerr << "}";
    }

    template <class T>
    void _print(const vector<T>& v) {
        cerr << "[ ";
        for (const T& i : v) {
            _print(i);
            cerr << " ";
        }
        cerr << "]";
    }

    template <class T>
    void _print(const set<T>& v) {
        cerr << "{ ";
        for (const T& i : v) {
            _print(i);
            cerr << " ";
        }
        cerr << "}";
    }

    template <class T>
    void _print(const multiset<T>& v) {
        cerr << "{ ";
        for (const T& i : v) {
            _print(i);
            cerr << " ";
        }
        cerr << "}";
    }

    template <class T, class V>
    void _print(const map<T, V>& v) {
        cerr << "{ ";
        for (const auto& i : v) {
            _print(i);
            cerr << " ";
        }
        cerr << "}";
    }

    template <class T>
    void _print(const unordered_set<T>& v) {
        cerr << "{ ";
        for (const T& i : v) {
            _print(i);
            cerr << " ";
        }
        cerr << "}";
    }

    template <class T, class V>
    void _print(const unordered_map<T, V>& v) {
        cerr << "{ ";
        for (const auto& i : v) {
            _print(i);
            cerr << " ";
        }
        cerr << "}";
    }
#else
    #define deb(x) // Disabled in Online Judge
#endif

#endif 
