#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<pair<int,LL> > G[200009];
LL arr[2*100009];

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
		int u,v;LL w;
		cin>>u>>v>>w;
		G[u-1].push_back(make_pair(v-1,w));
		G[v-1].push_back(make_pair(u-1,w));
	}

	for(int i=0;i<n;i++){cin>>arr[i];}

	multiset<pair<LL,int> > mul;
	for(int i=0;i<n;i++){
		mul.insert(make_pair(arr[i],i));
	}

	LL res[n];	
	for(int i=0;i<n;i++){res[i] = arr[i];}

	while(!mul.empty()){
		pair<LL,int> p = *mul.begin();mul.erase(mul.begin());

		int u = p.second;
		LL ans = p.first;
		for(int i=0;i<(int)G[u].size();i++){
			int v = G[u][i].first;
			LL w = G[u][i].second;
			if(res[v] > (ans + 2*w)){
				if(mul.find(make_pair(res[v],v)) != mul.end()){
					mul.erase(make_pair(res[v],v));
				}
				res[v] = ans + 2*w;
				mul.insert(make_pair(res[v],v));
			}
		}
	}
	for(int i=0;i<n;i++){cout<<res[i]<<" ";}cout<<endl;
}