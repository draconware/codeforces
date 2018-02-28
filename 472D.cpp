#include<bits/stdc++.h>
using namespace std;

int parent[2009];
vector<pair<int,int> > G[2009];
bool mark[2009];
int dist[2009][2009];

int root(int x){
	while(x != parent[x]){
		x = parent[x];
	}
	return x;
}

void dfs(int s,int distance,int r){
	mark[s]=true;
	dist[r][s]=distance;
	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i].first,w = G[s][i].second;
		if(!mark[v]){dfs(v,distance+w,r);}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d", &arr[i][j]);
		}
	} 

	vector<pair<int,pair<int,int> > > edges;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			edges.push_back(make_pair(arr[i][j],make_pair(i,j)));
		}
	}
	sort(edges.begin(),edges.end());
	for(int i=1;i<=n;i++){parent[i]=i;}
	int k=1;
	for(int i=0;i<(int)edges.size() && k<n;i++){
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int x = root(u);
		int y = root(v);
		//cout<<u<<","<<v<<" "<<x<<","<<y<<endl;
		if(x!=y){
			parent[max(x,y)]=min(x,y);
			G[u].push_back(make_pair(v,edges[i].first));
			G[v].push_back(make_pair(u,edges[i].first));
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		memset(mark,0,sizeof(mark));
		dfs(i,0,i);
	}

	bool flag=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arr[i][j]!=dist[i][j]){flag=false;}
			if(i!=j && arr[i][j]==0){flag=false;}
			//cout<<dist[i][j]<<" ";
		}
		//cout<<endl;
	}
	if(flag){printf("YES\n");}
	else{printf("NO\n");}
}