#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
int path=0;
void mazepath(int i,int j,int n,int m,string osf){
    if(i==n-1 and j==m-1){
        path++;
        cout<<osf<<endl;
        return;
    }
    if(i>=n or j>=m){
        return;
    }
    mazepath(i,j+1,n,m,osf+"R");
    mazepath(i+1,j,n,m,osf+"D");
    mazepath(i+1,j+1,n,m,osf+"//");//Diagonal
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
int path=0;
void mazepath(int i,int j,int n,int m,string osf){
    if(i==n-1 and j==m-1){
        path++;
        cout<<osf<<endl;
        return;
    }
    if(i>=n or j>=m){
        return;
    }
    mazepath(i,j+1,n,m,osf+"R");
    mazepath(i+1,j,n,m,osf+"D");
    mazepath(i+1,j+1,n,m,osf+"//");//Diagonal
}
void dicepath(int n,int i,string osf){
    if(i==n-1){
        cout<<osf<<endl;
        return;
    }
    if(i>n-1){
        return;
    }
    for (int j =1;j<=6; ++j)
    {
        dicepath(n,i+j,osf+to_string(j)+"-->");
    }
}

int main(){
    ios::sync_with_stdio(0);   
    cin.tie(0);   

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    mazepath(0,0,3,3,"");
    cout<<"Total path="<<path<<"\n";
    dicepath(7,0,"");
    return 0;
}
