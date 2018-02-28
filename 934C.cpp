#include<bits/stdc++.h>
using namespace std;

int arr[2009];
int dp[2009][4];

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

	for(int i=0;i<n;i++){cin>>arr[i];}

	if(arr[0] == 1){
		dp[0][0] = 1;
		dp[0][2] = 1;
	}else{
		dp[0][1] = 1;
		dp[0][3] = 1;
	}

	for(int i=1;i<n;i++){
		if(arr[i] == 1){
			dp[i][0] = dp[i-1][0]+1;
			dp[i][1] = dp[i-1][1];
			dp[i][2] = max(dp[i-1][2]+1,dp[i-1][1]+1);
			dp[i][3] = dp[i-1][3];
		}else{
			dp[i][0] = dp[i-1][0];
			dp[i][1] = max(dp[i-1][0]+1,dp[i-1][1]+1);
			dp[i][2] = dp[i-1][2];
			dp[i][3] = max(dp[i-1][3]+1,dp[i-1][2]+1);
		}
	}
	int ans = max(dp[n-1][0],max(dp[n-1][1],max(dp[n-1][3],dp[n-1][2])));
	cout<<ans<<endl;
}