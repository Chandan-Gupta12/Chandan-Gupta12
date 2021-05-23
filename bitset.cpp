#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void subsets(string s,int i,int n,string osf){
    if(i==n){
        cout<<osf<<endl;
        return;
    }
    subsets(s,i+1,n,osf+s[i]);
    subsets(s,i+1,n,osf);
}
bool palin(string s,int l,int r){
    if(l>=r) {return true;}

    if(s[l]!=s[r]){return false;}
    // return false;
    palin(s,l+1,r-1);
}

int squareroot(int *a,int n){
    int s=0;
    int l=n-1;
    while(s<=l){
        int mid=(s+l)/2;
        if((a[mid]*a[mid])==n){
            return a[mid];
        }
        else if((a[mid]*a[mid])>n){
            l=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}
int c=0;
int staircase(int n,int i){
    if(i==n){
        c++;
    }
    if(i>n){
        return 0;
    }
    staircase(n,i+1)+staircase(n,i+2);
    return c;

}

int main(){
    ios::sync_with_stdio(0);   
    cin.tie(0);   

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cout<<staircase(4,0);
    
    
    return 0;
}
