#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int h,w;
	cin>>h>>w;

	char arr[h+1][w+1];
	memset(arr,'#',sizeof(arr));

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>arr[i][j];
		}
	}
	int dp[h+1][w+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			if(arr[i][j]=='.'){
				if(arr[i-1][j]=='.'){dp[i][j]++;}
				if(arr[i][j-1]=='.'){dp[i][j]++;}
			}
		}
	}
	int q;
	cin>>q;

	while(q--){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;

		int ans = dp[r2][c2]-dp[r1-1][c2]-dp[r2][c1-1]+dp[r1-1][c1-1];
		for(int i=c1;i<=c2;i++){
			if(arr[r1][i]=='.' && arr[r1-1][i]=='.'){ans--;}
		}
		for(int i=r1;i<=r2;i++){
			if(arr[i][c1]=='.' && arr[i][c1-1]=='.'){ans--;}
		}
		cout<<ans<<endl;
	}
}