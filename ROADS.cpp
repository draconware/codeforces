#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<pair<int,pair<int,int> > > v[109];
int val[109],lim[109];

int dp(int i,int k){
	if(i==n && k>=0){return 0;}
	if(k<0){return INT_MAX;}
	if(lim[i] <= t){return val[i];}

	for(int j=0;j<v[i].size();j++){
		int x = dp(v[i][j].first , k-v[i][j].second.first);
		if(x!=INT_MAX && val[i]<=x){
			val[i]=x;
			lim[i]=min(lim[i],k-v[i][j].second.first);
		}
	}
	return val[i];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int t;
	cin>>t;

	while(t--){
		for(int i=0;i<109;i++){v[i].clear();val[i]=INT_MAX;lim[i]=INT_MAX;}
		int r,x,y,z,w;
		cin>>n>>k>>r;

		for(int i=0;i<r;i++){
			cin>>x>>y>>z>>w;
			v[x].push_back(make_pair(y,make_pair(z,w)));
		}
		int ans=dp(1,k);
		if(ans != INT_MAX){cout<<ans<<endl;}
		else{cout<<ans<<endl;}
	}
}