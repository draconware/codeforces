#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m,b,mod;
	cin>>n>>m>>b>>mod;

	int dp[509][509];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;

	int arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}

	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k+arr[i]<=b;k++){
				dp[j][k+arr[i]] = (dp[j][k+arr[i]] + dp[j-1][k])%mod;
			}
		}
	}

	int ans=0;
	for(int i=0;i<=b;i++){
		ans = (ans + dp[m][i])%mod;
	}
	cout<<ans<<endl;
}