#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

vector<int> mask[60];
vector<int> G[100009];

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

	vector<int> v;
	for(int i=0;i<n;i++){
		LL x;cin>>x;v.pb(x);
	}

	for(int i=0;i<n;i++){
		LL val = v[i];
		for(int j=59;j>=0;j--){
			if(val>=(1LL<<j)){
				val -= (1LL<<j);
				mask[j].pb(i);
			}
		}
	}

	for(int i=0;i<60;i++){
		if((int)mask[i].size() > 2){
			cout<<"3"<<endl;return 0;
		}
	}

	for(int i=0;i<60;i++){
		for(int j=0;j<(int)mask[i].size();j++){
			for(int k=j+1;k<(int)mask[i].size();k++){
				int u = mask[i][j];
				int v = mask[i][k];
				G[u].pb(v);
				G[v].pb(u);
				edges.pb(mp(u,v));
			}
		}
	}

	for(int i=0;i<(int)edges.size();i++){
		for(int j=0;j<n;j++){mark[j]=false;}
		int u = edges[i].ff;
		int v = edges[i].ss;

		dfs(u,v);
	}
}