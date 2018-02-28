#include<bits/stdc++.h>
using namespace std;

vector<int> G[300009];
bool mark[300009];
bool vis[300009];
int parent[300009];
int maxi,maxi_idx;

int root(int x){
	while(x!=parent[x]){
		x = parent[x];
	}
	return x;
}

void dfs(int s,int pos,int val){
	mark[s]=true;
	if(pos>maxi){maxi = pos;maxi_idx=s;}
	parent[s]=val;
	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i];
		if(!mark[v]){dfs(v,pos+1,val);}
	}
}

void dfs1(int s,int pos){
	vis[s]=true;
	//level2[s]=pos;
	maxi = max(pos,maxi);

	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i];
		if(!vis[v]){dfs1(v,pos+1);}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m,q;
	scanf("%d %d %d", &n, &m, &q);
	int max_dist[n+1];

	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d %d", &a, &b);

		G[a].push_back(b);
		G[b].push_back(a);
	}
	memset(mark,0,sizeof(mark));
	memset(vis,0,sizeof(vis));
	memset(max_dist,0,sizeof(max_dist));

	int c=1;
	for(int i=1;i<=n;i++){
		if(!mark[i]){
			maxi=-1;maxi_idx=-1;
			dfs(i,0,i);
			//cout<<maxi<<" ";
			maxi=-1;
			dfs1(maxi_idx,0);
			//cout<<maxi<<endl;
			max_dist[i]=maxi;
		}
	}

	while(q--){
		int type;
		scanf("%d", &type);

		if(type==1){
			int x;
			scanf("%d", &x);

			int u = root(x);
			printf("%d\n",max_dist[u]);
		}else{
			//cout<<"----- ";
			int x,y;
			cin>>x>>y;

			int x1 = root(x);
			int y1 = root(y);
			if(x1 != y1){
				maxi = max(max_dist[x1],max_dist[y1]);
				maxi = max(maxi,(int)(ceil((float)max_dist[x1]/2.0))+(int)(ceil((float)max_dist[y1]/2.0))+1);
				int mini = min(parent[x1],parent[y1]);
				parent[x1] = parent[y1] = mini;
				max_dist[parent[x1]] = maxi;
			}
		}
	}
}