#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL MAX = (LL)(1e14);

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m,k;
	cin>>n>>m>>k;

	int c[n+1];
	for(int i=1;i<=n;i++){cin>>c[i];}

	LL cost[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>cost[i][j];
		}
	}
	LL dp[n+1][k+1][m+1];
	for(int x=0;x<=n;x++){
		for(int y=0;y<=k;y++){
			for(int z=0;z<=m;z++){
				dp[x][y][z]=MAX;
			}
		}
	}
	if(c[1]==0){
		for(int x=1;x<=m;x++){
			dp[1][1][x] = cost[1][x];
		}
	}else{
		dp[1][1][c[1]]=0;
	}
	for(int x=2;x<=n;x++){
		for(int y=1;y<=k;y++){
			if(c[x]==0){
				for(int z=1;z<=m;z++){
					dp[x][y][z] = min(dp[x][y][z],dp[x-1][y][z]+cost[x][z]);
					//if(x==2 && y==1 && z==2){cout<<dp[x][y][z]<<" ";}
					for(int i=1;i<=m;i++){
						if(z!=i){dp[x][y][z]=min(dp[x][y][z],dp[x-1][y-1][i]+cost[x][z]);}
						//if(x==2 && y==1 && z==2){cout<<dp[x][y][z]<<" ";}
					}
					//if(x==2 && y==1 && z==2){cout<<endl;}
				}
			}else{
				dp[x][y][c[x]]=min(dp[x][y][c[x]],dp[x-1][y][c[x]]);
				for(int i=1;i<=m;i++){
					if(c[x]!=i){dp[x][y][c[x]]=min(dp[x][y][c[x]],dp[x-1][y-1][i]);}
				}
				//cout<<x<<","<<y<<","<<c[x]<<" "<<dp[x][y][c[x]]<<endl;
			}
		}
	}
	LL ans=MAX;
	for(int i=1;i<=m;i++){
		ans = min(ans,dp[n][k][i]);
	}
	if(ans>=MAX){cout<<"-1"<<endl;}
	else{cout<<ans<<endl;}
}