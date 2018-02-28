#include<bits/stdc++.h>
using namespace std;

vector<int> v[4009];
int cost[4009];
int best=INT_MAX,x;
bool mark[4009];

void dfs(int s,int c){
	if(c>1){return;}
	for(int i=0;i<(int)v[s].size();i++){
		if(c==1 && mark[v[s][i]]){
			best = min(best,cost[x]+cost[s]+cost[v[s][i]]);
		}else{
			dfs(v[s][i],c+1);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	for(int i=0,x,y;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end());
	}
	for(int i=1;i<=n;i++){cost[i] = (int)v[i].size();}
	memset(mark,0,sizeof(mark));

	for(int i=1;i<=n;i++){
		memset(mark,0,sizeof(mark));
		int size = (int)v[i].size();
		for(int j=0;j<size;j++){mark[v[i][j]]=true;}
		x=i;
		dfs(i,0);
	}
	if(best == INT_MAX){cout<<"-1"<<endl;}
	else{cout<<best-6<<endl;}
}