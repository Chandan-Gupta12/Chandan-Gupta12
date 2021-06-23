#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define loop(i,a,b) for(auto i=a;i<=b;++i)
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define all(v)  v.begin(),v.end()

int ph[1000001];
void init(int mxn,int n){  //Using Sieve More efficient.
    loop(i,1,1000000)
    ph[i]=i;

    for(int i=2;i<=mxn;i++){
        if(ph[i]==i){
            for(int j=i;j<=mxn;j+=i){
                ph[j]/=i;
                ph[j]*=(i-1);
            }
        }
    }
    cout<<ph[n]<<endl;
}

int phi(int n){
    int res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res=res/i;
            res=res*(i-1);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n>1){
      res=res/n;
      res*=(n-1);
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   
//Algorithm for Euler totient Function.

    int n;
    cin>>n;
    init(1000001,n);
    cout<<phi(n)<<endl;
return 0;
}
//Time complexity O(sqrt(n))
