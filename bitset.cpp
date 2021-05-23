#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void subsets(string s,int i,int n,string osf){     //getting all substring of a string.
    if(i==n){
        cout<<osf<<endl;
        return;
    }
    subsets(s,i+1,n,osf+s[i]);
    subsets(s,i+1,n,osf);
}
bool palin(string s,int l,int r){  //to check if string is palindrome or not.
    if(l>=r) {return true;}

    if(s[l]!=s[r]){return false;}
    // return false;
    palin(s,l+1,r-1);
}

int squareroot(int *a,int n){ //square root of number via binary search.
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
int staircase(int n,int i){  //N-staircase problem i.e you are on 0 stair and want to reach nth stair and can take on 1 ,2 ,3 jump to reach destination .count possible number of ways to reach there.
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
