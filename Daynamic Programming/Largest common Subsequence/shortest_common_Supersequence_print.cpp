// #include <bits/stdc++.h> 
// using namespace std;
// typedef long long ll;

// /*
// Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest supersequence exists, print any one of them.

// Examples:

// Input: X = "AGGTAB",  Y = "GXTXAYB"
// Output: "AGXGTXAYB" OR "AGGXTXAYB" 
// OR Any string that represents shortest
// supersequence of X and Y

// Input: X = "HELLO",  Y = "GEEK"
// Output: "GEHEKLLO" OR "GHEEKLLO"
// OR Any string that represents shortest 
// supersequence of X and Y
// */

// int main(){
//     // string x,y;
//     // cin>>x>>y;

//     string x = "AGGTAB";
//     string y = "GXTXAYB";

//     int n = x.size();
//     int m = y.size();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));   //dp[i][j] = for String x of length i and string y of length j longest common subsequence length

//     //base condition = if(i==0 || j==0)dp[i][j]=0;

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(x[i-1]==y[j-1])dp[i][j] = 1 + dp[i-1][j-1];
//             else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//         }
//     }

//      int i = n,j = m;
//     string ans;

//     while(i>0 && j>0){
//         if(x[i-1]==y[j-1]){
//             ans.push_back(x[i-1]);
//             i--;
//             j--;
//         }
//         else{
//             if(dp[i-1][j]>dp[i][j-1]){
//                 ans.push_back(x[i-1]);
//                 i--;
//             }
//             else {
//             ans.push_back(y[j-1]);
//             j--;
//             }
//         }
//     }

//     reverse(ans.begin(),ans.end());
//     cout<<ans<<endl;



//     return 0;
// }