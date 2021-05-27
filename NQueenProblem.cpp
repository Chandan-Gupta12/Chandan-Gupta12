#include<bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long int 


bool isitsafe(vector<vector<bool>> grid,int row,int col,int n){
    for(int i=row-1;i>=0;i--){   //column check
        if(grid[i][col]) return false;
    }
    for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--){ //left upper diagonal
        if(grid[i][j]) return false;
    }
    for(int i=row-1,j=col+1;i>=0 and j<n;i--,j++){ //right upper diagonal
        if(grid[i][j]) return false;
    }
    return true;
}

void display(vector<vector<bool>> &grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]){
                cout<<" Q ";
            }
            else{
                cout<<".  ";
            }
        }
        cout<<endl;
    }
}

int queencount=0;
void countNQueen(vector<vector<bool>> &grid,int curr_row,int n){
    //Base case
    if(curr_row==n){
        queencount++;
        display(grid,n);
        cout<<"\n\n";
        return;

    }
    for(int i=0;i<n;i++){
        if(isitsafe(grid,curr_row,i,n)){
            grid[curr_row][i]=true;
            countNQueen(grid,curr_row+1,n);
            grid[curr_row][i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);   
    cin.tie(0);   



    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;cin>>n;
    vector<vector<bool> > grid(n,vector<bool> (n,false));
    countNQueen(grid,0,n);
    cout<<queencount<<endl;
    
    return 0;
}
   
