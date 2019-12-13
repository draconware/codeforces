#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

vector<int> G[200009];

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

	vector<int> v;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.pb(x);
	}

	for(int i=0;i<n;i++){
		int val = v[i];
		int cnt=0;
		while(val>0){
			G[val].pb(cnt);
			val/=2;cnt++;
		}
		G[val].pb(cnt);
	}

	for(int i=0;i<=200000;i++){
		sort(G[i].begin(),G[i].end());
	}

	int ans = INT_MAX;

	for(int i=0;i<=200000;i++){
		if((int)G[i].size() >= k){
			int res=0;
			for(int j=0;j<k;j++){
				res+=G[i][j];
			}
			ans = min(ans,res);
		}
	}
	cout<<ans<<endl;
}