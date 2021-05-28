#include<bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long int 

void display(vector<vector<int>> &grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isitsafe(vector<vector<int>> &grid,int i,int j,int n,vector<vector<bool>> &visited){
    return i>=0 and j>=0 and i<n and j<n and visited[i][j]==false;
}

void KnightTour(vector<vector<int>> &grid, int i,int j,int n,int count,vector<vector<bool> > &visited){
    //Base case
    if(count==n*n-1){
        grid[i][j]=count;
        display(grid,n);
        cout<<"\n\n";
        return;
    }
    if(count>=n*n){
        return;
    }
    int xdir[8]={-2,-2,-1,-1,2,2,1,1};
    int ydir[8]={1,-1,2,-2,1,-1,2,-2};
    visited[i][j]=true;
    grid[i][j]=count;
    for(int k=0;k<8;k++){
        if(isitsafe(grid,i+xdir[k],j+ydir[k],n,visited)){
            KnightTour(grid,i+xdir[k],j+ydir[k],n,count+1,visited);
        }
    }
    grid[i][j]=-1;
    visited[i][j]=false;
}

int main(){
    ios::sync_with_stdio(0);   
    cin.tie(0);   



    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;cin>>n;
    vector<vector<int> > grid(n,vector<int> (n,-1));
    vector<vector<bool> > visited(n,vector<bool> (n,false));

    KnightTour(grid,0,0,n,0,visited);
    
    return 0;
}
   
