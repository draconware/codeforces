#include<bits/stdc++.h>
using namespace std;

#define LL long long

bool uni[200009];
vector<int> G[200009];
LL child[200009];
bool mark[200009];

LL dfs(int s){
	mark[s]=true;
	LL c = uni[s]?1LL:0LL;

	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i];
		if(!mark[v]){
			c+=dfs(v);
		}
	}
	child[s]=c;
	return c;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,k;
	cin>>n>>k;

	memset(uni,0,sizeof(uni));
	for(int i=0;i<2*k;i++){
		int a;cin>>a;uni[a]=true;
	}
	
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	memset(mark,0,sizeof(mark));
	dfs(1);

	LL ans=0;
	//for(int i=1;i<=n;i++){cout<<child[i]<<" ";}cout<<endl;
	for(int i=1;i<=n;i++){
		ans += min(child[i],2*k-child[i]);
	}
	cout<<ans<<endl;
}