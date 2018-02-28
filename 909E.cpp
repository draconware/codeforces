#include<bits/stdc++.h>
using namespace std;

int type[100009];
vector<int> G[100009];
int indegree[100009];
int lev[100009];
bool vis[100009];

void dfs(int s,int prev_type,int curr_type,int val){
	if(prev_type==0 && curr_type==1){val++;}
	if(lev[s]<val){lev[s]=val;}
	else{
		if(vis[s]){return ;}
	}
	vis[s]=true;

	int len = (int)G[s].size();
	for(int i=0;i<len;i++){
		int v = G[s][i];
		dfs(v,curr_type,type[v],val);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++){
		cin>>type[i];
	}
	memset(indegree,0,sizeof(indegree));
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		G[b].push_back(a);
		indegree[a]++;
	}

	vector<int> v;
	bool flag=false;
	for(int i=0;i<n;i++){
		if(indegree[i]==0){v.push_back(i);if(type[i]==1){flag=true;}}
	}
	memset(vis,0,sizeof(vis));

	int len = (int)v.size();
	for(int i=0;i<len;i++){
		dfs(v[i],0,type[v[i]],0);
	}

	int ans=0;
	for(int i=0;i<n;i++){
		ans = max(ans,lev[i]);
	}
	cout<<ans<<endl;
}