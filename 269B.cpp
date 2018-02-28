#include<bits/stdc++.h>
using namespace std;

int arr[5005];
int dp[5005];

int lis(int n){
	for(int i=1;i<=n;i++){dp[i]=1;}

	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(arr[j]<=arr[i]){dp[i] = max(dp[i],dp[j]+1);}
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){ans = max(ans,dp[i]);}
	return ans;
}

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

	for(int i=1;i<=n;i++){
		double b;
		cin>>arr[i]>>b;
	}

	cout<<n-lis(n)<<endl;
}