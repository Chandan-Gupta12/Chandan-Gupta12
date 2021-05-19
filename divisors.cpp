#include<bits/stdc++.h>
using namespace std;

#define ll long long int 



int main(){
    long long n=100005;
    
    vector<long long > v(n+1,0);
    v[0]=1;                      //sieve of eratosthenes
    v[1]=1;
    for(int i=2;i*i<=n;i++){
        if(v[i]==0){
            for(int j=i*i;j<=n;j+=i){
                v[j]=1;
            }
        }
    }
     vector<long long> div(n,1);
     for(int i =2;i<=n;i++){    //precomputation of divisors.
         for(int j=i;j<=n;j+=i){
             div[j]++;
            
     }
     }
     int x;
     cin>>x;
     cout<<v[x];
   
    return 0;
}
