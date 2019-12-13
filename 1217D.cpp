#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int vis[5009];
int res[5009];
bool flag=false;
vector<pii> G[5009];

void dfs(int s){
	vis[s] = 1;
	for(int i=0;i<(int)G[s].size();i++){
		int u = G[s][i].ff;
		int idx = G[s][i].ss;
		if(vis[u]==0){
			res[idx] = 1;
			dfs(u);
		}else if(vis[u]==1){
			res[idx] = 2;
			flag=true;
		}else{
			res[idx] = 1;
		}
	}
	vis[s] = 2;
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

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;

		G[x].pb(mp(y,i));
	}

	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
		}
	}

	if(flag){cout<<"2"<<endl;}
	else{cout<<"1"<<endl;}

	for(int i=0;i<m;i++){cout<<res[i]<<" ";}cout<<endl;
}