#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int dp[n][2],total=0;
	int arr[n];

	for(int i=0;i<n;i++){cin>>arr[i];total+=arr[i];}

	dp[0][0]=arr[0];
	dp[0][1]=0;

	for(int i=1;i<n;i++){
		dp[i][0] = max(dp[i-1][0],arr[i]+dp[i-1][1]);
		dp[i][1] = min(dp[i-1][1]+arr[i],dp[i-1][0]);
	}
	cout<<dp[n-1][0]<<" "<<total-dp[n-1][0]<<endl;
}