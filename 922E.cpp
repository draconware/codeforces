#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL inf = (LL)(1e15);

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	LL inimana,manacapinc,manainc;
	cin>>n>>inimana>>manacapinc>>manainc;

	int tree[n];
	int total=0;
	for(int i=0;i<n;i++){
		cin>>tree[i];
		total+=tree[i];
	}

	LL cost[n];
	for(int i=0;i<n;i++){
		cin>>cost[i];
	}
	LL dp[total+1][n+1];
	for(int i=0;i<=total;i++){
		for(int j=0;j<n;j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = inimana;
	for(int i=0;i<=total;i++){
		for(int j=0;j<n;j++){
			if(j==0){
				if(i<=tree[j]){
					if(inimana >= i*cost[j]){
						if(dp[i][j]>=inf){
							dp[i][j] = inimana - i*cost[j];
						}else{
							dp[i][j] = max(dp[i][j],inimana - i*cost[j]);
						}
					}
				}
			}else{
				for(int k=0;k<=min(i,tree[j]);k++){
					if(dp[i-k][j-1] >= inf){continue;}
					LL x = min(dp[i-k][j-1]+manainc,(i-k)*manacapinc+inimana);
					if(x>=(k*cost[j])){
						if(dp[i][j]>=inf){
							dp[i][j] = x - k*cost[j];
						}else{
							dp[i][j] = max(dp[i][j],x - k*cost[j]);
						}
					}
				}
			}
			//cout<<i<<","<<j<<" -------- "<<dp[i][j]<<endl;
		}
	}
	for(int i=total;i>=0;i--){
		if(dp[i][n-1]<inf && dp[i][n-1]>=0){cout<<i<<endl;break;}
	}
}