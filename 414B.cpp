#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL M = 1000000007;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	LL n,len;
	cin>>n>>len;

	LL dp[len+9][n+9];
	memset(dp,0,sizeof(dp));
	for(LL i=1;i<=n;i++){
		dp[1][i]=1;
	}
	for(LL i=2;i<=len;i++){
		for(LL j=1;j<=n;j++){
			for(LL k=j;k<=n;k+=j){
				dp[i][k]+=dp[i-1][j];
				dp[i][k]%=M;
			}
		}
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		ans = ans + dp[len][i];
		ans%=M;
	}
	cout<<ans<<endl;
}