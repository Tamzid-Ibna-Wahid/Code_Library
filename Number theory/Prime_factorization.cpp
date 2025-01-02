#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
 const int N = 1e7+10;
vector<int>lp(N,0),hp(N,0);   // 10 => 2(lowest prime) * 5(higest prime)

bool arr[N]={false};
void sieve(){
     arr[0]=arr[1]=true;
     for(int i=2;i< N;i++){      
          if(!arr[i]){ 
            lp[i]=hp[i]=i;
               for(int j=2*i;j< N;j+=i){     
                arr[j]=true;                  //false=prime  true=composite
                hp[j]=i;
                if(lp[j]==0){
                    lp[j]=i;
                }
               } 
          }
     }
}


int main(){

    sieve();
    int num;
    cin>>num;

    vector<int>prime_factors;

    while(num>1){

        int prime_factor = hp[num];  // we can use lp

        while(num% prime_factor==0){
            num /=prime_factor;
            prime_factors.push_back(prime_factor);
        }

    }
    for(int factor : prime_factors){
        cout<<factor<<" ";
    }
}

/*
//count er maddhome korte chaile

   unordered_map<int,int>mp;

    while(num>1){

        int prime_factor = hp[num];  // we can use lp

        while(num% prime_factor==0){
            num /=prime_factor;
           mp[prime_factor]++;
        }

    }
    for(auto it : mp){
        cout<<"Prime "<<it.first<<" count "<<it.second<<endl;
    }

 */