#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
 const int N = 1e7+10;

bool arr[N]={false};

void sieve(){
     arr[0]=arr[1]=true;
     for(int i=2;i*i < N;i++){      
          if(!arr[i]){ 
               for(int j=i*i;j< N;j+=i){     
                arr[j]=true;                  //false=prime  true=composite
               } 
          }
     }
}


int main(){

    sieve();
   
}

