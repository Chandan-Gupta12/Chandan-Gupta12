#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define loop(i,a,b) for(int i=a;i<b;i++)
#define N 101

int ar[N][N],I[N][N];
void mul(int x[][N],int y[][N],int dim){
    int res[dim+1][dim+1];
    loop(i,0,dim) {
        loop(j,0,dim){
            res[i][j]=0;
            loop(k,0,dim){
                res[i][j]+=x[i][k]*y[k][j];
            }
        }
    }
    loop(i,0,dim){
        loop(j,0,dim){
            x[i][j]=res[i][j];
        }
    }
}
void power(int A[][N],int dim,int n){
    loop(i,0,dim){
        loop(j,0,dim){
            if(i==j) I[i][j]=1;
            else I[i][j]=0;
        }
    }
    while(n){
        if(n%2){
            mul(I,A,dim);
            n--;
        }
        else{
            mul(A,A,dim);
            n=n/2;
        }
    }
    // loop(i,0,n){
    //     mul(I,A,dim);
    // }
     loop(i,0,dim){
        loop(j,0,dim){
           A[i][j]=I[i][j];
    }
}
}

void printmat(int A[][N],int dim){
    loop(i,0,dim){
        loop(j,0,dim){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    ios::sync_with_stdio(false);   
    cin.tie(NULL);   



    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
     
    int t,dim,n;
    cin>>t;
    while(t--){
        cin>>dim>>n;
        loop(i,0,dim){
            loop(j,0,dim){
                cin>>ar[i][j];
            }
        }
        power(ar,dim,n);
        printmat(ar,dim);
    }
    return 0;
}
