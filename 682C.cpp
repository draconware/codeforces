#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL val[100009],child[100009];
vector<pair<LL,LL> > G[100009];
bool mark[100009];
LL ans=0;

LL dfs1(LL s,LL p){
	mark[s]=true;
	LL c=1;

	for(LL i=0;i<G[s].size();i++){
		LL u = G[s][i].first;
		if(u!=p){c += dfs1(u,s);}
	}
	child[s]=c;
	return c;
}

void dfs2(LL s,LL x){
	mark[s]=true;
	if(x<0){x=0;}
	if(x>val[s]){ans+=child[s];return;}
	for(LL i=0;i<G[s].size();i++){
		int u = G[s][i].first,w = G[s][i].second;
		if(!mark[u]){dfs2(u,x+w);}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	LL n;
	cin>>n;

	for(LL i=1;i<=n;i++){cin>>val[i];}

	for(LL i=1;i<=n-1;i++){
		LL x,y;
		cin>>x>>y;
		G[i+1].push_back(make_pair(x,y));
		G[x].push_back(make_pair(i+1,y));
	}
	memset(child,0,sizeof(child));
	memset(mark,0,sizeof(mark));
	dfs1(1,0);
	//for(int i=1;i<=n;i++){cout<<child[i]<<" ";}cout<<endl;
	memset(mark,0,sizeof(mark));
	dfs2(1,0);
	cout<<ans<<endl;
}