#include<bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long int 


        
int main(){
    ios::sync_with_stdio(0);   
    cin.tie(0);   



    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 and a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
 return 0; 
    
}
   
