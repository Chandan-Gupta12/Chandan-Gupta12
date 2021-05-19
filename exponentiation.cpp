#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

int power(int x,int y){
  if(y==0) return 1;
  if(y==1) return x;
  int k=power(x,y/2);
  if(y%2==0){
    return k*k;
  }
  else{
    return x*k*k;
  }
}


int main(){
    
    int x,y;
    cin>>x>>y;
    cout<<power(x,y);
  
     
    return 0;
}
