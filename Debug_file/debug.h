#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <utility>
#include <type_traits>

using namespace std;

// Debug Macro
#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

// Overloads for Basic Types
void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(float t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(const string& t) { cerr << t; }
void _print(bool t) { cerr << (t ? "true" : "false"); }

// Overloads for Complex Structures (Template Specializations)
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

#endif // DEBUG_H

// #include<C:\Users\tamzi\Coding\Cpp language\debug.h>