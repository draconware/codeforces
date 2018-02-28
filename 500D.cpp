#include<bits/stdc++.h>
using namespace std;

vector<int> G[100009];
pair<pair<int,int>,long long> edges[100009];
long long size[100009];

void dfs(int s,int p){
	size[s] = 1;
	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i];
		if(v!=p){
			dfs(v,s);
			size[s] = size[s] + size[v];
		}
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

	for(int i=0;i<n-1;i++){
		int a,b;
		long long c;
		cin>>a>>b>>c;

		G[a].push_back(b);
		G[b].push_back(a);
		edges[i] = make_pair(make_pair(a,b),c);
	}

	dfs(1,0);
	long long m = n;
	long long total = 0;
	for(int i=0;i<n-1;i++){
		int v = edges[i].first.first;
		int u = edges[i].first.second;
		long long w = edges[i].second;
		long long x = min(size[v],size[u]);
		total = (total + (2*w*x*(m-x)));
	}

	int q;
	cin>>q;

	while(q--){
		int x;
		long long y;
		cin>>x>>y;
		x--;

		long long w = edges[x].second;
		int a = edges[x].first.first;
		int b = edges[x].first.second;
		long long c = min(size[a],size[b]);
		total = total - (2*w*c*(m-c));
		total = total + (2*y*c*(m-c));
		edges[x].second = y;

		long double ans = (long double)total;
		ans = ans*3.0;
		long double d = (long double)n;
		ans = (ans/(d*(d-1)));
		cout.precision(13);
		cout<<ans<<endl;
	}
}