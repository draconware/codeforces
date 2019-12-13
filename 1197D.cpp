#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

LL dp[300009];
LL arr[300009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	LL k;
	cin>>n>>m>>k;

	for(int i=0;i<n;i++){
		cin>>arr[i];
		dp[i] = max(0LL,arr[i] - k);

		LL sum = arr[i];
		for(int j=i-1;j>=0 && (i-j)<=m;j--){
			dp[i] = max(dp[i],dp[j]+sum-k);
			sum+=arr[j];
		}
		if(i < m){
			dp[i] = max(dp[i],sum - k);
		}
	}

	LL ans=0;
	for(int i=0;i<n;i++){
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
}