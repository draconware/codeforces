#include<bits/stdc++.h>
using namespace std;

set<int> color;
vector<pair<int,int> > G[100009];
set<int> uf[100009];
bool mark[100009];

void dfs(int s,int c){
	mark[s]=true;
	for(int i=0;i<G[s].size();i++){
		int v = G[s][i].first,w = G[s][i].second;
		if(!mark[v] && c==w){
			uf[c].insert(s);uf[c].insert(v);
			dfs(v,c);
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

	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		G[a].push_back(make_pair(b,c));
		G[b].push_back(make_pair(a,c));
		color.insert(c);
	}

	for(set<int>::iterator it = color.begin();it!=color.end();it++){
		memset(mark,0,sizeof(mark));
		for(int i=1;i<=n;i++){
			if(!mark[i]){dfs(i,*it);}
		}
	}

	int q;
	cin>>q;

	while(q--){
		int a,b;cin>>a>>b;

		int ans=0;
		for(set<int>::iterator it = color.begin();it!=color.end();it++){
			if(uf[*it].find(a)!=uf[*it].end() && uf[*it].find(b)!=uf[*it].end()){ans++;}
		}
		cout<<ans<<endl;
	}
}