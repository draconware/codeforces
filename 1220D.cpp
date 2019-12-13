#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

vector<int> G[100];

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

	vector<LL> v;
	for(int i=0;i<n;i++){
		LL x;cin>>x;
		v.pb(x);
	}

	for(int i=0;i<n;i++){
		int p=0;
		LL x=v[i];

		while(x%2 == 0){
			x/=2;
			p++;
		}
		G[p].pb(i);
	}
	// for(int i=0;i<64;i++){
	// 	for(int j=0;j<(int)G[i].size();j++){cout<<G[i][j]<<" ";}cout<<endl;
	// }

	int ans = 0,best = 0;

	for(int i=0;i<64;i++){
		ans = max(ans,(int)G[i].size());
		if(ans == G[i].size()){best = i;}
	}

	cout<<n - ans<<endl;
	vector<bool> mark(n,0);

	for(int i=0;i<(int)G[best].size();i++){mark[G[best][i]] = true;}

	for(int i=0;i<n;i++){
		if(!mark[i]){cout<<v[i]<<" ";}
	}
	cout<<endl;
}