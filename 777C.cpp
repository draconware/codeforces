#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	int n,m;
	scanf("%d %d", &n, &m);

	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d", &arr[i][j]);
		}
	}
	int t;
	scanf("%d", &t);

	int dp[n][m];
	for(int i=0;i<m;i++){dp[0][i]=1;}
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]>=arr[i-1][j]){dp[i][j] = dp[i-1][j]+1;}
			else{dp[i][j] = 1;}
		}
	}

	int res[n];
	for(int i=0;i<n;i++){res[i]=INT_MIN;}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			res[i]=max(res[i],dp[i][j]);
		}
	}
	while(t--){
		int x,y;
		scanf("%d %d", &x, &y);

		if(res[y-1]>=(y-x+1)){printf("Yes\n");}
		else{printf("No\n");}
	}
	return 0;
}