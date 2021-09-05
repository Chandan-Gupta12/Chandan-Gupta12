#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define loop(i,a,b) for(auto i=a;i<=b;i++)
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define all(v) v.begin(),v.end()

void printvec(vector<int> &p){
   for(auto x:p){
      cout<<x<<" ";
   }
   cout<<endl;
}

 void print(int n){
   if(n==0){
      return;
   }
   cout<<n<<endl;
   print(n-1);
 } 
void insert(vector<int> &x,int temp){
   if(x.size()==0 or x[x.size()-1]<=temp){
      x.pb(temp);
      return;
   }
   int l=x[x.size()-1];
   x.pop_back();
   insert(x,temp);
   x.pb(l);
}
void sort(vector<int> &v){
   if(v.size()==1){
      return ;
   }
   int ele=v[v.size()-1];
   v.pop_back();
   sort(v);
   insert(v,ele);
}
int main()
{
    ios::sync_with_stdio(0);   
    cin.tie(0);   



    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<int> v(n);
       loop(i,0,n-1){
         cin>>v[i];
       }
       sort(v);
       printvec(v);
    }
   
return 0;   
}
 
