#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;  // less ,less_equal , greater, greater_equal, cmp, *a.find_by_order() , order_of_key()

typedef long long ll;
typedef long l;
typedef long double ld;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"

#define REPn(i,n) for(ll i = 0; i < n; i++) 
#define REPsn(i,s,n) for(ll i = s; i <= n; i++)

#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define int long long
#define em emplace_back
#define mp make_pair 
#define pb push_back 
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size()) 
#define INF 2000000000000000000
const ll mod = 1000000007;


ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
int lcm(int a, int b){ if(a*b==0) return 0; else return a*b/__gcd(a,b);}

std::vector<pair<int,int>>knight ={{-1,2}, {1,2}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {-2,-1}, {-2,1}};

const int N = 2000010;




void siuuuuu(){

    pbds a;
    
    // inserting element
    a.insert(1);
    a.insert(40);
    a.insert(4);
    a.insert(7);
    a.insert(4);  // order set only contain unique value
    
    // a contains
    
    for(auto &i :a){
        cout<<i<<" ";
    }
    cout<<endl;
    
    
    // finding kth element
    cout<<*a.find_by_order(0)<<endl;
    cout<<*a.find_by_order(1)<<endl;
    cout<<*a.find_by_order(2)<<endl;
    cout<<*a.find_by_order(3)<<endl;
    
    cout<<endl;
    
    // finding the number of element smaller then x
    cout<<a.order_of_key(6)<<endl;
    cout<<a.order_of_key(100)<<endl;
    cout<<a.order_of_key(0)<<endl;
    
    
    // lower bound of x 
    cout<<*a.lower_bound(6)<<endl;
    
    
    // upper bound of x
     // if no upper bound return 0
    cout<<"upper_bound : "<<*a.upper_bound(40)<<endl;
    
    // remove element
    a.erase(6);
    a.erase(23); // element that is not present will not affected
    
    
    
    







}




signed main(){

 #ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
 #endif


     fast_cin();
     cout << fixed;
     cout << setprecision(10);

    int tt;
                tt=1;
    // cin>>tt;  

    while(tt--){

        siuuuuu();          
    }
  


  

    return 0;
}