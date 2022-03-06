#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define loop(i,a,b) for(auto i=a;i<=b;++i)
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define ss second
#define ff first
#define sz size()

void bfs(int node,vector<int> &visi,vector<vector<int>> &graph){
	queue<int> q;
	vector<int> ans;
	q.push(node);
	while(!q.empty()){
		int curr=q.front();
		visi[node]=1;
		q.pop();
		ans.pb(curr);
		for(auto neighbour:graph[node]){
			if(!visi[neighbour]){
				q.push(neighbour);
				visi[neighbour]=1;
			}
		}
	}
}
void dfs(int node,vector<int> &visi,vector<int> &storedfs,vector<vector<int>> &graph){
	storedfs.pb(node);
	visi[node]=1;
	for(auto neighbour:graph[node]){
		if(!visi[neighbour]){
			dfs(neighbour,visi,storedfs,graph);
		} 
	}
}
//Code for detection of cycle in a graph using bfs.
bool detectcycle(int node,vector<vector<int>> &graph,vector<int> &visited){
	queue<pair<int,int>> q;
	q.push({node,-1});
	visited[node]=1;
	while(!q.empty()){
		int curr_node=q.front().ff;
		int prev_node=q.front().ss;//prev_node=parent node.
		q.pop();
		for(auto neighbour:graph[curr_node]){
			if(!visited[neighbour]){
				q.push({neighbour,curr_node});
				visited[neighbour]=1;
			}
			else if(prev_node!=neighbour){
				return true;
			}
//why true when neighbour is not be equal to previous node?
//prev_node is already visited.it means if current node  				
//is marked visited therefore it should be coming from previous node
//but it is not .Hence it means that it is marked visited from
//some other direction. cycle exist.
		}
	}
	return false;
}
//code for detection of cycle in graph using dfs.
bool detectcycledfs(int node,int parent ,vector<vector<int>> &graph,vector<int>&visited){
	visited[node]=1;
	for(auto neighbours:graph[node]){
		if(!visited[neighbours]){
			if(detectcycledfs(neighbours,node,graph,visited)){
				return true;
			}
		}
		else if(parent!=neighbours){
			return true;
		}
	}
	return false;
}
//Bipartite Graph-A graph coloured using two colors and having no two adjacents
//nodes coloured with same colour.
//Cecking for bipprtite using bfs.
bool checkbipartite(int node,vector<vector<int>> &graph,vector<int> &color){
	queue<int> q;
	q.push(node);
	color[node]=1;
	while(!q.empty()){
		int curr_node=q.front();
		q.pop();
		for(auto neighbour:graph[node]){
			if(color[neighbour]==-1){
				color[neighbour]=1-color[node];
				q.push(neighbour);
			}
			else if(color[curr_node]==color[neighbour]){
				return false;
			}
		}
	}
}
//Bipartite graph-using dfs.
bool bipartitedfs(int node,vector<int> &color,vector<vector<int>> &graph){
	if(color[node]==-1)
		color[node]=1;
	for(auto neighbour:graph[node]){
		if(color[neighbour]==-1){
			color[neighbour]=1-color[node];
			if(!bipartitedfs(neighbour,color,graph)){
				return false;
			}
		}
		else if(color[neighbour]==color[node]){
			return false;
		}
	}
	return true;
}
//code for cycle detection in an directed graph using dfs.
bool cycledirected(int node,vector<int> &visi,vector<vector<int>> &graph,vector<int> &dfsvisi){
	visi[node]=1;
	dfsvisi[node]=1;
	for(auto neighbour:graph[node]){
		if(!visi[neighbour]){
			if(cycledirected(neighbour,visi,graph,dfsvisi)) return true;
		}
		else if(dfsvisi[neighbour]){//dfsvisi[neighbour] and visi[neighbour] both are 1.
			return true;
		}
	}
	dfsvisi[node]=0;
	return false;
}
//Topographical Node-Linear ordering of vertices in such a way that
//if there is an edge u->v,then u appears before v in that ordering.
//toposort using dfs.
void toposortdfs(int node,vector<int> &visi,stack<int> &st,vector<vector<int>> &graph){
	visi[node]=1;
	for(auto neighbour:graph[node]){
		if(!visi[neighbour]){
			toposortdfs(neighbour,visi,st,graph);
		}
	}
	st.push(node);
	//empty the stack and u will get a topographical order.
}
//Topographical sort using bfs.Also called kahn's algorithm.
void toposortbfs(int n,vector<vector<int>>&graph){
	queue<int> q;
	vector<int> indegree(n+1,0);//n is number of vertices.
	for(int i=1;i<=n;i++){
		for(auto neighbour:graph[i]){
			indegree[neighbour]++;
		}
	}
	vector<int> topo;
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int curr_node=q.front();
		q.pop();
		topo.pb(curr_node);
		for(auto neighbour:graph[curr_node]){
			indegree[neighbour]--;
			if(indegree[neighbour]==0){
				q.push(neighbour);
			}
		}
	}
	//answer is in topo.
}
//cycle detection in directed graph using bfs.kahn's algorithm.
//For cyclic directed graph topographical sort is not possible.
//Intuition here is to check topographical sort vector length 
//if length is less than number of vertices than their is a cycle.
bool cycledetectionbfs(int n,vector<vector<int>>&graph){
	queue<int> q;
	vector<int> indegree(n+1,0);//n is number of vertices.
	for(int i=1;i<=n;i++){
		for(auto neighbour:graph[i]){
			indegree[neighbour]++;
		}
	}
	vector<int> topo;
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int curr_node=q.front();
		q.pop();
		topo.pb(curr_node);
		for(auto neighbour:graph[curr_node]){
			indegree[neighbour]--;
			if(indegree[neighbour]==0){
				q.push(neighbour);
			}
		}
	}
	if(topo.sz==n) return false;
	return true;
}
//shortest distance between two nodes in an undirected graph.
int distancenodes(int src,vector<int> &disi,vector<vector<int>> &graph){
	disi[src]=0;//dist is filled with infinity.
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int curr_node=q.front();
		q.pop();
		for(auto neighbour:graph[curr_node]){
			if(disi[curr_node]+1<disi[neighbour]){
				q.push(neighbour);
				disi[neighbour]=1+disi[curr_node];
			}
		}
	}
	for(auto x:disi){
		cout<<x<<" ";
	}
}
//shortest path in acyclic directed weighted graph.
int shortestpath(int src,vector<vector<pair<int,int>>> &graph,int n){
	vector<int> visi(n+1,0);
	stack<int> st;
	for(int i=1;i<=n;i++){
		if(!visi[i]){
			toposortdfs(i,visi,st,graph);
		}
	}
	vector<int> dis(n+1,INT_MAX);
	dis[src]=0;
	while(!st.empty()){
		int curr_node=st.top();
		st.pop();
		if(dis[curr_node]!=INT_MAX){
			for(auto neighbour:graph[curr_node]){
				if(dis[curr_node]+neighbour.ss<dis[neighbour.ff]){
					dis[neighbour.ff]=dis[curr_node]+neighbour.ss;
				}
			}
		}
	}
	for(auto x:dis){
		cout<<(x==INT_MAX)?"can't reach":x;
		cout<<" ";
	}
	cout<<endl;
} 
//Dijkstra's Algorithm-Shortest distance via priority queue
int Dijstraalgo(int src,int n,vector<vector<pair<int,int>>> &graph,int n){
	vector<int> disi(n+1,INT_MAX);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> > pq;
	//pair-{distance,Node}
	disi[src]=0;
	pq.push({0,src});
	while(!pq.empty()){
		int curr_dis=pq.top().ff;
		int curr_node=pq.top().ss;
		pq.pop();
		for(auto neighbour:graph[curr_node]){
			if(neighbour.ss+disi[curr_node]<disi[neighbour.ff]){
				disi[neighbour.ff]=neighbour.ss+disi[curr_node];
				pq.push({disi[neighbour.ff],neighbour.ff});
			}
		}
	}
	for(auto x:disi){
		cout<<x<<" ";
	}
}
//Minimum spanning tree.(MST)
//Spanning tree-A tree which has exactly n nodes and n-1 edges and
//every node can be reached from any other node.
//Minimum-Minimum implies spanning tree with minimum weight.
//Prims algorithm is used for mst.
//brute-force for prims algorithm.
void mstbf(vector<vector<int>> &graph,int n){
	vi key(n,INT_MAX);
	vi mst(n,false);
	vi parent(n,-1);
	key[0]=0;
	for(int count =0;count <n-1;count++){//MST contains n-1 edges.
		int mini=INT_MAX,u;
		for(int i=0;i<n;i++){
			if(key[i]<mini and mst[i]==false){
				mini=key[i];
				u=i;
			}
		}
		mst[u]=true;
		for(auto neighbour:graph[u]){ 
			int x=neighbour.ff;
			int weight=neighbour.ss;
			if(mst[x]==false and weight<key[x]){
				parent[x]=u;
				key[x]=weight;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<parent[i]<<"-> "<<i;
	}
}
//Efficient prims algorithm.
void mst(vector<vector<int>> &graph,int n){
	vi key(n,INT_MAX);
	vi mst(n,false);
	vi parent(n,-1);
	priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	key[0]=0;//key implies minimum weight.
	parent[0]=-1;
	pq.push({0,0});//{key value,key index} minimum key will be at the top.
	for(int count =0;count <n-1;i++){//MST contains n-1 edges.
		int u=pq.top().ss;
		pq.pop();
		mst[u]=true;
		for(auto neighbour:graph[u]){ 
			int x=neighbour.ff;
			int weight=neighbour.ss;
			if(mst[x]==false and weight<key[x]){
				parent[x]=u;
				pq.push({key[x],x});
				key[x]=weight;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<parent[i]<<"-> "<<i;
	}
}
//disjoint set union-It contains two function one is findparent and another is union.
void makeset(int n,vector<vector<int>> &graph){
	vector<int> parent(n);
	vector<int> rank(n,0);
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
}
//7->4->6
int findpar(int node,vector<int> &parent){
	if(node==parent[node]){//if node is parent of itself.
		return node;
	}
	return parent[node]=findpar(parent[node],parent);//path compression
}
void unionn(vector<int> &rank,vector<int> &parent,int u,int v){//here we are doing union of a and b
	u=findpar(u);
	v=findpar(v);
	if(rank[u]>rank[v]){
		parent[v]=u;
	}
	else if(rank[v]>rank[u]){
		parent[u]=v;
	}
	else{
		parent[v]=u;//or we can also make parent[u]=v
		rank[u]++;
	}
}
//kruskals algorithm for mst.
//In this we sort all edges according to their weight in increasing order
//let assume an pair  of vector containing {wt,u,v}
void kruskal(int n){
	vector<int> parent(n);
	vector<int> rank(n,0);
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	sort(all(edges));//edges is above vector {wt,u,v}
	vector<pair<int,int>> mst;
	int cost=0;
	for(int i=0;i<edges.size();i++){
		if(findpar(edges[i].ss.ff)!=findpar(edges[i].ss.ss)){
			cost+=edges[i].ff;
			mst.pb({edges[i].ss.ff,edges[i].ss.ss});
			unionn(edges[i].ss.ff,edges[i].ss.ss,rank,parent);
		}
	}
	// print mst
}
void FIO(){
	ios::sync_with_stdio(0);   
    cin.tie(0);   
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int main()
{
	FIO();
	int n,m;cin>>n>>m;
	vector<vector<int>> graph(n+1);
	while(m--){
		int u,v;
		cin>>u>>v;
		graph[u].pb(v);
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(auto x:graph[i]){
	// 		cout<<x<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// vector<int> visi(n+1,0);
	// vector<int> dfsvisi(n+1,-1);
	// int f=0;
	// for(int i=1;i<=n;i++){
	// 	if(visi[i]==0){
	// 		cout<<i<<' ';
	// 		if(cycledirected(i,visi,graph,dfsvisi)){
	// 			f=1;
	// 		}
	// 	}
	// }
	// cout<<endl;
	// for(auto x:visi){
	// 	cout<<x<<" ";
	// }
	// cout<<endl;
	vector<int> dis(n,INT_MAX);
	distancenodes(0,dis,graph);
}
