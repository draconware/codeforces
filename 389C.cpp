#include<bits/stdc++.h>
using namespace std;

vector<int> G[100009];
bool mark[100009];
int color[100009];
int val[100009];

void dfs(int s,int p){
	if(color[s]==1){val[s]=1;}
	for(int i=0;i<G[s].size();i++){
		if(G[s][i]!=p){dfs(G[s][i],s);val[s]+=val[G[s][i]];}
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

	int n;
	cin>>n;

	memset(color,0,sizeof(color));
	for(int i=0;i<n-1;i++){
		int x,y,z;cin>>x>>y>>z;
		G[x].push_back(y);
		G[y].push_back(x);
		if(z==2){color[x]=1;color[y]=1;}
	}
	memset(val,0,sizeof(val));
	dfs(1,-1);

	vector<int> res;
	for(int i=1;i<=n;i++){
		if(color[i]==1 && val[i]==1){res.push_back(i);}
	}
	cout<<res.size()<<endl;
	if(res.size()>0){
		for(int i=0;i<res.size();i++){cout<<res[i]<<" ";}cout<<endl;
	}
}