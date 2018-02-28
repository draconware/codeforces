#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end());
	int a[n],b[n];
	for(int i=0;i<n;i++){
		a[i]=v[i].first;b[i]=v[i].second;//mark[a[i]]=true;
	}

	int dp[1000009],c=1;
	dp[0]=0;
	for(int i=0;i<n;i++){
		int x = a[i];
		for(;c<x;c++){
			dp[c] = dp[c-1];
		}
		if(x-b[i]-1 < 0){
			dp[x] = 1;
		}else{
			dp[x] = dp[x-1-b[i]] + 1;
		}
		c = x+1;
	}
	//for(int i=0;i<=7;i++){cout<<dp[i]<<" ";}cout<<endl;
	int ans=0;
	for(int i=0;i<n;i++){
		ans = max(ans,dp[a[i]]);
	}
	//cout<<ans<<endl;
	cout<<n-ans<<endl;
}